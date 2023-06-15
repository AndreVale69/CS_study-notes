CREATE INDEX ie_id_corsostudi   ON Inserogato(id_corsostudi);
CREATE INDEX ie_aa              ON Inserogato(annoaccademico);
ANALYZE Inserogato;

SELECT DISTINCT I.nomeins, I.codiceins
FROM Insegn I
    JOIN InsErogato IE ON I.id = IE.id_insegn
WHERE IE.annoaccademico = '2006/2007'
      AND IE.id_corsostudi = 4;