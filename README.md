# SecInspect

SecInspect est un outil CLI écrit en C pour réaliser un audit simple d’un système Linux/macOS.

Le projet est pédagogique, mais l’objectif est de construire un outil réellement utilisable, modulaire et maintenable.

## Objectifs

- progresser en langage C
- utiliser les appels système POSIX
- analyser les permissions
- détecter des configurations ou fichiers sensibles
- produire des rapports simples

## Structure du projet

```text
secinspect/
├── Makefile
├── README.md
├── include/
├── src/
└── tests/
```

## Compilation

```bash
make
```

## Exécution

```bash
./secinspect
```

## Roadmap

### Semaine 1 — Fondations

- créer l’arborescence du projet
- créer un Makefile
- organiser `src/` et `include/`
- compiler plusieurs fichiers `.c`
- créer une première CLI simple
- ajouter un logger
- revoir les structures
- gérer les erreurs proprement
