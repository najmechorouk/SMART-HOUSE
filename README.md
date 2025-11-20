# SMARTE-HOUSE
Le circuit Smart Home est divisé en deux sections : intérieure et extérieure.
# système intérieure:
Ce module gère l’environnement intérieur (détection et réaction à la météo, feu, fumée, son, température/humidité).
Capteurs utilisés :
Capteur de pluie (A0) : détecte l’humidité (pluie).
Capteur de flamme (A1) : détecte la présence de feu.
Capteur de fumée (MQ2 – A2) : détecte des gaz ou fumée.
Capteur sonore (D2) : détecte des bruits brefs.
DHT11 (D4) : mesure la température et l’humidité ambiante.
Actionneurs / sorties :
Servomoteur (D10) : actionne un bras pour rentrer le linge si pluie.
Buzzer passif (D5) : alerte sonore en cas de feu.
LED rouge (D6) : s’allume si fumée détectée.
LED blanche (D7) : clignote à chaque bruit détecté.
Écran LCD I2C (0x27) : affiche la température, l’humidité, ou une alerte (feu ou fumée).
Fonctionnement :
1. Pluie détectée (<500) : servomoteur se positionne à 180° pour rentrer le linge, sinon revient à 0°.
2. Flamme détectée (<500) : buzzer émet un son de 1000 Hz tant que la flamme est présente.
3. Fumée (>300) : LED rouge s’allume.
4. Son détecté (digital HIGH) : la LED blanche clignote (toggle).
5. Affichage LCD :
Si feu ou fumée : affichage d’alerte.
Sinon : affiche la température (°C) et l’humidité (%)
# système extérieure
Ce module gère l’extérieur : détection de passage, éclairage automatique, ouverture de porte de garage et tracking solaire.
Capteurs utilisés :
2 Capteurs ultrasoniques (TRIG1/ECHO1, TRIG2/ECHO2) :
-Route (TRIG1/ECHO1) : détecte une voiture ou personne arrivant.
-Garage (TRIG2/ECHO2) : détecte un objet/voiture à l’entrée du garage.
3 capteurs LDR (A0, A1, A2) :
-Obscurité (A0) : détecte la lumière ambiante.
-Gauche/Droite (A1/A2) : pour l’orientation du panneau solaire.
Actionneurs :
2 LEDs (D6, D7) : s’allument si obscurité et détection sur la route.
Servomoteur porte (D9) : ouvre/ferme la porte de garage.
Servomoteur tracking (D10) : oriente un panneau solaire selon la lumière.
Fonctionnement :
Détection sur la route + obscurité (>800) :
Les 2 LEDs s’allument pendant 6 secondes (éclairage automatique).
Objet détecté devant le garage (<10 cm) :
Ouverture automatique de la porte (servo à 90°), refermée après 3 secondes.
Tracking solaire (LDR gauche/droite) :
La différence de lumière ajuste le servomoteur pour suivre la lumière du soleil.
En résumé, ce système de maison intelligente (smart home)
permet :
De protéger le linge en cas de pluie.
De détecter et alerter en cas de feu ou fumée.
De réagir au bruit ambiant.
D’afficher l’environnement sur un écran.
D’ouvrir automatiquement la porte du garage à l’arrivée d’un objet.
D’éclairer l’entrée en cas d’obscurité + présence.
D’orienter un panneau solaire selon la lumière.
