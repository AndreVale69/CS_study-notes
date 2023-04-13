select Nome
from Cantante
where Nome not in
      (select Nome
       from Cantante C
       where Nome not in
             (select Nome
              from Autore
              where Autore.Canzone = C.Canzone))