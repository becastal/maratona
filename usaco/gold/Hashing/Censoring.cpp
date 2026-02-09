#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

const ll p = 69420;
const ll mod = 1e9+9;

/*
	so preciso manter qual o hash do min(i, m) valores;

	S[0] * p + S[1] * p^2 + S[2] * p^3 + ... 

	->
	
	dividir por p
	retirar S[i-m];

	S[1] * p + S[2] * p^2 + S[3] * p^3 + ... 
*/

int solve() {
	string S, T; cin >> S >> T;
	int n = (int)S.size(), m = (int)T.size();

	vector<ll> base(m + 1, 0);
	base[0] = 1;
	for (int i = 1; i <= m; i++) {
		base[i] = base[i-1] * p % mod;
	}

	ll hash_T = 0;
	for (int i = 0; i < m; i++) {
		hash_T = (hash_T * p + T[i]) % mod;
	}

	string R = "";
	vector<ll> A = {0};
	for (int i = 0; i < n; i++) {
		A.push_back((A.back() * p + S[i]) % mod);
		R.push_back(S[i]);

		if ((int)R.size() >= m) {
			int tam = (int)R.size();
			ll janela = (A[tam] - A[tam - m] * base[m]) % mod;
			if (janela < 0) janela += mod;

			if (janela == hash_T) {
				for (int j = 0; j < m; j++) {
					A.pop_back();
					R.pop_back();
				}
			}
		}
	}
	cout << R << endl;

	return(0);
}

void setIO(string nome) {
	if (nome == "") return;
	freopen((nome + ".in").c_str(), "r", stdin);
	freopen((nome + ".out").c_str(), "w", stdout);
}

int main() {
    _;
	setIO("censor");

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}

    return(0);
}
