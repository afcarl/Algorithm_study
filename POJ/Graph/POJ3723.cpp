#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

const int INF = 100000000;
int parent[20005];
int rank[20005];
//////////////////////////////////////////////////////////////////////////
// union_find_set
void init_union_find(int n) {
  for (int i=0;i<n;i++) {
    parent[i] = i;
    rank[i] = 0;
  }
}

int find(int x) {
  if (parent[x] == x) {
    return x;
  }
  else {
    parent[x] = find(parent[x]);
    return parent[x];
  }
}

void unite(int x, int y) {
  x = find(x);
  y = find(y);
  if (x == y) {
    return;
  } else {
    if (rank[x] < rank[y]) {
      parent[x] = y;
    } else {
      parent[y] = x;
      if (rank[x] == rank[y]) rank[x]++;
    }
  }
}

bool same(int x, int y) {
  return find(x) == find(y);
}
//////////////////////////////////////////////////////////////////////////
struct edge {
  int from,to,cost;
};
int n,m,r,test;

bool cmp (const edge& e1,const edge& e2) {
  return e1.cost < e2.cost;
}

edge e[50005];

int krustra () {
  sort(e,e+r,cmp);
  init_union_find(n+m);
  int res = 0;
  for (int i=0;i<r;i++) {
    edge tmp = e[i];
    if (!same(tmp.from,tmp.to)) {
      unite(tmp.from,tmp.to);
      res += tmp.cost;
    }
  }
  return res;
}

int main () {
  cin >> test; 
  while (test--) {
    cin >> n >> m >> r;
    for (int i=0;i<r;i++) {
      int a,b,c;
      scanf("%d%d%d",&a,&b,&c);
      e[i].from = a;
      e[i].to = n+b;
      e[i].cost = -c;
    }
    cout << 10000*(n+m)+krustra() << endl;
  }
  return 0;
}
