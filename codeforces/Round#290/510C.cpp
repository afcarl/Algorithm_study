#include <iostream>
#include <string>
#include <queue>
using namespace std;
int n,in[30],w[30][30];
string s[105],ans;
queue<int> q;

bool topo_sort() {
  for (int i=1;i<=26;i++) {
    for (int j=1;j<=26;j++) {
      if (w[i][j]) in[j]++;
    }
  }

  for (int i=1;i<=26;i++) {
    if (in[i] == 0) {
      q.push(i);
      ans += i-1+'a';
    }
  }

  while (!q.empty()) {
    int tmp = q.front(); q.pop();
    for (int i=1;i<=26;i++) {
      if (w[tmp][i]) {
	in[i]--;
	if (in[i] == 0) {
	  q.push(i);
	  ans += i-1+'a';
	}
      }
    }
  }

  if (ans.length() < 26) return false;
  return true;
}

int main() {
  cin >> n;
  for (int i=0;i<n;i++) {
    cin >> s[i];
  }

  for (int i=0;i<n-1;i++) {
    bool flag = false;
    if (s[i][0] == s[i+1][0]) {
      int l1 = s[i].length(); int l2 = s[i+1].length();
      for (int j=1;j<l1 && j<l2;j++) {
	if (s[i][j] != s[i+1][j]) {
	  flag = true;
	  w[s[i][j]-'a'+1][s[i+1][j]-'a'+1] = 1;
	  break;
	}
      }

      if (!flag && l1 > l2) {
	cout << "Impossible" << endl;
	return 0;
      }
    } else {
      w[s[i][0]-'a'+1][s[i+1][0]-'a'+1] = 1;
    }
  }

  if (topo_sort()) cout << ans << endl;
  else cout << "Impossible" << endl;
  
  return 0;
}
