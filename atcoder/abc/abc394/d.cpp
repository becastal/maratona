#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

int main()
{
    _;

    string s; cin >> s;
    stack<char> S;
    int ok = 1;
    for (char c : s) {
        if (c == '(' or c == '[' or c == '<') {
            S.push(c);
        } else {
            if (S.empty()) {
                ok = 0;
                break;
            }
            if ((c == ')' and S.top() != '(') ||
                (c == ']' and S.top() != '[') ||
                (c == '>' and S.top() != '<')) {
                ok = 0;
                break;
            }
            S.pop();
        }
    }

    if (!S.empty()) ok = 0;
    cout << (ok ? "Yes" : "No") << endl;
    
    return(0);
}

