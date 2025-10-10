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

void setIO(string nome) {
	if (nome == "") return;
	freopen((nome + ".in").c_str(), "r", stdin);
	freopen((nome + ".out").c_str(), "w", stdout);
}

int main()
{
    _;
	setIO("");

	int n; cin >> n;
	vector<int> a(n), b(n);
	for (int& i : a) cin >> i;
	for (int& i : b) cin >> i;

	sort(a.rbegin(), a.rend());
	sort(b.begin(), b.end());

	ll res = 1;
	for (int l = 0; l < n; l++) {
		auto it = lower_bound(b.begin(), b.begin() + (n - l), a[l]);
		ll tam = (b.begin() + (n - l)) - it;

		if (tam <= 0) return cout << 0 << endl, 0;
		res *= tam;
	}
	cout << res << endl;

    return(0);
}
