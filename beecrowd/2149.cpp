#include <bits/stdc++.h>
using namespace std;
 
int main() {
 
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        int a = 0, res = 0;
        for (char c : s) {
            if (c == '<') {
                a++;
            } else if (c == '>') {
                if (a) res++;
                a--;
            }
        }
        cout << res << "\n";
    }
 
    return 0;
}
