# MYCI
_My_Composant_Implementation_

# Models

# Générateur
## Générateur list 
  * __C++__: Ce générateur est un générateur c++ Il est nécessaire d'avoir le support de _c++11_ et de la std.
  * __RUST__: TODO
  * __JAVA__: TODO
  * __PYTHON__: started
  * __UML__: started
  * __GRAPH__: generate graphic view of component and deployment

### GLOBAL
| GÉNÉRATEUR | TYPE | STRUCTURE | INTERFACE | DÉPLOIEMENT | COMPOSANT | LINK | COMPILATION | RUN |
|------------|------|-----------|-----------|-------------|-----------|------|-------------|-----|
| C++        | OK   | OK        | OK        | OK          | OK        | OK   | OK          | OK  |


### TYPE
| GÉNÉRATEUR | TYPE | Function | Pointer | array | default | array TO_STR | pointer TO_STR | STR_TO_pointer | STR_TO_SP        |
|------------|------|----------|---------|-------|---------|--------------|----------------|----------------|------------------|
| C++        | OK   | OK       | OK      | OK    | OK      | OK           | OK             | OK             | OK               |


### STRUCTURE
| GÉNÉRATEUR   | STRUCT | get | set | constucteur | TO_STR | FROM_STR | default | PARENT | SHELL |
|--------------|--------|-----|-----|-------------|--------|----------|---------|--------|-------|
| C++        - | OK     | OK  | OK  | OK          | OK     | OK       | OK      | OK     | TD    |


### ERROR
| GÉNÉRATEUR | get | set | constucteur | TO_STR | FROM_STR | DEFAULT | PARENT |
|------------|-----|-----|-------------|--------|----------|---------|--------|
| C++        | OK  | OK  | OK          | OK     | OK       | TODO    | OK     |


### INTERFACE
| GÉNÉRATEUR | INTERFACE | COMPOSANT ACCÈS | FUNCTION | DATA | get | set | default | SHELL | FAKE | CALLER |
|------------|-----------|-----------------|----------|------|-----|-----|---------|-------|------|--------|
| C++        | OK        | OK              | OK       | OK   | OK  | OK  | OK      | OK    | OK   | OK     |


### COMPONENT
| GÉNÉRATEUR | INTERFACE | ACCES INTERFACE | FUNCTION | DATA | INIT | COPY | DESTRUCTION | get | set | default | PARENT | SAVE | RESTORE | 
|------------|-----------|-----------------|----------|------|------|------|-------------|-----|-----|---------|--------|------|---------+
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
# gitlab_runner
