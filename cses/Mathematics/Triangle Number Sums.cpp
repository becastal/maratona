#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

const ll MAX = 1e12+10;
vector<ll> T;
int solve() {
	ll n; cin >> n;
	if (binary_search(all(T), n)) return cout << 1 << endl, 0;

	unordered_set<ll> S;
	for (ll i : T) {
		if (i > n) break;
		if (S.count(n - i) or n == 2*i) return cout << 2 << endl, 0;
		S.insert(i);
	}

	cout << 3 << endl;

	return(0);
}

int main()
{
    _;

	ll s = 0;
	for (ll i = 1; s <= MAX; i++) {
		s += i;
		T.push_back(s);
	}

	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

