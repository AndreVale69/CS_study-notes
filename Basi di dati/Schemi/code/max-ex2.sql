select Cognome, Nome, max(Stipendio)
from Impiegato, Dipartimento D
where Dipart = D.Nome and
      D.Citta = 'Milano'