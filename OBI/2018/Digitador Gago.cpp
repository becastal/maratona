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

    string s;
    while (getline(cin, s)) {
        string res = "";
        for (int i = 0; i < (int)s.size(); i++) {
            if (s[i] != ' ') {
                res.push_back(s[i]);
                continue;
            }

            if (i + 4 < (int)s.size() && string(1, s[i + 1]) + s[i + 2] == string(1, s[i + 3]) + s[i + 4]) {
                res += " " + string(1, s[i + 1]) + s[i + 2];
                i += 4;
            } else {
                res.push_back(' ');
            }
        }
        cout << res << endl;
    }

    return 0;
}

