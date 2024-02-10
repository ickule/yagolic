# YAGOLIC

Yet Another Game Of Life In C

This repository is dedicated to a C command line game of life following the rules from J. H. Conway.

## Dependencies

This program uses C17 code, targets GNU/Linux computers and is meant to be compatible with the clang tools.

You need the following packages:

- cmake
- ninja-build (if you want to use `ninja` instead of `make`)
- clang
- clang-tidy
- clang-format

As an example, if you are using a Debian based distribution, you can use the following:

```sh
sudo apt update
sudo apt install cmake ninja-build clang clang-tidy clang-format
```

## Compiling the program

### Configuring

Run `cmake .` to configure the build with standard UNIX makefiles.

Alternatively, run `cmake -G Ninja .` to configure the build with build.ninja files.

### Building

Run `cmake --build .` to build the program.

> [!NOTE]
> The program is located in the `bin` folder after compilation.

## Running the program

Run `bin/yagolic.elf` to execute the program.

## Contributing

### Formatting

Run `clang-format -i src/*.c include/*.h -Werror --dry-run` to check the format of your code.

Please correct any errors before pushing top the repository.

### Linting

Run `clang-tidy src/*.c  include/*.h -- -Iinclude` to lint your code.

Please correct any errors before pushing top the repository.

## Contacts
