conn = psycopg2.connect(...)
with conn:
    with conn.cursor() as cur1:
        # ...
    print("Qui cur1 e' stato chiuso")
print("Qui e' stato fatto solo un commit: conn e' ancora aperta!")
with conn:
    with conn.cursor() as cur2:
        # ...
    print("Qui cur2 e' stato chiuso")
print("Qui e' stato fatto un altro commit: conn e' ancora aperta!")
conn.close()