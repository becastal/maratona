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
	vector<int> v;
	for (int i = 1; i < (int)primes.size(); i++) {
		int ii = primes[i] + primes[i-1] + 1;
		if (ii < MAX and divi[ii] == ii) v.push_back(ii);	
	}
	//for (int i : v) cout << i << endl; 

	int n, k; cin >> n >> k;
	cout << (upper_bound(v.begin(), v.end(), n) - v.begin() >= k ? "YES" : "NO") << endl;
    
    return(0);
}
