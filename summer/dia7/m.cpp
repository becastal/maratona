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

struct pt { // ponto
	int x, y;
	char z;
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
		return in >> p.x >> p.y >> p.z;
	}
};

ll sarea2(pt p, pt q, pt r) { // 2 * area com sinal
	return (q-p)^(r-q);
}

bool col(pt p, pt q, pt r) { // se p, q e r sao colin.
	return sarea2(p, q, r) == 0;
}

int main()
{
    _;

	int n; cin >> n;
	vector<pt> v(n);

	set<char> S;
	for (auto& p : v) cin >> p, S.emplace(p.z);

	if (S.size() == n) return cout << 1 << endl, 0;
	
	int tudo_col = 1;

	for (int i = 0; i < n and tudo_col; i++) {
		for (int j = i+1; j < n and tudo_col; j++) {
			for (int k = j+1; k < n and tudo_col; k++) {
				tudo_col &= col(v[i], v[j], v[k]);
			}
		}
	}

	if (tudo_col) return cout << 2 << endl, 0;

	cout << "Infinity" << endl;
    
    return(0);
}
