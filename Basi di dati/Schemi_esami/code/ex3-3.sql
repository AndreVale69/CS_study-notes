SELECT  cs.nome, f.nome
FROM    corsostudi cs,
        inserogato ie,
        corsoinfacolta cif,
        facolta f
WHERE   ie.id_corsostudi = cs.id        AND
        ie.annoaccademico = '2010/2011' AND
        cif.id_corsostudi = cs.id       AND
        cif.id_facolta    = f.id
GROUP BY cs.nome, f.nome
ORDER BY cs.nome