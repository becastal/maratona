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
	int n, s; cin >> n >> s;
	vector<int> a(n);
	for (int& i : a) cin >> i;

	int res = 0;
	for (ll i = 0, soma = 0, maior = 0, pos = 0; i < n; i++) {
		soma += a[i];

		if (a[i] > maior) {
			maior = a[i];
			pos = i;
		}

		if (soma > s and !res) {
			res = pos + 1;
			soma -= maior;
		}
	}

	cout << res << endl;

	return(0);
}

int main()
{
    _;

	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
