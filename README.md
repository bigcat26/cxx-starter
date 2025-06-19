# CXX Quick Start Project

A skeleton project aim to start my C++ project ASAP

## Requirements

- CMake
- Conan
- Ninja
- VSCode

## Usage

```shell
git clone https://github.com/bigcat26/cxx-starter.git
code -a cxx-starter
```

run following commands inside vscode terminal

```
mkdir .build && cd .build && conan install .. -of . --build missing
```

- `cmd + shift + p:  CMake Configure`
- `cmd + shift + p:  CMake Build`
- `F5`: start debug run
