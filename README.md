# 2022-2023-4GP-virgile-julie
Projet 4GP du capteur au banc de test en open source hardware
---
## Sommaire
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

Dans ce projet, nous allons concevoir un capteur résistif fonctionnant sur la base d'un phénomène physique observé qui est l'effet tunnel. En faisant varier la distance séparant les particules du réseau( par des déformations en compression et en tension), la conductivité du graphite varie ainsi que sa résistivité.

Pour appliquer ce phènomène, la jauge de contrainte sera peu couteuse. Elle se présente sous la forme d’un U en papier, sur lequel on vient déposer du graphite à l’aide d’un crayon à papier ceci est très simple à réaliser et sa fabrication ne génère pas d’impact négatif sur l’environnement. A noter aussi que la réponse du capteur va dépendre du type de mine utilisée. 


Nous avons débuté notre projet par la fabrication de notre shield pour notre chaine de mesures. Ce dernier a été conçu a l'aide du logiciel KICAD  sur la base du amplificateur transimpédance simulation électrique du circuit associé au shield sur le logiciel LTSpice.

![ ](Images_kicad/Schématique_Shield.png)
    
Par la suite, nous avons ensuite imprimé notre circuit PCB après validation de celle-ci, qui aura demande de multiples essais. 
Puis, nous avons réalisé le montage des composants sur la carte vierge avec le matériel ci-dessous.

## Matériel nécessaire
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
