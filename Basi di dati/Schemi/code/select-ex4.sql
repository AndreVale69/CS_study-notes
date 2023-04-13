select distinct C.Nome, count(*) as NumCanzoni
from Cantante C join Autore A on C.Nome = A.Nome
group by C.Nome