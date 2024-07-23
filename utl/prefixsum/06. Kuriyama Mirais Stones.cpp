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
	for (int& vi : v)
		cin >> vi;

	vector<ll> pre(n + 1, 0), preo(n + 1, 0);
	for (int i = 1; i <= n; i++)
		pre[i] = pre[i - 1] + v[i - 1];

	sort(v.begin(), v.end());
	for (int i = 1; i <= n; i++)
		preo[i] = preo[i - 1] + v[i - 1];

	int q; cin >> q;
	while (q--)
	{
		int ty, l, r; cin >> ty >> l >> r;

		vector<ll>& vq = (ty == 1 ? pre : preo);

		cout << vq[r] - vq[l - 1] << endl;
	}
    
    return(0);
}
