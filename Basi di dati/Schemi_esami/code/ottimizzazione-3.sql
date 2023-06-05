SELECT  Nome, Abitanti, Superficie, Comune2
FROM    COMUNE JOIN ADIACENTE ON CodISTAT = Comune1
WHERE   TipoTerritorio <> 'pianura'