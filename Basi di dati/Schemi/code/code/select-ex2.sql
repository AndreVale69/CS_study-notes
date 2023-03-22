-- Diviso 12 perche' il campo Stipendio e' annuale
select Stipendio/12 as StipendioMensile
from Impiegato
where Cognome = 'Bianchi'