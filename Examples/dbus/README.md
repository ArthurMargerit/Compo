# Interface

This code is a example of dbus use as a server to touch component.
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
$ ./dbus_server_bin

```
Check the interface.

### with graphical Interface
Launch d-feet or equivalent.
Go to Session-DBus and search Server.app1.Calcul
And click to call function...

### ### with terminal bash command

Generic command:
```bash
$ dbus-send --session --print-reply --dest=TARGET COMPO INTERFACE.FUNCTION TYPE:VALUE ...
```

Example:
```bash
$ dbus-send --session --print-reply --dest=Server.app1.Calcul /a Cal.a.add double:5.1 double:2.5
```

```bash
$ dbus-send --session --print-reply --dest=Server.app1.Calcul /a Cal.a.sub double:3.3 double:2.1
```

```bash
$ dbus-send --session --print-reply --dest=Server.app1.Calcul /a Cal.a.time double:4.3 double:2.99
```

## Read the code
 Start by reading:
 
 - file.yaml
 - src/main.cpp 
