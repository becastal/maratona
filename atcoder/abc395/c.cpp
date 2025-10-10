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
	vector<int> v(n);
	for (int& i : v) cin >> i;

	int res = INF;

	map<int, int> p;
	for (int i = 0; i < n; i++) {
		if (p.count(v[i])) {
			res = min(res, i - p[v[i]] + 1);
		}
		p[v[i]] = i;
	}

	map<int, int> p2;
	for (int i = n-1; i >= 0; i--) {
		if (p2.count(v[i])) {
			res = min(res, p2[v[i]] - i + 1);
		}
		p2[v[i]] = i;
	}

	cout << (res == INF ? -1 : res) << endl;
    
    return(0);
}
