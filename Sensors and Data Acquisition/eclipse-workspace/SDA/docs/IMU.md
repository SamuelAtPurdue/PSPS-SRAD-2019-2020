# IMU
This library was last edited by Jeffrey Kaji on *8 Oct 2019*. <br/>

## Description
This is a C library that will implement the 9-axis Inertial Measurement Unit, 
to be used in conjunction with Sensors and Vector. <br/>
Created for use by Purdue Space Program Solids. <br/><br/>
__Required Files:__
* _"Vector.h"_
* _"Vector.c"_
* _"IMU.h"_
* _"IMU.c"_

## Methods
* **IMU_getACC()**
* **IMU_getGYR()**
* **IMU_getMAG()** <br/><br/>

### IMU_getACC()
##### Description
Gets acceleration *Vector* from the IMU. <br/>
**NEEDS TO BE IMPLEMENTED**
##### Syntax
Vector* v = IMU_getACC();
##### Parameters
None.
##### Returns
Pointer to the acceleration vector from the IMU _(Vector*)_


### IMU_getGYR()
##### Description
Gets angular acceleration *Vector* from the IMU. <br/>
**NEEDS TO BE IMPLEMENTED**
##### Syntax
Vector* v = IMU_getGYR();
##### Parameters
None.
##### Returns
Pointer to the angular acceleration vector from the IMU _(Vector*)_


### IMU_getMAG()
##### Description
Gets magnetic field *Vector* from the IMU. <br/>
**NEEDS TO BE IMPLEMENTED**
##### Syntax
Vector* v = IMU_getMAG();
##### Parameters
None.
##### Returns
Pointer to the magnetic field vector from the IMU _(Vector*)_
