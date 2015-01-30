#include <iostream>
using namespace std;

int status[305];
int m, t, r;
int main() {
    cin >> m >> t >> r;
    int res = 0;
    if (t < r) {
        cout << -1 << endl;
        return 0;
    }
    for (int i = 0; i < m; i++) {
        int time;
        cin >> time;
        int j = time - 1;
        while (r > status[time]) {
            res++;
            for (int k = j + 1; k <= j + t; k++) {
                if (k >= 0 && k <= 300) status[k]++;
            }
            j--;
        }
    }
    cout << res << endl;
    return 0;
}