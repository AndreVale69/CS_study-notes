%% Esercizio 1. Smoothing
%
% - Applicare diversi filtri di smoothing alle due immagini reali
%   definite sotto ("peacock" con rumore gaussiano e "peppers" con
%   rumore impulsivo);
% - Confrontare i risultati sia in modo qualitativo (quali
%   ritornano un'immagine migliore?) e quantitativo (quali
%   ritornano il valore di SNR piu' alto?)
%   -- Utilizzare SNR versione VAR;
% - Filtri da provare:
%   - media: 3x3, 5x5, 9x9
%   - gaussiano: 3x3, 5x5, 9x9 (attenzione a stimare correttamente
%                la deviazione standard del filtro con la regola)
%   - mediano: 3x3, 5x5, 9x9
%


clear all;
close all;
clc;


% Immagine 1. peacock con rumore gaussiano
I1 = rgb2gray(imread('peacock.jpg'));
J1 = imnoise(I1,'gaussian',0.01);
figure, imshow(I1); set(gcf,'name','Originale');
figure, imshow(J1); set(gcf,'name','Rumore Gaussiano');

% % Immagine 2. pepper con rumore impulsivo
load imdemos
I2 = pepper;
% aggiungo rumore sale e pepe all'immagine originale
J2 = imnoise(I2,'salt & pepper',0.05);
figure, imshow(I2); set(gcf,'name','Originale');
figure, imshow(J2); set(gcf,'name','Rumore Gaussiano');


for esempio = 1:2
    if esempio == 1
        % Soluzione per I1,J1
        I = I1;
        J = J1;
    else
        % Soluzione per I2,J2
        I = I2;
        J = J2;
    end
    fprintf('\n\nIMMAGINE %d\n',esempio);
    
    
    % Step 1: calcolo SNR immagine originale con rumore
    % Casting per il calcolo del SNR
    I = double(I);
    J = double(J);
    
    SNR1var = var(I(:))/var(J(:));
    
    % Step 2: Effettuo tutti i filtraggi: salvo i risultati in un array di celle
    % Media
    H = fspecial('average',3);
    Filtered{1} = imfilter(J,H);
    meth{1} = 'Media 3x3    '; % salvo il nome del filtro
    
    H = fspecial('average',5);
    Filtered{2} = imfilter(J,H);
    meth{2} = 'Media 5x5    '; % salvo il nome del filtro
    
    H = fspecial('average',9);
    Filtered{3} = imfilter(J,H);
    meth{3} = 'Media 9x9    ';
    
    
    % Gaussiano
    H = fspecial('gaussian',3,3/5);
    Filtered{4} = imfilter(J,H);
    meth{4} = 'Gaussiano 3x3';
    
    H = fspecial('gaussian',5,5/5);
    Filtered{5} = imfilter(J,H);
    meth{5} = 'Gaussiano 5x5';
    
    H = fspecial('gaussian',9,9/5);
    Filtered{6} = imfilter(J,H);
    meth{6} = 'Gaussiano 9x9';
    
    
    % Mediano
    Filtered{7} = medfilt2(J,[3 3]);
    meth{7} = 'Mediano 3x3  ';
    
    Filtered{8} = medfilt2(J,[5 5]);
    meth{8} = 'Mediano 5x5  ';
    
    Filtered{9} = medfilt2(J,[9 9]);
    meth{9} = 'Mediano 9x9  ';
    
    % calcolo e visualizzo i diversi SNR
    fprintf('SNR prima del filtraggio:      VAR: %g \n',SNR1var);
    for i = 1:9
        F = Filtered{i};
        SNRFiltvar = var(I(:))/var(F(:));
        fprintf('SNR dopo filtro %s: VAR: %g \n',meth{i},SNRFiltvar);
    end
    
    % visualizzo le soluzioni
    figure,set(gcf,'name','Filtrate');
    for i = 1:9
        F = Filtered{i};
        subplot(3,3,i)
        imshow(uint8(F))
        title(meth{i})
    end
end