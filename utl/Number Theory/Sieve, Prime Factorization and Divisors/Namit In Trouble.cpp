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

const int MAX = 1e6+10;
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

int main()
{
    _;

	crivo(MAX-1);	
	vector<ll> v;
	sort(primes.begin(), primes.end());
	for (int i : primes) {
		if ((ll)i * i < 1e10) v.push_back((ll)i * i);
		else break;
	}

	int t; cin >> t;
	while (t--) {
		ll n, k; cin >> n >> k;

		int a = upper_bound(v.begin(), v.end(), n) - v.begin(), b = 0;
		if (k < n) {
			b = a - (upper_bound(v.begin(), v.end(), k) - v.begin());
		}

		cout << a << ' ' << b << endl;
	}
    
    return(0);
}
