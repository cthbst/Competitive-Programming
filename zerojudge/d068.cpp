#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    int in;
    while (cin >>in ){
          cout <<(in>50?in-1:in) <<endl;
    }
    return EXIT_SUCCESS;
}
