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

const int MAX = 7e6+10;
int divi[MAX];
vector<int> primes;
vector<ll> prefp;

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


int solve() {
	int n; cin >> n;
	vector<int> a(n);
	
	for (int& i : a) cin >> i;
	sort(a.rbegin(), a.rend());

	vector<ll> pre(n+1, 0);
	for (int i = 1; i <= n; i++) {
		pre[i] = pre[i-1] + a[i-1];
	}

	int l = 0, r = n, res;
	while (l <= r) {
		int m = l + (r - l) / 2;

		if (pre[m] >= prefp[m]) {
			res = m;
			l = m+1;
		} else {
			r = m-1;
		}
	}
	
	cout << (n - res) << endl;

	return(0);
}

int main()
{
    _;

	crivo(MAX-1);

	prefp.resize((int)primes.size() + 1);
	for (int i = 1; i < (int)primes.size(); i++) {
		prefp[i] = prefp[i-1] + primes[i-1];
	}

	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
