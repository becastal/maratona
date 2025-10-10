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
		for (++i; i <= n; i+=i&-i) F[i]+=x;	
	};
	int pref(int i) {
		int res = 0;
		for (++i; i; i-=i&-i) res += F[i];
		return res;
	};
	int query(int l, int r) {
		return pref(r) - pref(l-1);
	}
};

const int MAX = 1e6+10;
int ult[MAX];

int solve() {
	int n; cin >> n;
	vector<int> A(n);
	for (int& i : A) cin >> i;

	int q; cin >> q;
	vector<int> res(q);

	vector<array<int, 2>> Q(q);
	vector<vector<int>> B(n);
	for (int i = 0, l, r; i < q; i++) {
		cin >> l >> r; l--, r--;
		B[r].push_back(i);
		Q[i] = {l, r};
	}
	
	Bit bit(n);
	memset(ult, -1, sizeof(ult));
	for (int i = 0; i < n; i++) {
		if (ult[A[i]] != -1) {
			bit.update(ult[A[i]], -1);
		}
		bit.update(ult[A[i]] = i, +1);
		for (int id : B[i]) {
			auto [l, r] = Q[id];
			res[id] = bit.query(l, r);	
		}
	}
	for (int i : res) cout << i << endl;

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

