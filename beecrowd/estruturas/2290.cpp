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

	int n; 
	while (cin >> n and n) {
		map<ll, int> M;
		for (int i = 0; i < n; i++) {
			ll x; cin >> x;
			M[x] ^= 1;
		}

		vector<ll> res;
		for (auto [a, b] : M) {
			if (b) res.push_back(a);
		}

		cout << res[0] << ' ' << res[1] << endl;
	}

    return(0);
}
