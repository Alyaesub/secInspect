# SecInspect

![Version](https://img.shields.io/badge/version-0.1-success)
![License](https://img.shields.io/badge/license-MIT-green)
![C](https://img.shields.io/badge/Langage-C-A8B9CC?logo=c&logoColor=white)
![Linux](https://img.shields.io/badge/Linux-FCC624?logo=linux&logoColor=black)
![macOS](https://img.shields.io/badge/macOS-000000?logo=apple&logoColor=white)
![Status](https://img.shields.io/badge/statut-en%20développement-orange)

**SecInspect** est un outil en ligne de commande (CLI) développé en **langage C**, destiné à l'inspection et à l'audit de sécurité des systèmes Linux et macOS.

Il vise à fournir une solution légère, modulaire et extensible permettant d'analyser des informations système, d'identifier des configurations potentiellement dangereuses et de produire des diagnostics de sécurité.

Le projet repose sur les interfaces **POSIX**, une architecture modulaire et des pratiques de développement sécurisé.

> **État du projet :** SecInspect est actuellement en développement. La version 0.1 permet l'inspection des informations système. Les fonctionnalités avancées d'audit de fichiers et de sécurité ne sont pas encore disponibles.

---

## Fonctionnalités

### Disponibles

- Interface en ligne de commande avec validation des arguments.
- Affichage de l'aide et de la version.
- Récupération du nom de la machine (`gethostname`).
- Identification du système d'exploitation et de son noyau (`uname`).
- Affichage de l'architecture matérielle.
- Gestion des erreurs des appels système sans interrompre les vérifications indépendantes.
- Propagation des codes de sortie vers le système d'exploitation.

### En développement

- Informations utilisateur et groupes (UID, GID).
- Analyse de fichiers et de répertoires.
- Parcours récursif.
- Vérification des permissions Unix.
- Détection de fichiers sensibles.
- Recherche de secrets potentiellement exposés.
- Analyse des processus et informations réseau.
- Journalisation structurée.
- Génération de rapports texte et JSON.

---

## Prérequis

SecInspect nécessite :

- Un environnement Linux ou macOS.
- Un compilateur C compatible (`gcc` ou `clang`).
- L'utilitaire `make`.

Le projet utilise les interfaces système POSIX et ne nécessite actuellement aucune bibliothèque externe.

## Installation

Cloner le dépôt :

```bash
git clone https://github.com/Alyaesub/secInspect
cd secinspect
```

Compiler le programme :

```bash
make
```

Le binaire `secinspect` est généré à la racine du projet.

Pour supprimer les fichiers générés :

```bash
make clean
```

La compilation utilise les options suivantes :

```text
-Wall -Wextra -Werror -Iinclude
```

Ces options activent des avertissements stricts et empêchent la compilation lorsqu'un avertissement est détecté.

---

## Utilisation

Syntaxe générale :

```bash
./secinspect [OPTION]
```

| Option      | Description                                       |
| ----------- | ------------------------------------------------- |
| `--help`    | Afficher l'aide et les commandes disponibles      |
| `--version` | Afficher la version du programme                  |
| `--scan`    | Effectuer une inspection des informations système |

### Afficher l'aide

```bash
./secinspect --help
```

### Afficher la version

```bash
./secinspect --version
```

### Exécuter une inspection système

```bash
./secinspect --scan
```

---

## Architecture

SecInspect est organisé en modules indépendants afin de faciliter la maintenance, les tests et l'évolution du projet.

```text
secinspect/
├── Makefile
├── README.md
├── LICENSE
├── .gitignore
├── include/
│   ├── banner.h
│   ├── cli.h
│   └── system_info.h
├── src/
│   ├── main.c
│   ├── banner.c
│   ├── cli.c
│   └── system_info.c
└── tests/
```

### Organisation des modules

| Module          | Responsabilité                                          |
| --------------- | ------------------------------------------------------- |
| `main.c`        | Point d'entrée du programme                             |
| `cli.c`         | Interprétation des arguments et exécution des commandes |
| `banner.c`      | Affichage de la bannière                                |
| `system_info.c` | Collecte des informations système                       |
| `include/`      | Déclarations publiques des modules                      |
| `tests/`        | Emplacement réservé aux futurs tests                    |

Chaque module expose ses fonctions publiques au moyen de fichiers d'en-tête `.h`.

Cette organisation permet de limiter les dépendances et de maintenir une séparation claire des responsabilités.

---

## Gestion des erreurs

SecInspect distingue les erreurs d'exécution des informations collectées durant l'inspection.

Lorsqu'une vérification système échoue :

- L'erreur est signalée.
- Les vérifications indépendantes continuent.
- Un statut d'échec est conservé.
- Le programme transmet son code de sortie au système d'exploitation.

### Codes de sortie

| Code | Signification                             |
| ---- | ----------------------------------------- |
| `0`  | Exécution réussie                         |
| `1`  | Erreur d'exécution ou arguments invalides |

Le code de sortie peut être consulté après l'exécution :

```bash
./secinspect --scan
echo $?
```

Cette approche permet l'intégration future de SecInspect dans des scripts d'automatisation et des pipelines CI/CD.

---

## Sécurité et limites

SecInspect est développé avec une attention particulière portée à la sécurité mémoire et à la robustesse des interactions avec le système.

Les principes appliqués comprennent notamment :

- La vérification des valeurs de retour des appels système.
- La gestion explicite des erreurs.
- Le contrôle de la taille des buffers.
- L'utilisation de formats explicites pour l'affichage des chaînes.
- Une compilation avec avertissements stricts.
- La séparation du traitement des commandes et des opérations système.

**SecInspect ne constitue pas un scanner de vulnérabilités complet.** Il ne remplace pas un audit de sécurité approfondi ni les outils professionnels spécialisés.

Son utilisation doit s'effectuer uniquement sur des systèmes pour lesquels l'utilisateur dispose des autorisations nécessaires.

---

## Contribution

Les contributions, signalements de bugs et propositions d'amélioration sont les bienvenus.

Pour contribuer :

1. Ouvrir une issue afin de présenter le problème ou l'amélioration envisagée.
2. Créer une branche dédiée à la modification.
3. Respecter l'organisation modulaire existante.
4. Vérifier la compilation avec `make`.
5. Proposer une pull request décrivant les changements apportés.

Les contributions doivent privilégier la lisibilité, la portabilité et la sécurité du code.

---

## Licence

Ce projet est distribué sous licence **MIT**.

Consultez le fichier [LICENSE](LICENSE) pour connaître les conditions d'utilisation, de modification et de redistribution.
