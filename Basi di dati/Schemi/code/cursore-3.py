cur.execute("SELECT * FROM test WHERE id=%s", (3))
cur.fetchone()
# RISULTATO: (3, 42, 'bar')