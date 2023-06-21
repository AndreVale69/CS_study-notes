SELECT  i.nomeins, d.descrizione
FROM    inserogato      ie,
        insegn          i,
        discriminante   d
WHERE   ie.annoaccademico = '2009/2010' AND
        ie.modulo = 0                   AND
        ie.id_insegn = i.id             AND
        ie.id_discriminante = d.id      AND
        (ie.crediti = 3 OR 
         ie.crediti = 5 OR
         ie.crediti = 12)
GROUP BY i.nomeins, d.descrizione
ORDER BY d.descrizione