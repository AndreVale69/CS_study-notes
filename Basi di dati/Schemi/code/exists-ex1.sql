select *
from Persona P
where exists (select *
              from Persona P1
              where P1.Nome = P.Nome and
                    P1.Cognome = P.Cognome and
                    P1.CodFiscale <> P.CodFiscale)