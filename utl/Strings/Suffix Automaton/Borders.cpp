#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

const int MAX = 400010;
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

	void processa() {
		vector<int> U(sz);
		iota(all(U), 0);
			
		sort(all(U), [&](int a, int b) { return len[a] > len[b]; });
		for (int u : U) if (link[u] != -1) {
			ocur[link[u]] += ocur[u];
		}
	}

	int calc() {
		int res = 0;
		for (int u = 1; u < sz; u++) {
			res += (len[u] - len[link[u]]) * ocur[u] * (ocur[u] - 1) / 2;
		}
		res++;
		return res;
	}
};

int solve() {
	string S; cin >> S;
	int n = (int)S.size();

	sam::init();
	for (int i = 0; i < n; i++) {
		sam::add(S[i] - 'a', i);	
	}
	sam::processa();

	cout << n * (n + 1) / 2 + sam::calc() - 1 << endl;

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


