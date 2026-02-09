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
	for (int i = 0; i < n; i++) {
		cin >> v[i].f;
		v[i].s = i;
	}
	sort(v.rbegin(), v.rend());

	vector<int> res(n);
	for (int l = 0, r, cont = 1; l < n; ) {
		res[v[l].s] = l+1;
		r = l+1;	
		while (v[r].f == v[l].f) {
			res[v[r++].s] = l+1;
		}

		l = r;
	}
	for (int i : res) cout << i << endl;
    
    return(0);
}
