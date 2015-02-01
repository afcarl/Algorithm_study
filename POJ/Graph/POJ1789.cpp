#include <iostream>
#include <stdio.h>
#include <list>
#include <map>
#include <string.h>
#include <string>
#include <algorithm>
using namespace std;
int n; const int INF = 100000000;
int w[2003][2003];
int min_tree[2003];
bool vis[2003];
char ss[2003][10];

int diff(char* s1, char* s2) {
  int res = 0;
  for (int i = 0; i < 7; i++) {
    if (s1[i] != s2[i]) res++;
  }
  return res;
}

int prim() {
  for (int i = 0; i < n; i++) {
    min_tree[i] = w[0][i];
    vis[i] = false;
  }
  min_tree[0] = 0;
  int res = 0;
  
  while (true) {
    int v = -1;
    for (int u = 0; u < n; u++) {
      if (!vis[u] && (v == -1 || (v != -1 && min_tree[u] < min_tree[v]))) v = u;
    }
    if (v == -1) break;
    vis[v] = true;
    res += min_tree[v];
    for (int u = 0; u < n; u++) {
      min_tree[u] = min_tree[u] > w[v][u] ? w[v][u] : min_tree[u];
    }
  }
  return res;
}

int main() {
  while (cin >> n && n) {
    for (int i = 0; i < n; i++) {
      scanf("%s",ss[i]);
    }
    memset(w,0,sizeof(w));
    for (int i = 0; i < n; i++) {
      for (int j = i; j < n; j++) {
	if (w[i][j] != 0) continue;
	w[i][j] = diff(ss[i], ss[j]);
	w[j][i] = w[i][j];
      }
    }
    
    int res = prim();
    
    cout << "The highest possible quality is 1/" << res << "." << endl;
  }
  return 0;
}