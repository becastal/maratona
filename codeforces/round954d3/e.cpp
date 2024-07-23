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
		int n, k; cin >> n >> k;
		vector<int> v(n);
		for (int& vi : v)
			cin >> vi;
		sort(v.begin(), v.end());

		int resa = 0;
		for (int i = 0; i < n; i += 2)
			if (i + 1 < n and i < n)
				resa += ((v[i + 1] - v[i]) + k - 1) / k;

		int resb = 0;
		for (int i = n - 1; i >= 0; i -= 2)
			if (i - 1 >= 0 and i >= 0)
				resb += ((v[i] - v[i - 1]) + k - 1) / k;

		cout << min(resa, resb) << endl;
	}
    
    return(0);
}
