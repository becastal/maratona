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

	const int n = 1e6 + 10;
	ll s[n];
	s[1] = 1;
	for (int i = 2; i < n; i++) s[i] = s[i-1] + i;
	//cout << s[n-1] - s[1] << endl;

	ll d; cin >> d;
	map<ll, ll> m;

	vector<pair<ll, ll>> res;
	for (int i = n-1; i >= 1; i--) {
		if (m.count(d+s[i]) and i < m[d+s[i]]) {
			//cout << i << ' ' << m[d+s[i]] << endl;
			res.emplace_back(i, m[d+s[i]]);
		}
		m[s[i]] = i;
	}

	cout << (int)res.size() << endl;
	for (auto [a, b] : res) cout << a << ' ' << b << endl;
    
    return(0);
}
