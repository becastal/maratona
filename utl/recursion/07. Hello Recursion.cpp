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
	for (int i = 0; i < t; i++)
	{
		int n; cin >> n;
		vector<int> v(n);
		for (int& vi : v)
			cin >> vi;

		function<int(int)> f = [&] (int a) {
			if (a < 0) return 0;
			return v[a] + f(a - 1);
		};

		cout << "Case " << i + 1 << ": " << f(n - 1) << endl;
	}
    
    return(0);
}
