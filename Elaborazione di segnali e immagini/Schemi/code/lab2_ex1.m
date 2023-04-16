A = imread('Paperino.jpg');
figure(1); 
imagesc(A);
axis square
title('Immagine Originale')

% creo una copia
B = A;
% accedo alle posizioni per disegnare gli "occhiali"
B(163:209,90:136,:)=0;
B(163:209,164:211,:)=0;
B(185:188,137:162,:)=0;

% visualizzo
figure(2); 
imagesc(B);
axis square
title('Immagine Modificata')

% - Visualizzate l'immagine originale e quella modificata 
%   attraverso il comando surf, in due plot separati nella
%   stessa figura. Per visuallizzare con surf occorre
%   trasformare la foto in scala di grigio
figure(3);
subplot(1,2,1)
surf(rgb2gray(A))
shading('flat')
title('Immagine Originale')
subplot(1,2,2)
surf(rgb2gray(B))
shading('flat')
title('Immagine Modificata')