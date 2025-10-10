#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

int solve() {
	auto divs = [](ll a) {
		int res = 0;
		for (ll i = 1; i * i <= a; i++) {
			if (a % i == 0) {
				res++;
				if (a / i != i) res++;
			}
		}
		return res;
	};

	int a = 0;
	for (int i = 0; ; i++) {
		a += (i + 1);
		if (divs(a) > 500) return cout << a << endl, 0;
	}

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
