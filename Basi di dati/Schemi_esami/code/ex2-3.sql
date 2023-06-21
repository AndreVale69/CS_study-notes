SELECT titolo, (fine-CURRENT_DATE) AS "GiorniRimanentiDiApertura"
FROM mostra
WHERE fine-CURRENT_DATE >= 0