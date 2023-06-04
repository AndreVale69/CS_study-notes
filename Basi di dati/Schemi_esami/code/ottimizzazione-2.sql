SELECT  IR.Ingrediente, IR.Quantita, IR.Ricetta, R.Regione
FROM    IN_RICETTA IR, RICETTA R
WHERE   IR.Ricetta = R.Nome AND
        R.Regione = 'Veneto' AND
        IR.Quantita = 4