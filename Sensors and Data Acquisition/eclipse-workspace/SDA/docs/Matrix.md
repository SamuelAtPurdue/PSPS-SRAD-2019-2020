# Matrix
This library was last edited by Jeffrey Kaji on *8 Oct 2019*. <br/>

## Description
This is a C library that performs matrix math, 
to be used in conjunction with [Vector](Vector.md). <br/>
Created for use by Purdue Space Program Solids. <br/><br/>
__Required Files:__
* [Vector.h](../src/Vector.h)
* [Vector.c](../src/Vector.c)
* [Matrix.h](../src/Matrix.h)
* [Matrix.c](../src/Matrix.c)

## Typedefs
#### struct _Matrix_
&ensp;&ensp;&ensp;&ensp;Vector **_e_**[3] 

## Methods
* **Matrix_new()**
* **MatrixRef_new()** <br/><br/>
* **getMUnit()** <br/><br/>
* **mulMV()** <br/><br/>
* **printM()** <br/><br/>

### Matrix_new()
##### Description
Constructs *Matrix* with given *Vector* **e** values **e0**, **e1**, **e2**.
##### Syntax
Matrix* m = Matrix_new(e0, e1, e2);
##### Parameters
e0: pointer to the vector to write to e[0] _(Vector*)_ <br />
e1: pointer to the vector to write to e[1] _(Vector*)_ <br />
e2: pointer to the vector to write to e[2] _(Vector*)_
##### Returns
Pointer to constructed matrix _(Matrix*)_


### Matrix_new()
##### Description
Constructs reference frame *Matrix* with given vectors *Vector* **e0**, **e1**. <br/>
A reference frame contains 3 perpendicular unit vectors. <br/>
**e0** and **e1** are converted into unit vectors and are crossed to find **e2**.
##### Syntax
Matrix* m = MatrixRef_new(e0, e1);
##### Parameters
e0: pointer to the vector whose unit vector is to written to e[0] _(Vector*)_ <br />
e1: pointer to the vector whose unit vector is to written to e[1] _(Vector*)_
##### Returns
Pointer to constructed matrix _(Matrix*)_


### getMUnit()
##### Description
Constructs *Matrix* with the unit vectors of *Matrix* **m0**.
##### Syntax
Matrix* m = getMUnit(m0);
##### Parameters
m0: pointer to the target matrix _(Matrix*)_
##### Returns
Pointer to resulting matrix _(Matrix*)_ 


### mulMV()
##### Description
Performs matrix multiplication of *Matrix* **m0** and *Vector* **v0**.
##### Syntax
Vector* v = mulMV(m0, v0);
##### Parameters
m0: pointer to the target matrix _(Matrix*)_ <br/>
v0: pointer to the target vector _(Vector*)_
##### Returns
Pointer to the resulting vector _(Vector*)_


### printM()
##### Description
Prints out *Matrix* **m** readably to the console.
##### Syntax
printM(m);
##### Parameters
m: pointer to matrix to print _(Matrix*)_
##### Returns
void

<br/>
##### Return to [README.md](README.md)