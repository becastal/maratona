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

	int t; cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;

		vector<ll> v(n + 1);
		for (int i = n - k + 1; i <= n; i++)
			cin >> v[i];

		if (k == 1) { cout << "yes" << endl; continue; }

		vector<ll> pre(n + 1);
		for (int i = n - k + 2; i <= n; i++)
			pre[i] = v[i] - v[i - 1];

		if (!is_sorted(pre.begin() + n - k + 2, pre.end())) { cout << "no" << endl; continue; }
		if (v[n - k + 1] > pre[n - k + 2] * (n - k + 1))   { cout << "no" << endl; continue; }
		cout << "yes" << endl;	
	}
    
    return(0);
}
