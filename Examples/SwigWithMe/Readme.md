# HelloWord

This code is a example of utilisation of Swig programs.

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
python3
```
In python shell:

```python
import swig_lib.Components.Compute as C
my_inst = C.Compute() // create a instance
my_int = my_inst.get_compute() // get interface

// call function
my_int.add(1,2)
my_int.sub(1,2)
my_int.time(1,2)
my_int.div(1,2)
```

# Write the right code
In this step we will implement the answer of the Compute interface.

Replace the add implementation SwigWithMe/src/Components/Compute_Calc_I_compute.cpp

``` C++
double Compute_Calc_I_compute::add(double a, double b) {

  double ret =

      double();

  return ret;
}
```

to 

``` C++
double Compute_Calc_I_compute::add(double a, double b) {
  return a+b;
}
```

Repeat this step for sub/time and div.

Recompile and have fun
