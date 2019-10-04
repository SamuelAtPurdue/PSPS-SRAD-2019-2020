/*
  basic.ino

  This sketch is a basic demonstration of how to use DataManager Library (v1.0).
  Writes and reads various variable types to a packet, which is a long array.

  Created 26 Sept 2019
  By Jeffrey Kaji
*/

#include <DataManager_v1-0.h>

#define C0_ADDR 0  // c0 address: 0          (0:0)
#define C1_ADDR 1  // c1 address: 1          (0:1)
#define L0_ADDR 2  // l0 address: 2,3,4,5    (0:2 to 1:1)
#define C2_ADDR 6  // c2 address: 6          (1:2)
#define I0_ADDR 7  // i0 address: 7,8        (1:3 to 2:0)
#define F0_ADDR 9  // f0 address: 9,10,11,12 (2:1 to 3:0)
#define I1_ADDR 13 // i1 address: 13,14      (3:1 to 3:2)
#define C3_ADDR 15 // c3 address: 15         (3:3)

#define PSIZE 4 // Size of packet

void printPacket(long*); // Prints out entire binary packet
void printVarBits(long,char,int); // Prints binary of variable
void printFloatBits(float,int); // Prints binary of float
void bitPrint(unsigned char); // Prints out binary of char


void setup() {

  // Initialize Serial
  Serial.begin(9600);

  // Initialize packet
  long packet[PSIZE] = {0};

  // Assign values to variables
  unsigned char c0 = 0b00000000;
  unsigned char c1 = 0b11111111;
  unsigned char c2 = 0b00001111;
  unsigned char c3 = 0b11010100;
  unsigned int  i0 = 0b1010110011110000;
  unsigned int  i1 = (unsigned int) (-1);
  unsigned long l0= 3141592653589793238;
  float f0 = 3.141593;

  // Write variables to packet
  DataManager.writeChar(packet, C0_ADDR, c0);
  DataManager.writeChar(packet, C1_ADDR, c1);
  DataManager.writeChar(packet, C2_ADDR, c2);
  DataManager.writeChar(packet, C3_ADDR, c3);
  DataManager.writeInt(packet, I0_ADDR, i0);
  DataManager.writeInt(packet, I1_ADDR, i1);
  DataManager.writeLong(packet, L0_ADDR, l0);
  DataManager.writeFloat(packet, F0_ADDR, f0);

  // Print entire packet in binary
  printPacket(packet);

  // Print Variable Binaries
  printVarBits(DataManager.readChar(packet, C0_ADDR),'C',0);
  printVarBits(DataManager.readChar(packet, C1_ADDR),'C',1);
  printVarBits(DataManager.readLong(packet, L0_ADDR),'L',0);
  printVarBits(DataManager.readChar(packet, C2_ADDR),'C',2);
  printVarBits(DataManager.readInt(packet, I0_ADDR),'I',0);
  printFloatBits(DataManager.readFloat(packet, F0_ADDR), 0);
  printVarBits(DataManager.readInt(packet, I1_ADDR),'I',1);
  printVarBits(DataManager.readChar(packet, C3_ADDR),'C',3);
}


void loop() {
}


// Print entire packet in binary
void printPacket(long *packet) {
  Serial.println("Full Packet:");
  for(int i = 0; i < PSIZE; i++)
    printVarBits(packet[i],'P',i);
  Serial.println();
}


// Print out variable value in binary, breaks into char and sends to bitPrint()
//    long value: variable value
//    char vType: variable type ('C' = char, 'I' = int, 'L' = long)
//     int    id: display number when printed
void printVarBits(long value, char vType, int id) {
  combo_t combo;
  combo.l = 0;
  int i;
  switch(vType) {
    case 'P': // P indicates method is printing a packet
    case 'F': // F for float (must be indirectly sent through printFloatBits() first)
    case 'L': i = 0; // L for long
              combo.l = value;
              break;
    case 'I': i = 2; // I for int
              combo.i[1] = value;
              break;
    case 'C': i = 3; // C for char
              combo.c[3] = value;
              break;  
  }
  
  Serial.print(vType);
  if(PSIZE > 10 and id < 10)
    Serial.print(0);
  Serial.print(id);
  Serial.print(" |");
      
  for(; i < 4; i++)
    bitPrint(combo.c[i]);
  Serial.println();
}


// Print out float value in binary (sends to printVarBits() as long)
//    long value: variable value
//     int    id: display number when printed
void printFloatBits(float value, int id) {
  combo_t combo;
  combo.f = value;
  printVarBits(combo.l, 'F', id);
}


// Print out char value in binary
//    char value: variable value to be printed
void bitPrint(unsigned char c) {
    for(int i = 7; i >=0; i--)
      Serial.print(((c & (1 << i)) >> i));
}