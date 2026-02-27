#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
//#define int ll

const int MAX = 1e6+10;
vector<int> divi[MAX];

void crivo(int lim) {
	for (int i = 1; i <= lim; i++) {
		for (int j = i; j <= lim; j += i) {
			divi[j].push_back(i);
		}
	}
}

namespace sam {
	int len[2*MAX], link[2*MAX], next[2*MAX][26]; 
	int pos[2*MAX], ocur[2*MAX], quant[2*MAX];
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

	ll calc() {
		ll res = 0;
		for (int u = 1; u < sz; u++) {
			/*
				quantos divisores de cont[u] 
				entre (len[link[u]] e len[u]];
			*/
			int a = len[link[u]] + 1, b = len[u];
			res += 1LL * ocur[u] * ( 
				upper_bound(all(divi[ocur[u]]), b) - lower_bound(all(divi[ocur[u]]), a)
			);
		}
		return res;
	}

	void processa() {
		vector<int> U(sz);
		iota(all(U), 0);

		sort(all(U), [&](int a, int b) { return len[a] > len[b]; });
		for (int u : U) if (link[u] != -1) {
			ocur[link[u]] += ocur[u];
			quant[u] = len[u] - len[link[u]];
		}
	}
};

int solve() {
	int n; cin >> n;
	string T; cin >> T;
	sam::init();
	crivo(n + 1);

	for (int i = 0; i < n; i++) {
		sam::add(T[i] - 'a', i);
	}
	sam::processa();

	cout << sam::calc() << endl;

	return(0);
}

signed main()
{
    _;

	int t = 1; // cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
    
    return(0);
}


