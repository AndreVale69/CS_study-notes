SELECT  ie.annoaccademico,
        MAX(ie.crediti) AS MaxCrediti,
        MIN(ie.crediti) AS MinCrediti
FROM    inserogato  ie
GROUP BY ie.annoaccademico