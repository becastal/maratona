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
    int n, m, k; cin >> n >> m >> k;
	int w; cin >> w;
    vector<int> v(w);
    for (int& i : v) cin >> i;
    sort(v.rbegin(), v.rend());
    
    vector<vector<ll>> cont(n + 1, vector<ll>(m + 1, 0));
    for (int i = 0; i + k <= n; i++) {
        for (int j = 0; j + k <= m; j++) {
            cont[i][j]++;
            cont[i + k][j]--;
            cont[i][j + k]--;
            cont[i + k][j + k]++;
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i > 0) cont[i][j] += cont[i - 1][j];
            if (j > 0) cont[i][j] += cont[i][j - 1];
            if (i > 0 && j > 0) cont[i][j] -= cont[i - 1][j - 1];
        }
    }

    priority_queue<ll> pq;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            pq.push(cont[i][j]);
			//cout << cont[i][j] << ' ';
        }
		//cout << endl;
    }

    ll res = 0;
	for (int i : v) {
		res += (ll)i * (ll)pq.top();
		pq.pop();
	}
    
    cout << res << endl;
}

int main() {
    _;

    int t; cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
