select I1.Nome
from Impiegato I1, Impiegato I2
where I1.Nome = I2.Nome and
      I2.Dipart = 'Produzione'