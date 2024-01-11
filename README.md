# YAGOLIC

Yet Another Game Of Life In C

This repository is dedicated to a C command line game of life following the rules from J. H. Conway.

## Dependencies

This repo uses C17 code, targets GNU/Linux computers and is meant to be compatible with the clang tools.

You need the following packages:

- cmake
- clang
- clang-tidy
- clang-format

As an example, if you are using a Debian based distribution, you can use the following:

```sh
sudo apt update
sudo apt install cmake clang clang-tidy clang-format
```

## Compiling

First, set up cmake then run the build:

```sh
cmake .
cmake --build .
```

## Running the program

The program is located in the `bin` folder after compilation.
You can run it with:

```sh
bin/gameOfLife.elf
```

## Contributing

### Formatting

### Linting

## Contacts
