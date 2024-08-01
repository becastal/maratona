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

int main()
{
    _;

	// talvez so two pointers tomando cuidado com o k;
	int t; cin >> t;
	while (t--) {
		int n, k; cin >> n >> k;
		vector<int> a(n), h(n);
		for (int& i : a) cin >> i;
		for (int& i : h) cin >> i;

		int soma = 0, res = 0;
		for (int l = 0, r = 0; l < n; l++) {
			while (r + 1 < n and (l == r or h[r - 1] % h[r] == 0 and soma + a[r + 1] <= k))
				r++, soma += a[r];

			soma -= a[l];
			res = max(res, r - l);
		}

		cout << res << endl;
	}
    
    return(0);
}

