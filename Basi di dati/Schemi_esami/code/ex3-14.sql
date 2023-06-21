SELECT  COUNT(ie.id_insegn) AS NumeroInsegnamenti,
        cs.nome
FROM    corsoinfacolta  cif,
        inserogato      ie,
        corsostudi      cs,
        facolta         f
WHERE   ie.modulo = 0               AND
        cif.id_corsostudi = cs.id   AND
        cif.id_facolta = f.id       AND
        ie.id_corsostudi = cs.id    AND
        f.nome LIKE '%Scienze Matematiche Fisiche e Naturali'
GROUP BY cs.nome