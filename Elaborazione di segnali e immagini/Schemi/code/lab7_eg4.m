%% Esempio 3: Filtro Mediano
% In questo esempio si vedra' come e' possibile eliminare il rumore
% impulsivo utilizzando un filtro di smoothing mediano.
clear all
close all
clc

load imdemos
I = saturn2;
% aggiungo rumore sale e pepe all'immagine originale
J = imnoise(I,'salt & pepper',0.02);
figure; set(gcf,'name','Studio sintetico rumore e filtraggio');
subplot(221); imagesc(I), colormap gray, axis image; title('Originale')
colorbar
subplot(222); imagesc(J), colormap gray, axis image; title('Noisy')
colorbar
% casting per il calcolo del SNR
I = double(I);
J = double(J);
SNR1mse = sum(J(:).^2)/sum((J(:)-I(:)).^2);
SNR1var = var(I(:))/var(J(:));
fprintf('SNR img noisy (Salt-pepper)\nMSE: %g\nVAR: %g\n\n',SNR1mse,SNR1var);


% per applicare il filtro mediano si usa
% la funzione medfilt2
Kmed = medfilt2(J);
% senza parametri si applica un filtro 3x3
subplot(223); imagesc(Kmed), colormap gray, axis image; title('Smoothing Mediano'), colorbar

SNRMedmse = sum(Kmed(:).^2)/sum((Kmed(:)-I(:)).^2);
SNRMedvar = var(I(:))/var(Kmed(:));
fprintf('SNR img noisy (Salt-pepper) + Median smoothing\nMSE: %g\nVAR: %g\n\n',SNRMedmse,SNRMedvar);