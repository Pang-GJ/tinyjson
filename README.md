# Tiny C++ Project Template
This is a tiny C++ project template using CMake.  

The requirements are:
- CMake 3.14+ highly recommended.
- A C++17 compatible compiler (doctest needed!).
- fmt (just I like it...)
- doctest (test needed)
- clang-format (optional)
- clang-tidy (optional)

## How To Use ?
To configure:
```
cmake -S . -B build
```
Add `-GNinja` if you have Ninja.

if you want to add tests, just add `-DBUILD_TESTS=on`  

To build:
```
cmake --build build
```

To test(`--target` can be written as `-t` in CMake 3.15+):
```
cmake --build build --target test
```

To clang-format:
```
cmake --build build --target clangformat
```

To clang-tidy:
```
cmake --build build --target clangtidy
```

## An awesome way to use 

Put the code in you bash or zsh (I use zsh):  
```
function taskpp() {
  case "$1" in 
    "new")
      git clone https://github.com/Pang-GJ/cpp-project-template.git
      mv cpp-project-template $2 && cd $2
      rm -rf .git
      git init .
      git add .
      git commit -m "Init C++ project"
      git branch -m main
      cd ..
      ;;
    "build")
      cmake -S . -B build
      cmake --build build
      ;;
    "test")
      cmake -S . -B build -DBUILD_TESTS=on
      cmake --build build --target $1
      ;;
    "format")
      cmake --build build --target clangformat
      ;;
    "tidy")
      cmake --build build --target clangtidy
      ;;
  esac 
}
```

As you see, it's quite a simple shell script function.  
To use it:
```
taskpp new <project-name> # create a project
taskpp build # build && make
taskpp test  # build for test
taskpp format # clang-format
taskpp tidy   # clang-tidy
```
(just a little like cargo in rust)
