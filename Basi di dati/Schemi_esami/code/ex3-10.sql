SELECT  i.nomeins,
        d.descrizione,
        ie.crediti,
        ie.annierogazione
FROM    insegn          i,
        inserogato      ie,
        corsostudi      cs,
        discriminante   d
WHERE   ie.modulo = 0                   AND
        ie.annoaccademico = '2010/2011' AND
        cs.nome LIKE '%Informatica'     AND
        ie.id_corsostudi = cs.id        AND
        ie.id_insegn = i.id             AND
        ie.id_discriminante = d.id
ORDER BY i.nomeins ASC