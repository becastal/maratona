#include <bits/stdc++.h>
// Otimizacoes agressivas, pode deixar mais rapido ou mais devagar
#pragma GCC optimize("Ofast")
// Auto explicativo
#pragma GCC optimize("unroll-loops")
// Vetorizacao
#pragma GCC target("avx2")
// Para operacoes com bits
#pragma GCC target("bmi,bmi2,popcnt,lzcnt")
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

const int MAX = 2e5+10;
int vis[MAX], F[MAX];

vector<int> divs[MAX];
void crivo(int n) {
	for (int i = 2; i <= n; i++) {
		for (int j = i; j <= n; j += i) {
			divs[j].push_back(i);
		}
	}
}

int solve() {
	memset(vis, 0, sizeof(vis));
	memset(F, 0, sizeof(F));
	int n; cin >> n;
	vector<int> A(n), B;

	int res = 0;
	for (int i = 0; i < n; i++) {
		cin >> A[i];
		vector<int> B_;

		for (int d : divs[A[i]]) {
			F[d]++;

			if (F[d] != (i + 1)) {
				res = max(res, F[d]);
			}
			else if (!vis[d]) {
				B_.push_back(d);
				vis[d] = 1;
			}
		}

		for (int d : B) {
			if (F[d] != (i + 1)) {
				res = max(res, F[d]);
				vis[d] = 0;
			} else {
				B_.push_back(d);
			}
		}

		B = move(B_);
		cout << res << " \n"[i == n - 1];
	}

	return(0);
}

int main()
{
    _;

	crivo(MAX-1);
	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

