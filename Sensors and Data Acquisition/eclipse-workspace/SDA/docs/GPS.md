# GPS
This library was last edited by Jeffrey Kaji on *8 Oct 2019*. <br/>

## Description
This is a C library that will implement the GPS receiver, 
to be used in conjunction with Sensors and Vector. <br/>
Created for use by Purdue Space Program Solids. <br/><br/>
__Required Files:__
* _"Vector.h"_
* _"Vector.c"_
* _"GPS.h"_
* _"GPS.c"_

## Methods
* **GPS_getLLA()**
* **GPS_getSAT()** <br/><br/>

### GPS_getLLA()
##### Description
Gets LLA data as *Vector* from GPS receiver. <br/>
**NEEDS TO BE IMPLEMENTED**
##### Syntax
Vector* v = GPS_getLLA();
##### Parameters
None.
##### Returns
Pointer to the LLA vector read from the receiver _(Vector*)_


### GPS_getSAT()
##### Description
Gets *unsigned char* the number of satellites connected. <br/>
**NEEDS TO BE IMPLEMENTED**
##### Syntax
unsigned char u = GPS_getSAT();
##### Parameters
None.
##### Returns
The number of satellites connected _(unsigned char)_


### GPS_getTME()
##### Description
Gets *unsigned int* GPS time. <br/>
**NEEDS TO BE IMPLEMENTED**
##### Syntax
unsigned int u = GPS_getTME();
##### Parameters
None.
##### Returns
The GPS time _(unsigned int)_