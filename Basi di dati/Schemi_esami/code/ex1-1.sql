CREATE DOMAIN GiorniSettimana AS CHAR(3)
       CHECK(VALUE IN('LUN', 'MAR', 'MER', 'GIO', 'VEN', 'SAB', 'DOM'));
CREATE TABLE Museo (
    nome            VARCHAR(30)
                    DEFAULT 'MuseoVeronese'
                    UNIQUE,
    citta           VARCHAR(20)
                    DEFAULT 'Verona',
    indrizzo        VARCHAR(100),
    numeroTelefono  VARCHAR(16),
    giornoChiusura  GiorniSettimana
                    NOT NULL,
    prezzo          INT 
                    NOT NULL
                    DEFAULT 10,
    PRIMARY KEY (nome, citta)
);
CREATE TABLE Opera (
    nome            VARCHAR(30),
    cognomeAutore   VARCHAR(20),
    nomeAutore      VARCHAR(20),
    museo           VARCHAR(30),
    citta           VARCHAR(20),
    epoca           VARCHAR(30),
    anno            INT,
    PRIMARY KEY(nome, cognomeAutore, nomeAutore),
    FOREIGN KEY(museo, citta) REFERENCES museo(nome, citta)
);
CREATE TABLE mostra (
    titolo  VARCHAR(30),
    inizio  DATE,
    fine    DATE
            NOT NULL,
    museo   VARCHAR(30),
    citta   VARCHAR(50),
    prezzo  INT,
    PRIMARY KEY(titolo, inizio),
    FOREIGN KEY(museo) REFERENCES museo(nome)
);
CREATE TABLE Orario (
    progressivo     INT,
    museo           VARCHAR(30)
                    NOT NULL,
    citta           VARCHAR(20)
                    NOT NULL,
    giorno          giornisettimana
                    NOT NULL,
    orarioApertura  TIME WITH TIME ZONE
                    DEFAULT '09:00 CET',
    orarioChiusura  TIME WITH TIME ZONE
                    DEFAULT '19:00 CET',
    PRIMARY KEY(progressivo),
    FOREIGN KEY(museo, citta) REFERENCES museo(nome, citta)
);