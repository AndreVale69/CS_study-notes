"""
Gestione semplice tabella Spese su PostgreSQL.\n
Manca la gestione delle eccezioni!
"""
from datetime import date
from decimal import Decimal

import psycopg2

# Il seguente import definisce delle variabili con dati sensibili
# come le password. Metodo semplice per isolare in un solo file
# tali parametri.
from myAppConfig import myHost, myDatabase, myUser, myPasswd

connessione = psycopg2.connect(host=myHost, database=myDatabase,\
                               user=myUser, password=myPasswd)
with connessione:
    with connessione.cursor() as cursore:
        cursore.execute(
            """CREATE TABLE IF NOT EXISTS Spese (
            id SERIAL PRIMARY KEY,
            data DATE NOT NULL,
            voce VARCHAR NOT NULL,
            importo NUMERIC NOT NULL
            )"""
        )
        print("Esito della creazione della tabella Spese:{:s}\n\
               Eventuali notifiche:{:s}"
            .format(cursore, statusmessage,
                    connessione, notices[-1]))
        
        cursore.execute("""SELECT count(*) FROM Spese""")
        numeroRighe = cursore.fetchone()[0]
        if numeroRighe == 0:
            cursore.execute("""
            INSERT INTO Spese(data, voce, importo)
            VALUES (%s,%s,%s), (%s,%s,%s), (%s,%s,%s), (%s,%s,%s)
            """,
            (
                date(2016,2,24), "Stipendio", Decimal("0.1"),
                date(2016,2,24), "Stipendio 'Bis'", Decimal("0.1"),
                date(2016,2,24), "Stipendio 'Tris'", Decimal("0.1"),
                date(2016,2,27), "Affitto", Decimal("-0.3")
            ))
            print("Esito dell'inserimento delle 4 tuple:{:s}"
                  .format(cursore.statusmessage)
        else:
            print("La tabella e' gia' presente con delle tuple e\
                  quindi nessuna tupla e' stata aggiunta.")
    connessione.commit() # Tutti i dati sono salvati

    with connessione.cursor() as lettore:
        lettore.execute("""
        SELECT id, data, voce, importo \
        FROM Spese
        """)
        print("Esito della selezione di tutte le tuple:{:s}"
              .format(cursore.statusmessage))
        print('=' * 55)
        patternRiga = "|{:>2s}|{:10s}|{:<20s}|{:>10s}|"
        print(patternRiga.format("N", "Data", "Voce", "Importo"))
        print('-' * 55)
        tot = Decimal("0")
        patternRiga = "|{:>2d}|{:10s}|{:<20s}|{:>10.2f}|"
        for tupla in lettore:
            print(patternRiga.format(tupla[0], tupla[1].isoformat(),
                                     tupla[2], tupla[3]))
            tot += tupla[3]
        print('-' * 55)
        # A questo punto la tabella e' stampata in output
    connessione.close()
print("{:>40s}{:10.2f}".format("Totale", tot))