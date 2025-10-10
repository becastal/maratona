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

const int MAX = 1e4+10;
ll tot[MAX];

void crivo(int lim) {
	for (int i = 1; i <= lim; i++) {
		tot[i] += i;
		for (int j = 2*i; j <= lim; j += i)
			tot[j] -= tot[i];
	}
}

int main()
{
    _;
	
	crivo(MAX-1);
	for (int i = 1; i < MAX; i++) {
		tot[i] += tot[i-1];
	}

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		cout << tot[n] * tot[n] << endl;
	}
    
    return(0);
}
