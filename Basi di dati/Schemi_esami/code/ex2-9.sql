SELECT  COUNT(DISTINCT (opera.nomeautore, opera.cognomeautore))
        AS NumeroAutoriDistinti
FROM    opera, museo
WHERE   opera.museo = museo.nome    AND
        opera.citta = museo.citta