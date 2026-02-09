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

	int n, t; cin >> n >> t;
	vector<pair<int, int>> v(n);

	for (auto& [a, b] : v) {
		char c; cin >> c;
		b = c == '1';
	}
	for (auto& [a, b] : v) {
		cin >> a;
	}
	sort(v.begin(), v.end());

	ll res = 0;
	vector<int> v_;
	for (auto [a, b] : v) {
		if (!b) {
			res += v_.end() - lower_bound(v_.begin(), v_.end(), a - t);
		} else {
			v_.push_back(a + t);
		}
	}
	cout << res << endl;
    
    return(0);
}
