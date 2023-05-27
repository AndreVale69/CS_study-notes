%% ESEMPI: creazione e applicazione diversi di filtri di smoothing
% e calcolo SNR
%
% Definisco l'immagine simulata I a cui poi aggiungo rumore
% gaussiano

clear all
close all
clc

I = ones(128,128).*128;
I(1:64,1:64) = 96;
I(65:128,65:128) = 160;
J = I +normrnd(0,5,128,128);
figure; set(gcf,'name','Studio sintetico rumore e filtraggio');
subplot(221); imagesc(I), colormap gray, axis image; title('Originale')
colorbar
subplot(222); imagesc(J), colormap gray, axis image; title('Noisy')
colorbar

% Calcolo il SNR_{MSE} e SNR_{VAR} nell'immagine di partenza
% f = I (immagine senza rumore)
% ftilde = J (immagine con rumore)
num = sum(J(:).^2);
den = sum((J(:)-I(:)).^2);
SNR1mse = num/den;
SNR1var = var(I(:))/var(J(:));
% Attenzione:
% Se l'immagine e' uint8 occorre fare un casting per avere la
% precisione nei calcoli (e la funzione "var" prende in 
% ingresso solo single/double):
% I = double(I);
% J = double(J);
% In questo esempio non ci sono problemi perche' e' un
% immagine sintetica definita come double

fprintf('SNR img noisy (Gauss)\nMSE: %g\nVAR: %g\n',SNR1mse,SNR1var);