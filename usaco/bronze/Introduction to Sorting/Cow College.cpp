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
	vector<ll> a(n);
	for (ll& i : a) cin >> i;

	sort(a.rbegin(), a.rend());

	ll res = 0, tut = INF;
	for (int i = 0; i < n; i++) {
		ll agr = a[i] * (i + 1);

		if (agr > res) {
			res = agr;
			tut = a[i];
		} else if (agr == res) {
			tut = a[i];
		}
	}
	cout << res << ' ' << tut << endl;

    return(0);
}
