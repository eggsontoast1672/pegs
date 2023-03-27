# Pegs - A Game of Object Elimination

## Overview

This is a PC port of a game I found on my TI-84 Plus Silver Edition.
The game is by Fred Coughlin and it's actually pretty fun, especially
for a game on a calculator.

## Help

Here are the instructions copied verbatim from the game:

> To beat each level you must destroy all of the pegs. If two like pegs are
> pushed into each other they disappear, except for triangles which form a solid
> block and plusses which allow you to choose a replacement block.

Basically, in each level, there are a certain amount of pegs. These pegs can
take the form of either a square, circle, triangle, or plus. In order to beat
the level, you have to destroy all of the pegs.

This can be done in one of two ways. For circles and blocks, you can just push
them into another circle or block respectively, and both will disappear. For
triangles, pushing one into another will create an immovable block, which is
then not required to be destroyed to win the level. For plusses, pushing one
into another will allow you to choose one of all the available peg types.

Another way to get rid of the block pegs is to push them into a black square,
which is like a pit. If you fall down a pit (e.g. move your character on top of
one), you have to restart the level. If you push a block on top of a pit, both
the block and the pit disappear.

## Compiling and Playing

First off, I haven't tested this game on Windows, MacOS, or any \*NIX operating
system other than GNU/Linux. Maybe I'll add support for other OS's in the
future, who knows. Probably not. But maybe!

Compiling on linux is easy. Just make sure you have the following packages
installed:

- make
- cmake
- sfml

### Ubuntu

```bash
apt install make cmake libsfml-dev
```

### Arch

```bash
pacman -S make cmake sfml
```

### Fedora

```bash
dnf install make cmake SFML-devel
```

Once you have those installed, create a build directory and install the cmake
files into it.

```bash
mkdir build && cd build && cmake ..
```

Finally, run `make` to compile it. The binary will be located within the `pegs`
directory, by the same name.
