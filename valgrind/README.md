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
  valgrind --leak-check=full --show-leak-kinds=all  ${prog_name}
  ```

## Reference

- [檢查程式記憶體的小工具-valgrind](http://daydreamer.idv.tw/rewrite.php/read-18.html)
