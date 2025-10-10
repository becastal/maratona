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

	int n; cin >> n;

	ll l = 1, r = n;
	while (l <= r) {
		ll m = l + (r - l) / 2;

		if ((1 + m) * m / 2 < n) {
			l = m + 1;	
		} else {
			r = m - 1;	
		}
	}

	ll s = (1 + l) * l / 2;
	assert(s - n <= l);
	for (int i = 1; i <= l; i++) {
		if (s - n == i) continue;
		cout << i << endl;
	}

    return(0);
}
