#include <cstring>
#include <iostream>
 
using namespace std;

int main() 
{
      char input[100] = "A bird came down the walk";
          char *token = strtok(input, " \n\t");
              while (token != NULL) {
                        cout << token << '\n';
                                token = strtok(NULL, " ");
                                    }
}
