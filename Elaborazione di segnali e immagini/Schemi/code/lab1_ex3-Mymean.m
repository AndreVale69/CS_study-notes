function y = MYmean(x)
% Calcola il valor medio.
% Per i vettori, MYmean(x) restituisce il valor medio.
% Per le matrici, MYmean(x) restituisce un vettore riga contenente il valor medio di ogni colonna.

[m,n] = size(x);

% A questo punto devo controllare se e' un vettore riga (1xn, quindi m=1) 
% oppure un vettore colonna (mx1, quindi n=1)

if m == 1 || n == 1
    % vettore
    y = sum(x)/length(x);
else
    % matrice
    % sum fa la somma colonna per colonna
    y = sum(x);
    % divido per il numero di righe
    y = y/m;
end