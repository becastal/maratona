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

	vector<int> v(1e6, 0);
	v[0] = 2, v[1] = 4;
	for (int i = 2; i < 1e6; i++)
		v[i] = v[i - 1] + 1 + i;

	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		cout << v[n - 1] << endl;
	}
    
    return(0);
}
