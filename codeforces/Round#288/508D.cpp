#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> Graph[66666];
string res;
int n;
int start;
int out[66666], in[66666], cnt[66666];

void dfs(int i) {
    while (cnt[i] < Graph[i].size()) {
        dfs(Graph[i][cnt[i]++]);
    }
    res += (char)i % 256;
}

void init() {
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int u = s[0] * 256 + s[1];
        start = u;
        int v = s[1] * 256 + s[2];
        Graph[u].push_back(v);
        out[u]++; in[v]++;
    }
}


int main() {
    cin >> n;
    init();
    int l = 0, r = 0;
    for (int i = 0; i < 66666; i++) {
        int d = out[i] - in[i];
        if (d == 1) {
            l++;
            start = i;
        }
        else if (d == -1) {
            r++;
        }
        else if (d != 0) {
            cout << "NO" << endl;
            return 0;
        }
        if (l > 1 || r > 1) {
            cout << "NO" << endl;
            return 0;
        }
    }
    dfs(start);
    res += (char)(start / 256);
    if (res.size() != n + 2) {
        cout << "NO" << endl;
    }
    else {
        cout << "YES" << endl;
        reverse(res.begin(), res.end());
        cout << res << endl;
    }
    return 0;
}