cur.executemany("INSERT INTO test(num, data) VALUES(%s, %s)",
                [(100, "abc'def"), (None, 'dada'), (42, 'bar')])