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
 
int solve() {
	int x, q; cin >> x >> q;
 
	set<pair<int, int>> s = {{0, x}};
	map<int, int> f = {{x, 1}};
 
	auto sz = [](pair<int, int> a) {
		return a.s - a.f;
	};
	while (q--) {
		int pi; cin >> pi;
		auto it = prev(s.lower_bound({pi, 0}));
 
		pair<int, int> a = *it, b(a.f, pi), c(pi, a.s);
 
		s.erase(a);
		s.insert(b);
		s.insert(c);
 
		if (--f[sz(a)] == 0) f.erase(sz(a));
		f[sz(b)]++, f[sz(c)]++;
 
		cout << f.rbegin()->f << endl;
	}
 
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
