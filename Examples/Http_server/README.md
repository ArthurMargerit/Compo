# http Server

This code is a example of http/server

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
$ ./Http_server_bin
# ... open the webpage ../../tool/test.html
# ... write the addr eg. http://127.0.0.1:8081
# ... write the interface_map_name eg. /info or /cap
# ... write a function call or scan to know the function provided
# ... Press call to do a call
#
# ... eg.
# http://127.0.0.1:8081/info get_name() -> ""
# http://127.0.0.1:8081/info get_type() -> ""
# http://127.0.0.1:8081/info get_location() -> ""
# http://127.0.0.1:8081/cat get_temperature() -> 0
#
# write exit in the terminal to close the server.
>>> exit
```

## ERROR
* (0) error | undefined :  => wrong address or server is not running
* (400) Bad Request | ... Wrong form ...  => function call not well write

## Read the code

Start by reading: 
 - file.yaml
 - src/main.cpp

## Edit the code

To customise the answer provide by the server edit the:
 * src/Components/Sensor_Information_I_information.cpp
 * src/Components/Sensor_Thermal_Sensor_I_capteur1.cpp
