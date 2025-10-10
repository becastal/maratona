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

const int MAX = 1e7+10;
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

int prime(ll n) {
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) return 0;
	}
	return 1;
}

int main()
{
    _;

	crivo(MAX-1);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		ll res = 0;
		for (int i : primes) {
			res += n / i;
			if (n / i == 0) break;
		}
		cout << res << endl;
	}
	//int N, res = 0;
	//cin >> N;
	//for (int i = 1; i <= N; i++) {
	//	cout << i << ": ";
	//	for (int j = i+1; j <= N; j++) {
	//		if (prime(lcm(i, j) / gcd(i, j))) cout << j << ' ', res++;
	//	}
	//	cout << endl;
	//}
	//dbg(res);
    
    return(0);
}
