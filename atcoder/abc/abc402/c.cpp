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

	vector<vector<int>> a(m);
	for (int i = 0, k; i < m; i++) {
		cin >> k;
		for (int j = 0, x; j < k; j++) {
			cin >> x;
			a[i].push_back(x);
		}
	}

	vector<int> b(n), pos(n+1);
	for (int i = 0; i < n; i++) {
		cin >> b[i];
		pos[b[i]] = i;
	}

	vector<int> res(n);
	for (int i = 0; i < m; i++) {
		int agr = 0;
		for (int j : a[i]) {
			agr = max(agr, pos[j]);
		}
		res[agr]++;
	}

	for (int i = 1; i < n; i++) {
		res[i] += res[i-1];
	}
	for (int i : res) cout << i << endl;
    
    return(0);
}
