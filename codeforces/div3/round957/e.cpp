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


	vector<vector<pair<int, int>>> v(101);
	for (int n = 2; n <= 9; n++) {
		ll onz = 1;
		for (int i = 1; i <= 17; i++) {
			if ((n * onz - i) % (n - 1) == 0) {
				ll a = (n * onz - i) / (n - 1), b = a - i;
				if (a > 10000) break;
				if (a and b) v[n].emplace_back(a, b);
			}
			onz = 10 * onz + 1;
		}
	}

	for (int n = 10; n <= 99; n++) {
		ll onz = n;
		for (int i = 1; i <= 17; i++) {
			if ((onz - (i + 1)) % (n - 2) == 0) {
				ll a = (onz - (i + 1)) / (n - 2),  b = 2 * a - (i + 1);
				if (a > 10000) break;
				if (a > 0 and b > 0) v[n].emplace_back(a, b);
			}
			onz = 10 * onz + (i & 1 ? n / 10 : n % 10);
		}
	}

	for (int i = 2; i <= 10000; i++) {
		v[1].emplace_back(i, i-1);
	}

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		cout << v[n].size() << endl;
		for (auto [a, b] : v[n]) {
			cout << a << ' ' << b << endl;
		}
	}
    
    return(0);
}
