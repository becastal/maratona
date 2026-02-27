#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

struct Bit {
	int n;
	vector<int> F;
	Bit (int n_) : n(n_), F(n_+1) {}
	void update(int i, int x) {
		for (i++; i <= n; i+=i&-i) F[i] += x;
	}
	int pref(int i) {
		int res = 0;
		for (i++; i; i-=i&-i) res += F[i];
		return res;
	}
};

int solve() {
	int n; cin >> n;
	vector<int> P(n), P_(n);

	Bit bit(n);
	for (int i = 0; i < n; i++) {
		cin >> P[i];
		P_[--P[i]] = i;	
		bit.update(i, +1);
	}

	int res = 0;
	for (int i = 0; i < n; i++) {
		int p = P_[i];
		res += bit.pref(p);
		bit.update(p, -1);
	}
	cout << res - n << endl;

	return(0);
}

signed main()
{
    _;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

