select distinct C.Nome, NumCantante, NumScritte
from (select Nome, count(*) as NumCantante
      from Cantante) C join
     (select Nome, count(*) as NumScritte
      from Autore) A
     on C.Nome = A.Nome