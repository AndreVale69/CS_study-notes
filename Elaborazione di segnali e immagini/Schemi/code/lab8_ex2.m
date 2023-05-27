%% Esercizio 2 - Trasformata di Hough
% 
% - Utilizzare la trasformata di Hough per estrarre le rette dalle seguenti 3
%   immagini (una sintetica, due reali):
%     - "line.jpg"
%     - "building.jpg"
%     - "Crane.png" 
% - Utilizzare le funzioni Matlab gia' implementate per la trasformata. 
%   Nota importante: l'input e' un'immagine binaria che contiene gli edge, da 
%   calcolare sull'immagine originale.
%   Suggerimento: per estrarre gli edge utilizzare il Canny edge detector
%   BW = edge(I,'canny');
% - Visualizzare le rette estratte sovrapposte all'immagine di partenza
% - Valutare come cambiano i risultati al variare dei parametri della trasformata
%   (numero di picchi, soglia, livello di quantizzazione di rho e di theta,
%   etc etc -- si veda l'help delle funzioni). 
%
%
% TRASFORMATA DI HOUGH in MATLAB
% Sono tre le funzioni di riferimento:
% 
% [H,theta,rho] = hough(BW) -> esegue la trasformata di Hough e ritorna:
% "rho" = distanza dall'origine fino alla linea lungo una
% retta perpendicolare alla linea stessa
% "theta" = l'angolo tra l'asse x e la retta perpendicolare
% "H" = la matrice di Hough le cui righe e colonne corrispondono ai valori
% di rho e theta 
% Per settare una diversa quantizzazione dello spazio utilizzare la
% variante:
% [H,T,R] = hough(BW,'RhoResolution',0.5,'Theta',-90:0.5:89);
%
% peaks = houghpeaks(H,numpeaks) -> identifica i picchi nella matrice H
% derivante dalla funzione hough. Numpeaks specifica il numero massimo di
% picchi da considerare. L'output, "peaks", ritorna una matrice contenente
% nelle righe/colonne le coordinate x/y dei picchi
%
% lines = houghlines(BW,theta,rho,peaks) -> estrae le linee nell'immagine
% binaria a partire dalle coordinate dei picchi contenute in peaks e dai
% valori di rho/theta. L'output, "lines", e' una struttura contenente
% informazioni sulle linee estratte. 
%



clear all
close all
clc

% Immagine 1
I = imread('line.png');

% Decommentare qui sotto per provare le altre immagini:
% Immagine 2
% RGB = imread('Crane.png');
% I  = rgb2gray(RGB);
%
% Immagine 3
% RGB = imread('building.jpeg');
% I  = rgb2gray(RGB);


% Passo 1. Estraggo gli edge
image = edge(I,'canny');

[M,N] = size(image);
figure(1), subplot(121), imshow(I), title('Immagine di Partenza'),axis square
subplot(122), imagesc(image), title('Edge - Canny'),axis square

% 1. Eseguo la trasformata di Hough e la visualizzo 
[H_M,theta_M,rho_M] = hough(image);
figure(2), imagesc(H_M), colormap jet, title('Trasformata di Hough')

% 2. Identifico i picchi nella trasformata di Hough
peaks = houghpeaks(H_M,5);
display(peaks)

% 3. Estraggo e visualizzo le linee sovrapposte all'immagine di partenza 
lines = houghlines(image,theta_M,rho_M,peaks);
figure(3), imagesc(I), colormap gray, hold on
for k = 1:length(lines)
   xy = [lines(k).point1; lines(k).point2];
   plot(xy(:,1),xy(:,2),'LineWidth',2,'Color','green');
end