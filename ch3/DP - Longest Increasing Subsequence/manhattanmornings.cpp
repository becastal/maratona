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

template<typename T> vector<T> lis(vector<T>& v) {
	int n = v.size(), m = -1;
	vector<T> d(n+1, INF);
	vector<int> l(n);
	d[0] = -INF;

	for (int i = 0; i < n; i++) {
		int t = upper_bound(d.begin(), d.end(), v[i]) - d.begin();
		d[t] = v[i], l[i] = t, m = max(m, t);
	}

	int p = n;
	vector<T> ret;
	while (p--) if (l[p] == m) {
		ret.push_back(v[p]);
		m--;
	}
	reverse(ret.begin(),ret.end());

	return ret;
}

int main()
{
    _;

	int n; cin >> n;
	int xh, yh, xw, yw;
	cin >> xh >> yh >> xw >> yw;

	vector<pair<int, int>> v(n);
	for (auto& [xi, yi] : v) cin >> xi >> yi;

	set<pair<int, int>> S;
	for (int i = 0; i < n; i++) {
		auto [xi, yi] = v[i];

		if (xi > max(xh, xw)) continue;
		if (xi < min(xh, xw)) continue;
		if (yi > max(yh, yw)) continue;
		if (yi < min(yh, yw)) continue;
		S.emplace(xi, yi);
	}

	if (S.empty()) return cout << 0 << endl, 0;

	vector<int> yy;	
	for (auto [xi, yi] : S) {
		yy.push_back(yi);
	}

	cout << lis(yy).size() << endl;
    
    return(0);
}
