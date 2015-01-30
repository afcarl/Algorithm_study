#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string s;

int main() {
    cin >> s;
    int num_1 = -1;
    int tmp = -1;
    for (int i = 0; i < s.size(); i++) {

        if ((s[i] - '0') % 2 == 0 && num_1 == -1 && s[s.size()-1]-'0' >= s[i]-'0') {
            num_1 = i;
            break;
        }
        else if ((s[i] - '0') % 2 == 0 && num_1 == -1){
            temp = i;
        }
        
    }
    
    if (num_1 == -1) {
        if (temp == -1) {
            cout << "-1" << endl;
        }
        else num_1 = temp;
    }
    
    if (num_1 != -1) {
        swap(s[num_1], s[s.size() - 1]);
        cout << s << endl;
    }
    return 0;
}
