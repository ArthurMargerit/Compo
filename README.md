# MYCI
_My_Composant_Implementation_

# Models

## SUPORTED
### Version 1

#### TYPES
Permet la déclaration de TYPES:
                         -----
Les types seront ensuite disponible et utilisable dans le reste du model(struct, function, interface ...).

Les types natif à un langage seront rajouté dans la version 2.

Exemples:
---------
```YAML
- TYPE: type_def type_name
- TYPE: unsigned long int uli
- TYPE: unsigned int ui
- TYPE: int* pi
- TYPE: int** ppi
- TYPE: 
   NAME:  ulli
   DEFINITION: unsigned long long int
```

Important:
-----------
  * Les déclaration de signature de function n'est pas disponible (ex: void(int,int))
  * Les _NAME_ ne peuvent pas prendre d'espace
  * Les Types std ne sont pas supporté par le générateur car il manque les includes.(ex std::pair<a,b>, std::tuple<a,b,c>).
  * Les valeur par défaut ne font pas partie du modèle mais un rajout du générateur.
  
Pour plus d'exemples voir le code dans model/version_1/types.yaml

#### STRUCT
Permet la déclaration de STRUCTS:
                         -------
Le concepts est semblable au structure en C.
Il permet d'unifier des types ensemble sous un nom commun.

Les Types sont définies au préalable avec le system de _TYPE_.
Example
-------
```YAML
- STRUCT:
   NAME: stuct_a

- STRUCT:
   NAME: stuct_b
   DATA:
   - type_a name
```

IMPORTANT:
------------
  * Les _STRUCTS_ sont dans une implémentassions C++ en non C(sizeof(stuct\_a) == 1 et != 0)
  * Les _NAME_ dans DATA ne peuvent pas être en double.
  * Les _TYPE_ dans DATA doive être définis en amont.
  * Les loop de type( a contient b qui contient a), ne sont pas interdit mais imposibles pour le compilateur C et C++ (il faut donc passer par un pointer) .
  
Les autres syntaxe possible sont dans model/version1/structs.yaml

#### INTERFACE
Permet la déclarations _INTERFACE_.

Example
-------
```YAML
- INTERFACE:
   NAME: interface_1

- INTERFACE:
   NAME: interface_2
   FUNCTION:
    - int a (int a , int b)

- INTERFACE:
   NAME: interface_2
   FUNCTION:
    - int a (int a , int b)
    - int a (int a , int b)


- INTERFACE:
   NAME: interface_2
   DATA:
    - int var1
   FUNCTION:
    - int a (int a , int b)
```
IMPORTANT:
-----------
  * Le parser de _FUNCTION_ est super strict(mal codé)
  * Les _VAR_ sont identique a _DATA_ dans struct, _TYPE_ défini en amont et _NAME_ en double interdit.

Les autres syntaxe possible sont dans model/version1/interface.yaml

#### COMPOSANT

Example
-------

```YAML

- COMPOSANT:
    NAME:Compa

- COMPOSANT:
    NAME:Compc
    DATA:
     - int vara
     - int varb
     - int varc
    FUNCTION:
     - int funca (int a, int b, int c)
     - int funcb (void)
    PROVIDE:
     - interface1 inta
    REQUIRE:
     - interface1 intb
```

Les autres syntaxe possible sont dans model/version1/composants.yaml

#### LINK

Example
-------

```YAML
- LINK:
   NAME: simple

- LINK:
    NAME: fifo_out
    DATA:
    - string fifo_in
    - string fifo_out

- LINK:
    NAME: fifo_in
    DATA:
    - string fifo_in
    - string fifo_out
    
```

Les autres syntaxe possible sont dans Test/model/links.yaml

#### DEPLOIMENT

Example
-------

```YAML
- DEPLOIMENT:
   NAME: Depa

- DEPLOIMENT:
   NAME: Depb
   INSTANCE:
    Compa insta

- DEPLOIMENT:
   NAME: depc
   INSTANCE:
    Comp1 insta
    Comp2 instb
   LINK:
    insta.req -> insta.prov
    instb.req -> instb.prov
```

Les autres syntaxe possible sont dans model/version1/deploiments.yaml

##


# Générateur

## Générateur list 
  * __C++__: Ce générateur est un générateur c++ Il est nécessaire d'avoir le support de _c++11_ et de la std.
  * __RUST__: TODO
  * __JAVA__: TODO
  * __PYTHON__: TODO

### GLOBAL
| GÉNÉRATEUR | TYPE | STRUCTURE | INTERFACE | DÉPLOIEMENT | COMPOSANT | LINK | COMPILATION | RUN |
|------------|------|-----------|-----------|-------------|-----------|------|-------------|-----|
| C++        | OK   | OK        | OK        | OK          | OK        | OK   | OK          | OK  |
| ...        |      |           |           |             |           |      |             |     |

### TYPE
| GÉNÉRATEUR | TYPE | Function | Pointer | array | default | array TO_STR | pointer TO_STR |
|------------|------|----------|---------|-------|---------|--------------|----------------|
| C++        | OK   | OK       | OK      | OK    | Ok      | TD           | OK             |
| Graphics   | -    | -        | -       | -     | -       |              |                |
| ...        | -    | -        | -       | -     | -       |              |                |

### STRUCTURE
| GÉNÉRATEUR   | STRUCT | get | set | constucteur | TO_STR | FROM_STR | default | PARENT | SHELL |
|--------------|--------|-----|-----|-------------|--------|----------|---------|--------|-------|
| C++        - | OK     | OK  | OK  | OK          | OK     | OK       | OK      | OK     | TD    |
| Graphics     | OK     | -   | -   | -           | -      | -        | OK      | OK     | -     |
| ...          | -      | -   | -   | -           | -      | -        |         |        |       |

### INTERFACE
| GÉNÉRATEUR | INTERFACE | COMPOSANT ACCÈS | FUNCTION | DATA | get | set | default | SHELL |
|------------|-----------|-----------------|----------|------|-----|-----|---------|-------|
| C++        | OK        | OK              | OK       | OK   | OK  | OK  | -       | TD    |
| ...        | -         | -               | -        | -    | -   | -   |         |       |


### COMPOSANT
| GÉNÉRATEUR | INTERFACE | ACCES INTERFACE | FUNCTION | DATA | INIT | COPY | DESTRUCTION | get | set | default | PARENT | SAVE | RESTORE |
|------------|-----------|-----------------|----------|------|------|------|-------------|-----|-----|---------|--------|------|---------|
| C++        | OK        | OK              | OK       | OK   | OK   | OK   | OK          | OK  | OK  | OK      | OK     | -    | -       |
| ...        | -         | -               | -        | -    | -    | -    | -           | -   | -   | -       | -      | -    | -       |

### DEPLOIMENT
| GÉNÉRATEUR | DEPLOIMENT | Instance | INSTALLATION LINK | default |   |
|------------|------------|----------|-------------------|---------|---|
| C++        | OK         | OK       | OK                |         |   |
| ...        | -          | -        | -                 |         |   |

### LINK
| GÉNÉRATEUR | LINK |
|------------|------|
| C++        | OK   |
| ...        | -    |



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


# Graphics
In order to help, visualisation of a deployment you can use graphical render.

## UML
You need to install PLANUML for rendering:
![Structs](http://marger.it:10080/ruhtra/compo/raw/master/doc/Structs.png)
![Interfaces](http://marger.it:10080/ruhtra/compo/raw/master/doc/Interfaces.png)
![Components](http://marger.it:10080/ruhtra/compo/raw/master/doc/Components.png)
![Deployment](http://marger.it:10080/ruhtra/compo/raw/master/doc/Deployments.png)

## GRAPH
You need to install GRAPHVIZ for rendering:
![1](http://marger.it:10080/ruhtra/compo/raw/master/doc/D1.d.png)
![2](http://marger.it:10080/ruhtra/compo/raw/master/doc/D2.d.png) 
![3](http://marger.it:10080/ruhtra/compo/raw/master/doc/D3.d.png)


# First Step

```bash
// Download the project
git clone URL

// Create a project space
mkdir project
cd project

// Set project conf
cp ../tuto/starter/compomeMe4cpp.py .compoMe.py
// read it 

// Copy helloWord code
cp ../tuto/starter/helloWord.yaml CompoMe.yaml
// read it

// Generate the project
../compome generate -f CompoMe.yaml
// look in src/ inc/ the code generated

// Compiled it
cp ../tuto/starter/CMakeLists_simple.txt CMakeLists.txt
cmake .
make

// Execute it
./project_dep1.bin

// you are now, READY TO CODE
```
