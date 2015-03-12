#include <iostream>
#include <cstdio>
#include <string>
#include <map>
#include <bitset>
#include <cassert>
#include "ALT_SPC_ALU.h"

using namespace std;


int main() {
  map<string, string> opcode;
  opcode["AND"] = "0000";
  opcode["OR"]  = "0001";

  string op = opcode["OR"];
  int aluA = 0x4;
  int aluB = 0x2;
  int aluOp = bitset<4>(op).to_ulong();

  ALT_SPC_ALU tb;
  tb.source(aluA, aluB, aluOp);
  //cout << tb.probe(R) << endl;
  assert((aluA | aluB) == tb.probe(R));
  return 0;
}


