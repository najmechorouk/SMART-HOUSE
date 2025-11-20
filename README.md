# SMART HOUSE – Arduino Project

Système domotique composé d’un circuit **intérieur** et d’un circuit **extérieur**, intégrant plusieurs capteurs et actionneurs pour assurer sécurité, confort et automatisation.

---

## 📸 Photos du projet

### Vue extérieure

![Exterior](house.jpg)

### Vue intérieure

![Interior](interior.jpg)

---

## 🏠 Système intérieur

Module chargé de détecter et réagir aux conditions environnementales : pluie, feu, fumée, son, température et humidité.

### Capteurs utilisés

* **Capteur de pluie (A0)** : mesure l’humidité, détecte la pluie
* **Capteur de flamme (A1)** : détecte la présence d’un feu
* **Capteur de fumée MQ2 (A2)** : détecte les gaz et fumées
* **Capteur sonore (D2)** : détecte des bruits courts
* **DHT11 (D4)** : température + humidité

### Actionneurs / Sorties

* **Servomoteur (D10)** : rentre le linge automatiquement
* **Buzzer (D5)** : alarme en cas de flamme
* **LED rouge (D6)** : fumée détectée
* **LED blanche (D7)** : clignote selon les bruits
* **Écran LCD I2C (0x27)** : affiche T°, humidité, ou alertes

### Fonctionnement

1. **Pluie < 500** → servo = **180°** (rentrer le linge)
2. **Flamme détectée (<500)** → buzzer = **1000 Hz**
3. **Fumée > 300** → LED rouge ON
4. **Son HIGH** → LED blanche toggle
5. Affichage LCD :

   * Alertes si feu/fumée
   * Sinon température (°C) + humidité (%)

🔗 Code du circuit intérieur :
[`Interior_SMART_HOUSE.ino`](Interior_SMART_HOUSE.ino)

---

## 🚗 Système extérieur

Module chargé de détecter la présence, éclairer automatiquement l’entrée, gérer la porte du garage et suivre la position du soleil.

### Capteurs utilisés

* **2 ultrasons (TRIG/ECHO)**

  * Route : détection de voiture/personne
  * Garage : détecte un objet proche (<10 cm)
* **3 capteurs LDR (A0, A1, A2)**

  * A0 : détecte l'obscurité
  * A1/A2 : tracking solaire gauche/droite

### Actionneurs

* **LEDs (D6, D7)** : éclairage automatique
* **Servomoteur porte (D9)** : ouverture/fermeture du garage
* **Servomoteur solaire (D10)** : orientation du panneau solaire

### Fonctionnement

1. **Obscurité + présence route (>800)**
   → LEDs ON **6 secondes**
2. **Distance garage < 10 cm**
   → Porte s’ouvre à **90°**, refermée après **3 s**
3. **Tracking solaire**
   → Servo s’oriente selon différence LDR gauche/droite

🔗 Code du circuit extérieur :
[`Exterieur_SMART_HOUSE.ino`](Exterieur_SMART_HOUSE.ino)

---

## 🧾 Résumé des fonctionnalités

* Détection automatique de pluie et protection du linge
* Alerte incendie (feu / fumée)
* Détection sonore et signalisation
* Affichage temps réel (LCD I2C)
* Détection de véhicule / présence en extérieur
* Éclairage automatique selon luminosité
* Ouverture intelligente du garage
* Orientation d’un panneau solaire

---


```markdown
![Arduino](https://img.shields.io/badge/Arduino-Project-blue)
![Status](https://img.shields.io/badge/Status-Completed-brightgreen)
```
