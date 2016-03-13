#include <iostream>
#include <map>
#include <stdio.h>
using namespace std;
long long a[300001];
int l[300001];
int r[300001];

int main() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	int seg = 0;
	map<int, int> record;
	l[0] = 0;
	for (int i = 0; i < n; ++i) {
		if (record.count(a[i])) {
			r[seg] = i;
			record.clear();
			seg += 1;
			l[seg] = i + 1;
		}
		else {
			record.insert(make_pair(a[i], i));
		}
	}
	if (!record.empty()) {
		r[seg - 1] = n - 1;
	}
	printf("%d\n", seg == 0 ? -1 : seg);
	for (int i = 0; i < seg; ++i) {
		printf("%d %d\n", l[i] + 1, r[i] + 1);
	}
	return 0;
}
