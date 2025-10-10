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

int solve() {
	int n; cin >> n;

	vector<int> a(n);
	for (int& i : a) cin >> i;

	ll res = 0;
	int agr = 0, cont = 0;
	for (int i : a) {
		for (int j = 30; j >= 0; j--) {
			if (i & (1 << j)) res += (1 << j);
		}
		if ((i & agr) != 0) agr = i, cont++;
		else agr |= i;
	}

	cout << res << ' ' << cont + !!(agr) << endl;

	return(0);
}

int main()
{
    _;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
