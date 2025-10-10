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
	setIO("gymnastics");
	
	int k, n; cin >> k >> n;
	vector<vector<int>> pos(k, vector<int>(n));

	for (int i = 0; i < k; i++) {
		vector<int> p(n);
		for (int j = 0; j < n; j++) {
			cin >> p[j]; p[j]--;
			pos[i][p[j]] = j;
		}
	}

	int res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int ok = 1;

			for (auto p : pos) {
				ok &= p[i] > p[j];
			}

			res += ok;
		}
	}
	cout << res << endl;

    return(0);
}
