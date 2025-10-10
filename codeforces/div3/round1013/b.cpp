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

void solve() {
	int n, x; cin >> n >> x;
	vector<int> v(n);
	for (int& i : v) cin >> i;

	sort(v.rbegin(), v.rend());
	int agr = 0, res = 0;;
	for (int i = 0; i < n; i++) {
		agr++;

		if (agr * v[i] >= x) {
			res++;
			agr = 0;
		}
	}

	cout << res << endl;
}

int main()
{
    _;

	int t; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
