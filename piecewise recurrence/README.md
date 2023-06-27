# Apache AGE Internship 2023 Coding Test – Question No.2: Backend

This program implements a piecewise recurrence relation in three different ways and explains the differences between them. The code is written in C and is optimized for performance.

## Development Environment

This program was developed using Visual Studio Code with the GCC compiler installed through MSYS2 on a Windows operating system. Visual Studio Code is a popular text editor and Integrated Development Environment (IDE) that provides many features for developing and debugging code. The GCC compiler is a widely used compiler for C and C++ languages, and MSYS2 is a package manager for Windows that provides a convenient way to install and manage software.

## Setting up the Development Environment

1. Install Visual Studio Code.
2. Install the C/C++ extension for VS Code. You can install the C/C++ extension by searching for 'c++' in the Extensions view (`Ctrl+Shift+X`).
3. Get the latest version of Mingw-w64 via MSYS2, which provides up-to-date native builds of GCC, Mingw-w64, and other helpful C++ tools and libraries. You can download the latest installer from the [MSYS2 page](https://www.msys2.org/) or use [this link](http://repo.msys2.org/distrib/x86_64/msys2-x86_64-20210604.exe) to the installer.
4. Follow the Installation instructions on the MSYS2 website to install Mingw-w64. Take care to run each required Start menu and `pacman` command.
5. Install the Mingw-w64 toolchain (`pacman -S --needed base-devel mingw-w64-x86_64-toolchain`). Run the `pacman` command in a MSYS2 terminal. Accept the default to install all the members in the toolchain group.

## Compiling and Running the Code

1. Open the terminal in Visual Studio Code by going to `View` > `Terminal`.
2. Navigate to the directory where your C file is located using the `cd` command in the terminal.
3. Compile the C code by typing `gcc -o prf prf.c` in the terminal, where `prf.c` is the name of your C file and `prf` is the name of the output executable file.
4. Run the compiled code by typing `./prf` in the terminal.

## License

This program is licensed under the [MIT License](https://opensource.org/licenses/MIT). You are free to use, modify, and distribute this code under the terms of the MIT License.