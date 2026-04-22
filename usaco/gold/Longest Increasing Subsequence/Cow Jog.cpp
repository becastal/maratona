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
	vector<int> A;

	Bit (int n_) : n(n_), A(n + 1) {}
	void update(int i, int x) {
		for (i++; i <= n; i+=i&-i) {
			A[i] = max(A[i], x);
		}
	}
	int pref(int i) {
		int res = 0;
		for (i++; i; i-=i&-i) {
			res = max(res, A[i]);
		}
		return res;
	}
};

int solve() {
	int n, t; cin >> n >> t;

	vector<array<int, 2>> A(n);
	vector<int> P(n), B(n);

	for (int i = 0; i < n; i++) {
		auto &[p, v] = A[i];
		cin >> p >> v;
		P[i] = B[i] = p + v * t;
		// cerr << "P[i]: " << P[i] << endl;
	}
	sort(all(B));

	Bit bit(n + 1);
	for (int& i : P) {
		i = lower_bound(all(B), i) - B.begin();
		i = n - i - 1;
		// cerr << "i: " << i << endl;
		bit.update(i, bit.pref(i) + 1);	
	}
	cout << bit.pref(n) << endl;

	return(0);
}


void setIO(string nome) {
	if (nome == "") return;
	freopen((nome + ".in").c_str(), "r", stdin);
	freopen((nome + ".out").c_str(), "w", stdout);
}

signed main()
{
    _;
	setIO("cowjog");

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

