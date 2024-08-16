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

template<typename T> vector<int> pi(T s) {
	vector<int> p(s.size());
	for (int i = 1, j = 0; i < s.size(); i++) {
		while (j and s[j] != s[i]) j = p[j-1];
		if (s[j] == s[i]) j++;
		p[i] = j;
	}
	return p;
}

template<typename T> vector<int> matching(T& s, T& t) {
	vector<int> p = pi(s), match;
	for (int i = 0, j = 0; i < t.size(); i++) {
		while (j and s[j] != t[i]) j = p[j-1];
		if (s[j] == t[i]) j++;
		if (j == s.size()) match.push_back(i-j+1), j = p[j-1];
	}
	return match;
}

int main()
{
    _;

	int n, w; cin >> n >> w;
	vector<int> a(n), b(w);
	for (int& i : a) cin >> i;
	for (int& i : b) cin >> i;
	if (w == 1) return cout << n << endl, 0;

	vector<int> da, db;
	for (int i = 1; i < n; i++) {
		da.push_back(a[i] - a[i-1]);
	}
	for (int i = 1; i < w; i++) {
		db.push_back(b[i] - b[i-1]);
	}

	auto res = matching(db, da);	
	cout << res.size() << endl;
    
    return(0);
}
