#ifndef DataManager_v1-0_h
#define DataManager_v1-0_h

#include "Arduino.h"

// Union allows variable types to easily be converted
typedef union {
  float f;
  long l;
  unsigned long ul;
  int i[2];
  unsigned int ui[2];
  char c[4];
  unsigned char uc[4];
} combo_t;

// Class holding methods
static class _DataManager {
  public:
    
    // Write Methods
    void writeChar (long *target, int addr,  char value);
    void writeInt  (long *target, int addr,   int value);
    void writeLong (long *target, int addr,  long value);
    void writeFloat(long *target, int addr, float value);
    
    // Read Methods
    char  readChar (long *target, int addr);
    int   readInt  (long *target, int addr);
    long  readLong (long *target, int addr);
    float readFloat(long *target, int addr);
    
    // Other
    unsigned char *getCharRep(long L);
  
} DataManager;

#endif