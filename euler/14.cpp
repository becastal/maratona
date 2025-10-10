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

map<ll, int> res;
ll f(ll x) {
	if (res.count(x)) return res[x];	
	return res[x] = 1 + (x & 1 ? f(3 * x + 1) : f(x / 2));
};

int solve() {

	res[1] = 0;
	int n = int(1000000);


	int pos, mx = 0;
	for (int i = 1; i < n; i++) {
		f(i);
		if (mx < res[i]) {
			mx = res[i];
			pos = i;
		}
	}
	cout << pos << endl;

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
