#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

struct Bit {
	int n;
	vector<ll> bit;
	Bit(int _n=0) : n(_n), bit(n + 1) {}
	Bit(vector<int>& v) : n((int)v.size()), bit(n + 1) {
		for (int i = 1; i <= n; i++) {
			bit[i] += v[i - 1];
			int j = i + (i & -i);
			if (j <= n) bit[j] += bit[i];
		}
	}
	void update(int i, ll x) { // soma x na posicao i
		for (i++; i <= n; i += i & -i) bit[i] += x;
	}
	ll pref(int i) { // soma [0, i]
		ll ret = 0;
		for (i++; i; i -= i & -i) ret += bit[i];
		return ret;
	}
	ll query(int l, int r) {  // soma [l, r]
		return pref(r) - pref(l - 1); 
	}
	int upper_bound(ll x) {
		int p = 0;
		for (int i = __lg(n); i+1; i--) 
			if (p + (1<<i) <= n and bit[p + (1<<i)] <= x)
				x -= bit[p += (1 << i)];
		return p;
	}
};

int solve() {
	int n; cin >> n;

	vector<int> A(n), B(n);
	for (int &i : A) cin >> i;
	for (int &i : B) cin >> i;

	vector<int> L(n, -1);
	stack<int> S;
	for (int i = 0; i < n; ++i) {
		while (!S.empty() and A[S.top()] < A[i]) S.pop();
		L[i] = S.empty() ? -1 : S.top();
		S.push(i);
	}

	vector<int> P(n, -1);
	vector<int> ordA(n); iota(all(ordA), 0);
	sort(all(ordA), [&](int i, int j){
		return A[i] > A[j];
	});

	vector<int> ordB(n); iota(all(ordB), 0);
	sort(all(ordB), [&](int i, int j){
		return B[i] > B[j];
	});

	Bit bit(n);
	int p = 0;
	for (int qi : ordB) {
		while (p < n and A[ordA[p]] >= B[qi]) {
			bit.update(ordA[p], 1);
			p++;
		}
		int cnt = (qi-1 >= 0 ? (int)bit.pref(qi-1) : 0);
		if (cnt > 0) {
			P[qi] = bit.upper_bound(cnt - 1);
		} else {
			P[qi] = -1;
		}
	}

	ll res = 0;
	for (int i = 0; i < n; ++i) {
		ll r = (ll)(n - i);
		ll a = (B[i] == A[i]) ? (i - L[i]) : 0;
		int t = min(L[i], P[i]) + 1;
		ll b = (t > 0) ? t : 0;
		res += r * (a + b);
	}
	cout << res << endl;

	return(0);
}

int cubo() {
	int n; cin >> n;
	vector<int> A(n), B(n);
	for (int& i : A) cin >> i;
	for (int& i : B) cin >> i;

	vector<vector<array<int, 2>>> Bom(n);

	auto f = [&A, &B, &Bom](int l, int r) {
		vector<int> C(A.begin() + l, A.begin() + r + 1),
					D(B.begin() + l, B.begin() + r + 1);

		int n = r - l + 1;
		vector<int> trav(n, 0), P(n, 0);
		for (int i = 0, mx = INT_MIN; i < n; i++) {
			if (mx < C[i]) {
				mx = C[i];
				trav[i] = 1;	
			}
			P[i] = mx;
		}

		int res = 0;
		for (int i = 0; i < n; i++) {
			if (trav[i] and C[i] == D[i]) res++;
			if (!trav[i] and P[i] >= D[i]) {
				Bom[l + i].push_back({l, r});
				res++;
			}
		}
		return res;
	};

	int res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			res += f(i, j);
		}
	}
	cout << res << endl;

	for (int i = 0; i < n; i++) {
		cout << "~~~~~~~~~~~~~~~~" << endl;
		cout << i << ": (" << B[i] << ") " << endl;
		for (auto [l, r] : Bom[i]) {
			cout << l << ' ' << r << endl;
		}
		cout << endl;
	}

	return(0);
}

int main()
{
    _;

	int t = 1; cin >> t;
	while (t--) {
		//cubo();
		solve();
	}
    
    return(0);
}

