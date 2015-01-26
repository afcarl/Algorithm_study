#include <iostream>
#include <algorithm>
using namespace std;
int n;
int a[100];
int dp[100];
int main() {
  cin >> n;
  int res = -10000000;
  for (int i=0;i<n;i++) {
    cin >> a[i];
  }
  for (int i=0;i<n;i++) {
    if (a[i] < 0) {
      res = max(dp[i-1],res);
      dp[i] = 0;
    }
    else {
      dp[i] = dp[i-1] + a[i];
      res = max(dp[i],res);
    }
  }
  cout << res << endl;
  
  return 0;
}
