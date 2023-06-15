CREATE INDEX ie_aa_idc ON Inserogato(annoaccademico, id_corsostudi);
ANALYZE Inserogato;

SELECT DISTINCT I.nomeins, I.codiceins
FROM Insegn I
    JOIN InsErogato IE ON I.id = IE.id_insegn
WHERE IE.annoaccademico = '2006/2007'
      AND IE.id_corsostudi = 4;