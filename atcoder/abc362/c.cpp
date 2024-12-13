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
	vector<pair<ll, ll>> v(n);
	for (auto& [i, j] : v) cin >> i >> j;

	ll menor = v[0].f, maior = v[0].s;
	for (int i = 1; i < n; i++) {
		menor = menor + v[i].f;
		maior = maior + v[i].s;
	}
	if (menor > 0 or maior < 0) return cout << "No" << endl, 0;
	cout << "Yes" << endl;

	ll L = 0;
	for (int i = 0; i < n; i++) {
		L += v[i].f;
	}

	for (int i = 0; i < n; i++) {
		ll d = min((ll)v[i].s - v[i].f, -L);
		L += d;
		v[i].f += d;
	}

	for (auto& [i, j] : v) cout << i << ' '; cout << endl;
    
    return(0);
}
