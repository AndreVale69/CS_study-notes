SELECT  cs.nome,
        ie.annoaccademico,
        SUM(ie.crediti) AS SommaCrediti
FROM    inserogato ie,
        corsostudi cs
WHERE   ie.id_corsostudi = cs.id    AND
        ie.modulo = 0
GROUP BY ie.annoaccademico, cs.id