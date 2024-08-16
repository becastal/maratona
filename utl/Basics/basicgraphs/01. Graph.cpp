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
	vector<vector<bool>> v(n, vector<bool>(n, 0));

	for (int i = 0; i < n; i++)
	{
		int ni, qi; cin >> ni >> qi; ni--;
		while(qi--)
		{
			int ai; cin >> ai; ai--;
			v[ni][ai] = 1;
		}
	}

	for (auto i : v)
	{
		for (auto j : i)
			cout << j << ' ';
		cout << endl;
	}
    
    return(0);
}
