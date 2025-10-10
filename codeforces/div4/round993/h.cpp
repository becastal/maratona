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
	int n, q; cin >> n >> q;
	vector v(n, vector<int>(n));
	for (auto& l : v) for (auto& c : l) cin >> c;

	vector f1(n+1, vector<ll>(n+1, 0)), fr(n+1, vector<ll>(n+1, 0)), fc(n+1, vector<ll>(n+1, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			f1[i+1][j+1] = f1[i+1][j] + f1[i][j+1] - f1[i][j] + v[i][j];
			fr[i+1][j+1] = fr[i+1][j] + fr[i][j+1] - fr[i][j] + v[i][j] * i;
			fc[i+1][j+1] = fc[i+1][j] + fc[i][j+1] - fc[i][j] + v[i][j] * j;
		}
	}

	while (q--) {
		int i1, j1, i2, j2;
		cin >> i1 >> j1 >> i2 >> j2;
		i1--; j1--;
		int w = j2 - j1;
		ll sum_1 = f1[i2][j2] - f1[i1][j2] - f1[i2][j1] + f1[i1][j1];
		ll sum_r = fr[i2][j2] - fr[i1][j2] - fr[i2][j1] + fr[i1][j1];
		ll sum_c = fc[i2][j2] - fc[i1][j2] - fc[i2][j1] + fc[i1][j1];
		cout << sum_r * w + sum_c + sum_1 * (-i1 * w - j1 + 1) << ' ';
	}
	cout << endl;
}

int main()
{
    _;

	int t; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
