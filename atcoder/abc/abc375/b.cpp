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
	vector<pair<int, int>> v(n);

	for (auto& [x, y] : v) cin >> x >> y;

	auto dist = [] (pair<int, int> a, pair<int, int> b) -> double {
		return hypot(a.f - b.f, a.s - b.s);
	};

	double res = 0;
	res += dist(pair<int, int>(0, 0), v[0]);
	res += dist(pair<int, int>(0, 0), v[n-1]);

	for (int i = 1; i < n; i++) {
		res += dist(v[i], v[i-1]);	
	}
	
	cout << fixed << setprecision(12) << res << endl;
    
    return(0);
}
