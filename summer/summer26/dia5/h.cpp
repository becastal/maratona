#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

template<typename T = int> struct frac {
	T num, den;
	template<class U, class V>
	frac(U num_ = 0, V den_ = 1) : num(num_), den(den_) {
		assert(den != 0);
		if (den < 0) num *= -1, den *= -1;
		T g = gcd(abs(num), den);
		num /= g, den /= g;
	}

	friend bool operator<(const frac& l, const frac& r) {
		return l.num * r.den < r.num * l.den;
	}
	friend frac operator+(const frac& l, const frac& r) {
		return {l.num*r.den + l.den*r.num, l.den*r.den};
	}
	friend frac operator-(const frac& l, const frac& r) {
		return {l.num*r.den - l.den*r.num, l.den*r.den};
	}
	friend frac operator*(const frac& l, const frac& r) {
		return {l.num*r.num, l.den*r.den};
	}
	friend frac operator/(const frac& l, const frac& r) {
		return {l.num*r.den, l.den*r.num};
	}
	friend ostream& operator<<(ostream& out, frac f) {
		out << f.num << '/' << f.den;
		return out;
	}
};

int solve() {
	int n, m; cin >> n >> m;
	vector<int> A(n), V(m);

	for (auto& i : A) cin >> i;
	for (auto& i : V) cin >> i;

	vector<int> P(n);
	iota(all(P), 0);

	sort(all(P), [&](int a, int b) {
		return A[a] > A[b];	
	});

	vector<vector<int>> R(m);
	vector<int> T(m);
	for (int i : P){

		int pj = -1;
		frac<int> melhor(0, 1);
		for (int j = 0; j < m; j++) {
			frac<int> exp(V[j] * A[i], T[j] + A[i]);
			if (melhor < exp) {
				melhor = exp;
				pj = j;
			}
		}
		
		assert(pj != -1);
		T[pj] += A[i];
		R[pj].push_back(i);
	}

	for (int i = 0; i < m; i++) {
		int nn = (int)R[i].size();
		cout << nn;
		for (int j = 0; j < nn; j++) {
			cout << ' ' << R[i][j] + 1;
		}
		cout << endl;
	}

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

