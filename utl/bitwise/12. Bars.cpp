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
		int n, p; cin >> n >> p;
		vector<int> v(p);
		for (int& vi : v)
			cin >> vi;

		bitset<100001> da;
		da[0] = 1;
		
		for (int vi : v)
			da |= da << vi;

		cout << (da[n] ? "YES" : "NO") << endl;
	}
    
    return(0);
}
