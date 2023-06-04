SELECT  R.CodiceRicetta, I.Nome, I.Calorie
FROM    RICETTA R JOIN COMPOSIZIONE C 
        ON R.CodiceRicetta = C.Ricetta
        JOIN INGREDIENTE I
        ON C.Ingrediente = I.Codice
WHERE   R.Regione = 'Veneto'