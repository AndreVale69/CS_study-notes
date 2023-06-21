SELECT  i.nomeins,
        d.descrizione,
        ie.nomemodulo,
        ie.modulo
FROM    inserogato      ie,
        corsostudi      cs,
        corsoinfacolta  cif,
        insegn          i,
        discriminante   d,
        facolta         f
WHERE   ie.annoaccademico = '2010/2011' AND
        ie.id_insegn = i.id             AND
        ie.id_discriminante = d.id      AND
        ie.id_corsostudi = cs.id        AND
        cs.id = cif.id_corsostudi       AND
        f.id = cif.id_facolta           AND
        f.nome = 'Economia'             AND
        ie.modulo > 0              