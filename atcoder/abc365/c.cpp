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
	ll m; cin >> m;

	vector<int> v(n); 
	for (int& i : v) cin >> i;

	if (accumulate(v.begin(), v.end(), 0LL) <= m) return cout << "infinite" << endl, 0;

	auto da = [&] (ll mi) {
		ll soma = 0;
		for (int i : v) {
			soma += min((ll)i, mi);
		}
		return soma <= m;
	};

	ll l = 0, r = (ll)2e14 + 10;
	while (l < r) {
		ll m = (l + r) / 2;

		if (da(m)) {
			l = m + 1;	
		} else {
			r = m;
		}
	}

	cout << l-1 << endl;
    
    return(0);
}
