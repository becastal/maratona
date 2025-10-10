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
	auto pal = [](int a, int b) {
		string s = (a < 10 ? "0" : "") + to_string(a) + (b < 10 ? "0" : "") + to_string(b);

		int ok = 1;
		for (int l = 0, r = (int)s.size()-1; l <= r and ok; l++, r--) {
			ok &= s[l] == s[r];
		}
		//if (ok) cout << s << endl;
		return ok;
	};
	while (t--) {
		char cc;
		int h, m, x, res = 0; cin >> h >> cc >> m >> x;

		set<pair<int, int>> s;

		while (1) {
			res += pal(h, m);
			s.emplace(h, m);

			int total = h * 60 + m + x;
			h = (total / 60) % 24;
			m = total % 60;
			if (s.count({h, m})) break;
		}
		cout << res << endl;
	}
    
    return(0);
}
