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
	int n; cin >> n;
	vector<array<ll, 3>> A(n);
	vector<ll> B;

	for (auto& [a, b, c] : A) {
		cin >> a >> b >> c;
		B.push_back(min({a + b, a + c, b + c}) + 2);
	}
	sort(all(B));

	for (auto [a, b, c] : A) {
		ll s = a + b + c, t = min({a + b, a + c, b + c}) + 2;
		cout << upper_bound(all(B), s) - B.begin() - (s >= t) << ' ';
	}
	cout << endl;

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
