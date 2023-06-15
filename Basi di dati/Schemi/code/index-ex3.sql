CREATE INDEX cs_id              ON CorsoStudi(id);
CREATE INDEX i_id               ON Insegn(id);
CREATE INDEX ie_id_corsostudi   ON Inserogato(id_corsostudi);
CREATE INDEX ie_id_insegn       ON Inserogato(id_insegn);
CREATE INDEX ie_aa              ON Inserogato(annoaccademico);
CREATE INDEX cs_nome            ON Corsostudi(nome);
ANALYZE Corsostudi;
ANALYZE Inserogato;
ANALYZE Insegn;

SELECT DISTINCT I.nomeins
FROM CorsoStudi CS
    JOIN InsErogato IE ON CS.id = IE.id_corsostudi
    JOIN Insegn I ON I.id = IE.id_insegn
WHERE IE.annoaccademico = '2009/2010'
      AND CS.nome = 'Laurea in Informatica';