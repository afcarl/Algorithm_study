#include <stdio.h>
#include <iostream>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <iomanip>
using namespace std;

struct edge {
  int from,to;
};

const int INF = 100000000;
double w[505][505];
edge e[505];
double res[505];
bool vis[505];
double min_tree[505];
int test,s,p,x,y;

double dis(int x1,int x2,int y1,int y2) {
  return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

void prim() {
  for (int i=0;i<p;i++) {
    vis[i] = false;
    min_tree[i] = INF;
  }
  min_tree[0] = 0;
  int t = 0;
  while (true) {
    int v = -1;
    for (int u=0;u<p;u++) {
      if (!vis[u] && (v == -1 || min_tree[u] < min_tree[v])) v = u;
    }
    if (v == -1) break;
    vis[v] = 1;
    res[t] = min_tree[v];
    t++;
    for (int u=0;u<p;u++) {
      min_tree[u] = min_tree[u] < w[v][u] ? min_tree[u] : w[v][u];
    }
  }
}

bool cmp (double a,double b) {
  return a > b;
}

int main() {
  scanf("%d",&test);
  while (test--) {
    memset(w,0,sizeof(w));
    memset(e,0,sizeof(e));
    memset(min_tree,0,sizeof(min_tree));
    memset(res,0,sizeof(res));
    memset(vis,0,sizeof(vis));
    scanf("%d%d",&s,&p);

    for (int i=0;i<p;i++) {
      scanf("%d%d",&x,&y);
      e[i].from = x;
      e[i].to = y;
    }

    for (int i=0;i<p;i++) {
      for (int j=0;j<p;j++) {
	w[i][j] = dis(e[i].from,e[j].from,e[i].to,e[j].to);
      }
    }
    prim();
    sort(res,res+p,cmp);
    //for (int i=0;i<p;i++) {
    //  cout << res[i] << " ";
    //}
    cout << fixed;
    cout << setprecision(2) << res[s-1] << endl;
  }

  return 0;
}
