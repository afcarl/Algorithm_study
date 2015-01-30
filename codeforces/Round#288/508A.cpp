#include <iostream>
#include <stdio.h>
using namespace std;

int n, m, k;
int a[1001][1001]; // The record array

int main() {
    cin >> m >> n >> k;
    int i;
    for (i = 1; i <= k; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        a[x][y] = 1;

	// judge the four possible square matrix
	if (a[x + 1][y - 1] && a[x + 1][y] && a[x][y - 1]) {
            cout << i << endl;
            return 0;
        }

	if (a[x + 1][y + 1] && a[x + 1][y] && a[x][y + 1]) {
            cout << i << endl;
            return 0;
        }

	if (a[x - 1][y - 1] && a[x][y - 1] && a[x - 1][y]) {
            cout << i << endl;
            return 0;
        }

	if (a[x - 1][y] && a[x - 1][y + 1] && a[x][y + 1]) {
            cout << i << endl;
            return 0;
        }
    }

    // if not return, the 2*2 matrix didn't appear
    if (i == k + 1) cout << "0" << endl;
    return 0;
}
