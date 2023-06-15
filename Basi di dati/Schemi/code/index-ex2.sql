SELECT DISTINCT I.nomeins
FROM CorsoStudi CS
    JOIN InsErogaTO IE ON CS.id = IE.id_corsostudi
    JOIN Insegn I ON I.id = IE.id_insegn
WHERE IE.annoaccademico = '2009/2010'
    AND CS.nome = 'Laurea in Informatica';