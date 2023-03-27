select Nome,
from Impiegato
where   Cognome = 'Rossi' and
        (Dipart = 'Amministrazione' or
         Dipart = 'Produzione')