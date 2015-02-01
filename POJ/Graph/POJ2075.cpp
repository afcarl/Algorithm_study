#include <stdio.h>
#include <iostream>
#include <map>
#include <iomanip>
#include <string>
const int INF = 100000000;
int n,m;
double min_cost[500];
bool vis[500];
double w[500][500];
using namespace std;

double prim() {
  double res = 0;
  for (int i=0;i<n;i++) {
    min_cost[i] = INF;
    vis[i] = 0;
  } 
  min_cost[0] = 0;
  while (true) {
    //cout << "1" << endl;
    int v = -1;
    for (int u=0;u<n;u++) {
      if (!vis[u] && (v == -1 || min_cost[u] < min_cost[v])) v = u;
    }
    if (v == -1) break;
    vis[v] = 1;
    res += min_cost[v];
    //cout << res << endl;
    for (int u=0;u<n;u++) {
      min_cost[u] = min_cost[u] < w[v][u] ? min_cost[u] : w[v][u];
    }
  }
  return res;
}

int main() {
  double amount;
  map<string,int> mymap;
  cin >> amount;
  cin >> n;
  for (int i=0;i<n;i++) {
    string s; cin >> s;
    mymap.insert(make_pair(s,i));
  }

  for (int i=0;i<n;i++) {
    for (int j=0;j<n;j++) {
      w[i][j] = INF;
    }
  }

  cin >> m;

  for (int i=0;i<m;i++) {
    string s1,s2; double t;
    cin >> s1 >> s2 >> t;
    w[mymap[s1]][mymap[s2]] = t;
    w[mymap[s2]][mymap[s1]] = t;
  }
  
  double res = prim();
  if (res <= amount) {
    cout << "Need " << fixed << setprecision(1) << res << " miles of cable" << endl;
  } else {
    cout << "Not enough cable" << endl;
  }
  return 0;
}
