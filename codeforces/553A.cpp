#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
#include <map>
#include <string.h>
#include <iomanip>
#include <utility>
#define INF 0x3fffffff
using namespace std;

const int MAXN = 1017;
const int mod = 1000000007;
long long bino[MAXN][MAXN];
int k;
int a[MAXN];
int sum[MAXN];

void computeBino() {
	bino[0][0] = 1;
	for (int i = 1; i <= 1001; i++) {
		bino[i][0] = 1;
		for (int j = 1; j <= i; j++) {
			bino[i][j] = (bino[i - 1][j - 1] + bino[i - 1][j]) % mod;
		}
	}
}


int main() {
	computeBino();
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> a[i];
		if (i != 0) {
			sum[i] = sum[i - 1] + a[i];
		}
		else {
			sum[i] = a[i];
		}
	}
	long long res = 1;

	for (int i = 1; i < k; i++) {
		res = (res*bino[sum[i] - 1][a[i] - 1]) % mod;
	}

	cout << res << endl;
	return 0;
}