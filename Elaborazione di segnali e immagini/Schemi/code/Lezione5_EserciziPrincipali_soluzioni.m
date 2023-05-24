% Corso di Elaborazione dei Segnali e Immagini
% Docente: Manuele Bicego 
% Docente Coordinatore: Marco Cristani
% Lezione 5: Soluzione esercizi principali 



%% Esempio 1 - SINUSOIDE A 20 Hz 1-D CAMPIONATA A 100 Hz 
% Obiettivo di questo esempio è mostrare come si possono
% generare segnali e controllarne lo spettro. In particolare,
% si definisce una sinusoide a 20 Hz, si campiona a 100Hz e si osserva lo 
% spettro di magnitudo con picco a 20 Hz. 
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

% Calcolo la trasformata di Fourier e definisco il vettore delle frequenze
F = fft(f);           % Fast Fourier Transform è l'implementazione della DFT
% Se il segnale originale ha N punti ho N bin in frequenza: 
% da 0 alla frequenza di campionamento (mu_s) con step mu_s/N
mu_sampling = mu_s/N; % passo
mu = 0:mu_sampling:mu_s-mu_sampling; % campioni nello spazio delle frequenze

subplot(222)
stem(mu,abs(F));
xlabel ('frequenza (Hz)')
ylabel ('|F|')
grid
title('DFT (abs) senza riordinamento');

% Eseguo operazione di centratura dello spettro e visualizzo spettro centrato
Fs = fftshift(F); % centratura 
mu_max = mu_s/2;  % frequenza di Nyquist ? 
mu = -mu_max:mu_sampling:mu_max-mu_sampling; % nuovo vettore frequenze 

subplot(223)
stem(mu,abs(Fs))
xlabel ('frequenza (Hz)')
ylabel ('|Fs|')
grid
title('DFT (abs) con riordinamento');

% Eseguo pulizia per eliminare le componenti con magnitudo bassa e calcolo la fase 
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
% calcolo la fft e la fft riordinata
% calcolo il vettore frequenze: 
%       fft riordinata: (N valori da -mu_s/2 a mu_s/2-step)
%       fft non riordinata: (N valori da 0 a mu_s-step)
%       step = mu_s/N
% visualizzo lo spettro di ampiezza
% Se segnale rumoroso: pulisco lo spettro e tolgo le frequenze troppo basse
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

% Calcolo la trasformata di Fourier e definisco il vettore delle frequenze
F = fft(f);           % Fast Fourier Transform è l'implementazione della DFT
mu_sampling = mu_s/N; % passo
mu = 0:mu_sampling:mu_s-mu_sampling; % campioni nello spazio delle frequenze

subplot(222)
stem(mu,abs(F));
xlabel ('frequenza (Hz)')
ylabel ('|F|')
grid
title('DFT (abs) senza riordinamento');

% Eseguo operazione di centratura dello spettro e visualizzo spettro centrato
Fs = fftshift(F); % centratura 
mu_max = mu_s/2;  % frequenza di Nyquist ? 
mu = -mu_max:mu_sampling:mu_max-mu_sampling; % nuovo vettore frequenze 

subplot(223)
stem(mu,abs(Fs))
xlabel ('frequenza (Hz)')
ylabel ('|Fs|')
grid
title('DFT (abs) con riordinamento');

% Eseguo pulizia per eliminare le componenti con magnitudo bassa e calcolo la fase 
th = 1e-6;
Fs(abs(Fs) < th) = 0; 

subplot(224)
stem(mu,angle(Fs)/pi) % Posso moltiplicare per 180 per avere gradi 
xlabel ('frequenza (Hz)')
ylabel ('fase/\pi')
grid
title('DFT (fase) con riordinamento');



%% Esercizio 1
% Analizzare tramite la Trasformata di Fourier Discreta  un segnale BOX
%   - Creare un'onda rettangolare di 1 secondo con una frequenza di 
%     campionamento di 500 Hz e una lunghezza di 0.2 s 
%     (funzione rectpuls – si veda l’help)
%   - Calcolare la DFT e visualizzarne lo spettro di ampiezza e di fase 
%     (con riordinamento)
%   - Controllare che il risultato ottenuto per lo spettro di ampiezza 
%     corrisponda a quanto spiegato in teoria
%
% (se si vuole): Provare ad effettuare la stessa analisi su un segnale audio 
% registrato direttamente in MATLAB, della durata di 4 secondi

% Funzione BoX

clear all
close all

mu_s = 500; % Frequenza di campionamento 
T = 0.2;    % lunghezza del rect in secondi 

time = -0.5-1/mu_s:1/mu_s:0.5; % Vettore dei tempi per il segnale rect 
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
mu_max = mu_s/2; % metà a sx e metà a dx dello zero

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

% Per la fase: ho un risultato molto rumoroso, quindi devo applicare un filtraggio restrittivo 
th = max(abs(FF))/4; % decido di pulire lo spettro cancellando i residui di frequenza sotto un quarto del massimo valore
FF(abs(FF) < th) = 0; 
theta = angle(FF);

subplot(133);
stem(freq,180*(theta)/pi)
xlabel ('frequenza (Hz)')
ylabel ('fase/\pi')
grid
title('Spettro di fase');



%% Esercizio 2
% Verificare il fenomeno dell'aliasing.
% In particolare: 
% - partire dal segnale sinusoidale sin(2*pi*fsig*t), dove fsig = 10 è la
%   frequenza del segnale
% - campionare un secondo di segnale ad una determinata frequenza ed effettuare
%   l'analisi di Fourier
% - Provare con le seguenti frequenze: 
%   [200, 100, 40, 20, 15, 14, 10]
% Per quali di queste avviene il fenomeno dell'aliasing?
% E' corretto rispetto alla teoria?


clear all
close all
clc

% creo il segnale campionato con frequenza Fs
% Suggerimento:
% Fisso Fs
% Calcolo DeltaT (1/Fs)
% Creo un vettore t per i tempi che va da 0 a 1 (1 secondo) con passo DeltaT
% creo il segnale con fsig = 10
% y = sin(2*pi*fsig*t);

for Fs = [200, 100, 40, 20, 15, 14, 10]
    Dt = 1/Fs;                % deltaT, passo
    t = 0:Dt:1-Dt;            % prendo un secondo di durata
    fsig = 10;                % frequenza sinusoide
    y = sin(2*pi*fsig*t);     % segnale
    
    
    % effettuo l'analisi di Fourier e visualizzo lo spettro riordinato
    
    N = length(t);            % numero di campioni
    Y = fft(y);
    mu_sampling = Fs/N;
    mu = -Fs/2:mu_sampling:Fs/2-mu_sampling;
    YY = fftshift(Y);
    
    close
    
    figure(1)
    subplot(211)
    stem(t,y,'filled')
    hold on;
    plot(t,y)
    title(['Segnale campionato con Fs = ',num2str(Fs)])
    
    
    subplot(212)
    stem(mu,abs(YY),'filled')
    title('DFT del segnale')
    xlabel('frequenze (Hz)')
    ylabel('magnitudo')
    
    pause
end
