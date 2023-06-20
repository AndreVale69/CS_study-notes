cur.execute("INSERT INTO test(num, data) VALUES (%s, %s)", (42, 'bar'))
cur.statusmessage()
# RISULTATO: 'INSERT 0 1'