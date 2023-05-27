%% Esempio 1: Filtro Media
% Per creare un filtro locale media: fspecial
% si veda doc fspecial
% Creo un filtro media 3x3
H = fspecial('average',3);
% Per applicare il filtro all'immagine: imfilter
Km = imfilter(J,H,'replicate');
% 'replicate' e' un'opzione per gestire il "problema dei bordi"
% Visualizzo il risultato
subplot(223); imagesc(Km), colormap gray, axis image; title('Smoothing Media'), colorbar
% Calcolo SNR
SNRMmse = sum(Km(:).^2)/sum((Km(:)-I(:)).^2);
SNRMvar = var(I(:))/var(Km(:));
fprintf('SNR img noisy + Mean smoothing \nMSE: %g\nVAR: %g\n',SNRMmse,SNRMvar);