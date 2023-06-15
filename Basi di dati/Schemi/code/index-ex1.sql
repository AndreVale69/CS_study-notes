CREATE index nomeins_index ON Insegn ( nomeins );
ANALYZE Insegn;
SELECT id, nomeins FROM Insegn WHERE nomeins = 'Algoritmi'