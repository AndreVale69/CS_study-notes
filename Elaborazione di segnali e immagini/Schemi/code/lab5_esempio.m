%% Esempio 1 - SINUSOIDE A 20 Hz 1-D CAMPIONATA A 100 Hz 
% Obiettivo di questo esempio e' mostrare come si possono
% generare segnali e controllarne lo spettro. In particolare,
% si definisce una sinusoide a 20 Hz, si campiona a 100Hz e
% si osserva lo spettro di magnitudo con picco a 20 Hz. 
% Controllare anche lo spettro di fase.


clear all
close all
clc

% FUNZIONI RICHIESTE: fft, fftshift, abs, angle

% Definisco le principali variabili di interesse e il segnale
mu = 20;        % frequenza del segnale sinusoidale
mu_s = 100;     % frequenza di campionamento 
Dt = 1/mu_s;    % delta T visto a lezione
t = 0:Dt:1-Dt;  % prendo un secondo di durata
N = length(t);  % numero di campioni

f = sin(2*pi*mu*t); % segnale sinusoidale

figure
subplot(221)
plot(t,f,'-b.','MarkerSize',9)
xlabel ('tempo (sec.)')
ylabel ('f(t)')
title('Segnale campionato');

% Calcolo la trasformata di Fourier e
% definisco il vettore delle frequenze
% Fast Fourier Transform e' l'implementazione della DFT
F = fft(f);
% Se il segnale originale ha N punti ho N bin in frequenza:
% da 0 alla frequenza di campionamento (mu_s) con step mu_s/N
mu_sampling = mu_s/N; % passo
% campioni nello spazio delle frequenze
mu = 0:mu_sampling:mu_s-mu_sampling;

subplot(222)
stem(mu,abs(F));
xlabel ('frequenza (Hz)')
ylabel ('|F|')
grid
title('DFT (abs) senza riordinamento');

% Eseguo operazione di centratura dello spettro e
% visualizzo spettro centrato
Fs = fftshift(F); % centratura 
mu_max = mu_s/2;  % frequenza di Nyquist ? 
% nuovo vettore frequenze
mu = -mu_max:mu_sampling:mu_max-mu_sampling;

subplot(223)
stem(mu,abs(Fs))
xlabel ('frequenza (Hz)')
ylabel ('|Fs|')
grid
title('DFT (abs) con riordinamento');

% Eseguo pulizia per eliminare le componenti
% con magnitudo bassa e calcolo la fase 
th = 1e-6;
Fs(abs(Fs) < th) = 0; 

subplot(224)
stem(mu,angle(Fs)/pi) % Posso moltiplicare per 180 per avere gradi
xlabel ('frequenza (Hz)')
ylabel ('fase/\pi')
grid
title('DFT (fase) con riordinamento');


%%%%%%%% RIASSUNTO:
% Passi:
% calcolo il vettore dei tempi e delle frequenze
% (N valori da -mu_s/2 a mu_s/2)
% calcolo la fft e la fft riordinata
% calcolo il vettore frequenze: 
%       fft riordinata: (N valori da -mu_s/2 a mu_s/2-step)
%       fft non riordinata: (N valori da 0 a mu_s-step)
%       step = mu_s/N
% visualizzo lo spettro di ampiezza
% Se segnale rumoroso: pulisco lo spettro e
% tolgo le frequenze troppo basse
% visualizzo lo spettro di fase
%%%%%%%%%%%%%%%%%%%


%%%%%%%%%%%%%%%%%%%%%%%
% Altro esempio con il seguente segnale: 
% f = cos(2*pi*10*t) - sin(2*pi*40*t)
% cosa ottengo?

f = cos(2*pi*10*t) - sin(2*pi*40*t); % segnale sinusoidale

figure
subplot(221)
plot(t,f,'-b.','MarkerSize',9)
xlabel ('tempo (sec.)')
ylabel ('f(t)')
title('Segnale campionato');

% Calcolo la trasformata di Fourier e
% definisco il vettore delle frequenze
% Fast Fourier Transform e' l'implementazione della DFT
F = fft(f);
mu_sampling = mu_s/N; % passo
% campioni nello spazio delle frequenze
mu = 0:mu_sampling:mu_s-mu_sampling;

subplot(222)
stem(mu,abs(F));
xlabel ('frequenza (Hz)')
ylabel ('|F|')
grid
title('DFT (abs) senza riordinamento');

% Eseguo operazione di centratura dello spettro e
% visualizzo spettro centrato
Fs = fftshift(F); % centratura 
mu_max = mu_s/2;  % frequenza di Nyquist ? 
% nuovo vettore frequenze 
mu = -mu_max:mu_sampling:mu_max-mu_sampling;

subplot(223)
stem(mu,abs(Fs))
xlabel ('frequenza (Hz)')
ylabel ('|Fs|')
grid
title('DFT (abs) con riordinamento');

% Eseguo pulizia per eliminare le componenti
% con magnitudo bassa e calcolo la fase 
th = 1e-6;
Fs(abs(Fs) < th) = 0; 

subplot(224)
stem(mu,angle(Fs)/pi) % Posso moltiplicare per 180 per avere gradi
xlabel ('frequenza (Hz)')
ylabel ('fase/\pi')
grid
title('DFT (fase) con riordinamento');