#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n, m; cin >> n >> m;
	int tot = n * m;

	auto valor = [&](char c) {
		if ('0' <= c and c <= '9') {
			return c - '0';
		}
		if ('a' <= c and c <= 'f') {
			return c - 'a' + 10;
		}
		return c - 'A' + 10;
	};

	vector<char> A(tot);
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (int j = 0; j < (int)s.size(); j++) {
			int x = valor(s[j]);
			for (int b = 0; b < 4; b++) {
				int col = 4 * j + b;
				if (col >= m) break;
				A[i * m + col] = !((x >> (3 - b)) & 1);
			}
		}
	}

	auto viz = [&](int u, int k) {
		if (k == 0) return u >= m ? u - m : -1;
		if (k == 1) return u % m != m - 1 ? u + 1 : -1;
		if (k == 2) return u + m < tot ? u + m : -1;
		return u % m ? u - 1 : -1;
	};

	vector<int> Ord(tot, -1), Low(tot), Pai(tot, -1), Filhos(tot);
	vector<char> It(tot), Art(tot);
	vector<int> St;
	int timer = 0;

	auto entra = [&](int u, int p) {
		Ord[u] = Low[u] = timer++;
		Pai[u] = p;
		St.push_back(u);
	};

	for (int s = 0; s < tot; s++) if (A[s] and Ord[s] == -1) {
		entra(s, -1);

		while (St.size()) {
			int u = St.back();

			if (It[u] < 4) {
				int v = viz(u, It[u]++);
				if (v == -1 or !A[v]) continue;

				if (Ord[v] == -1) {
					Filhos[u]++;
					entra(v, u);
				}
				else if (v != Pai[u]) {
					Low[u] = min(Low[u], Ord[v]);
				}
			}
			else {
				St.pop_back();

				if (Pai[u] != -1) {
					int p = Pai[u];
					Low[p] = min(Low[p], Low[u]);
					if (Pai[p] != -1 and Low[u] >= Ord[p]) {
						Art[p] = 1;
					}
				}
			}
		}

		Art[s] = Filhos[s] > 1;
	}

	int res = 0;
	for (int i = 0; i < tot; i++) {
		res += Art[i];
	}
	cout << res << endl;

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
