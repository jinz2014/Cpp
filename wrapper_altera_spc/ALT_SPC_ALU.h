/* 
 * A C++ wrapper for Altera's FPGA test of ALU
 *
 * dependencies {
 *   Altera's source and probe verfication component
 *   Altera's quartus_stp command
 * }
 *
 * Author JZM
 */

#ifndef ALT_SPC_ALU_H
#define ALT_SPC_ALU_H

#include <cstdio>

// newline
#ifdef _WIN32 
  #define NL '\r'
#elif __CYGWIN__
  #define NL '\r'
#else
  #define NL '\n'
#endif

// Index of each Altera's source and probe component
enum index {
  A,
  B,
  OP,
  Shamt,
  R
};


class ALT_SPC_ALU {
  private:
    char usbName[32];  // e.g. USB-Blaster [USB-0] 
    char devName[32];  // e.g. @1: EP2C35 (0X020B4)
    char cmd[256];     // command buffer for TCL evaluation
    char res[33];      // result of probing the 32-bit ALU result
    FILE *fp;          // file pointer returned by popen

  public :
    // constructor
    ALT_SPC_ALU();

    // source data into Altera's source component
    void source(const int aVal, 
                const int bVal, 
                const int opVal, 
                const int aIndex = A,
                const int bIndex = B, 
                const int opIndex = OP);

    void source(const int aVal, 
                const int bVal, 
                const int shamtVal, 
                const int opVal, 
                const int aIndex = A, 
                const int bIndex = B, 
                const int shamtIndex = Shamt, 
                const int opIndex = OP);

    // probe data from Altera's probe component
    unsigned int probe(const int instanceIndex);
};

#endif
