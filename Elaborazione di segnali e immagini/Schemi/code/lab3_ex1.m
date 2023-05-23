%%
%%% ESERCIZIO 1
% Implementare a mano la cross correlazione 1D, partendo e
% completando lo script sottostante
clear all
close all
clc

f1 = [1 1 1 1 1 1 1 1]; %box 
f2 = [1 2 3 4 5 6 7 8]; %triangolo

M = length(f1);
N = length(f2);

% NOTA: Assumiamo per questo esercizio che f1 e f2 
% abbiano la stessa dimensione: in caso contrario si puo' fare 
% zero-padding, come spiegato qui di seguito:
%
% Zero padding: operazione per rendere uguali le dimensioni dei
%               vettori (segnali) in ingresso
% if N>M 
%    % concatena due vettori: cat(DIM,A,B)
%    f1 = cat(2,f1,zeros(1,N-M));
%    M=N;
% elseif N<M
%    f2 = cat(2,f2,zeros(1,M-N));
% end
% 


figure; set(gcf,'name','Cross Correlazione','IntegerHandle','off');
subplot(511); stem(f1); title('f1')
subplot(512); stem(f2); title('f2')

% Primo confronto: un bin di sovrapposizione
% si aggiungono zeri a destra e a sinistra
tf1 = [zeros(1,N-1),f1,zeros(1,N-1)];
tf2 = [f2,zeros(1,2*N-2)];

lag = [-N+1:N-1];
MYf1xf2 = [];
for i=1:2*N-1
    subplot(513); stem(tf1); title('f1 allineato')
    subplot(514); stem(tf2); title('f2 allineato')
    % calcolare il valore della cross correlazione
    MYf1xf2 = [MYf1xf2 sum(tf1.*tf2)];
    % spostare f2 verso destra aggiungendo uno zero davanti e
    % rimuovendolo in fondo
    tf2(end) = [];
    tf2 = [0 tf2];
    % Oppure si ricostruisce da zero
    % tf2 = [zeros(1,i) f2 zeros(1,2*M-2-i)];
    % Ultima possibilita': si puo' fare in modo compatto
    % con circshift
    % tf2 = circshift(tf2,1,2);
    
    % visualizzare il vettore di crosscorrelazione
    % calcolato fino adesso
    subplot(515); stem(lag(1:i),MYf1xf2); xlim([-N+1 N-1]);
    
    % il programma si ferma per un secondo
    pause(1);
end

hold on; subplot(515); plot(lag(1:i),MYf1xf2); 