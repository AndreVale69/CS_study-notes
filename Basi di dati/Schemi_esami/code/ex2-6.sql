SELECT      mostra.titolo, mostra.inizio, mostra.fine
FROM        mostra
WHERE       mostra.fine > CURRENT_DATE
ORDER BY    mostra.inizio ASC, mostra.fine ASC