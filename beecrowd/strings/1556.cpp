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
    while (cin >> s) {
        int n = (int)s.size();
        vector<vector<int>> prox(n+1, vector<int>(26, -1));

        for (int i = n-1; i >= 0; i--) {
            prox[i] = prox[i+1];
            prox[i][s[i]-'a'] = i;
        }

        function<void(int, string)> f = [&](int i, string agr) {
            for (int j = 0; j < 26; j++) {
                int p = prox[i][j];
                if (p == -1) continue;

                string nagr = agr + char('a' + j);
                cout << nagr << endl;
                f(p+1, nagr);
            }
        };

        f(0, "");
        cout << endl;
    }
    
    return(0);
}

