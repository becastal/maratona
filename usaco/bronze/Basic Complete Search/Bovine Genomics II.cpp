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
	setIO("cownomics");

	int n, m; cin >> n >> m;
	vector<string> bom(n), ruim(n);

	for (auto& i : ruim) cin >> i;
	for (auto& i : bom) cin >> i;

	int res = 0;
	for (int i = 0; i < m; i++) {
		for (int j = i + 1; j < m; j++) {
			for (int k = j + 1; k < m; k++) {

				set<string> a;
				for (int ii = 0; ii < n; ii++) {
					string s = "   ";
					s[0] = ruim[ii][i], s[1] = ruim[ii][j], s[2] = ruim[ii][k];
					a.insert(s);
				}

				int ok = 1;
				for (int ii = 0; ii < n; ii++) {
					string s = "   ";
					s[0] = bom[ii][i], s[1] = bom[ii][j], s[2] = bom[ii][k];
					ok &= !a.count(s);
				}
				res += ok;
			}
		}
	}
	cout << res << endl;

    return(0);
}
