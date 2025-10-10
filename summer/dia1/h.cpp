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

	vector<multiset<ll>> v(30);
	vector<ll> cont(30, 0);
	int t, n = 0; cin >> t;
	for (int i = 0, x; i < t; i++) {
		char c; cin >> c >> x;
		int l = log2(x);
		
		if (c == '+') {
			n++;

			v[l].insert(x);
			cont[l] += x;
		} else {
			n--;

			v[l].erase(v[l].find(x));
			cont[l] -= x;
		}

		ll k = 0, s = 0;
		for (int i = 0; i < 30; i++) {
			if (v[i].empty()) continue;

			k += (*v[i].begin() > 2*s);
			s += cont[i];
		}
		cout << n - k << endl;
	}
    
    return(0);
}
