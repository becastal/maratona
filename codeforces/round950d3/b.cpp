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
		int n, f, k; cin >> n >> f >> k; f--, k--;
		vector<int> v(n), cont(101, 0);
		for (int& vi : v)
		{
			cin >> vi;
			cont[vi]++;
		}

		if (k == n) { cout << "YES" << endl; continue; }
		int fi = v[f];
		sort(v.rbegin(), v.rend());
		
		if (v[k] > fi)
			cout << "NO" << endl;
		else if (v[k] < fi)
			cout << "YES" << endl;
		else
			cout << (k == n - 1 or v[k + 1] < fi ? "YES" : "MAYBE") << endl;
	}
    
    return(0);
}
