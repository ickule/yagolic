# YAGOLIC

Yet Another Game Of Life In C

This repository is dedicated to a C command line game of life following the rules from J. H. Conway.

## Dependencies

This program uses C17 code, targets GNU/Linux computers and is meant to be compatible with the LLVM toolchain.

You need the following tools:

- cmake
- ninja
- clang
- clang-tidy
- clang-format

As an example, if you are using a Debian based distribution, you can use the following:

- On Debian:

    ```sh
    sudo apt update
    sudo apt install cmake ninja-build clang clang-tidy clang-format
    ```

- On Arch Linux:

    ```sh
    pacman -S cmake ninja clang
    ```

## Compiling the program

### Configuring

Run `cmake` to configure the build environment with your preferred build system:

- With the default build system (usually Unix Makefiles):

    ```sh
    cmake .
    ```

- With Ninja build system:

    ```sh
    cmake -GNinja .
    ```

> [!NOTE]
> You can select your preferred compiler by prepending your command with the `CC` variable definition.
>
> For example, to use `clang`, you can run the following:
>
> - With the default build system:
>
>     ```sh
>    CC=/usr/bin/clang cmake .
>    ```
>
> - With Ninja build system:
>
>    ```sh
>    CC=/usr/bin/clang cmake -GNinja .
>    ```
>
### Building

Run `cmake --build .` to build the program.

> [!NOTE]
> The program is located in the `bin` folder after compilation.

## Running the program

Run `bin/yagolic` to execute the program.

## Contributing

### Formatting

Run `clang-format -i src/*.c include/*.h -Werror --dry-run` to check the format of your code.

Please correct any errors before pushing to the repository.

### Linting

Run `clang-tidy src/*.c  include/*.h -- -Iinclude` to lint your code.

Please correct any errors before pushing to the repository.
