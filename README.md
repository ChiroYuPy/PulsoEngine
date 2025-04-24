<p align="center">
  <img width="500px" src="assets/pulsoengine-logo.svg">
</p>

# PulsoEngine

[![Build Status](https://img.shields.io/github/actions/workflow/status/ton-user/pulsoengine/ci.yml?branch=main)](https://github.com/ton-user/pulsoengine/actions/workflows/ci.yml)  
Un moteur de jeu de rythme modulaire écrit en **C++**, conçu pour créer des jeux synchronisés avec la musique.

## Créer un jeu avec PulsoEngine

PulsoEngine est pensé pour faciliter le développement de jeux de rythme tout en restant suffisamment générique pour d'autres types de jeux. Il propose une architecture modulaire, un système de gestion graphique par groupes d'objets, et un moteur d'animations synchronisées avec le temps ou l’audio.

### Fonctionnalités principales

- Gestion des **éléments graphiques hiérarchiques** (conteneurs, groupes d’objets).
- **Animations synchronisées** avec le temps ou la musique.
- **Modularité** pour un découplage facile des composants (rendu, logique, entrée…).
- **Gestion de ressources** (textures, sons, etc.).
- **Système de rendu** personnalisable (OpenGL/SFML selon implémentation).
- Conception orientée objet, pensée pour l’**extensibilité**.

## Objectifs

PulsoEngine vise à fournir un socle pour les jeux où la synchronisation audio-visuelle est essentielle. Il met l’accent sur la simplicité d’extension, la performance, et une architecture claire.

- Fournir une base solide pour la création de jeux de rythme en C++.
- Permettre une séparation propre entre les composants (rendu, logique, ressources).
- Proposer un moteur d’animation léger mais précis.
- Offrir une expérience de développement fluide et testable.

## Prérequis

- **C++23**
- Système avec support de **SFML** ou **OpenGL**
- CMake (ou autre système de build compatible)
- Un IDE recommandé : **Visual Studio**, **CLion**, ou **VS Code**

## Construire le projet

Le projet utilise CMake pour la configuration. Lancez :

```bash
cmake -B build
cmake --build build
