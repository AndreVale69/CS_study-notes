create view Stadi(NomeStadio, Squadra, NroPart) as
select NomeStadio, Paese,
       count(distinct Data, Ora)
from Incontro, Nazionale
where (Squadra1 = Paese or Squadra2 = Paese)
group by NomeStadio, Paese;

select Citta
from Stadio
where NomeStadio in
      (select NomeStadio
       from Stadi
       where Squadra = 'Italia' and
             NroPart =
                (select max(NroPart)
                from Stadi
                where Squadra = 'Italia'))