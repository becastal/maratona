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
		i = max(0, i), i = min(n-1, i);
		for (++i; i <= n; i+=i&-i) F[i] += x;
	}
	int pref(int i) {
		i = max(0, i), i = min(n-1, i);
		int res = 0;
		for (++i; i; i-=i&-i) res += F[i];
		return res;
	}
	int query(int l, int r) {
		l = max(0, l), r = min(n-1, r);
		return pref(r) - pref(l-1);
	}
};

int solve() {
	int n, q; cin >> n >> q;
	vector<int> A(n);

	for (int& i : A) cin >> i;

	
	stack<int> S;
	vector<int> L(n), R(n);
	for (int i = 0; i < n; i++) {
		while (S.size() and A[S.top()] < A[i]) S.pop();	
		L[i] = (S.size() ? S.top() : -1) + 1;
		S.push(i);
	}

	while (S.size()) S.pop();	
	for (int i = n-1; i >= 0; i--) {
		while (S.size() and A[S.top()] > A[i]) S.pop();
		R[i] = (S.size() ? S.top() : n) + 1;
		S.push(i);
	}

	vector<array<int, 4>> E(q + n);
	for (int i = 0, l, r; i < q; i++) {
		cin >> l >> r;
		E[i] = {r, -l, 1, i};
	}

	for (int i = 0; i < n; i++) {
		//printf("(%d, %d)\n", L[i], R[i]);
		E[q + i] = {R[i], -L[i], 0, i};
	}

	Bit bit(n+2);
	vector<int> Re(q);
	sort(all(E));
	for (auto [r, l, tp, id] : E) {
		l = -l;

		if (tp == 0) {
			bit.update(l, +1);
		} else {
			Re[id] = bit.query(l, n);
		}
	}

	for (int i = 0; i < q; i++) {
		cout << (Re[i] ? "NO" : "YES") << endl;
	}

	return(0);
}

int main()
{
    _;

	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

