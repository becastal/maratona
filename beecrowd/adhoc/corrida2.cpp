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

	vector<pair<double, int>> v(2, {0.0, 0});
	for (int i = 0; i < v.size(); i++)
	{
		int n;
		double d, vi;
		cin >> n >> d >> vi;

		v[i].f = d / vi;
		v[i].s = n;
	}

	sort(v.begin(), v.end());
	cout << v[0].s << endl;
    
    return(0);
}
