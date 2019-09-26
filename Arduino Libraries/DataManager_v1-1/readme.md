# Arduino DataManager Library v1.1
This library was last edited by *Jeff Kaji* on *26 Sept 2019*. <br />

**Development Goals for 1.1**
* Individual bit manipulation, aka "flags" (STATUS: NOT COMPLETE)
* Address name shortcuts (maybe?) (STATUS: NOT COMPLETE)

## Description
This is a C++ library for Arduino, created by Jeffrey Kaji for use by Purdue Space Program Solids. <br />


DataManager reads and writes variables of type *char*, *int*, *long* and *float* to specific bits within a *long* array. 
Each *long* element in this array can then be broken down further into an array of *chars*. 
Multi-byte variables *int*, *long*, *float* can be split across adjacent *long* elements within the array. 
This data management allows for dense and uniform variable storage (regardless of type) within a packet object, 
aiding storage and transmission. 

Location of a given *char* **A** within *long* **packet**[n] is as follows, given by address *int* **addr**:

*long* **L** = **packet**[**addr** / 4]; <br />
*char* **c**[4] ← **L**; <br />
*char* **A** = **c**[**addr** % 4];


<pre>                                       Data bit breakdown of char array c[4]
        ————————————————————————————————————————————————————————————————————————————————————————————————— 
        |          c[0]         |          c[1]         |          c[2]         |          c[3]         | 
        |———————————————————————|———————————————————————|———————————————————————|———————————————————————| 
(float) |31 30 29 28 27 26 25 24|23 22 21 20 19 18 17 16|15 14 13 12 11 10  9  8| 7  6  5  4  3  2  1  0| 
 (long) |31 30 29 28 27 26 25 24|23 22 21 20 19 18 17 16|15 14 13 12 11 10  9  8| 7  6  5  4  3  2  1  0| 
  (int) |15 14 13 12 11 10  9  8| 7  6  5  4  3  2  1  0|15 14 13 12 11 10  9  8| 7  6  5  4  3  2  1  0| 
 (char) | 7  6  5  4  3  2  1  0| 7  6  5  4  3  2  1  0| 7  6  5  4  3  2  1  0| 7  6  5  4  3  2  1  0| 
        ————————————————————————————————————————————————————————————————————————————————————————————————— </pre>

**Examples:** Given *long* **packet**[2], with *char* **c**[4] and *int* **addr**
* A *char* at **addr** = 6 is stored in **c**[2] of **packet**[1]
* An *int* at **addr** = 3 is stored in **c**[3] of **packet**[0] and **c**[0] of **packet**[1]
* A *long* at **addr** = 1 is stored at **c**[1] to **c**[3] of **packet**[0] and **c**[0] of **packet**[1]
* A *float* at **addr** = 0 is stored at **c**[0] to **c**[3] of **packet**[0]

Note: The above examples are overlapping. Reading and writing overlapping data will not cause an error, but may lead to unexpected results.

## Methods
* **writeChar()**
* **writeInt()**
* **writeLong()**
* **writeFloat()** <br /> <br />
* **readChar()**
* **readInt()**
* **readLong()**
* **readFloat()** <br /> <br />
* **getCharRep()** <br /> <br />

### writeChar()
##### Description
Writes *char* **value** to specified address *int* **addr** in given *long* array **target**.
##### Syntax
DataManager.writeChar(target, addr, value);
##### Parameters
target: the target packet _(*long)_ <br />
addr: the address to write to _(int)_ <br />
value: the data to write to the packet _(char)_
##### Returns
None.

### writeInt()
##### Description
Writes *int* **value** to specified address *int* **addr** in given *long* array **target**.
##### Syntax
DataManager.writeInt(target, addr, value);
##### Parameters
target: the target packet _(*long)_ <br />
addr: the starting address to write to _(int)_ <br />
value: the data to write to the packet _(long)_
##### Returns
None.


### writeLong()
##### Description
Writes *long* **value** to specified address *int* **addr** in given *long* array **target**.
##### Syntax
DataManager.writeLong(target, addr, value);
##### Parameters
target: the target packet _(*long)_ <br />
addr: the starting address to write to _(int)_ <br />
value: the data to write to the packet _(int)_
##### Returns
None.


### writeFloat()
##### Description
Writes *float* **value** to specified address *int* **addr** in given *long* array **target**.
##### Syntax
DataManager.writeFloat(target, addr, value);
##### Parameters
target: the target packet _(*long)_ <br />
addr: the starting address to write to _(int)_ <br />
value: the data to write to the packet _(float)_
##### Returns
None.


### readChar()
##### Description
Reads *char* from specified address *int* **addr** in given *long* array **target**.
##### Syntax
DataManager.readChar(target, addr);
##### Parameters
target: the target packet _(*long)_ <br />
addr: the address to read from _(int)_ <br />
##### Returns
the data read from the packet _(char)_


### readInt()
##### Description
Reads *int* starting from specified address *int* **addr** in given *long* array **target**.
##### Syntax
DataManager.readInt(target, addr);
##### Parameters
target: the target packet _(*long)_ <br />
addr: the starting address to read from _(int)_ <br />
##### Returns
the data read from the packet _(int)_


### readLong()
##### Description
Reads *long* starting from specified address *int* **addr** in given *long* array **target**.
##### Syntax
DataManager.readLong(target, addr);
##### Parameters
target: the target packet _(*long)_ <br />
addr: the starting address to read from _(int)_ <br />
##### Returns
the data read from the packet _(long)_


### readFloat()
##### Description
Reads *float* starting from specified address *int* **addr** in given *long* array **target**.
##### Syntax
DataManager.readFloat(target, addr);
##### Parameters
target: the target packet _(*long)_ <br />
addr: the starting address to read from _(int)_ <br />
##### Returns
the data read from the packet _(float)_


### getCharRep()
##### Description
Breaks down bytes of given *long* **L** into *char* array of length 4.
##### Syntax
DataManager.getCharRep(L);
##### Parameters
L: the *long* to be broken down _(long)_
#### Returns
the *char* representation of L _(*char)_


Installation
--------------------------------------------------------------------------------

To install this library, just place this entire folder as a subfolder in your
Arduino/lib/targets/libraries folder.

When installed, this library should look like:

Arduino/lib/targets/libraries/DataManager_v1-1 <br />
Arduino/lib/targets/libraries/DataManager_v1-1/DataManager_v1-1.cpp <br />
Arduino/lib/targets/libraries/DataManager_v1-1/DataManager_v1-1.h  <br />
Arduino/lib/targets/libraries/DataManager_v1-1/keywords.txt  <br />
Arduino/lib/targets/libraries/DataManager_v1-1/examples  <br />
Arduino/lib/targets/libraries/DataManager_v1-1/readme.md  <br />

Building
--------------------------------------------------------------------------------

After this library is installed, you just have to start the Arduino application.
You may see a few warning messages as it's built.

To use this library in a sketch, go to the Sketch | Import Library menu and select *"DataManager_v1-1"*.  This will add a corresponding line to the top of your sketch: <br />
_\#include <DataManager_v1-1.h>_

To stop using this library, delete that line from your sketch.


After a successful build of this library, a new file named "*DataManager_v1-1.o*" will appear
in "*Arduino/lib/targets/libraries/DataManager_v1-1*". This file is the built/compiled library
code.

If you choose to modify the code for this library (i.e. "*DataManager_v1-1.cpp*" or "*DataManager_v1-1.h*"),
then you must first 'unbuild' this library by deleting the "*DataManager_v1-1.o*" file. The
new "*DataManager_v1-1.o*" with your code will appear after the next press of "verify".

## Note
This *README.md* file heavily borrows from the example provided in the library "Test" created by Nicholas Zambetti found here:
<https://www.arduino.cc/en/uploads/Hacking/Test.zip>

