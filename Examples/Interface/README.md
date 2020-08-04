# Interface

This code is a example of Interface use and the basic connection with a Terminal Command.

In this example we implement Two Interfaces (Information and Sensor) and we call when in the terminal interface.

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
$ ./Interface_bin
================ Term on Information Interface ================

>>>?
- Information
	 string get_name()
	 string get_type()
	 string get_location()

>>>get_name()
get_name()->MyComputer

>>>get_type()
get_type()->[TEMP]

>>>get_location()
get_location()->Desk5

>>>exit
================    Term on Sensor Interface   ================

>>>?
- Sensor
	 double get_value()
	 Range get_range()

>>>get_range()
get_range()->{addr:0x7ffd39c01fd0,type:Range,min:0,max:100}

>>>get_value()
get_value()->35

>>>exit
================    Term on Sensor v2 Interface   ================

>>>?
- Sensor
	 double get_value()
	 Range get_range()
- Sensor_v2
	 void add_offset(double offset)
     
>>>add_offset(1.66)
add_offset(1.66)
```

## Read the code
 Start by reading:
 
 - file.yaml
 - src/main.cpp 
 
 
