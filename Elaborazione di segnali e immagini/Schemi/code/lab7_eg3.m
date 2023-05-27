%% Esempio 2: Filtro Gaussiano
% Per creare un filtro locale gaussiano: fspecial
% filtro gaussiano KxK con standard deviation 0.6
H = fspecial('gaussian',3,0.6);
% Importante: relazione tra K (W nella teoria) e sigma:
% W = 5*sigma
Kg = imfilter(J,H,'replicate');
subplot(224); imagesc(Kg), colormap gray, axis image; title('Smoothing Gaussiano'), colorbar
SNRGmse = sum(Kg(:).^2)/sum((Kg(:)-I(:)).^2);
SNRGvar = var(I(:))/var(Kg(:));
fprintf('SNR img noisy + Gaussian smoothing \nMSE: %g\nVAR: %g\n',SNRGmse,SNRGvar);