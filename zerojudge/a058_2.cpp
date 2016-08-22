#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    int a;
    cin >>a;
    int in,out1=0,out2=0,out3=0;
    while (a--){
          
          cin >>in;
          if ((in%3)==0)
             out1+=1;
          else if ((in%3)==1)
               out2+=1;
          else 
               out3+=1;
               
    }
    cout << out1<<" "<< out2<<" "<< out3<<" \n";
    return EXIT_SUCCESS;
}
