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
	setIO("guess");

	int n; cin >> n;
	vector<vector<string>> a(n);

	for (int i = 0; i < n; i++) {
		string ki; cin >> ki;
		int k; cin >> k;
		while (k--) {
			string s; cin >> s;
			a[i].push_back(s);
		}
	}

	int res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			set<string> S;

			int x = 0;
			for (string s : a[i]) S.insert(s);
			for (string s : a[j]) x += S.count(s);

			res = max(res, x + 1);
		}
	}
	cout << res << endl;

    return(0);
}
