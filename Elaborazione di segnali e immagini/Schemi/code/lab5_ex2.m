%% Esercizio 2
% Verificare il fenomeno dell'aliasing.
% In particolare: 
% - partire dal segnale sinusoidale sin(2*pi*fsig*t),
%   dove fsig = 10 e' la frequenza del segnale
% - campionare un secondo di segnale ad una determinata
%   frequenza ed effettuare l'analisi di Fourier
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
% Creo un vettore t per i tempi che va da 0 a 1 (1 secondo)
% con passo DeltaT creo il segnale con fsig = 10
% y = sin(2*pi*fsig*t);

for Fs = [200, 100, 40, 20, 15, 14, 10]
    Dt = 1/Fs;                % deltaT, passo
    t = 0:Dt:1-Dt;            % prendo un secondo di durata
    fsig = 10;                % frequenza sinusoide
    y = sin(2*pi*fsig*t);     % segnale
    
    
    % effettuo l'analisi di Fourier e
    % visualizzo lo spettro riordinato
    
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