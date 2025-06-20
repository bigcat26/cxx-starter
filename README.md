# C++ Quick Start Project

A skeleton project aimed at starting C++ projects as quickly as possible.

## Requirements

- CMake
- Conan
- Ninja

## Usage

1. **Clone the repository:**

    ```shell
    git clone https://github.com/bigcat26/cxx-starter.git
    cd cxx-starter
    ```

3. **Open in VSCode:**

    ```shell
    # If the editor's command-line tool (e.g., 'code', 'cursor') is in your PATH
    code .
    ```

4. **Set up the project:**

    Run the following commands in the VSCode integrated terminal:

    ```shell
    # Create a build directory and navigate into it
    mkdir build && cd build

    # Install dependencies using Conan
    conan install .. --output-folder=. --build=missing
    ```

5. **Configure and Build:**

    Use the VSCode Command Palette (`Cmd + Shift + P` on macOS, `Ctrl + Shift + P` on Windows/Linux):

    - Run `CMake: Configure`
    - Run `CMake: Build`

6. **Debug:**

    - Press `F5` to start a debugging session.
