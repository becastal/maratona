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
    //_;

	string s;
	int n, pri = 1;
	vector<int> ord, certo;

	while (getline(cin, s)) {
		vector<int> v;	

		stringstream ss(s);
		int x;
		while (ss >> x) {
			v.push_back(x);
		}

		if (v.size() == 1) {
			n = v[0];
			pri = 1;
		} else if (pri) {
			certo = v;
			ord.resize(n+1);
			for (int i = 0; i < n; i++) {
				ord[v[i]] = i+1;
			}
			pri = 0;
		} else {
			vector<int> ordi(n);
			for (int i = 0; i < n; i++) {
				ordi[i] = ord[v[i]];
			}

			for (int i : ordi) cout << i << ' '; cout << endl;
			cout << (int)lis(ordi).size() << endl;
		}
	}
    
    return(0);
}
