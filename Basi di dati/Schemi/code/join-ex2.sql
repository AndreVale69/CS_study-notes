select Nome, Cognome, G.NroPatente,
       Targa, Marca, Modello
from Guidatore G left join Automobile A
     on (G.NroPatente = A.NroPatente)