cur.execute("SELECT * FROM test WHERE id < %s", (4))
for record in cur:
    print(record, end=", ")
# RISULTATO:
# (1, 100, "abc'def"), (2, None, 'dada'), (3, 42, 'bar')