# Vector
This library was last edited by Jeffrey Kaji on *8 Oct 2019*. <br/>

## Description
This is a C library that performs vector math. <br/>
Created for use by Purdue Space Program Solids. <br/><br/>
__Required Files:__
* [Vector.h](../src/Vector.h)
* [Vector.c](../src/Vector.c)

## Typedefs
#### struct _Vector_
&ensp;&ensp;&ensp;&ensp;double **_x_**[3] 

## Methods
* **Vector_new()** <br/><br/>
* **addV()**
* **subV()**
* **mulV()**
* **divV()** <br/><br/>
* **dotV()** 
* **crossV()** <br/><br/>
* **getVVal()**
* **getVMag()**
* **getVUnit()**
* **getVUnitVal()** <br/><br/>
* **getVAngle()**
* **getVAngleDeg()** <br/><br/>
* **projV()**
* **projP()** <br/><br/>
* **printV()** <br/><br/>
* **deg2rad()**
* **rad2deg()** <br/><br/>

### Vector_new()
##### Description
Constructs *Vector* with given *double* **x** values **x0**, **x1**, **x2**.
##### Syntax
Vector* v = Vector_new(x0, x1, x2);
##### Parameters
x0: the value to write to x[0] _(double)_ <br />
x1: the value to write to x[1] _(double)_ <br />
x2: the value to write to x[2] _(double)_
##### Returns
Pointer to constructed vector _(Vector*)_


### addV()
##### Description
Adds *Vector* **v0** with *Vector* **v1** element-wise.
##### Syntax
Vector* v = addV(v0, v1);
##### Parameters
v0: pointer to the vector to add to _(Vector*)_ <br/>
v1: pointer to the vector to add with _(Vector*)_
##### Returns
Pointer to sum vector _(Vector*)_ 


### subV()
##### Description
Subtracts *Vector* **v1** from *Vector* **v0** element-wise.
##### Syntax
Vector* v = subV(v0, v1);
##### Parameters
v0: pointer to the vector to subtract from _(Vector*)_ <br/>
v1: pointer to the vector to subtract with _(Vector*)_
##### Returns
Pointer to difference vector _(Vector*)_


### mulV()
##### Description
Multiplies a *Vector* **v0** by a *double* **d**.
##### Syntax
Vector* v = mulV(v0, d);
##### Parameters
v0: pointer to the vector to be multiplied _(Vector*)_ <br/>
d: the value to multiply the vector with _(double)_
##### Returns
Pointer to the product vector _(Vector*)_


### divV()
##### Description
Divides a *Vector* **v0** by a *double* **d**.
##### Syntax
Vector* v = divV(v0, d);
##### Parameters
v0: pointer to the vector to be divided _(Vector*)_ <br/>
d: the value to divide the vector with _(double)_
##### Returns
Pointer to the quotient vector _(Vector*)_


### dotV()
##### Description
Calculates the dot product of *Vector* **v0** and *Vector* **v1**.
##### Syntax
double d = dot(v0, v1);
##### Parameters
v0: pointer to the first vector _(Vector*)_ <br/>
v1: pointer to the second vector _(Vector*)_
##### Returns
Result of the dot product _(double)_


### crossV()
##### Description
Calculates the cross product of *Vector* **v0** with *Vector** **v1**.
##### Syntax
Vector* v = crossV(v0, v1);
##### Parameters
v0: pointer to the vector to be crossed _(Vector*) <br/>
v1: pointer to the vector to cross with _(Vector*)
##### Returns
Pointer to result of cross product _(Vector*)_


### getVVal()
##### Description
Gets the *double* value of the dimension *int* **n** of *Vector* **v0**.
##### Syntax
double d = getVVal(v0, n);
##### Parameters
v0: pointer to the target vector _(Vector*)_
n: index to be returned _(int)_
##### Returns
Value at index _(double)_


### getVMag()
##### Description
Gets the *double* magnitude of *Vector* **v0**.
##### Syntax
double d = getMag(v0);
##### Parameters
v0: pointer to the target vector _(Vector*)_
##### Returns
Magnitude of the vector _(double)_


### getVUnit()
##### Description
Returns the unit vector of *Vector* **v0**.
##### Syntax
Vector* v = getVUnit(v0);
##### Parameters
v0: pointer to the target vector _(Vector*)_
##### Returns
Pointer to unit vector, i.e. same direction, magnitude of 1 _(Vector*)_ 


### getVUnitVal()
##### Description
Gets the *double* value of the dimension *int* **n** of the unit vector of *Vector* **v0**.
##### Syntax
double d = getVUnitVal(v0, n);
##### Parameters
v0: pointer to the target vector _(Vector*)_
n: index to be returned _(int)_
##### Returns
Value at index of unit vector _(double)_


### getVAngle()
##### Description
Calculates the *double* angle between to vectors in radians.
##### Syntax
double d = getVAngle(v0, v1);
##### Parameters
v0: pointer to first vector _(Vector*)_
v1: pointer to second vector _(Vector*)_
##### Returns
Angle between the two vectors in radians _(double)_


### getVAngleDeg()
##### Description
Calculates the *double* angle between to vectors in degrees.
##### Syntax
double d = getVAngle(v0, v1);
##### Parameters
v0: pointer to first vector _(Vector*)_
v1: pointer to second vector _(Vector*)_
##### Returns
Angle between the two vectors in degrees _(double)_

### printV()
##### Description
Prints out *Vector* **v** readably to the console.
##### Syntax
printV(v);
##### Parameters
v: pointer to vector to print _(Vector*)_
##### Returns
void


### deg2rad()
##### Description
Converts angle *double* **deg** from degrees to radians.
##### Syntax
double d = deg2rad(deg);
##### Parameters
deg: angle in degrees _(double)_
##### Returns
Angle in radians _(double)_


### rad2deg()
##### Description
Converts angle *double* **rad** from radians to degrees.
##### Syntax
double d = rad2deg(rad);
##### Parameters
rad: angle in radians _(double)_
##### Returns
Angle in degrees _(double)_

<br/>
###### Return to [README.md](README.md)