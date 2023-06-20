cur.execute("CREATE TABLE test(\
            id SERIAL PRIMARY KEY,\
            num integer,\
            data varchar)")
cur.execute("INSERT INTO test(num, data) VALUES(%s, %s)",
            (100, "abc'def"))
# psyconpg2 fa le conversioni!