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

	int n, r;
	while (cin >> n >> r)
	{
		vector<int> v(n, 0);
		for (int i = 0; i < r; i++)
		{
			int vi; cin >> vi; vi--;
			v[vi] = 1;
		}

		for (int i = 0; i < n; i++)
			if (!v[i]) 
				cout << i + 1 << ' ';

		cout << (n == r ? "*" : "") << endl;
	}
    
    return(0);
}
