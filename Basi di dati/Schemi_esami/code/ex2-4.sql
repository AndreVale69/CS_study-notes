SELECT  orario.orarioapertura, orario.orariochiusura
FROM    orario, museo
WHERE   orario.museo = museo.nome       AND
        orario.citta = museo.citta      AND
        museo.giornochiusura != 'MAR'   AND
        orario.giorno = 'MAR'