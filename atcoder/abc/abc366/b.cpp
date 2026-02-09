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

	int n, m = 0; cin >> n;
	vector<string> v(n);
	for (auto& i : v) cin >> i, m = max(m, (int)i.size());

	vector<string> res(m);
	for (int i = 0; i < m; i++) {
		for (int j = n-1; j >= 0; j--) {
			if (i >= (int) v[j].size()) {
				res[i].push_back('*');
				continue;
			}
			res[i].push_back(v[j][i]);
		}
	}

	for (int i = 0; i < m; i++) {
		while (res[i].back() == '*') {
			res[i].pop_back();
		}
		cout << res[i] << endl;
	}
    
    return(0);
}
