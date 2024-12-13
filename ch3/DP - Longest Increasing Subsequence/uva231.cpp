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

	int t = 1;
	vector<int> v(1);
	while (cin >> v[0] and v[0] != -1) {
		int x;
		while (cin >> x and x != -1) {
			v.push_back(-x);
		}
		v[0] = -v[0];
		if (t != 1) cout << endl;
		cout << "Test #" << t++ << ":\n  maximum possible interceptions:" << lis(v).size() << endl;
		v.resize(1);
	}
    
    return(0);
}
