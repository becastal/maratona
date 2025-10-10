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

struct frac {
	int num, den;
	template<class U, class V>
	frac(U num_ = 0, V den_ = 1) : num(num_), den(den_) {
		assert(den != 0);
		if (den < 0) num *= -1, den *= -1;
		int g = gcd(abs(num), den);
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
	string s; getline(cin, s);
	int n;
	n = stoi(s);

	getline(cin, s);
	int m = count(s.begin(), s.end(), ' ') / 2 + 1;

	stringstream ss(s); 
	vector<frac> a;
	vector<char> op;
	for (int i = 0; i < m-1; i++) {
		int a_, b_; char c;
		ss >> a_ >> c >> b_ >> c;
		a.push_back(frac(a_, b_));
		op.push_back(c);
	}
	int a_, b_; char c;
	ss >> a_ >> c >> b_;
	a.push_back(frac(a_, b_));
	

	while (count(op.begin(), op.end(), '*') + count(op.begin(), op.end(), '/')) {
		for (int i = 0; i < op.size(); i++) {
			if (op[i] == '+' or op[i] == '-') continue;

			if (op[i] == '*') a[i] = a[i] * a[i+1];
			else a[i] = a[i] / a[i+1];

			op.erase(op.begin() + i);	
			a.erase(a.begin() + i + 1);
			break;
		}
	}

	frac res = a[0];

	for (int i = 0; i < (int)op.size(); i++) {
		if (op[i] == '-') res = res - a[i+1];
		else res = res + a[i+1];
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
