#include <iostream>
using namespace std;
int a[11][11];
int main() {
  int n;
  cin >> n;
  for (int i=1;i<=n;i++) {
    for (int j=1;j<=n;j++) {
      if (i==1 || j==1) {
	a[i][j] = 1;
	continue;
      } else {
	a[i][j] = a[i-1][j] + a[i][j-1];
      }
    }
  }
  cout << a[n][n] << endl;
  return 0;
}
