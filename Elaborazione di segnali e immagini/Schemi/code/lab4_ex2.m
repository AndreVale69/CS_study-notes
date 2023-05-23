%% Esercizio 2
% Implementazione manuale della cross-correlazione 2D
% Calcolare manualmente la cross correlazione 2D tra le 
% matrici X1 e X2. Confrontare con il risultato del
% comando matlab xcorr2(X1,X2)
%
% Suggerimento: usare la versione piu' ottimizzata:
% si fa zero padding della matrice immagine (la matrice piu'
% grande) e si fa scorrere il kernel
% 

clear all
close all

X1 =[1     2     5     2     5;
     3     4     5     4     2;
     5     2     3     2     2;
     2     3     2     4     2;
     3     4     2     2     3];
     
     
X2 =[3     3     2;
     2     3     4;
     4     5     4];

 
[R1, C1] = size(X1);
[R2, C2] = size(X2);

% Zero padding: aggiungere (R2-1) colonne di zeri a dx e a sx e 
% (C2-1) righe di zeri sopra e sotto

% In due passi: prima si aggiungono le colonne 
paddedX1 = [zeros(R1,C2-1) X1 zeros(R1,C2-1)];
% In pratica:
% paddedX1 = [zeros(5,2) X1 zeros(5,2)];

% ora le righe
paddedX1 = [zeros(R2-1,C1+2*(C2-1)); paddedX1; ...
            zeros(R2-1,C1+2*(C2-1))];
% In pratica:
% paddedX1 = [zeros(2,5+4); paddedX1; zeros(2,5+4)];


% si crea la matrice di cross-correlazione
% dimensione 7x7: (5+3-1)x(5+3-1)
MyCrossCorr = zeros(R1+R2-1,C1+C2-1);

[r,c] = size(MyCrossCorr); % valori da calcolare

% doppio ciclo for
for i = 1:r
    for j = 1:c
        % si estrae la parte di paddedX1 
        extractedX1 = paddedX1(i:i+R2-1,j:j+C2-1);
        % si moltiplica punto a punto per il kernel
        tmp = extractedX1.*X2;
        % si somma e si memorizza in posizione i,j
        MyCrossCorr(i,j) = sum(tmp,'all');
    end
end

% confronto con il risultato 
MatlabCrossCorr = xcorr2(X1,X2);

% check
sum(abs(MyCrossCorr - MatlabCrossCorr),'all')