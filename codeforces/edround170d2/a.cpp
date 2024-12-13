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

void solve() {
    string s, t;
    cin >> s >> t;

	int i = 0;
	while (i < (int)s.size() and i < (int)t.size() and s[i] == t[i]) i++;
    cout << (int)s.size() + (int)t.size() - max(i-1, 0) << endl;
}

int main() {
    _;

    int t; 
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}

