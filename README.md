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
    NAME: fifo
    ONE2ONE: true
    ONE2MANY: false
    MANY2ONE: false
    ATOMIC: false
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
  * __C__: TODO
  * __C++__: Ce générateur est un générateur c++ il ne supporte pas actuellement toute les fonctionnalitées. Il est nécessaire d'avoir le support de _c++11_.
  * __RUST__: TODO
  * __JAVA__: TODO
  * __PYTHON__: TODO

### GLOBAL
| GÉNÉRATEUR | TYPE | STRUCTURE | INTERFACE | DÉPLOIEMENT | COMPOSANT | LINK | COMPILATION | RUN |
|------------|------|-----------|-----------|-------------|-----------|------|-------------|-----|
| C++        | OK   | OK        | OK        | OK          | OK        | OK   | OK          | OK  |
| ...        |      |           |           |             |           |      |             |     |

### TYPE
| GÉNÉRATEUR | TYPE | Function | Pointer | array |
|------------|------|----------|---------|-------|
| C++        | OK   | OK       | OK      | OK    |
| ...        | -    | -        | -       | -     |

### STRUCTURE
| GÉNÉRATEUR   | STRUCT | défaut valeur | get | set | constucteur | TO_STR | FROM_STR |
|--------------|--------|---------------|-----|-----|-------------|--------|----------|
| C++        - | OK     | OK            | OK  | OK  | OK          | OK     | OK       |
| ...          | -      | -             | -   | -   | -           | -      | -        |

### INTERFACE
| GÉNÉRATEUR | INTERFACE | COMPOSANT ACCÈS | FUNCTION | DATA | get | set |
|------------|-----------|-----------------|----------|------|-----|-----|
| C++        | OK        | OK              | OK       | OK   | OK  | OK  |
| ...        | -         | -               | -        | -    | -   | -   |

### COMPOSANT
| GÉNÉRATEUR | INTERFACE | ACCES INTERFACE | FUNCTION | DATA | INIT | COPY | DESTRUCTION | get | set |
|------------|-----------|-----------------|----------|------|------|------|-------------|-----|-----|
| C++        | OK        | OK              | OK       | OK   | OK   | OK   | OK          | OK  | OK  |
| ...        | -         | -               | -        | -    | -    | -    | -           | -   | -   |

### DEPLOIMENT
| GÉNÉRATEUR | DEPLOIMENT | Instance | INSTALLATION LINK |
|------------|------------|----------|-------------------|
| C++        | OK         | OK       | OK                |
| ...        | -          | -        | -                 |

### LINK
| GÉNÉRATEUR | LINK | DIRECT_LINK CALL | DIRECT_LINK RETURN |
|------------|------|------------------|--------------------|
| C++        | OK   | OK               | OK                 |
| ...        | -    | -                | -                  |


### COMPILATION
| GÉNÉRATEUR | COMPILATION | CMAKE FULL | CMAKE COMPOSANT | CMAKE RUN | LINUX | WINDOWS |
|------------|-------------|------------|-----------------|-----------|-------|---------|
| C++        | OK          | OK         | OK              | OK        | OK    |         |
| ...        | -           | -          | -               |           |       |         |

### RUN
| GÉNÉRATEUR | RUN | MEMORY | DEBUG |
|------------|-----|--------|-------|
| C++        | OK  | OK     | OK    |
| -          | -   | -      | -     |


### COMPILATEUR
| GÉNÉRATEUR | C++ |
|------------|-----|
| G++        | OK  |
| clang      | -   |
| tvc        | -   |
| diab       | -   |


## on supprime tout...
Régénération total.
Tout les fichiers précédents sont supprimé et remplacé par les nouveaux tout le code a l'intérieur des composants, interfaces, fonctions sera supprimé.

## FUSIIIIIOOOONNNNNNN !!!
Utilisation de ton gestionnaire de version de code.

## Git

Il faudrait des retours sur son efficacité.
 
```bash
# création d'une branche
git checkout -b newdep

# génération dans la nouvelle branche
python compo.py generate deploiments

# commit standard
git add .
git commit -m "nouveaux type de déploiement"

# on revient sur master et on merge
git chekout master
git merge newdep

# !!!!!!!!!!!!!!!!!!!!!!!!!!!!
# !!! gestion des conflits !!!
# !!!!!!!!!!!!!!!!!!!!!!!!!!!!

# commit apres le merge
git add .
git commit -m "nouveaux status"
```

# Compilations

## Cmake
### Tout d'un coup
```bash
cd test
ln -s ../tool/CMakeLists-full.txt CMakeLists.txt
cmake .

make
./dep1
```
### composant par composant
```bash
cd test
ln -s ../tool/CMakeLists-lib.txt CMakeLists.txt
cmake .
make

# Toute les libs sont dans /build/lib
./build/bin/dep1
```

TODO

TODO
TODO
