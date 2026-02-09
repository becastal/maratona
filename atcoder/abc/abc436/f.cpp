#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

struct Bit {
	int n;
	vector<int> F;
	
	Bit(int n_) : n(n_), F(n_+1, 0) {};
	void update(int i, int x) {
		for (i++; i <= n; i+=i&-i) F[i]++;
	};
	int pref(int i) {
		int res = 0;
		for (i++; i; i-=i&-i) res += F[i];
		return res;
	}
};

int solve() {
	int n; cin >> n;
	vector<int> P(n), P_(n), foi(n, 0);

	for (int i = 0; i < n; i++) {
		cin >> P[i]; P[i]--;
		P_[P[i]] = i;
	}

	Bit bit(n);
	ll res = 0;
	for (int i = 0; i < n; i++) {
		int p = P_[i];
		int a = bit.pref(p - 1), b = i - a;
		bit.update(p, +1);
		res += 1LL * (a + 1) * (b + 1);
	}
	cout << res << endl;

	return(0);
}

int main()
{
    _;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

