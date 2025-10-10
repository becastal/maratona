#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

#define int long long
const int MAX = 100010;
int divi[MAX];
vector<int> primes;

void crivo(int lim) {
	divi[1] = 1;
	for (int i = 2; i <= lim; i++) {
		if (divi[i] == 0) divi[i] = i, primes.push_back(i);
		for (int j : primes) {
			if (j > divi[i] or i*j > lim) break;
			divi[i*j] = j;
		}
	}
}

void solve() {
	int x; cin >> x;

	vector<pair<int, int>> f;
	for (int p : primes) {
		if ((ll)p * p > x) break;
		if (x % p != 0) continue;

		int cont = 0;	
		while (x % p == 0) {
			cont++;
			x /= p;
		}
		f.emplace_back(p, cont);
	}
	if (x > 1) f.emplace_back(x, 1);
	sort(f.begin(), f.end());

	vector<int> res = {1};

	for (auto [p, e] : f) {
		int agr = 1;
		vector<int> temp;
		for (int i = 0; i <= e; i++) {
			if (i & 1) for (int j = (int)res.size()-1; j >= 0; j--) temp.push_back(res[j]*agr);
			else for (int j = 0; j < (int)res.size(); j++) temp.push_back(res[j]*agr);
			agr *= p;
		}
		res = temp;
	}

	for (int i = 0; i < (int)res.size(); i++) {
		cout << res[i] << " \n"[i==(int)res.size()-1];
	}
}

signed main()
{
    _;
	crivo(MAX-1);

	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		cout << "Case " << t << ":\n";	
		solve();
	}
    
    return(0);
}
