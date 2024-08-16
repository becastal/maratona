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

	int n, q; cin >> n >> q;

	vector<int> v(n);
	for (int& vi : v)
		cin >> vi;

	vector<vector<int>> pre(n + 1, vector<int>(4, 0));
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= 3; j++)
			pre[i][j] = pre[i - 1][j];
		pre[i][v[i - 1]]++;
	}

	while (q--)
	{
		int l, r; cin >> l >> r;
		for (int i = 1; i <= 3; i++)
			cout << pre[r][i] - pre[l - 1][i] << ' ';
		cout << endl;
	}
    
    return(0);
}
