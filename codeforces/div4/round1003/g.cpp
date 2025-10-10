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

const int MAX = 2e5+10;
int divi[MAX], cont[MAX], contsp[MAX];
map<int, int> memo[MAX];

void crivo(int lim) {
	for (int i = 1; i <= lim; i++) divi[i] = 1;

	for (int i = 2; i <= lim; i++) if (divi[i] == 1)
		for (int j = i; j <= lim; j += i) divi[j] = i;
}

void fact(vector<int>& v, int n) {
	if (n != divi[n]) fact(v, n/divi[n]);
	v.push_back(divi[n]);
}

map<int, int> fact_(int n) {
	if (!memo[n].empty()) return memo[n];
	map<int, int> res; 
	vector<int> f; fact(f, n);
	for (int i : f) res[i]++;
	return memo[n] = res;
}

int solve() {
	int n; cin >> n;
	vector<int> a(n);
	for (int& i : a) cin >> i;

	ll res = 0;
	int primos = 0;
	for (int i = 0; i < n; i++) {
		auto f = fact_(a[i]);

		int se = 0;
		for (auto [p, e] : f) se += e;

		if (se == 1) {
			res += primos - cont[a[i]];
			res += contsp[a[i]];
			primos++;
		}

		if (se == 2) {
			res += cont[a[i]];
			for (auto [p, e] : f) {
				res += cont[p];
				contsp[p]++;
			}
			res++;
		}

		//cout << res << " \n"[i==n-1];
		cont[a[i]]++;
	}

	//ll res_ = 0;
	//cout << 0 << ' ';
	//for (int i = 1; i < n; i++) {
	//	for (int j = 0; j <= i; j++) {
	//		auto f = fact_(lcm(a[i], a[j]));

	//		int se = 0;
	//		for (auto [p, e] : f) se += e;
	//		if (se == 2) res_++;
	//	}
	//	cout << res_ << " \n"[i==n-1];
	//}

	cout << res << endl;
	memset(cont, 0, sizeof(cont));
	memset(contsp, 0, sizeof(contsp));
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
