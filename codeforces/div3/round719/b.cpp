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

	vector<int> v;
	for (int i = 1; i <= 9; i++) {
		ll j = i;

		while (j <= (ll)1e9) {
			v.push_back(j);	
			j = i + (j * 10);
		}
	}
	sort(v.begin(), v.end());

	//for (int i : v) cout << i << endl;

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		cout << upper_bound(v.begin(), v.end(), n) - v.begin() << endl;
	}
	
    
    return(0);
}
