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

const int MAX = 5263700;
int divi[MAX];
vector<ll> primes;

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
	//dbg(primes.size());	

	vector<ll> v;
	for (int i = 0; i < (int)primes.size(); i++) {
		for (int j = i+1; j < (int)primes.size(); j++) {
			if (primes[i] * primes[j] > 10527450) break;
			v.push_back(primes[i] * primes[j]);
		}
	}
	sort(v.begin(), v.end());

	int t; cin >> t;
	while (t--) {
		int k; cin >> k;
		cout << v[k-1] << endl;
	}
    
    return(0);
}
