#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
const int INF = 0x3f3f3f3f;
const double inf = 1e9;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

int solve() {
	// (a1)(a2)(a3)...(an) = x
	// ln((a1)(a2)(a3)...(an)) = ln(x);
	// a1 + a2 + a3 + ... + an = ln(x);
	// e ** s = x;

	ll a, b; cin >> a >> b;
	string A = to_string(a), B = to_string(b);
	while (A.size() < B.size()) A = "0" + A;

	ll dp[20][2][2][2];
	int vis[20][2][2][2];
	int escolha[20][2][2][2];
	memset(vis, 0, sizeof(vis));

	auto f = [&](auto&& f, int pos, int tight_baixo, int tight_cima, int zero_esq) -> ll {
		if (pos == B.size()) return 1;
		if (vis[pos][tight_baixo][tight_cima][zero_esq]) return dp[pos][tight_baixo][tight_cima][zero_esq];
		vis[pos][tight_baixo][tight_cima][zero_esq] = 1;

		int chao = tight_baixo ? A[pos] - '0' : 0;
		int teto = tight_cima ? B[pos] - '0' : 9;

		ll agr = -inf;
		for (int i = chao; i <= teto; i++) {
			int zero_esq_ = zero_esq and (i == 0);
			ll p = zero_esq_ ? 1 : i;

			ll agr_ = p * 
							f(f,
							pos + 1,
							tight_baixo and (i == chao),
							tight_cima and (i == teto),
							zero_esq and (i == 0));
			if (agr < agr_) {
				agr = agr_;
				escolha[pos][tight_baixo][tight_cima][zero_esq] = i;
			}
		};
		return dp[pos][tight_baixo][tight_cima][zero_esq] = agr;
	};
	ll s = f(f, 0, 1, 1, 1);
	//cout << s << endl;
	//cout << exp(s) << endl;

	string res = "";
	int tight_baixo = 1, tight_cima = 1, zero_esq = 1;
	for (int pos = 0; pos < B.size(); pos++) {
		int chao = tight_baixo ? A[pos] - '0' : 0;
		int teto = tight_cima ? B[pos] - '0' : 9;

		int i = escolha[pos][tight_baixo][tight_cima][zero_esq];
		res.push_back(char(i + '0'));

		tight_baixo = tight_baixo and (i == chao); 
		tight_cima = tight_cima and (i == teto);
		zero_esq = zero_esq and (i == 0);
	}
	cout << stoll(res) << endl;

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
