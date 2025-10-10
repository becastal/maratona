#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve(int n, int q) {
	// cada remocao eh tirar:
	// - quantos anteriores a mim sao menores que eu
	// - quantos posteriores a mim sao maiores que eu
	// - update pra me tirar do bloco.
	// ambas as queries em O(sqrt(N));

	vector<int> A(n), pos(n+1);
	for (int i = 0; i < n; i++) {
		cin >> A[i];
		pos[A[i]] = i;
	}

	ll res = 0;
	vector<ll> bit(n+1, 0);
	for (int i = n-1; i >= 0; i--) {
		for (int j = A[i]; j; j-=j&-j) res += bit[j];
		for (int j = A[i]; j <= n; j+=j&-j) bit[j]++;
	}

	int tam = ceil(sqrt(n));

	int quant = (n + tam - 1) / tam;
	vector<vector<int>> B(quant);

	for (int i = 0; i < quant; i++) {
		for (int j = i * tam; j < min(n, (i + 1) * tam); j++) {
			B[i].push_back(A[j]);
		}
		sort(all(B[i]));
	}

	auto query = [&](int l, int r, int x, int tipo) -> ll {
		if (l > r) return 0;
		int l_ = l / tam, r_ = r / tam;
		ll res = 0;

		if (l_ == r_) {
			for (int i = l; i <= r; i++) if (A[i]) {
				res += (tipo ? A[i] < x : A[i] > x);
			}
		} else {
			for (int i = l, lim = (l_ + 1) * tam - 1; i <= lim; i++) if (A[i]) {
				res += (tipo ? A[i] < x : A[i] > x);
			}

			for (int i = l_ + 1; i <= r_ - 1; i++) {
				if (tipo) {
					res += lower_bound(all(B[i]), x) - B[i].begin();
				} else {
					res += B[i].end() - upper_bound(all(B[i]), x);
				}
			}

			for (int i = r_ * tam; i <= r; i++) if (A[i]) {
				res += (tipo ? A[i] < x : A[i] > x);
			}
		}
		return res;
	};

	while (q--) {
		int val; cin >> val;
		int p = pos[val];

		cout << res << endl;
		res -= query(0, p, val, 0);
		res -= query(p, n-1, val, 1);

		int bl = p / tam;
		B[bl].erase(lower_bound(all(B[bl]), val));
		A[p] = 0;
	}

	return(0);
}

int main()
{
    _;

	int n, q;
	while (cin >> n >> q) {
		solve(n, q);
	}
    
    return(0);
}

