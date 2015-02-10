#include <iostream>
#include <string.h>
using namespace std;
int n,k; // n stands for number of box, k stands for color
int b[105][105]; // the i-th color in the j-th box
int vol[105]; // volumn of every box

int main() {
  cin >> n >> k;
  int tmp_max = 0, max_index = 0;
  int tmp_min = 100000000;
  for (int i=1;i<=n;i++) {
    cin >> vol[i];
    if (vol[i] > tmp_max) {
      tmp_max = vol[i];
      max_index = i;
    }
    if (vol[i] < tmp_min) {
      tmp_min = vol[i];
    }
  }

  if (tmp_max - tmp_min > k) {
    cout << "NO" << endl;
    return 0;
  }

  // first round to fill the largest box
  int a = vol[max_index] / k;
  int c = vol[max_index] % k;
  for (int i=1;i<=k;i++) {
    if (c) {
      b[max_index][i] = a+1;
      c--;
    } else {
      b[max_index][i] = a;
    }
  }

  // fill other box using different color
  for (int i=1;i<=n;i++) {
    if (i==max_index) continue; //ignore the largest box
    int diff = vol[max_index] - vol[i];
    int diff2 = diff%k;
    int minus1 = diff/k;
    int minus2 = diff2;

    // initialize of b array, assign value using largest box property
    for (int j=k;j>=1;j--) {
      b[i][j] = b[max_index][j];
    }

    for (int j=k;i>=1;j--) {
      if (diff == 0) break;
      if (diff2) {
	b[i][j] = b[max_index][j]-minus1-1;
	diff--;
	diff2--;
      } else {
	b[i][j] = b[max_index][j]-minus1;
	diff--;
      }
    }
    
  }

  cout << "YES" << endl;
  for (int i=1;i<=n;i++) {
    for (int j=1;j<=k;j++) {
      while (b[i][j]) {
	cout << j << " ";
	b[i][j]--;
      }
    }
    cout << endl;
  }


  return 0;
}
