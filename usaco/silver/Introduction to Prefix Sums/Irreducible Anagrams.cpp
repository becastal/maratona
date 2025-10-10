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

void setIO(string nome) {
	if (nome == "") return;
	freopen((nome + ".in").c_str(), "r", stdin);
	freopen((nome + ".out").c_str(), "w", stdout);
}

int main()
{
    _;
	setIO("");

	string s; cin >> s;
	int n = (int)s.size();

	vector<vector<int>> pre(n+1, vector<int>(26, 0));
	for (int i = 1; i <= n; i++) {
		pre[i] = pre[i-1];	
		pre[i][s[i-1]-'a']++;
	}

	int q; cin >> q;
	while (q--) {
		int l, r; cin >> l >> r;

		if (l == r) {
			cout << "Yes" << endl;
			continue;
		}

		vector<int> qi(26, 0);
		int agr = 0;
		for (int i = 0; i < 26; i++) {
			qi[i] = pre[r][i] - pre[l-1][i];
			if (qi[i]) agr |= (1 << i);
		}
		//for (int i : qi) cout << i << ' '; cout << endl;

		cout << (__builtin_popcount(agr) >= 3 or s[r-1] != s[l-1] ? "Yes" : "No") << endl;
	}

    return(0);
}
