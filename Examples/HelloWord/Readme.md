# HelloWord

This code is a example of HelloWord programs.
You will find 3 Concepts,
The Interface witch define the function.
The Component witch define witch interface is provided and required.
The Deployment witch connect the interface of component to external link.

## Code Generation
```bash
$ ../../compome generate -f file.yaml
# ... generate code
```

## Compilation of code
```bash
$ cmake .
# ... precompilation

$ make
# ... compilation
```

## Use it
```bash
./helloWord_bin
#
# in a other terminal
# We open a udp Connection with netcat
$ nc -u 127.0.0.1 5555
# write the next function call
hello("word")

```
the answer should be "".
To exit the server write exit in the server terminal

# Write the right code
In this step we will implement the answer of the Helloword.

Edit the File "src/Components/HelloWord_Hello_I_inter.cpp".

## How to read the Path of the file.
src/ for sources in c/cpp projects
Components/ for the CompoMe Components

HelloWord_Hello_I_inter.cpp can be split in 3
"HelloWord" for The Component name
"Hello_I" for the Interface name
"inter" for the name of the implementation.

## Edit the Function
find the implementation of hello and rewrite it as something like.
```c++
CompoMe::String HelloWord_Hello_I_inter::hello(CompoMe::String who) {
  if (who == "Word" || who == "word") {
     return "!!! Welcome !!!";
  } else {
    return "(-: wrong :-)";
  }
 }
```

## recompile and run the code
``` bash
make
./helloWord_bin
# In an other terminal
$ nc -u 127.0.0.1 5555
hello("word")
hello("")
```

The first answer should be "!!! Welcome !!!" and the second "(-: wrong :-)".
