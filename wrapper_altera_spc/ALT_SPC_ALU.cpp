#include <cstdio> 
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <iostream>
#include <bitset>
#include "ALT_SPC_ALU.h"

using namespace std;

//----------------------------------------------------------------------------------------
// Assume there are no warnings or errors when reading the value returned 
// from quartus_stp command (e.g. Warning (292006): Can't contact license server "..."
//
// Assume only one USB Blaster is installed and Altera DE2 FPGA is the only device 
// in the JTAG chain
//----------------------------------------------------------------------------------------
ALT_SPC_ALU::ALT_SPC_ALU() {
  char *pos;
  fp = popen("quartus_stp --tcl_eval lindex [get_hardware_names] 0", "r");
  assert (fp != NULL);
  assert(fgets(usbName, 32, fp) != NULL);
  if ((pos=strchr(usbName, NL)) != NULL) *pos = '\0';

  fp = popen("quartus_stp --tcl_eval lindex [get_device_names -hardware_name [lindex [get_hardware_names] 0]] 0", "r");
  assert (fp != NULL);
  assert(fgets(devName, 32, fp) != NULL);
  
  if ((pos=strchr(devName, NL)) != NULL) *pos = '\0';
  assert(-1 != pclose(fp));
}

void ALT_SPC_ALU::source(const int aVal, const int bVal, const int shamtVal, const int opVal, 
    const int aIndex, const int bIndex, const int shamtIndex, const int opIndex) {
  FILE *f;
  f = fopen("source.tcl", "w");
  fprintf(f, "start_insystem_source_probe -hardware_name {%s} -device_name \"%s\"\n",usbName, devName);
  fprintf(f, "write_source_data -instance_index %d -value %x -value_in_hex\n", aIndex, aVal);
  fprintf(f, "write_source_data -instance_index %d -value %x -value_in_hex\n", bIndex, bVal);
  fprintf(f, "write_source_data -instance_index %d -value %x -value_in_hex\n", shamtIndex, shamtVal);
  fprintf(f, "write_source_data -instance_index %d -value %d", opIndex, opVal);
  fclose(f);
  popen("quartus_stp -t source.tcl",  "r");
}

void ALT_SPC_ALU::source(const int aVal, const int bVal, const int opVal, 
    const int aIndex, const int bIndex, const int opIndex) {
  FILE *f;
  f = fopen("source.tcl", "w");
  fprintf(f, "start_insystem_source_probe -hardware_name {%s} -device_name \"%s\"\n",usbName, devName);
  fprintf(f, "write_source_data -instance_index %d -value %x -value_in_hex\n", aIndex, aVal);
  fprintf(f, "write_source_data -instance_index %d -value %x -value_in_hex\n", bIndex, bVal);
  fprintf(f, "write_source_data -instance_index %d -value %d", opIndex, opVal);
  fclose(f);
  popen("quartus_stp -t source.tcl",  "r");
}

unsigned int ALT_SPC_ALU::probe(const int instanceIndex) {
  char tmp[64];
  strcpy(cmd, "quartus_stp --tcl_eval eval ");
  strcat(cmd, "\"start_insystem_source_probe ");

  string s = string(usbName);
  s.insert(s.find('['), "\\");
  s.insert(s.find(']'), "\\");
  sprintf(tmp, "-hardware_name {%s} ", s.c_str()); 
  strcat(cmd, tmp);

  s = string(devName);
  s.insert(s.find('('), "\\");
  s.insert(s.find(')'), "\\");
  sprintf(tmp, "-device_name {%s}; ", s.c_str()); 
  strcat(cmd, tmp);

  sprintf(tmp, "read_probe_data -instance_index %d\"", instanceIndex); 
  strcat(cmd, tmp);

  fp = popen(cmd, "r");
  assert(fp != NULL);
  assert(fgets(res, 33, fp) != NULL);
  return (unsigned int) bitset<32>(string(res)).to_ulong();
}

