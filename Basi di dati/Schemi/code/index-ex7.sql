CREATE INDEX ins_lower_nonins
       ON Insegn (LOWER (nomeins) varchar_pattern_ops);
ANALYZE Insegn;
SELECT nomeins FROM Insegn
WHERE LOWER (nomeins) LIKE 'algoritmi %'