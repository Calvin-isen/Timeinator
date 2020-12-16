# Présentation Projet Timeinator

Nous avons réalisé un réveil virtuel qui offre à un utilisateur différentes fonctionnalités qui peuvent s'avérer très utiles dans la vie de tous les jours.

Les différents modes proposés sont les suivants : 

  - Un réveil classique avec un son et une heure choisie par l'utilisateur
  - Un réveil automatisé qui sonnera tous les matin à l'heure indiquée par l'utilisateur
  - Un chronomètre classique qui pourra également stocker 3 temps intermédiaires 
  - Un compte à rebours avec 2 temps de sonnerie intermédiaire
  - Une fonctionnalité statistique pour connaître le nombre d'utilisations des différents modes
  - Une visualisation monitoring des processus du logiciel 

# Documentation 

## Les Prérequis logiciels
Afin de pouvoir lire les musiques, vous devez installer VLC.
Pour cela vous devez taper la commande suivante:
```markdown
sudo apt install vlc
```
Pour utiliser le mode monitoring, il est nécessaire d'installer htop sur sa machine.
Pour cela vous devez taper la commande suivante:
```markdown
sudo apt install htop
```

## Le Menu
Lors du lancement du programme, le menu s'affichera et vous permettra d'utiliser les différents modes proposés ci-dessus qui se lanceront sur des terminaux distincts.

```markdown
1) Reveil
2) Reveil automatisé
3) Chrono
4) Statistique
5) Monitoring
6) Compte à rebours
7) Eteindre Timeinator
```

## Le Réveil

### - Classique


```markdown

```

### - Automatisé

```markdown

```

## Le Chronomètre

Le mode chronomètre permet de lancer un chronomètre par action clavier de l'utilisateur. 
Il est également possible d'enregistrer au maximim 3 temps intermédiaires sur action clavier de l'utilisateur. 

Commande à utiliser :

- Démarrer le chronomètre : Appuyer sur la touche "Enter" de votre clavier 

- Enregistrer un tour : Appuyer sur la touche 'a' de votre clavier puis appuyer sur "Enter"

- Arrêter le chronomètre : Appuyer sur la touche 'z' de votre clavier puis appuyer sur "Enter"



## Le Compte à Rebours

Le mode compte à rebours permet de programmer un décompteur via une interface (Terminal) pour l'utilisateur.
L'utilisateur peut ainsi programmé le temps qui souhaite instancier et peut ainsi programmé 0, 1 ou 2 temps de sonneries intermédiaires.

Une fois que vous avez configuré vos temps de sonneries, vous pouvez choisir les types de sonneries (chansons) à mettre pour une sonnerie intermédiaire.



## Les Statistiques

Le mode statistique permet de voir les différentes application lancé depuis le début du programme et leurs temps d'exécution.



## Monitoring

Le mode monitoring permet à l'utilisateur de visualiser tous les processus en cours sur la machine et en temps réel.
Il peut également filtrer les éléments à afficher à travers le terminal htop suivant ses désirs.



