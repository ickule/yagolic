# YAGOLIC

Yet Another Game Of Life In C

This repository is dedicated to a C command line game of life following the rules from J. H. Conway.

## Table of Content

- [YAGOLIC](#yagolic)
  - [Table of Content](#table-of-content)
  - [Dependencies](#dependencies)
  - [Compiling the program](#compiling-the-program)
    - [Configuring](#configuring)
      - [For a Unix target](#for-a-unix-target)
      - [For Windows](#for-windows)
    - [Building](#building)
  - [Running the program](#running-the-program)
  - [Contributing](#contributing)
    - [Formatting](#formatting)
    - [Linting](#linting)

## Dependencies

This program uses C17 code, targets GNU/Linux computers and is meant to be compatible with the LLVM toolchain.

You need the following tools:

- cmake
- ninja
- clang
- clang-tidy
- clang-format
- mingw-w64

As an example, if you are using a Debian based distribution, you can use the following:

- On Debian:

    ```sh
    sudo apt update
    sudo apt install cmake ninja-build clang clang-tidy clang-format mingw-w64
    ```

- On Arch Linux:

    ```sh
    pacman -S cmake ninja clang mingw-w64-gcc
    ```

## Compiling the program

### Configuring

#### For a Unix target

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

#### For Windows

Run `cmake` to configure the build environment with your preferred build system and windows toolchain.
It is recommended to store your build configuration in a dedicated folder to avoid conflicts with native Linux builds:

- With the default build system:

    ```sh
    cmake -DCMAKE_TOOLCHAIN_FILE=cmake/Toolchain-gcc-windows.cmake -Bbuild-windows .
    ```

- With Ninja build system:

    ```sh
    cmake -DCMAKE_TOOLCHAIN_FILE=cmake/Toolchain-gcc-windows.cmake -Bbuild-windows -GNinja .
    ```

> [!NOTE]
> This project also provides a `clang` based windows toolchain:
>
> - With the default build system:
>
>     ```sh
>    cmake -DCMAKE_TOOLCHAIN_FILE=cmake/Toolchain-clang-windows.cmake -Bbuild-windows .
>    ```
>
>
>
> - With Ninja build system:
>
>    ```sh
>    cmake -DCMAKE_TOOLCHAIN_FILE=cmake/Toolchain-clang-windows.cmake -DCMAKE_EXE_LINKER_FLAGS="${CMAKE_EXE_LINKER_FLAGS} -L/usr/lib/gcc/x86_64-w64-mingw32/12-win32/" -Bbuild-windows -GNinja .
>    ```

> [!WARNING]
> If you are cross-compiling with Debian, you may need to specify which libgcc version clang should use.
> You can add the following `-DCMAKE_EXE_LINKER_FLAGS="${CMAKE_EXE_LINKER_FLAGS} -L/usr/lib/gcc/x86_64-w64-mingw32/12-win32/"` to the previous commands, making sure you adapt the path to the necessary folder.

### Building

Run `cmake --build .` to build the program.

In case you are cross compiling, you should specify the build folder: `cmake --build build-windows`.

> [!NOTE]
> The program is located in the `bin` folder after compilation, including cross compilations builds.

## Running the program

Run `bin/yagolic` to execute the program.

You will also find `bin/yagolic.exe` if you cross compiled.

## Contributing

### Formatting

Run `clang-format -i src/*.c include/*.h -Werror --dry-run` to check the format of your code.

Please correct any errors before pushing to the repository.

### Linting

Run `clang-tidy src/*.c  include/*.h -- -Iinclude` to lint your code.

Please correct any errors before pushing to the repository.
