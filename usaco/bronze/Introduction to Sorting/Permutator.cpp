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
	for (int i = 0; i < n; i++) {
		cin >> a[i]; 
		a[i] = (ll)(i + 1) * (n - i) * a[i];
	}

	vector<ll> b(n);
	for (ll& i : b) cin >> i;	


	sort(a.begin(), a.end());
	sort(b.rbegin(), b.rend());
	ll res = 0;
	for (int i = 0; i < n; i++) {
		res += a[i] * b[i];
	}
	cout << res << endl;

    return(0);
}
