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
	vector<vector<int>> ca(m, vector<int>(26, 0)),
						cb(m, vector<int>(26, 0));

	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (int j = 0; j < m; j++) {
			ca[j][s[j]-'A']++;
		}
	}

	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (int j = 0; j < m; j++) {
			cb[j][s[j]-'A']++;
		}
	}

	int res = 0;
	for (int i = 0; i < m; i++) {
		int agr = 1;
        for (char c : {'A','C','G','T'}) {
            agr &= !(ca[i][c - 'A'] > 0 and cb[i][c - 'A'] > 0);
        }
		res += agr;	
    }

	cout << res << endl;

    return(0);
}
