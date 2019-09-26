#include "Arduino.h"
#include "DataManager_v1-1.h"

// Write 'char' to 'long' array
void _DataManager::writeChar(long *target, int addr, char value) {
  combo_t combo;
  combo.l = target[addr / 4];
  combo.c[addr % 4] = value;
  target[addr / 4] = combo.l;
}


// Write 'int' to 'long' array
void _DataManager::writeInt(long *target, int addr, int value) {
  if(addr % 4 == 3) { // If Data Overlaps Variables
    // Populate Combos
    combo_t combo[3];
    combo[0].l = target[addr / 4];
    combo[1].l = target[addr / 4 + 1];
    combo[2].l = value;
    
    // Update Combos
    combo[0].c[3] = combo[2].c[0];
    combo[1].c[0] = combo[2].c[1];
    
    // Update Target
    target[addr / 4] = combo[0].l;
    target[addr / 4 + 1] = combo[1].l;
    
  } else { // If Data Doesn't Overlap Variables
    // Populate Combos
    combo_t combo[2];
    combo[0].l = target[addr / 4];
    combo[1].l = value;
    
    // Update Combos
    combo[0].c[addr % 4 + 1] = combo[1].c[1];
    combo[0].c[addr % 4] = combo[1].c[0];
    
    // Update Target
    target[addr / 4] = combo[0].l;
  }
}


// Write 'long' to 'long' array
void _DataManager::writeLong(long *target, int addr, long value) {
  if(addr % 4 == 0) {
    target[addr] = value;
  } else {
    // Populate Combos
    combo_t combo[3];
    combo[0].l = target[addr / 4];
    combo[1].l = target[addr / 4 + 1];
    combo[2].l = value;
    
    // Write New Values
    char *total = malloc(8 * sizeof(char));
    memcpy(total,            combo[0].c, 4 * sizeof(char));
    memcpy(total + 4,        combo[1].c, 4 * sizeof(char));
    memcpy(total + addr % 4, combo[2].c, 4 * sizeof(char));
    
    // Re-Populate Combos
    memcpy(combo[0].c, total,     4 * sizeof(char));
    memcpy(combo[1].c, total + 4, 4 * sizeof(char));
    
    // Update Target
    target[addr / 4] = combo[0].l;
    target[addr / 4 + 1] = combo[1].l;
  }
}


// Write 'float' to 'long' array
void _DataManager::writeFloat(long *target, int addr, float value) {
  combo_t combo;
  combo.f = value;
  writeLong(target, addr, combo.l);
}
  

// Read 'char' from 'long' array
char _DataManager::readChar(long *target, int addr) {
  combo_t combo;
  combo.l = target[addr / 4];
  return combo.c[addr % 4];
}


// Read 'int' from 'long' array
int _DataManager::readInt(long *target, int addr) {
  int value;
  if(addr % 4 == 3) {
    combo_t combo[2];
    combo[0].l = target[addr / 4];
    combo[1].l = target[addr / 4 + 1];
    value = (combo[1].c[0] << 8) + combo[0].c[3];
  } else {
    combo_t combo;
    combo.l = target[addr / 4];
    value = (combo.c[addr % 4 + 1] << 8) + combo.c[addr % 4];
  }
  
  return value;
}


// Read 'long' from 'long' array
long _DataManager::readLong(long *target, int addr) {
  long value;
  if(addr % 4 == 0) {
    value = target[addr / 4];
  } else {
    combo_t combo[3];
    combo[0].l = target[addr / 4];
    combo[1].l = target[addr / 4 + 1];
    
    char *total = malloc(8 * sizeof(char));
    memcpy(total,            combo[0].c, 4 * sizeof(char));
    memcpy(total + 4,        combo[1].c, 4 * sizeof(char));
    memcpy(combo[2].c, total + addr % 4, 4 * sizeof(char));

    value = combo[2].l;
  }
  
  return value;
}


// Read 'float' from 'long' array
float _DataManager::readFloat(long *target, int addr) {
  combo_t combo;
  combo.l = readLong(target, addr);
  return combo.f;
}


// Hidden char pointer used in getCharRep()
unsigned char *_charRep;


// Represents 'long' as 'char' array of length 4
unsigned char *_DataManager::getCharRep(long L) {
  combo_t combo;
  combo.l = L;
  _charRep = combo.uc;
  return _charRep;
}
