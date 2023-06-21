-- DISTINCT evita che si contino due giorni uguali. Perche' nella
-- tabella orario si potrebbe trovare due giorni uguali ma con
-- orari differenti (e.g. mattina e pomeriggio)
SELECT  COUNT(DISTINCT orario.giorno)
FROM    museo, orario
WHERE   museo.nome = 'Arena'        AND
        museo.citta = 'Verona'      AND
        museo.nome = orario.museo   AND
        museo.citta = orario.citta