#include <iostream>
using namespace std;

int n,m;
bool flag;
char a[55][55];

void dfs(int x, int y, int prex, int prey, char s) {
  if (flag) return;
  vis[x][y] = 1;
  if (x+1 <= n && a[x+1][y] == s && x+1 != prex) {
    if (vis[x+1][y]) flag = 1;
    dfs(x+1,y,x,y,s);
  }

  if (x-1 >= 1 && a[x-1][y] == s && x-1 != prex) {
    if (vis[x-1][y]) flag = 1;
    dfs(x-1,y,x,y,s);
  }

  if (y+1 <= m && a[x][y-1] == s && y-1 != prey) {
    if (vis[x][y-1]) flag = 1;
    dfs(x,y-1,x,y,s);
  }

  if (y-1 >= 1 && a[x][y-1] == s && y-1 != prey) {
    if (vis[x][y-1]) flag = 1;
    dfs(x,y-1,x,y,s);
  }
}

int main() {
  cin >> n >> m;
  for (int i=1;i<=n;i++) {
    for (int j=1;j<=m;j++) {
      char s; cin >> s;
      a[i][j] = s;
    }
  }

  for (int i=1;i<=n;i++) {
    if (flag) break;
    for (int j=1;j<=m;j++) {
      if (flag) break;
      if (!vis[i][j]) dfs(i,j,0,0,a[i][j]);
    }
  }

  if (flag) cout << "Yes" << endl;
  else cout << "No" << endl;
  
  return 0;
}
