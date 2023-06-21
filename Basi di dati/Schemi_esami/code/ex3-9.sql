SELECT  ie.id, i.nomeins, d.descrizione
FROM    insegn          i,
        discriminante   d,
        inserogato      ie
WHERE   ie.id_insegn = i.id             AND
        ie.id_discriminante = d.id      AND
        ie.annoaccademico = '2008/2009' AND
        ie.modulo = 0                   AND
        ie.crediti > 9
ORDER BY i.nomeins