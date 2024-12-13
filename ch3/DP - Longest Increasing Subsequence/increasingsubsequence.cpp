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
		int t = lower_bound(d.begin(), d.end(), v[i]) - d.begin();
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

	int n;
	while (cin >> n and n) {
		vector<int> v(n);
		for (int& i : v) cin >> i;
		auto res = lis(v);
		cout << res.size();
		for (int i : res) cout << ' ' << i;
		cout << endl;
	}
    
    return(0);
}
