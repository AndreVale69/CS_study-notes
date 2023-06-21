ALTER TABLE mostra
      RENAME COLUMN prezzo TO prezzoIntero;

ALTER TABLE mostra
      ADD COLUMN prezzoRidotto INTEGER
                               DEFAULT 5;

ALTER TABLE mostra
      ADD CONSTRAINT CHK_Prezzo CHECK(prezzoRidotto < prezzoIntero);