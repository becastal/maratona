#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
//#define int ll

const int MAX = 1e6+10;
namespace sam {
	int len[2*MAX], link[2*MAX], next[2*MAX][26];
	int ocur[2*MAX], pos[2*MAX];
	int sz, last;

	void init() {
		len[0] = 0; link[0] = -1;
		sz = 1, last = 0;
	}

	void add(int c, int t) {
		int cur = sz++;
		len[cur] = len[last] + 1;
		pos[cur] = t;
		ocur[cur] = 1;

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

	ll calc(const string& S) {
		int n = (int)S.size(), u = 0, tam = 0;

		queue<int> Q;
		for (int i = 0; i < n; i++) {
			Q.push(S[i] - 'a');
			while (Q.size() and next[u][Q.front()]) {
				u = next[u][Q.front()];	Q.pop();
				tam++;
			}
		}

		unordered_set<int> Set;
		for (int i = 0; i < n; i++) {
			if (tam == n) {
				Set.insert(u);
			}

			// considerar so o sufixo de tamanho tam - 1
			tam--;
			if (u and len[link[u]] >= tam) {
				u = link[u];
			}

			Q.push(S[i] - 'a');
			while (Q.size() and next[u][Q.front()]) {
				u = next[u][Q.front()];
				Q.pop();
				tam++;
			}
		}

		ll res = 0;
		for (int v : Set) {
			res += ocur[v];
		}

		return res;
	}

	void processa() {
		vector<int> U(sz);
		iota(all(U), 0);
		sort(all(U), [&](int a, int b) {
			return len[a] > len[b];
		});

		for (int u : U) if (link[u] != -1) {
			ocur[link[u]] += ocur[u];
		}
	}

	void printa() {
		for (int i = 0; i < sz; i++) {
			for (int c = 0; c < 26; c++) if (next[i][c]) {
				int j = next[i][c];
				cout << i << ' ' << j << ' ' << char('a' + c) << endl;
			}
		}
		cout << endl;

		for (int i = 1; i < sz; i++) {
			cout << i << ' ' << link[i] << ' ' << '$' << endl;
		}

		for (int i = 1; i < sz; i++) {
			cout << i << " |  ocur[i]: " << ocur[i]  
						<< ", range len: [" << len[link[i]] + 1 << ", " << len[i] << "]\n";
		}
	}
};

int solve() {
	string T; cin >> T;
	int n = (int)T.size();
	sam::init();
	for (int i = 0; i < n; i++) {
		sam::add(T[i] - 'a', i);
	}
	sam::processa();
	//sam::printa();

	int q; cin >> q;
	for (int t = 0; t < q; t++) {
		string S; cin >> S;
		cout << sam::calc(S) << endl;
	}

	return(0);
}

signed main()
{
    _;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
