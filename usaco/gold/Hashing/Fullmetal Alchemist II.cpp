#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

/*

abcd defg fghi
   ^ ^ ^^ ^^

pra todas as perms, eu consigo salvar: qual o maior
prefixo de A[i] que eh tambem sufixo de A[i-1];

*/

const ll pot = 6920;
const ll mod = 1e9+9;

int solve() {
	int n, s = 0, mx = 0; cin >> n;

	vector<string> A(n);
	for (auto& i : A) {
		cin >> i;
	}

	vector<string> B;
	for (int i = 0; i < n; i++) {
		int ruim = 0;
		for (int j = 0; j < n and !ruim; j++) if (i != j) {
			ruim |= (A[j].find(A[i]) != string::npos);
		}
		if (!ruim) {
			B.push_back(A[i]);
		}
	}
	A = move(B);
	n = (int)A.size();

	for (auto i : A) {
		s += (int)i.size();
		mx = max(mx, (int)i.size());
	}

	vector<ll> base(mx+1, 1);
	for (int i = 1; i <= mx; i++) {
		base[i] = base[i-1] * pot % mod;
	}

	vector<vector<ll>> Pre(n);
	for (int i = 0; i < n; i++) {
		int m = (int)A[i].size();
		Pre[i] = vector<ll>(m + 1, 0);

		for (int j = 1; j <= m; j++) {
			Pre[i][j] = (Pre[i][j-1] * pot % mod + A[i][j-1]) % mod;
		}
	}
	auto query = [&](int i, int l, int r) {
		return (Pre[i][r+1] - base[r-l+1] * Pre[i][l] % mod + mod) % mod;
	};

	vector<vector<int>> C(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < min((int)A[i].size(), (int)A[j].size()); k++) {
				if (query(j, 0, k) == query(i, (int)A[i].size() - k - 1, (int)A[i].size() - 1)) {
					C[i][j] = (k + 1);
				}
			}
		}
	}

	vector<int> P(n);
	iota(all(P), 0);

	int res = s;
	do {
		int agr = s;
		for (int i = 1; i < n; i++) {
			agr -= C[P[i-1]][P[i]];
		}
		res = min(res, agr);
	} while (next_permutation(all(P)));
	cout << res << endl;

	return(0);
}

int main()
{
    _;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

