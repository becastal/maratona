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

void solve() {
	int x; cin >> x;

	int ok = 0;
	auto f = [&](auto f, int x) -> void {
		if (x < 0 or ok) return;
		if (!x or x % 33 == 0) {
			ok = 1;
			return;
		}

		if (x != 33) {
			string s = to_string(x);

			for (int i = 1; i < (int)s.size(); i++) {
				if (s[i] == '3' and s[i-1] == '3') {
					s.erase(s.begin()+i-1);
					s.erase(s.begin()+i-1);
					f(f, stoi(s));
				}
			}
		}
	};
	f(f, x);

	cout << (ok ? "YES" : "NO") << endl;
}

int main()
{
    _;

	int t; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
