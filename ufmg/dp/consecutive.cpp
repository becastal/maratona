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
	map<int, int> memo;

	int res = 0, val = 0;
	for (int i = 0; i < n; i++)
	{
		memo[v[i]] = memo[v[i] - 1] + 1;
		if (res < memo[v[i]])
		{
			res = memo[v[i]];
			val = v[i];
		}
	}

	vector<int> r;
	for (int i = n - 1; i >= 0; i--)
		if (v[i] == val)
		{
			r.push_back(i);
			val--;
		}
	reverse(r.begin(), r.end());

	cout << res << endl;
	for (int ri : r)
		cout << ri + 1 << ' ';
	cout << endl;
    
    return(0);
}

