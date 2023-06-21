SELECT  cs.codice,
        cs.nome,
        cs.abbreviazione
FROM    corsostudi cs
WHERE   cs.nome ILIKE '%lingue%'