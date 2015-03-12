#include <fstream>
#include <iostream>
#include <string>
#include <cstring> // strtok
#include <cstdlib> // atol
 
using namespace std;

int main()
{
 
    // ifstream is used for reading files
    // We'll read from a file called Sample.dat
    ifstream inf("Sample.dat");
 
    // If we couldn't open the input file stream for reading
    if (!inf)
    {
        // Print an error and exit
        cerr << "Uh oh, Sample.dat could not be opened for reading!" << endl;
        //exit(1);
    }
 
    // While there's still stuff left to read
    while (inf)
    {
        // read stuff from the file into a string and print it
        string strInput;
        getline(inf, strInput);
        cout << strInput << endl;
    }
 
    //return 0;
 
    // When inf goes out of scope, the ifstream
    // destructor will close the file

    //
    // simple data read using stream operator >>
    //

    ifstream num("data.txt");
    if (!num)
    {
        // Print an error and exit
        cerr << "Uh oh, data.txt could not be opened for reading!" << endl;
    }
    int x;
    int count = 0, s = 0;
    while (num >> x) {
      count++;
      s = s + x;
    }
    cout << "cout = " << count << endl;
    cout << "sum  = " << s << endl;


    // read CPU stat and convert string data to double data
    ifstream cpustat("/proc/stat");
    if (!cpustat) {
      cerr << "/proc/stat cannot be opened" << endl;
    }

    double cputime[4];
    string cpuinfo;
    char *tk;
    int i;

    while (cpustat) {
      getline(cpustat, cpuinfo);
      // cpu0-4 is not valid
      if (cpuinfo.find("cpu") != string::npos) {
        i = 0;
        cout << cpuinfo << endl;
        char *t = new char[cpuinfo.length()];
        strcpy(t, cpuinfo.c_str());
        tk = strtok(t, " ");
        while (tk != NULL) {
          tk = strtok(NULL, " ");
          cputime[i] = atof(tk);
          printf("%f\n", cputime[i]);
          i++;
        }
      }
    }
}

