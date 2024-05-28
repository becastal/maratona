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

int todos(vector<int> v)
{
	for (auto vi : v)
		if (vi < 1) return 0;

	return 1;
}

int main()
{
    _;

	int n, m, r = 0;
	cin >> n >> m;

	while (n--)
	{
		vector<int> v(m);
		for (auto& vi : v)
			cin >> vi;

		r += todos(v);
	}

	cout << r << endl;
    
    return(0);
}
