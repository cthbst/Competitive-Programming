#include <math.h>
#include <sys/timeb.h>

#include <iostream>
// --------------------------------------------------------
int is_prime(int no) {
    int i;
    double x = sqrt(no) + 0.1;
    for (i = 2; i <= x; i++)
        if ((no % i) == 0) return 0;
    return 1;
}
using namespace std;
int main(int argc, char* argv[]) {
    long long int out = 2;
    for (int i = 3; i <= 2000000; i += 2)
        if (is_prime(i)) out += i;
    cout << out << endl;
}
