cur.execute("SELECT * FROM test WHERE id < %s", (4))
cur.fetchmany(3)
# RISULTATO:
# [(1, 100, "abc'def"), (2, None, 'dada'), (3, 42, 'bar')]
cur.fetchmany(2)
# RISULTATO:
# []