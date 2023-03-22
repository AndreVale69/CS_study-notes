select Impiegato.Nome, Impiegato.Cognome, Dipartimento.Citta
from Impiegato, Dipartimento
where Impiegato.Dipart = Dipartimento.Nome