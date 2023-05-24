%% Esercizio 1
% Analizzare tramite la Trasformata di Fourier Discreta
% un segnale BOX:
%   - Creare un'onda rettangolare di 1 secondo con una frequenza di
%     campionamento di 500 Hz e una lunghezza di 0.2 s
%     (funzione rectpuls - si veda l'help)
%   - Calcolare la DFT e visualizzarne lo spettro di
%     ampiezza e di fase (con riordinamento)
%   - Controllare che il risultato ottenuto per lo spettro
%     di ampiezza corrisponda a quanto spiegato in teoria
%
% (se si vuole): Provare ad effettuare la stessa analisi
% su un segnale audio registrato direttamente in MATLAB,
% della durata di 4 secondi

% Funzione BoX

clear all
close all

mu_s = 500; % Frequenza di campionamento 
T = 0.2;    % lunghezza del rect in secondi 

% Vettore dei tempi per il segnale rect
time = -0.5-1/mu_s:1/mu_s:0.5;
x = rectpuls(time,T); % Genero l'onda rettangolare
% Guardare il doc di rectpuls

figure(1) 
plot(time,x,'k');
title(['Rectangular Pulse ampiezza =', num2str(T),'s']);
xlabel('tempo(s)');
ylabel('ampiezza');


% Passi:
% calcolo il vettore frequenze (N valori da -mu_s/2 a mu_s/2)
% calcolo la fft e la fft riordinata
% visualizzo lo spettro di ampiezza
% visualizzo lo spettro di fase


N = length(x); % N campioni, N freqs nella fft
mu_sampling = mu_s/N; % una ogni mu_s/N 
mu_max = mu_s/2; % meta' a sx e meta' a dx dello zero

% vettore delle frequenze: N valori da -mu_s/2 a mu_s/2 
mu = -mu_max:mu_sampling:mu_max-mu_sampling; 

X = fft(x); 

% Eseguo operazione di centratura dello spettro 
% e calcolo spettro di ampiezza
shifted = fftshift((X));
X1 = abs(shifted); 

figure(2)
plot(mu,X1,'r');
title('Spettro di Magnitudo');
xlabel('frequenza (Hz)')
ylabel('magnitudo |X(f)|');

figure(3)
plot(mu,180*angle(X)/pi,'r');
title('Spettro di Fase');
xlabel('frequenze (Hz)')
ylabel('fase/\pi');



% Seconda parte (se si vuole):  stessa analisi su un segnale audio
% registrato direttamente in MATLAB, della durata di 4 secondi

% Registro segnale audio
recObj = audiorecorder;
disp('Start')
recordblocking(recObj,4);
disp ('End')

play(recObj)
myVoice = getaudiodata(recObj);

% in recObj posso recuperare la frequenza di campionamento
% e il numero di campioni
mu_s = recObj.SampleRate; % Frequenza di campionamento 
N = recObj.TotalSamples; % Numero di campioni 


% Passi:
% calcolo il vettore frequenze (N valori da -mu_s/2 a mu_s/2)
% calcolo la fft e la fft riordinata
% visualizzo lo spettro di ampiezza
% pulisco lo spettro e tolgo le frequenze troppo basse
% visualizzo lo spettro di fase

mu_m = mu_s/2;
freq = -mu_m:mu_s/N:mu_m-mu_s/N; % vettore frequenze
F = fft(myVoice);
FF = fftshift(F);

figure(1)
subplot(131)
plot([1:N],myVoice);
xlabel('#campioni')
ylabel ('ampiezza')
title ('Segnale registrato') 

subplot(132)
plot(freq,(abs(FF)));
xlabel('frequenze (Hz)')
ylabel ('magnitudo')
title ('DFT (abs) del segnale ') 

% Per la fase: ho un risultato molto rumoroso,
% quindi devo applicare un filtraggio restrittivo.
% decido di pulire lo spettro cancellando i residui di
% frequenza sotto un quarto del massimo valore
th = max(abs(FF))/4;
FF(abs(FF) < th) = 0; 
theta = angle(FF);

subplot(133);
stem(freq,180*(theta)/pi)
xlabel ('frequenza (Hz)')
ylabel ('fase/\pi')
grid
title('Spettro di fase');