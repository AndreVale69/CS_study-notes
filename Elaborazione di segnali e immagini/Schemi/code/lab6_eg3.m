%% Operazione puntuale: Trasformazione Non lineare (Log/Potenza) ---
% La trasformazione lineare espande in modo uniforme la dinamica 
% originale dell'immagine, producendo un effetto globale di
% miglioramento del contrasto.
% In alcuni casi pero' si ha l'esigenza di effettuare una
% trasformazione non uniforme, che agisca differentemente sui
% livelli di grigio. In particolare:
% Immagine sottoesposta = i particolari interessanti sono poco
%                         evidenti e concentrati nelle zone scure;
%                         in tal caso possiamo espandere la dinamica
%                         associata ai livelli scuri e comprimere
%                         quella dei livelli chiari;
% Immagine sovraesposta = i particolari interessanti sono poco
%                         evidenti e concentrati nelle zone chiare;
%                         in tal caso possiamo espandere la dinamica
%                         associata ai livelli chiari e comprimere
%                         quella dei livelli scuri.
% L'espansione non uniforme della dinamica dell'immagine si puo'
% ottenere mediante elevazione a potenza dei livelli originari.
clear all;
close all;
clc;

% carico immagine "Spine.png" e applico trasformazione 
% a potenza per migliore il contrasto
img = imread('Spine.png');
img = (rgb2gray(img));
figure, imshow(img),colorbar
figure,  imhist(img),colorbar

% I dettagli che mi interessano sono nei livelli di grigio scuri --
% --> gamma <1
gamma = 0.4;
s_tilde = double(img).^gamma;
s_tilde_min = double(min(s_tilde(:)));
s_tilde_max = double(max(s_tilde(:)));
MAX = 255;
MIN = 0;
s = ((s_tilde - s_tilde_min)./(s_tilde_max-s_tilde_min))*(MAX-MIN) + MIN;

s = uint8(s);
figure, imshow(s),colorbar
figure, imhist(s),colorbar


%
% carico immagine "satellite.jpg" e applico trasformazione
% di potenza per migliore il contrasto
img = imread('satellite.jpg');
img = (rgb2gray(img));
figure, imshow(img),colorbar
figure, imhist(img),colorbar

% I dettagli che mi interessano sono nei livelli di grigio chiari --
% --> gamma >1
gamma = 4;
s_tilde = double(img).^gamma;
s_tilde_min = double(min(s_tilde(:)));
s_tilde_max = double(max(s_tilde(:)));
MAX = 255;
MIN = 0;
s = ((s_tilde - s_tilde_min)./(s_tilde_max-s_tilde_min))*(MAX-MIN) + MIN;

s = uint8(s);

figure,  imshow(s),colorbar
figure, imhist(s),colorbar