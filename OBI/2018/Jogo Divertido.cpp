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
	// o numero tem que ser par e !(%3);
	// a parte do par eh gulosa, depois mais trampo
	string s; cin >> s;

	int r = (int)s.size() - 1, res = 0;
	while (r >= 0 and s[r] - '0' & 1) {
		r--;
		res++;
	}
	if (r < 0) return cout << "Cilada" << endl, 0;

	int soma = 0;
	for (char c : s) {
		soma += c - '0';
		soma %= 3;
	}

	if (!soma) return cout << res << endl, 0;

	vector<int> tp = {1, 2};
	for (int k = 0; k <= 1; k++) {
		// achar o numero que eh mod 3 == 1 e tem a menor quantidade de 0s consecutivos depois;
		set<int> esc;
		for (int i = 0; i < r; i++) {
			if ((s[i] - '0') % 3 == tp[k]) {
				int ii = 1, j = i;
				while (j + 1 < r and s[j + 1] == '0') {
					ii++, j++;
				}
				esc.insert(ii);
			}
		}
		if (!esc.empty()) {
			return cout << res + *esc.begin() << endl, 0;
		}

		// agora achar dois em que mod 3 == 2 e que tenham a menor qs de 0s cons;
		for (int i = 0; i < r; i++) {
			if ((s[i] - '0') % 3 == tp[k^1]) {
				int ii = 1, j = i;
				while (j + 1 < r and s[j + 1] == '0') {
					ii++, j++;
				}
				esc.insert(ii);
			}
		}
		if (esc.size() >= 2) {
			auto it = esc.begin(); it++;
			return cout << res + *esc.begin() + *it << endl, 0;
		}
	}

	return 0;
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
