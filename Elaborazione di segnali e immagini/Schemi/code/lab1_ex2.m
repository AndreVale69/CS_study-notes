% Generare un numero casuale con il comando randn (distribuzione normale standard). 
x = randn;

% Assegnare alla variabile y il valore 1 se tale numero e' compreso
% tra -1 e 1 (media +- deviazione standard), 0 altrimenti.
if x < 1 && x > -1
    y = 1;
else
    y = 0;
end

% visualizziamo il numero generato
fprintf('Numero generato: %f\n',x) % funzione fprintf per stampare


% visualizziamo y
fprintf('E'' compreso fra -1 e 1?')
y

% - Se ripeto il procedimento 10000 volte, quante volte il numero
%   casuale cade nell'intervallo [-1 1]?
cnt = 0;
for i = 1:10000
    x = randn;
    if x < 1 && x > -1
        cnt = cnt+1;
    end
end
fprintf('Numero di volte in cui il numero cade fra -1 e 1: %d\n',cnt)

% EXTRA: Provare a risolvere l'esercizio anche senza usare cicli 
% (suggerimento: consultate l'help della funzione randn)
x = randn([1 10000]); % Genero un vettore con 10000 numeri casuali
y = (x < 1) & (x > -1); 
cnt = sum(y);
fprintf('Numero di volte in cui il numero cade fra -1 e 1: %d\n',cnt)