#include <iostream>
#include <vector>
#include <stdio.h>
#include <queue>
#include <utility>
#include <functional>

using namespace std;
const int INF = 100000000;
int dis[5001];
int dis2[5001];
int n, r;

struct edge {
	int to, cost;
};

vector<edge> Graph[5001];
typedef pair<int, int> P;

void heap_dijkstra() {
	priority_queue<P, vector<P>, greater<P> > q;
	dis[1] = 0;
	q.push(P(0, 1));
	while (!q.empty()) {
		P p = q.top(); q.pop();
		int tmp_dis = p.first;
		int u = p.second;
		if (tmp_dis > dis2[u]) continue;
		for (int i = 0; i < Graph[u].size(); i++) {
			edge &e = Graph[u][i];
			int d = tmp_dis + e.cost;
			if (dis[e.to] > d) {
				dis2[e.to] = dis[e.to];
				dis[e.to] = d;
				q.push(P(dis[e.to], e.to));
			} else if (dis2[e.to] > d && d > dis[e.to]) {
				dis2[e.to] = d;
				q.push(P(dis2[e.to], e.to));
			}
		}
	}

}

int main() {
	cin >> n >> r;
	for (int i = 0; i < r; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		edge tmp;
		tmp.cost = c;
		tmp.to = b;
		Graph[a].push_back(tmp);
		edge tmp2;
		tmp2.cost = c;
		tmp2.to = a;
		Graph[b].push_back(tmp2);
	}
	for (int i = 1; i <= n; i++) {
		dis[i] = INF;
		dis2[i] = INF;
	}
	heap_dijkstra();
	cout << dis2[n] << endl;
	return 0;
}
