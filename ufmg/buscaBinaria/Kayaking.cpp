#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

int solve() {
	int a, b, c; cin >> a >> b >> c;
	int sa, sb, sc; cin >> sa >> sb >> sc;
	int n = (a + b + c) / 2;
	vector<int> C(n);
	for (int& i : C) cin >> i;

	sort(all(C));

	auto da = [&](int v) {
		vector<int> cont = {a, b, c}, val = {sa, sb, sc};

		for (int ci : C) {
			int preciso = (v + ci - 1) / ci, ok = 0;

			for (int i = 0; i < 3 and !ok; i++) {
				for (int j = 0; j < 3 and !ok; j++) {
					if ((i == j ? cont[i] >= 2 : cont[i] and cont[j]) and val[i] + val[j] >= preciso) {
						cont[i]--, cont[j]--;
						ok = 1;
					}
				}
			}

			if (!ok) return 0;
		}
		return 1;
	};

	int l = C[0] * 2 * sa, r = C[n-1] * 2 * sc, res = r;
	while (l <= r) {
		int m = l + (r - l) / 2;
		if (da(m)) {
			l = m+1;
			res = m;
		} else {
			r = m-1;
		}
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
