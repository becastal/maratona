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

	map<int, int> m;
	int l = 0, res = 0;
	for (int r = 0; r < n; r++)
	{
		m[v[r]]++;
		while (l < n and (m.count(v[l]) and m[v[l]] > 1 or m.count(v[r]) and m[v[r]] > 1))
			m[v[l++]]--;

		res = max(res, r - l + 1);
	}

	cout << res << endl;
    
    return(0);
}
