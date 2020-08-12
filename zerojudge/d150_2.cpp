#include <iostream>
#include <string>

void swap(int *in0, int *in1) {
    int a;

    a = *in0;
    *in0 = *in1;
    *in1 = a;
}

using namespace std;
int main(int argc, char *argv[]) {
    int in0;

    cin >> in0;
    while (in0--) {
        int in1;

        cin >> in1;

        int in[in1];

        for (int i = 0; i < in1; i++) cin >> in[i];

        for (int i = 0; i < in1; i++)
            for (int i1 = 0; i1 < in1; i1++)
                if (in[i] > in[i1]) {
                    swap(&in[i], &in[i1]);
                }

        long long int out = 0;
        for (int i = 2; i < in1; i += 3) {
            out += in[i];
        }

        cout << out << endl;
    }

    return 0;
}
