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
	int c = 0;
	while (t--)
	{
		int n; cin >> n;
		vector<int> v(n);
		for (int& vi : v)
			cin >> vi;
		sort(v.begin(), v.end());

		cout << "Case " << ++c << ": " << (v[n / 2]) << endl;
	}
    
    return(0);
}
