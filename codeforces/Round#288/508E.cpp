#include <iostream>
#include <string>
#include <stack>
using namespace std;
int n;
int le[666], ri[666], p[666], cur_len[666];
string ans = "";
int main() {
    cin >> n;
    stack<int> mystack;
    for (int i = 0; i < n; i++) {
        cin >> le[i] >> ri[i];
        mystack.push(i);
        ans += "(";
        cur_len[i] = ans.length();
        while (!mystack.empty() && cur_len[mystack.top()] + le[mystack.top()] <= ans.length() + 1) {
            if (cur_len[mystack.top()] + ri[mystack.top()] <= ans.length()) {
                cout << "IMPOSSIBLE" << endl;
                return 0;
            }
            else {
                ans += ")";
                mystack.pop();
            }
        }
    }
    if (mystack.empty()) {
        cout << ans << endl;
    }
    else {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    return 0;
}