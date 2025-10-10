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

	int n, m; cin >> n >> m;

	set<string> S;
	map<string, int> val; 
	vector<int> v_cols(m), v_lins(n);
	vector<map<string, int>> cols(m), lins(n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			string s; cin >> s;
			cols[j][s]++;
			lins[i][s]++;
			S.insert(s);
		}
		cin >> v_lins[i];
	}
	for (int& i : v_cols) cin >> i;

	int foi = 0;
	while (foi < S.size()) {
	//for (int kk = 0; kk < 100; kk++) {
		string tira_lin = "";
		for (int i = 0; i < n; i++) {
			if (lins[i].size() != 1) continue;

			foi++;
			val[lins[i].begin()->f] = v_lins[i] / lins[i].begin()->s;
			tira_lin = lins[i].begin()->f;
			lins[i].erase(tira_lin);
			break;
		}

		for (int i = 0; i < n; i++) {
			if (lins[i].count(tira_lin)) {
				v_lins[i] -= val[tira_lin] * lins[i][tira_lin];
				lins[i].erase(tira_lin);
			}
		}
		for (int i = 0; i < m; i++) {
			if (cols[i].count(tira_lin)) {
				v_cols[i] -= val[tira_lin] * cols[i][tira_lin];
				cols[i].erase(tira_lin);
			}
		}

		if (foi == S.size()) break;
		string tira_col = "";
		for (int i = 0; i < m; i++) {
			if (cols[i].size() != 1) continue;

			foi++;
			val[cols[i].begin()->f] = v_cols[i] / cols[i].begin()->s;
			tira_col = cols[i].begin()->f;
			cols[i].erase(tira_col);
			break;
		}

		for (int i = 0; i < n; i++) {
			if (lins[i].count(tira_col)) {
				v_lins[i] -= val[tira_col] * lins[i][tira_col];
				lins[i].erase(tira_col);
			}
		}
		for (int i = 0; i < m; i++) {
			if (cols[i].count(tira_col)) {
				v_cols[i] -= val[tira_col] * cols[i][tira_col];
				cols[i].erase(tira_col);
			}
		}
	}

	for (auto [a, b] : val) {
		cout << a << ' ' << b << endl;
	}
    
    return(0);
}
