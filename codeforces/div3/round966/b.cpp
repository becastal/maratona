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
	int n; cin >> n;
	bitset<(int)2e5 + 10> bs;
	vector<int> v(n);
	for (int& i : v) cin >> i, i--;
	bool tudo = 1;
	for (int i = 0; i < n and tudo; i++) {
		bool certo = 1;
		int x = v[i];
		if (i) {
			if (x >= 1 and x < n - 1) certo &= bs[x - 1] | bs[x + 1];
			else if (x < n - 1) certo &= bs[x + 1];
			else if (x >= 1) certo &= bs[x - 1];
		}
		bs[x] = 1;
		tudo &= certo;
	}
	cout << (tudo ? "yes" : "no") << endl;
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
