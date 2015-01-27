
// POJ2479

/*|Description
 *|  This is a dp problem.
 *|  Key part using dynamic programming three times.
 *|  The first time, dpleft[i] stands for the maximum continuous sum ended with position i.
 *|  The second time, dpright[i] stands for the maximum continuous sum started with position i.
 *|  The third time, dp[i] stands for the maximum continuous sum after position i (not necessarily start at).
 *|  Then find the maximum
 */

// DP is art

#include <iostream>
#include <stdio.h>
using namespace std;
int a[50001];
int dpleft[50001];
int dpright[50001];
int dp[50001];

int main() {
  int T, n;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++) {
      if (i == 0) dpleft[i] = a[i];
      else dpleft[i] = dpleft[i - 1] + a[i] > a[i] ? dpleft[i - 1] + a[i] : a[i];
    }
    for (int i = n - 1; i >= 0; i--) {
      if (i == n - 1) dpright[i] = a[i];
      else dpright[i] = dpright[i + 1] + a[i] > a[i] ? dpright[i + 1] + a[i] : a[i];
    }
    for (int i = n-1; i >= 0; i--) {
      if (i == n-1) dp[i] = a[i];
      else dp[i] = dp[i + 1] > dpright[i] ? dp[i + 1] : dpright[i];
    }
    int res = -10000000;
    for (int i = 0; i < n-1; i++) {
      int tmp = dpleft[i] + dp[i + 1];
      if (res < tmp) res = tmp;
    }
    cout << res << endl;
  }
  return 0;
}
