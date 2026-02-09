#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

#define sq(x) ((x)*(ll)(x))
struct pt { // ponto
	int x, y;
	pt(int x_ = 0, int y_ = 0) : x(x_), y(y_) {}
	bool operator < (const pt p) const {
		if (x != p.x) return x < p.x;
		return y < p.y;
	}
	bool operator == (const pt p) const {
		return x == p.x and y == p.y;
	}
	pt operator + (const pt p) const { return pt(x+p.x, y+p.y); }
	pt operator - (const pt p) const { return pt(x-p.x, y-p.y); }
	pt operator * (const int c) const { return pt(x*c, y*c); }
	ll operator * (const pt p) const { return x*(ll)p.x + y*(ll)p.y; }
	ll operator ^ (const pt p) const { return x*(ll)p.y - y*(ll)p.x; }
	friend istream& operator >> (istream& in, pt& p) {
		return in >> p.x >> p.y;
	}
};

ll sarea2(pt p, pt q, pt r) { // 2 * area com sinal
	return (q-p)^(r-q);
}

int ccw(pt p, pt q, pt r) {
    ll area = sarea2(p, q, r);
    if (area == 0) return 10000000;
    return 10000000 * (2 + (area > 0));
}

int manhatann(pt a, pt b) {
	return abs(b.x - a.x) + abs(b.y - a.y);
}

const ll pot = 69420;
const ll mod = 1e9+9;

int solve() {
	int n; cin >> n;
	vector<pt> A(n);

	for (auto& [a, b] : A) cin >> a >> b;

	vector<int> B(n);
	for (int i = 0; i < n; i++) {
		int antes = (i - 1 + n) % n;
		int depois = (i + 1) % n;
		pt a = A[antes], b = A[i], c = A[depois];
		B[i] = ccw(a, b, c) + manhatann(b, c);
	}

	vector<ll> Preco(n, LLONG_MAX);

	for (int i = 0; i < n; i++) {

		ll cw_ = 0;
		pt ult = A[i];
		for (int j = i; j != 0; j = (j + 1) % n) { 
			cw_ += manhatann(ult, A[j]);
			ult = A[j];
		}
		cw_ += manhatann(ult, A[0]);

		ll ccw_ = 0;
		ult = A[i];
		for (int j = i; j != 0; j = (j - 1 + n) % n) { 
			ccw_ += manhatann(ult, A[j]);
			ult = A[j];
		}
		ccw_ += manhatann(A[0], ult);

		Preco[i] = min(cw_, ccw_);
	}

	vector<ll> P(2*n+1, 0);
	unordered_map<ll, int> M;
	for (int i = 0; i < n; i++) {
		ll hash = 0;
		for (int j = i; j < i + n; j++) {
			hash = (hash * pot % mod + B[j % n]) % mod;
			M[hash]++;	
		}
	}

	ll res = LLONG_MIN;
	for (int ini = 0; ini < n; ini++) {
		pt ult = A[ini];
		ll hash = 0, d = 0;
		for (int i = 0, p = ini; i < n; i++, p = (p + 1) % n) {
			hash = (hash * pot % mod + B[p]) % mod;
			d += manhatann(ult, A[p]);
			ult = A[p];

			if (M[hash] == 1 or !p) {
				res = max(res, Preco[p] + d - Preco[ini]);
				break;
			}
		}
	}
	cout << res << endl;

	return(0);
}

void setIO(string nome) {
	if (nome == "") return;
	freopen((nome + ".in").c_str(), "r", stdin);
	freopen((nome + ".out").c_str(), "w", stdout);
}

int main() {
    _;
	setIO("lightsout");

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}

    return(0);
}
