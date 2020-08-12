#include <iostream>

using namespace std;

int main() {
    int in[3];

    while (cin >> in[0] >> in[1] >> in[2]) {
        cout << in[0] << " 個餅乾，"
             << in[1] + ((int)(in[0] / 10) < (int)(in[2] / 2) ? in[0] / 10
                                                              : in[2] / 2)
             << " 盒巧克力，" << in[2] << " 個蛋糕。" << endl;
    }
    // system("PAUSE");
}
