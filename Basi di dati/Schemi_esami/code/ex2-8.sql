SELECT  AVG(orario.orariochiusura::time-orario.orarioapertura::time)
        AS OreMedieDiApertura
FROM    museo, orario
WHERE   museo.nome = 'Arena'        AND
        museo.citta = 'Verona'      AND
        museo.nome = orario.museo   AND
        museo.citta = orario.citta