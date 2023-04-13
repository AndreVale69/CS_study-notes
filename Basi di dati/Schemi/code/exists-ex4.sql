select *
from Persona P
where (Nome,Cognome) not in
            (select Nome, Cognome
             from Persona Q
             where Q.CodFiscale <> P.CodFiscale)