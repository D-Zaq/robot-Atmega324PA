# robot-Atmega324PA

Au sein d’une équipe formé de quatre ingénieurs, programmer en C/C++ et implémenter sur le microcontrôleur AVR Atmega324PA afin de rendre un robot capable d’éviter des obstacles à moins de 4m.

# 1. Description de la structure du code et de son fonctionnement

Étant donné les circonstances actuelles dans le monde, notre projet intégrateur du 
cours INF1900 a été remplacé par un robot simulé par le logiciel SimullDE. Ce robot 
a pour but de pouvoir simuler des évitements d’obstacles. En effet, le robot devra 
pouvoir effectuer des manœuvres d’évitement préprogrammées. Dès le début, tous 
les membres de l’équipe se sont mis d’accord sur le but à atteindre ainsi que la 
manière pour atteindre ce but, soit suivre le chemin le plus simple et le plus sûr afin 
d’avoir un robot fonctionnel. Pour ce faire, nous avons créé, dans notre librairie, un 
fichier .h et un fichier .cpp pour chaque périphérique. Dans ces fichiers, on trouve les 
fonctions liées à l’utilisation et le fonctionnement du périphérique en question.
Tout d’abord, les fichiers sonar.h et sonar.cpp contiennent les fonctions nécessaires 
pour l’envoi du signal (envSignal), la détection de l’écho de chacun des sonars 
(detecteGauche, detecteMilieu, detecteDroite), calculer la distance 
(calculerDistance) et par la suite afficher la valeur arrondie (arrondie) de cette 
dernière et l’étiquette qui lui est associée (ecrireEtiquette).

Ensuite, afin de manipuler adéquatement l’afficheur 7 segments, nous utilisons les 
fichiers afficherChiffreDansSegment.h et afficherChiffreDansSegment.cpp. Ces 
fichiers contiennent les fonctions nécessaires afin de sélectionner et rendre actif un 
des cinq afficheurs (choisirSegment) et ensuite afficher le chiffre voulu en allumant 
les bons segments (afficherChiffre). Ces deux dernières fonctions sont combinées 
pour créer une fonction qui fera les deux en même temps permettant ainsi l’affichage 
des vitesses des deux roues dans les bons afficheurs 
(afficherChiffreDansSegment).

En ce qui concerne l’écran LCD (liquid crystal display), on nous a fourni les fichiers 
avec préfixe “lcm_so1602dtr” et “customprocs”. Il s’agit ici de classes contenant de 
multiples méthodes utiles à l’utilisation de cet écran. Parmi eux, nous utilisons 
principalement les méthodes write et clear, la surcharge d’opérateur << ainsi que le 
constructeur de LCD.

Pour ce qui est des moteurs, nous avons utilisé un fichier par moteur, le droit 
(moteurDroit.cpp et moteurDroit.h), le gauche (moteurGauche.cpp et 
moteurGauche.h) et les deux en même temps (moteurs.cpp et moteurs.h). Pour 
contrôler chaque moteur (roue), nous avons utilisé trois fonctions. La première 
(changementVitesse) permet de changer la vitesse du robot. Les deux autres 
(acceleration et ralentissement) servent comme leurs noms l’indiquent à changer la 
vitesse du robot de façons graduelles. Dès qu’on change la vitesse, on fait appelle 
aux fonctions des fichiers de l’afficheur 7 segments pour mettre à jour la vitesse du 
robot simulé ainsi qu’aux fonctions des fichiers signalPWM.cpp et signalPWM.h. Ces 
fonctions sont ajustementPWM et ajustement qui modifient les registres OCR1B et OCR1A 
pour apporter les modifications nécessaires et ainsi mettre à jour les 
oscilloscopes. Pour cette partie, on s’est largement inspiré du tp6.

Par après, les fichiers allumerDel.cpp et allumerDel.h permettent le contrôle des DEL 
droite et gauche en utilisant les fonctions allumerDelGaucheVert, 
allumetDelDroiteVert, allumerDelGaucheRouge et allumetDelDroiteRouge.
Pour finir, les fichiers manoeuvre.h et manoeuvre.cpp contiennent les 6 manoeuvres 
à effectuer réparties dans des fonctions(manoeuvre1, manoeuvre2 ...) ainsi que la 
fonction (getManoeuvre) qui permettra de sélectionner quelle manoeuvre sera 
exécutée dans le switch case du programme principal. Ces manoeuvres sont choisies 
en fonction de la distance de l’obstacle détecté grâce au rebond du signal provenant 
des sonars.

Nous avons donc réuni toutes ces fonctions dans notre librairie pour pouvoir mener à 
bien les objectifs de ce projet final et contrôler efficacement les périphériques par la 
création d’un fichier (l'exécutable) main.cpp. Dans ce dernier fichier, on effectue les 
deux modes, soit le mode détection et le mode manoeuvre, en boucle. Le mode 
détection consiste à appeler la fonction d’envoi du signal et détecter l’écho d’un sonar 
et refaire ces deux étapes pour les deux autres sonars et ensuite calculer la distance 
en utilisant la fonction calculerDistance. Ce mode est exécuté en boucle lorsque le 
bouton poussoir n’est pas appuyé (bool clique = false). Lorsqu’on appuie sur le bouton 
poussoir, la routine d’interruption externe sera exécutée (bool clique = true). On 
passera alors en mode manoeuvre où un switch case sélectionne le bon cas afin 
d'exécuter la fonction de manoeuvre préprogrammée. À la fin de ce mode (après que
la manoeuvre se termine), on revient au mode détection (clique = false). 

# 2. Expérience de travail à distance

Pour ce qui est de l’expérience de travail à distance, nous avons été agréablement 
surpris. En effet, avant de commencer le projet, nous étions un peu réticents au 
changement étant donné que les circonstances liées au covid-19 ont fait en sorte que 
l’environnement de travail et nos états psychologiques n’étaient pas optimaux pour la 
réalisation de notre premier projet d’envergure.

Cependant, des plateformes de communications et de partages nous ont permis de 
rendre le travail en équipe plutôt agréable. Le logiciel Discord nous a permis de 
discuter en groupe dans des appels vocaux et sur messages textuels à tout moment 
et de pouvoir se partager nos écrans pour faciliter le travail. De plus, les chargés des 
laboratoires ont réussi à être présents et actifs afin de répondre à nos moindres soucis. 
La plateforme Git nous a permis de pouvoir avoir sur nos ordinateurs chacun des 
fichiers nécessaires aux projets, de pouvoir travailler dessus en équipe et de pouvoir les mettre à jour. 
Le logiciel SimullDE nous a permis d’avoir une simulation assez proche de la réalité et le fait d’avoir 
l’écran LCD nous a permis de déboguer de façon plus efficace qu’avec la DEL sur le robot physique.

En somme, il est vrai que travailler sur un robot physique et de le voir réaliser un 
parcours aurait été plus amusant et stimulant, mais, en ces temps de crise, on pense 
que notre projet à distance s’est bien déroulé.
