insert into ProdottiMilanesi
       (select Codice, Descrizione
        from Prodotto
        where LuogoProd = 'Milano')