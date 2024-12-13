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

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> v(n);
		for (int& i : v) cin >> i;

		int maxa = 0, somaa = 0;
		for (int i = 0; i < n; i += 2) {
			somaa++;
			maxa = max(maxa, v[i]);
		}

		int maxb = 0, somab = 0;
		for (int i = 1; i < n; i += 2) {
			somab++;
			maxb = max(maxb, v[i]);
		}

		cout << max(maxa + somaa, maxb + somab) << endl;
	}
    
    return(0);
}
