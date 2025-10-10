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

const int MAX = 1e3+10;
int divi[MAX];

void crivo(int lim) {
	for (int i = 1; i <= lim; i++) divi[i] = 1;

	for (int i = 2; i <= lim; i++) if (divi[i] == 1)
		for (int j = i; j <= lim; j += i) divi[j] = i;
}

void fact(map<int, int>& v, int n) {
	if (n != divi[n]) fact(v, n/divi[n]);
	v[divi[n]]++;
}

int main()
{
    _;

	const int mod = 1e9+7;
	int n; cin >> n;
	crivo(n);

	map<int, int> f;
	for (int i = 2; i <= n; i++) {
		fact(f, i);	
	}

	ll res = 1;
	for (auto [a, b] : f) {
		res = (res * (b + 1)) % mod;
	}
	cout << res << endl;
    
    return(0);
}
