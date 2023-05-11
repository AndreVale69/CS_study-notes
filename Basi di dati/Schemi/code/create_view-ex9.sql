create view TasseInd(Targa, Tassa) as
select Targa, Tasse/count(*)
from Moto join Proprietario
      on Moto.Targa = Proprietario.Targa
group by Targa, Tasse;

select Nome, sum(Tassa)
from Proprietario join TasseInd
       on Proprietario.Targa = TasseInd.Targa
group by Nome