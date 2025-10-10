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

const int MAX = 2750131 + 10;
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
	int n; cin >> n;

	multiset<int> m;
	vector<int> res;
	for (int i = 0, x; i < 2 * n; i++) {
		cin >> x; m.insert(x);	
	}

	for (int i = 0; i < n; i++) {
		int a = *m.rbegin(), b;

		if (a == divi[a]) {
			b = lower_bound(primes.begin(), primes.end(), a) - primes.begin() + 1;
			res.push_back(b);
		} else {
			b = a / divi[a];
			res.push_back(a);
		}
		m.erase(m.find(a));
		m.erase(m.find(b));
	}

	for (int i : res) cout << i << ' '; cout << endl;
    
    return(0);
}
