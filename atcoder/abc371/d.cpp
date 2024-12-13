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

	int n; cin >> n;
	vector<pair<int, int>> eixo;
	vector<int> X(n), P(n);

	for (int& i : X) cin >> i;
	for (int& i : P) cin >> i;

	for (int i = 0; i < n; i++) {
		eixo.emplace_back(X[i], P[i]);
	}

	sort(eixo.begin(), eixo.end());
	vector<ll> pref(n + 1, 0);	
	for (int i = 1; i <= n; i++) {
		pref[i] = pref[i-1] + eixo[i-1].s;
	}

	int q; cin >> q;
	for (int i = 0, l, r; i < q; i++) {
		cin >> l >> r;

		int li = lower_bound(eixo.begin(), eixo.end(), pair<int, int>(l, -INF)) - eixo.begin();
		int ri = upper_bound(eixo.begin(), eixo.end(), pair<int, int>(r, INF)) - eixo.begin();

		cout << pref[ri] - (li >= 0 ? pref[li] : 0) << endl;
	}
    
    return 0;
}

