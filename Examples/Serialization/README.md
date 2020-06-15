# Serialization

This code is a example of Struct use and the basic Serialization System.

# How to use it ?

## Code Generation
```bash
$ ../../compome generate -f file.yaml
# ... generate code
```

## Compilation of code
```bash
$ cmake .
# ... post compil
$ make
# ... compilation
```

## Use it
```bash
$ ./Serialization_bin add
Id:5
Fist Name:Jean
Last Name:Dupond
Score:18.6
Path to img profile:/img/jd.png

$ ./Serialization_bin add
Id:6
Fist Name:Marc 
Last Name:Moulin
Score:85.2
Path to img profile:/img/mm.png

$ ./Serialization_bin add
Id:7
Fist Name:Paul
Last Name:Verand
Score:87.01     
Path to img profile:/tmp/pv.png

$ ./Serialization_bin list
5:Jean Dupond with a score of 18.6 | "/img/jd.png"
6:Marc Moulin with a score of 85.2 | "/img/mm.png"
7:Paul Verand with a score of 87.01 | "/tmp/pv.png"
```

## Read the code
 Start by reading:
 
 - file.yaml
 - src/main.cpp 
 - bdd.txt
