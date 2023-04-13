select distinct Nome, NumCanzoni = (select count(*)
                                    from Autore A
                                    where A.Nome = C.Nome)
from Cantante C