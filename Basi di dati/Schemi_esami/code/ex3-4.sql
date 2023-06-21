SELECT  cs.nome,
        cs.codice,
        cs.abbreviazione
FROM    corsostudi      cs,
        corsoinfacolta  cif,
        facolta         f
WHERE   cs.id = cif.id_corsostudi   AND
        f.id = cif.id_facolta       AND
        f.nome = 'Medicina e Chirurgia'