# MySokoban

![Language](https://img.shields.io/badge/Language-C-blue)
![Ncurses](https://img.shields.io/badge/Library-Ncurses-yellow)
![POSIX](https://img.shields.io/badge/POSIX-Compliant-gold)
![Build](https://img.shields.io/badge/Build-Makefile-orange)
![Last Commit](https://img.shields.io/github/last-commit/Enoal-Fauchille-Bolle/MySokoban)
![Repo Size](https://img.shields.io/github/repo-size/Enoal-Fauchille-Bolle/MySokoban)
![License](https://img.shields.io/github/license/Enoal-Fauchille-Bolle/MySokoban)
[![wakatime](https://wakatime.com/badge/user/018bbded-63e4-4a01-bd5e-21d050739656/project/018bf83b-75df-4a8d-9e59-9b6359ba2488.svg)](https://wakatime.com/badge/user/018bbded-63e4-4a01-bd5e-21d050739656/project/018bf83b-75df-4a8d-9e59-9b6359ba2488)
![Lines of Code](https://tokei.rs/b1/github/Enoal-Fauchille-Bolle/MySokoban)

This project is a terminal-based Sokoban game written in C using the ncurses library. Developed as part of the Epitech curriculum, it challenges players to push boxes to designated storage locations within a warehouse.

## Repository Short Description

Terminal-based Sokoban game in C using ncurses, developed for the Epitech project.

## Features

- Terminal-based Sokoban gameplay.
- Player movement using arrow keys.
- Game reset using the spacebar.
- Terminal resizing handling (displays a message if the terminal is too small).
- Exit codes: 0 for victory, 1 for defeat, and 84 for errors.

## Prerequisites

- C compiler (gcc, clang, etc.)
- ncurses library

## Compilation

To compile the project, simply run:

```bash
make
```

This will generate the executable `my_sokoban`.

## Usage

Launch the game by providing a map file as an argument:

```bash
./my_sokoban map
```

### Map Format

- **Wall**: `#`
- **Player**: `P`
- **Box**: `X`
- **Storage Location**: `O`
- **Empty Spaces**: space and newline

Example map file:

```text
############
#        O #
#  P    ####
#          #
#######    #
#  O ##    #
#    ##    #
#          #
#       XX #
#       #  #
############
```

If the map contains unauthorized characters, the program will exit with an error and return code 84.

## Unit Tests

Unit tests are implemented using the Criterion framework to verify the core functionalities of the game.

To run the tests, simply run:

```bash
make tests_run
```

## License

[Include the project license here if applicable]
```