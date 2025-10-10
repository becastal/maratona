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

	string t, p; cin >> t >> p;
	int n = (int)t.size(), m = (int)p.size();
	vector<int> v(n);
	for (int& i : v) cin >> i;

	auto da = [&](int x) {
		vector<int> ruim(n, 0);
		for (int i = 0; i < x; i++) {
			ruim[v[i]-1] = 1;
		}

		string T = "";
		for (int i = 0; i < n; i++) {
			if (!ruim[i]) T.push_back(t[i]);
		}

		int ni = (int)T.size();
		vector<vector<int>> prox(ni+1, vector<int>(26, -1));
		for (int i = ni-1; i >= 0; i--) {
			prox[i] = prox[i+1];
			prox[i][T[i]-'a'] = i;
		}

		bool ok = true;
		for (int i = 0, j = 0; i < m; i++) {
			j = prox[j][p[i]-'a'];
			if (j == -1) {
				ok = false;
				break;
			}
			j++;
		}

		return ok;
	};

	int l = 0, r = n;
	while (l < r) {
		int mm = (l + r) / 2;

		if (da(mm)) {
			l = mm+1;
		} else {
			r = mm;
		}
	}

	cout << l-1 << endl;
    
    return(0);
}
