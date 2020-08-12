#include <iostream>
using namespace std;

int to_min(char a[]) {
    int min = 0;
    min += (a[0] - '0') * 600;
    min += (a[1] - '0') * 60;
    min += (a[3] - '0') * 10;
    min += (a[4] - '0');
    return min;
}

void to_clock_out(int min) {
    cout << min / 600;
    min %= 600;
    cout << min / 60;
    min %= 60;
    cout << ":";
    cout << min / 10;
    min %= 10;
    cout << min;
}

int main() {
    int k;
    cin >> k;
    while (k--) {
        int n;
        char start_time[10], end_time[10];
        cin >> n >> start_time >> end_time;
        int start_min = to_min(start_time), end_min = to_min(end_time);
        while (n--) {
            char name[15], need_time[10];
            cin >> name >> need_time;
            to_clock_out(start_min - to_min(need_time));
            cout << " ";
            to_clock_out(end_min - to_min(need_time));
            cout << endl;
        }
    }
}
