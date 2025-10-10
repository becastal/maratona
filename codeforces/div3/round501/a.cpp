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

	int n, m; cin >> n >> m;
	vector<int> v(m+1, 0), res;

	for (int i = 0, l, r; i < n; i++) {
		cin >> l >> r; l--, r--;
		v[l]++, v[r+1]--;
	}

	for (int i = 1; i <= m; i++) {
		v[i] += v[i-1];
	}

	for (int i = 0; i < m; i++) {
		if (!v[i]) res.push_back(i+1);
	}
    
	cout << res.size() << endl;
	for (int i : res) cout << i << ' '; cout << endl;

    return(0);
}
