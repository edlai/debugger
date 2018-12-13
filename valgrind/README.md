# valgrind

a useful tool to check memory leak.

## Requirements

- valgrind (from tar-ball)

  ```ash
  $ wget http://www.valgrind.org/downloads/valgrind-3.14.0.tar.bz2
  $ tar xvf valgrind-3.14.0.tar.bz2
  $ cd valgrind-3.14.0
  $ ./configure
  $ make
  $ sudo make install
  $ sudo ldconfig
  ```
- using apt  (Optional)  

  ```
  $ apt-get install valgrind*
  ```

## Usage

- valgrind
  ```console
  $ valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all  -v ${your_prog_name}
  ```

## Reference

- [Valgrind 的介绍](http://senlinzhan.github.io/2017/12/31/valgrind/)
- [檢查程式記憶體的小工具-valgrind](http://daydreamer.idv.tw/rewrite.php/read-18.html)
