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
	int x;
	while (cin >> x) {
		v.push_back(x);
	}

	int n = v.size(), m = -1;
	vector<int> d(n+1, INF), l(n); d[0] = -INF;

	for (int i = 0; i < n; i++) {
		int t = lower_bound(d.begin(), d.end(), v[i]) - d.begin();
		d[t] = v[i], l[i] = t, m = max(m, t);
	}

	int p = n;
	vector<int> res;
	while (p--)  if (l[p] == m) {
		res.push_back(v[p]);
		m--;
	}
	reverse(res.begin(), res.end());

	cout << res.size() << endl << '-' << endl;
	if (res.size() == 1) return cout << v[0] << endl, 0;
	for (int i : res) cout << i << endl;
    
    return(0);
}
