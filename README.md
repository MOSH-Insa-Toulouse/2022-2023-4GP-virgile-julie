# 2022-2023-4GP-virgile-julie
Projet 4GP du capteur au banc de test en open source hardware
---
## Sommaire
  - [1) Livrables](#1-livrables)
  - [2) Description](#2-description)
  - [3) Shield PCB](#3-shield-pcb)
  - [4) Arduino](#4-arduino)
  - [5) Application Android APK](#5-application-android-apk)
  - [6) Banc de test et mesures](#6-banc-de-test-et-mesures)
  - [7) Datasheet](#7-datasheet)
  - [8) Limites et perspectives](#8-Limites-et-perspectives)
---
## 1) Livrables

Lors de notre projecteur, nous avons décidé de réaliser l'ensemble des options (headers) sur la schématique du shield: 
- capteur
- module bluetooth
- flex sensor
- écran OLED
- potentiomètre digital
 
 Pour se faire, nous avons du réaliser un cahier des charges adaptés:
 
-  Réalisation d'un Shield PCB sur KiCad
-  Réalisation d'un code Arduino permettant la mesure du capteur, ainsi que le réglage du potentiomètre, l'affichage sur un écran OLED, l'envoie des données par module Bluetooth
- Réalisation d'une Application android APK réalisée avec MIT APP INVENTOR
- Réalisation d'une Datasheet du capteur
---
## 2) Description

Dans ce projet, nous allons concevoir un capteur résistif fonctionnant sur la base d'un phénomène physique observé qui est l'effet tunnel. En faisant varier la distance séparant les particules du réseau( par des déformations en compression et en tension), la conductivité du graphite varie ainsi que sa résistivité.

Pour appliquer ce phènomène, la jauge de contrainte sera peu couteuse. Elle se présente sous la forme d’un U en papier, sur lequel on vient déposer du graphite à l’aide d’un crayon à papier ceci est très simple à réaliser et sa fabrication ne génère pas d’impact négatif sur l’environnement. A noter aussi que la réponse du capteur va dépendre du type de mine utilisée. 


Nous avons débuté notre projet par la fabrication de notre shield pour notre chaine de mesures. Ce dernier a été conçu a l'aide du logiciel KICAD  sur la base du amplificateur transimpédance simulation électrique du circuit associé au shield sur le logiciel LTSpice.

![ ](Images_kicad/ampli_transimpédance.png)
    
    
Pour exploiter le signal de sortie du capteur par un convertisseur analogique-numérique d’une carte Arduino, la sortie du capteur est reliée à un circuit amplificateur transimpédance. Ce circuit dispose de trois étages de filtrage : 
- Un filtre passe-bas R1C1 qui permet de filtrer les bruits en courants sur le signal d’entrée
- Un filtre passe bas R3C4 couplé à un amplificateur opérationnel LTC1050 permettant de filtrer la composante du bruit à 50 Hz provenant du réseau électrique
- Un filtre de sortie R5C2 qui coupe les bruits due à l’échantillonnage de l’ADC
On retrouve la valeur de résistance du capteur grâce à la formule suivante : 
R=(1+R3/R2)*R1*Vcc/Vadc-R1-R5


Par la suite, nous avons ensuite imprimé notre circuit PCB après validation de celle-ci, qui aura demande de multiples essais. 
Puis, nous avons réalisé le montage des composants sur la carte vierge avec le matériel ci-dessous.

Matériel nécessaire
* 1 carte Arduino Uno
* 2 Résistance de 100kΩ
* 1 Résistance de 1kΩ
* 1 Potentiomètre digital MCP-41050
* 2 Condensateurs 100nF
* 1 Condensateurs 1µF
* 1 AOP LTC1050
* 1 Écran OLED01
* 1 Module Bluetooth HC-05

Puis, nous avons codé avec l'usage d'une carte Arduino le code permettant la lecture des mesures du capteur ainsi que l'ajout sur le code des fonctions associés aux différentes options ajoutés soit l'écran OLED, le module Bluetooth et le potentiomètre digital.  
Ensuite, nous avons développé une application Android qui a pour but de recevoir des données via Bluetooth grâce le site MIT App Inventor.  
Et enfin, nous avons réalisé notre propre banc de test : nous avons effectué un test de rayon de courbure et un test de répétabilité avec deux types de crayons (2B, HB2).  

---
## 3) Shield PCB

### Réalisation de la Schématique de Shield
Cette partie se consacre à la réalisation et la fabrication du support éléctronique, soit le PCB de notre projet. Il a été réalisé sur le logiciel Kicad en se basant sur le template d'un arduino uno.

Pour se faire, nous avons conçu l'ensemble des symboles et empreintes associés aux options choisis précédements. Avec les empreintes, nous les avons connecté avec le reste du circuit existant afin d'obtenir notre shield.

![](Images_kicad/Schématique_Shield.png)

### Réalisation de la Schématique du PCB
En se basant sur notre Shield, nous avons réalisé le routage de notre circuit en prenant soin de limiter les distances entre les composantes et leur pins associés. Cette étape fut très laboriseuse car le fait d'avoir une seule couche pour le PCB, nous obligeait de trouver des stratagèmes d'optimisation de place et de placement. Lorsque cette étape était fini, nous pouvons passer à la pose du plan de masse de notre circuit.

![](Images_kicad/Empreinte_SHIELD.png)

Comme nous pouvons le voir, le résultant possède néanmoins un fil supplémentaire, un fil rouge, qui sera ajouté lors de la fabrication du shield pour respecter le plan de masse. 

### Fabrication du PCB
Le PCB a été fabriqué à partir d'une plaquette d’époxy recouverte d’une fine couche de cuivre. 

Etapes de fabrication:

* Réaliser une insolation aux UVs de notre plaquette avec le calque de notre circuit (10 minutes)
* Retirer la partie de résine non isolée avec un révélateur
* Plonger notre plaquette dans un bain de percholorure de fer

### Assemblage des composantes
Lorsque le PCB a été fabriqué, il nous reste l'étape d'assemblage du shield. Pour se faire, il nous faut donc percer le PCB et souder les composants.
Pour ce qui est du perçage, dans les consignes, il était dit de prévoir deux tailles de trous sur le Kicad, soit un de diamètre 0,8mm pour les composants et headers et un de diamètre 1mm pour les broches de connexion de la carte Arduino Uno.

## 4) Arduino

## 5) Application Android APK
Nous avons développé une application android à l’aide du développeur MIT App Inventor. Couplée au module Bluetooth HC-05, cette application permet d’afficher en direct la résistance du capteur et l’évolution de la résistance en fonction du temps grâce à  un graphique déroulant.


![appli_bluetooth](https://github.com/MOSH-Insa-Toulouse/2022-2023-4GP-virgile-julie/assets/123975087/a192055e-3689-4256-bf70-24b60545cbc5)

Voici le schéma block de notre application : 

![schéma_block_appli_1](https://github.com/MOSH-Insa-Toulouse/2022-2023-4GP-virgile-julie/assets/123975087/490bf1ec-95da-4b09-ba4f-32359234c1b5)


![schéma_block_appli_2](https://github.com/MOSH-Insa-Toulouse/2022-2023-4GP-virgile-julie/assets/123975087/dc8a4b9c-ade0-4727-9aff-b7befa0f4e2a)


Le graphique déroulant permet une analyse qualitative plus que quantitative car le graphique déroulant n’a pas d’échelle en ordonnée. 
Les limites de cette application sont : 
-	Si on lance l’application alors que la carte Arduino tournait déjà, il y a une erreur car l’application ne reçoit pas une seule valeur numérique mais plusieurs
-	Si l’application reçoit la valeur infinie, l’application affiche une erreur 


## 6) Banc de test et mesures 

Un banc de test présentant différents arcs de cercle de différents diamètres a été utilisé pour les mesures de caractéristiques électriques. Le but est de mesurer la variation de résistance entre le capteur « à plat » et le capteur courbé sur les arcs de cercle. 
En désignant r le rayon du cercle et e l’épaisseur du banc de test, on calcule la déformation de chaque arc de cercle à partir de cette formule : ε = e / 2r 


![bancdetest](https://github.com/MOSH-Insa-Toulouse/2022-2023-4GP-virgile-julie/assets/123975087/364b97e4-43ff-4bdd-b029-aae2df5c6a04)


Nous avons testé notre capteur avec deux crayons différents : un avec une mine 2B et un avec une mine HB2.

![graph_mine2B](https://github.com/MOSH-Insa-Toulouse/2022-2023-4GP-virgile-julie/assets/123975087/68cd9440-5752-4a5c-8961-479224f5fc12)

Caractéristique du capteur en tension en fonction d’un pourcentage de déformation pour un crayon 2B

![grpah_mineHB2](https://github.com/MOSH-Insa-Toulouse/2022-2023-4GP-virgile-julie/assets/123975087/a3691d29-9dac-4ba0-b7cd-0eb3ac0961b1)

Caractéristique du capteur en tension en fonction d’un pourcentage de déformation pour un crayon HB2


## 7) Datasheet

Vous trouverez le lien vers la datasheet du capteur : 

## 8) Limites et perspectives

La réponse du capteur dépend grandement de la quantité déposée de graphite, ce qui est difficilement mesurable dans le cas du dépot avec une mine de crayon. 

La valeur de la résistance du potentiomète est modifiable seulement au niveau du code : si on veut modifier sa valaeur, il faut modifier le code. On peut imaginer un dispositif qui permet de modifier sa valeur grâce à l'ajout d'un composant au niveau du Hardware, comme par exemple un encodeur rotatif.


