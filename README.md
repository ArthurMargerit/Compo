
![1](http://gitlab.marger.it:10443/ruhtra/compo/raw/master/doc/D1.d.png)
![2](http://gitlab.marger.it:10443/ruhtra/compo/raw/master/doc/D2.d.png) 
![3](http://gitlab.marger.it:10443/ruhtra/compo/raw/master/doc/D3.d.png)

# How to install Compome?

clone the repo 
```bash
git clone https://gitlab.marger.it:10443/ruhtra/compo 
```

Define the env
```bash
export COMPOME_PATH=/where/i/clone/compo

# In a simple project just define it as
export COMPOME_MODEL_PATH=.
```

```bash
pip install -r tools/env.txt
```

## For c++ generation
You need to install clang-format and swig.

## For uml generation
You need to install plantuml.

![Structs](http://gitlab.marger.it:10443/ruhtra/compo/raw/master/doc/Structs.png)
![Interfaces](http://gitlab.marger.it:10443/ruhtra/compo/raw/master/doc/Interfaces.png)
![Components](http://gitlab.marger.it:10443/ruhtra/compo/raw/master/doc/Components.png)
![Deployment](http://gitlab.marger.it:10443/ruhtra/compo/raw/master/doc/Deployments.png)

## For graph generation
You need to install graphviz.

# Compome concept

This project is a component/interface generator.

Good for:
- Reuse Code
- Clear code organization
- Tool to code
- Code generation

Step:

- Create one or more interface.
- Create a component witch implements interfaces and other interfaces

Example : file.yaml

```bash
## Type Definition
- TYPE:
    NAME: int 
    DEFINITION: int
    NATIF: True

- TYPE:
    NAME: ui8
    DEFINITION: std::uint8_t
    INCLUDE: "<cstdint>"

- TYPE:
    NAME: void
    DEFINITION: void
    NATIF: True

- TYPE:
    NAME: string
    DEFINITION: std::string
    INCLUDE: <string>

## Interface to lock/open the door of a car
- INTERFACE:
    NAME: Car::Gate::Locker
    FUNCTION:
      - void open_window ()
      - void close_window ()
      - string state ()

## Interface to open/close the windows of a car
- INTERFACE:
    NAME: Car::Gate::Window
    DATA:
      - ui8 percent
    FUNCTION:
      - void lock ()
      - void unlock ()

## Interface to report the state of a car system
- INTERFACE:
    NAME: Car::Reporter
    FUNCTION:
      - void send_err (int err_code, string message)
      - void send_info (int info_code, string message)

## Component in place to manage a door and windows car
- COMPONENT:
    NAME: Car::Gates::controller
    PROVIDE:
    - Car::Gate::Window win
    - Car::Gate::Locker locker
    REQUIRE:
    - Car::Reporter reporting_station
```

- Generate code
```bash
$ compome generate -f file.yaml
$ # compile it // by default the code should compile
$ 
```

- Write your specific code in the implementations

# All Compome Element

## Type:
The type is a system to define Type:
- basic type of a language like int,long,char etc...
- external struct or class like std::string, std::vector etc... 
- pointer, std::shared_ptr and ref

## Enum:
As c/c++ you can define enum.

## Struct:
Help the user to define struct.
You can define:

- Attribute
- Function
- Parent

Compome is in charge of:
- Serialization
- UML generation

## Interface

You can define:
- Attribute
- Function
- Parent

Compome is in charge of:
- Call to String
- String to Call

## Component
You can define:
- Attribute
- Function
- Provide
- Require
- Sub Component
- Sub Connector
- Connection
- Parent

Compome is in charge of:
- call to String
- String to call

## CONNECTOR
## LINK
## DEPLOYMENT

#  How to run test ?

```bash
# Download the project
git clone https://www.gitlab.marger.it:10443/ruhtra/compo

# jump to test
cd compo/Test/gen

# run test for cpp
./run_test.sh cpp
./run_test.sh graph
./run_test.sh uml
./run_test.sh python
```

# Générateur
## Générateur list 
  * __C++__:  You need to support _c++11_ and the std.
  * __PYTHON__: started
  * __UML__: Generate uml dep graph 
  * __GRAPH__: generate graphic view of component and deployment

### GLOBAL
| GÉNÉRATEUR | TYPE | STRUCTURE | INTERFACE | DÉPLOIEMENT | COMPOSANT | LINK | COMPILATION | RUN |
|------------|------|-----------|-----------|-------------|-----------|------|-------------|-----|
| C++        | OK   | OK        | OK        | OK          | OK        | OK   | OK          | OK  |

### TYPE
| GÉNÉRATEUR | Function | Pointer | array | default | array TO_STR | pointer TO_STR | STR_TO_pointer | STR_TO_SP |
|------------|----------|---------|-------|---------|--------------|----------------|----------------|-----------|
| C++        | OK       | OK      | OK    | OK      | OK           | OK             | OK             | OK        |

### Enum
| GÉNÉRATEUR | DEFAULT | SERIALIZATION |
|------------|---------|---------------|
| C++        | OK      | OK            |

### STRUCTURE
| GÉNÉRATEUR | get | set | constucteur | default | PARENT | SHELL |
|------------|-----|-----|-------------|---------|--------|-------|
| C++        | OK  | OK  | OK          | OK      | OK     | OK    |


### ERROR
| GÉNÉRATEUR | get | set | constucteur | TO_STR | FROM_STR | DEFAULT | PARENT |
|------------|-----|-----|-------------|--------|----------|---------|--------|
| C++        | OK  | OK  | OK          | OK     | OK       | TODO    | OK     |


### INTERFACE
| GÉNÉRATEUR | INTERFACE | COMPOSANT ACCÈS | FUNCTION | DATA | get | set | default | DISTRIBUTE | PARENT |
|------------|-----------|-----------------|----------|------|-----|-----|---------|------------|--------|
| C++        | OK        | OK              | OK       | OK   | OK  | OK  | OK      | -          | OK     |


### SERIALIZATION
| SERIALIZATION | TYPE | STRUCT | ERROR | CALLER | FAKE | POINTER | CONTEXT |
|---------------|------|--------|-------|--------|------|---------|---------|
| C++/STREAM    | OK   | OK     | OK    | OK     | OK   | OK      | PARTIAL |
| C++/DBUS      | OK   | OK     | -     | OK     | OK   | -       | -       |
| C++/JSON      | -    | -      | -     | -      | -    | -       | -       |


### COMPONENT
| GÉNÉRATEUR | INTERFACE | ACCES INTERFACE | FUNCTION | DATA | INIT | COPY | DESTRUCTION | get | set | default | PARENT | SAVE | RESTORE |
|------------|-----------|-----------------|----------|------|------|------|-------------|-----|-----|---------|--------|------|---------|
| C++        | OK        | OK              | OK       | OK   | OK   | OK   | OK          | OK  | OK  | OK      | OK     | -    | -       |

### SUBCOMPONENT
| GÉNÉRATEUR | SUBCOMPONENT | CONNECTION C2SC | CONNECTION SC2C | CONNECTION SC2SC | STEP |
|------------|--------------|-----------------|-----------------|------------------|------|
| C++        | OK           | OK              | OK              | OK               | OK   |


### DEPLOIMENT
| GÉNÉRATEUR | DEPLOIMENT | Instance | INSTALLATION LINK | default | CONNECTION |
|------------|------------|----------|-------------------|---------|------------|
| C++        | OK         | OK       | OK                | OK      | OK         |


### LINK
| GÉNÉRATEUR | LINK |
|------------|------|
| C++        | OK   |


### COMPILATION
| GÉNÉRATEUR        | COMPILATION | CMAKE FULL | CMAKE COMPOSANT | CMAKE RUN |
|-------------------|-------------|------------|-----------------|-----------|
| C++ CMAKE MAKE    | OK          | OK         | OK              | OK        |
| C++ CMAKE NINJA   | -           | -          | -               | -         |
| C++ CMAKE WINDOWS | -           | -          | -               | -         |
| ...               |             |            |                 |           |


### RUN
| GÉNÉRATEUR | RUN | MEMORY | DEBUG | UNIT TEST | SHELL |
|------------|-----|--------|-------|-----------|-------|
| C++        | OK  | OK     | OK    | -         | -     |
| ...        |     |        |       |           |       |

### LINK
| GÉNÉRATEUR | IN | OUT | MULTI_IN |
|------------|----|-----|----------|
| C++ FIFO   | OK | OK  | NO       |
| C++ UDP    | -  | -   | YES      |
| C++ TCP    | -  | -   | YES      |
| C++ SHMEM  | -  | -   | NO       |
| C++ DIRECT | OK | OK  | NO       |


