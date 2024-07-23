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

	int n, x; cin >> n >> x;
	vector<int> v(n);
	for (int& vi : v)
		cin >> vi;

	vector<ll> pre(n + 1, 0);
	map<ll, ll> twos;
	ll res = 0;
	for (int i = 1; i <= n; i++)
	{
		pre[i] = pre[i - 1] + v[i - 1];
		res += (pre[i] == x);

		res += twos[pre[i] - x];
		twos[pre[i]]++;
	}

	cout << res << endl;
    
    return(0);
}
