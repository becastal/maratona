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

	vector<ll> v(210);

	while (cin >> v[0]) {
		int n = 1;
		while (cin >> v[n] and v[n++] != -999999) {
		}
		n--;

		ll maxi = 1, mini = 1, res = v[0];
		for (int i = 0; i < n; i++) {
			if (!v[i]) {
				maxi = mini = 1;	
				res = max(res, 0LL);
				continue;
			}

			if (v[i] < 0) {
				swap(maxi, mini);
			}

			maxi = max(v[i], maxi * v[i]);
			mini = min(v[i], mini * v[i]);

			res = max(res, maxi);
		}

		cout << res << endl;
	}
    
    return(0);
}

