select *
from Persona P
where P.Nome = P1.Nome and
      P.Cognome = P1.Cognome and
      P.CodFiscale <> P1.CodFiscale