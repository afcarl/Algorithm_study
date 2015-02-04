#include <iostream>
using namespace std;
int n,m;
char a[55][55];

int main() {
  cin >> n >> m;
  int tmp = 1;
  while (tmp <= n) {
    if (tmp % 4 == 2) {
      a[tmp++][m] = '#'; // now the pointer point to rightmost
    } else if (tmp % 4 ==0) {
      a[tmp++][1] = '#'; // now the pointer point to leftmost
    } else {
      for (int i=1;i<=m;i++) {
	a[tmp++][i] = '#';
      }
    }
  }

  for (int i=1;i<=n;i++) {
    for (int j=1;j<=n;j++) {
      if (a[i][j] != '#') cout << '.';
      else cout << a[i][j];
    }
    cout << endl;
  }

  return 0;
}
