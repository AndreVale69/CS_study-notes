% A vettore riga che contiene i numeri pari da 2 fino a 20, 
% B vettore riga con tutti i numeri da -22 a -13, 
% C vettore riga con 10 valori uguali a 0. 
A = [2:2:20];
B = [-22:1:-13];
C = zeros(1,10);
 
% Creare una matrice MatX dove le righe sono costituite da A, B e C (in questo ordine) 
MatX = [A;B;C];

% Verificare e salvare le dimensioni di MatX e il numero di elementi
[nr,nc] = size(MatX);
num = numel(MatX);

% Estrarre la sotto-matrice che contiene le prime due righe e le prime cinque colonne
MatXsub = MatX(1:2,1:5);

% Sostituire la seconda colonna di MatX con il valore 31
MatX(:,2) = 31;

% Creare una matrice MatY di numeri reali distribuiti in modo random (randn), 
% con 4 righe e 10 colonne
MatY = randn(4,10);

% Creare una matrice MatZ data dalla concatenazione di MatX e MatY
MatZ = [MatX;MatY];

% Verificare le dimensioni di MatZ ed estrarre la diagonale
[nrz,ncz] = size(MatZ);
diagZ = diag(MatZ);