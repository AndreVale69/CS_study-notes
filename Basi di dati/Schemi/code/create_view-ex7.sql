create view StadiItalia(NomeStadio, NroPart) as
select NomeStadio, count(*)
from Incontro
where Squadra1 = 'Italia' or
      Squadra2 = 'Italia'
group by NomeStadio;

select Citta
from Stadio
where NomeStadio in
      (select NomeStadio
       from StadiItalia
       where NroPart =
          (select max(NroPart)
           from StadiItalia))