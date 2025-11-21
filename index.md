
# SMART HOUSE – Projet Arduino

Bienvenue sur la page officielle du projet Smart House, un système domotique conçu pour améliorer le confort, la sécurité et l’automatisation d’une habitation grâce à des capteurs et actionneurs intelligents.

---

## Présentation générale

Le projet est composé de deux modules principaux :

1. **Circuit intérieur** : surveillance des conditions environnementales et gestion des alertes.
2. **Circuit extérieur** : détection de présence, contrôle de l’éclairage, gestion du garage et orientation d’un panneau solaire.

L’objectif est d’intégrer plusieurs fonctionnalités de domotique tout en restant modulable et facile à maintenir.

---

## Système intérieur

Le module intérieur surveille la météo, détecte les risques d’incendie et contrôle des éléments comme le linge à l’extérieur.

### Capteurs

| Capteur           | Fonction                | Pin |
| ----------------- | ----------------------- | --- |
| Capteur de pluie  | Détection pluie         | A0  |
| Capteur de flamme | Détection feu           | A1  |
| Capteur MQ2       | Détection fumée et gaz  | A2  |
| Capteur sonore    | Détection de sons       | D2  |
| DHT11             | Température et humidité | D4  |

### Actionneurs et affichage

| Actionneur    | Fonction                                 | Pin  |
| ------------- | ---------------------------------------- | ---- |
| Servomoteur   | Rentrer le linge                         | D10  |
| Buzzer        | Alarme incendie                          | D5   |
| LED rouge     | Indication fumée                         | D6   |
| LED blanche   | Indication sonore                        | D7   |
| Écran LCD I2C | Affichage température, humidité, alertes | 0x27 |

### Schéma de fonctionnement

1. Détection de pluie (< 500) → servomoteur 180° pour rentrer le linge.
2. Détection de flamme (< 500) → buzzer 1000 Hz.
3. Détection de fumée (> 300) → LED rouge allumée.
4. Détection sonore → LED blanche clignote.
5. Affichage LCD : priorise alertes, sinon température et humidité.

### Visualisation

![Vue intérieure](interior.jpg){ width=600 }

Code du module intérieur : [`Interior_SMART_HOUSE.ino`](Interior_SMART_HOUSE.ino)

---

## Système extérieur

Le module extérieur contrôle la sécurité, l’éclairage et l’orientation solaire.

### Capteurs

| Capteur         | Fonction                          | Pin       |
| --------------- | --------------------------------- | --------- |
| Ultrason route  | Détection véhicules/personnes     | TRIG/ECHO |
| Ultrason garage | Détection objets proches (<10 cm) | TRIG/ECHO |
| LDR A0          | Détection obscurité               | A0        |
| LDR A1          | Tracking solaire gauche           | A1        |
| LDR A2          | Tracking solaire droite           | A2        |

### Actionneurs

| Actionneur          | Fonction                    | Pin    |
| ------------------- | --------------------------- | ------ |
| LED                 | Éclairage automatique       | D6, D7 |
| Servomoteur porte   | Ouverture/fermeture garage  | D9     |
| Servomoteur solaire | Orientation panneau solaire | D10    |

### Schéma de fonctionnement

1. Obscurité + présence route (> 800) → LEDs allumées 6 secondes.
2. Distance garage < 10 cm → porte ouverte 90°, refermée après 3 secondes.
3. Tracking solaire → orientation du panneau selon différence de luminosité LDR gauche/droite.

### Visualisation

![Vue extérieure](house.jpg){ width=600 }

Code du module extérieur : [`Exterieur_SMART_HOUSE.ino`](Exterieur_SMART_HOUSE.ino)

---

## Fonctionnalités principales

* Protection automatique du linge en cas de pluie.
* Détection et alerte incendie (feu/fumée).
* Détection sonore et signalisation.
* Affichage en temps réel sur écran LCD.
* Détection de véhicules et présence extérieure.
* Éclairage automatique selon luminosité.
* Ouverture intelligente de la porte du garage.
* Orientation automatique d’un panneau solaire.
