#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
//#define int ll

const int MAX = 100010;
namespace sam {
	int len[2*MAX], link[2*MAX], next[2*MAX][26]; 
	int pos[2*MAX], ocor[2*MAX], quant[2*MAX], res[2*MAX];
	int sz, last;
	vector<int> U;

	void init(int reset = 0) {
		if (reset) {
			for (int i = 0; i <= sz; i++) {
				len[i] = 0, link[i] = 0;
				pos[i] = ocor[i] = quant[i] = 0;
				res[i] = INT_MAX;
				for (int j = 0; j < 26; j++) {
					next[i][j] = 0;
				}
			}
		} else for (int i = 0; i < 2*MAX; i++) {
			res[i] = INT_MAX;
		}
		
		len[0] = 0; link[0] = -1;
		sz = 1, last = 0;
	}
	
	void add(int c, int t) {
		int cur = sz++;
		len[cur] = len[last] + 1;
		pos[cur] = t;
		ocor[cur] = 1;

		int p = last;
		while (p != -1 and !next[p][c]) {
			next[p][c] = cur;
			p = link[p];
		}

		if (p == -1) {
			link[cur] = 0;
		} else {
			int q = next[p][c];
			if (len[p] + 1 == len[q]) {
				link[cur] = q;
			} else {
				int clone = sz++;
				pos[clone] = pos[q];
				len[clone] = len[p] + 1;
				link[clone] = link[q];
				for (int i = 0; i < 26; i++) {
					next[clone][i] = next[q][i];
				}

				while (p != -1 and next[p][c] == q) {
					next[p][c] = clone;
					p = link[p];
				}

				link[q] = link[cur] = clone;
			}
		}
		last = cur;
	}

	void ordem() {
		U = vector<int>(sz);
		iota(all(U), 0);
		sort(all(U), [&](int a, int b) { return len[a] > len[b]; });
	}

	void inputa(string& S) {
		vector<int> agr(sz);

		int u = 0, tam = 0;
		for (char c : S) {
			c -= 'a';
			while (u and !next[u][c]) {
				u = link[u];
				tam = len[u];
			}

			if (next[u][c]) {
				u = next[u][c];
				tam++;
			} else {
				u = 0;
				tam = 0;
			}

			agr[u] = max(agr[u], tam);
		}
		
		for (int u_ : U) if (link[u_] != -1) {
			int v = link[u_];
			agr[v] = max(agr[v], min(agr[u_], len[v]));
		}

		for (int i = 0; i < sz; i++) {
			res[i] = min(res[i], agr[i]);
		}
	}

	int calc() {
		int ret = 0;
		for (int i = 0; i < sz; i++) if (res[i] != INT_MAX){ 
			ret = max(ret, res[i]);
		}
		return ret;
	}
};

int solve() {
	vector<string> A;

	string s; 
	while (cin >> s) {
		A.push_back(s);
	}
	int n = (int)A.size();

	sam::init();
	for (int i = 0; i < (int)A[0].size(); i++) {
		sam::add(A[0][i] - 'a', i);
	}
	sam::ordem();

	for (int i = 1; i < n; i++) {
		sam::inputa(A[i]);
	}
	cout << sam::calc() << endl;

	return(0);
}

signed main()
{
    _;

	int t = 1; // cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

