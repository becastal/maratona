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

const int MAX = 1.019e8+10;
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

	int N = primes.size();
	vector<int> pren(N+1, 0), pre1(N+1, 0);
	
	for (int i = 1; i <= N; i++) {
		pren[i] = pren[i-1] + (32 - __builtin_clz(primes[i-1]));
		pre1[i] = pre1[i-1] + (__builtin_popcount(primes[i-1]);
	}

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		int pos = lower_bound(pren.begin(), pren.end(), n) - pren.begin();
			
	}
    
    return(0);
}
