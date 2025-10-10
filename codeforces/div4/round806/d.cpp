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

int main()
{
    _;

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		set<string> S;
		vector<string> v(n);
		for (auto& i : v) cin >> i, S.emplace(i);

		for (int ii = 0; ii < n; ii++) {
			int ok = 0;
			auto s = v[ii];
			for (int i = 0; i < (int)s.size() and !ok; i++) {
				ok |= (S.count(s.substr(0, i)) and S.count(s.substr(i)));
			}
			cout << ok;
		}
		cout << endl;

	}
    
    return(0);
}
