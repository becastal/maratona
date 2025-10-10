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

	int n, q; cin >> n >> q;
	vector<int> v(n), diff(n+1, 0);
	for (int& i : v) cin >> i;

	for (int i = 0, l, r; i < q; i++) {
		cin >> l >> r; l--, r--;
		diff[l]++, diff[r+1]--;	
	}
	for (int i = 1; i <= n; i++) {
		diff[i] += diff[i-1];
	}

	sort(v.rbegin(), v.rend());
	sort(diff.rbegin(), diff.rend());

	ll res = 0;
	for (int i = 0; i < n; i++) {
		res += (ll)v[i] * diff[i];
	}
	cout << res << endl;

    return(0);
}
