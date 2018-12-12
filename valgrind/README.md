# valgrind

a useful tool to check memory leak.

## Requirements

- valgrind

  ```sh
  wget http://www.valgrind.org/downloads/valgrind-3.14.0.tar.bz2
  tar xvf valgrind-3.14.0.tar.bz2
  cd valgrind-3.14.0
  ./configure
  make
  make install
  ldconfig
  ```

## Usage

- valgrind
  ```sh
  valgrind –leak-check=yes ${prog_name}
  ```
