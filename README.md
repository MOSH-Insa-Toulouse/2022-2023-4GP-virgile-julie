# 2022-2023-4GP-virgile-julie
Projet 4GP du capteur au banc de test en open source hardware
---
## Sommaire
- [2022_Franco_Alonso_Projet_capteur](#2022_franco_alonso_projet_capteur)
  - [Sommaire](#sommaire)
  - [1) Livrables](#1-livrables)
  - [2) Description](#2-description)
  - [3) Shield PCB](#3-shield-pcb)
  - [4) Arduino](#4-arduino)
  - [5) Application Android APK](#5-application-android-apk)
  - [6) Banc de test](#6-banc-de-test)
  - [7) Datasheet](#7-datasheet)
  - [8) limites](#7-limites)
---
## 1) Livrables
Lors de notre projecteur, nous avons décidé de réaliser l'ensemble des options sur la schématique du shield: 
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

Dans le cadre de l'UF MOSH, nous avons conçu un capteur résistif composé de matériaux peu chers : un simple papier et un crayon suffisent à créer ce capteur.
Ici, le phénomène physique observé est l'effet tunnel. En effet, il existe un lien entre la conduction des électrons et la distance interatomique du réseau percolet. En faisant varier la distance séparant les particules du réseau (en pliant une feuille de papier sur laquelle on aura déposé du graphite par exemple), la conductivité du graphite varie, la résistivité varie également, et donc, la résistance variera aussi en fonction des dimensions du capteur. C'est cette propriété que l'on va exploiter afin de créer notre capteur résistif.  
Nous avons également implémenté  un shield sur notre chaine de mesures. Ce dernier a été conçu a l'aide du logiciel KICAD et aura un rôle de conditionneur du signal. Le shield est composé d'un amplificateur transimpédance, d'un module Bluetooth, d'un écran OLED, d'un encodeur rotatoire ainsi que d'une entrée analogique pour le capteur résistif.  
Pour finir, nous avons effectué l'ensemble des tests du circuit sur le logiciel LTSpice (voir [_Rapport LTSpice_](https://github.com/MOSH-Insa-Toulouse/2022_Franco_Alonso_Projet_capteur/blob/8504636d878c9423babecade3b70e7a892836c6b/Rapport_LTSpice.pdf)).  
Nous avons ensuite imprimé notre circuit PCB après validation de l'équipe pédagogique.  
Puis, nous avons utilisé une carte Arduino pour la lecture des mesures et la création des fonctions relatives à l'écran OLED, au module Bluetooth ainsi qu'a l'encodeur rotatoire.  
Ensuite, avec le site MIT App Inventor, nous avons développé une application Android qui a pour but de recevoir des données via Bluetooth.  
Et enfin, nous avons réalisé notre propre banc de test : nous avons effectué un test de rayon de courbure et un test de répétabilité avec deux types de crayons (B, HB).  
