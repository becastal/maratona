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

vector<int> nums;
int solve() {
	int x; cin >> x;
	cout << *lower_bound(nums.begin(), nums.end(), x) << endl;

	return(0);
}

int main()
{
    _;

	vector<ll> pot;
	for (ll tr = 1; tr < (ll)1e5; tr *= 3LL) {
		pot.push_back(tr);
	}

	int n = (int)pot.size(); 
	for (int i = 1; i < (1 << n); i++) {
		int agr = 0;
		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) {
				agr += pot[j];
			}
			//cout << !!(i & (1 << j));
		}
		//cout << ": " << agr << endl;
		nums.push_back(agr);
	}

	sort(nums.begin(), nums.end());

	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
