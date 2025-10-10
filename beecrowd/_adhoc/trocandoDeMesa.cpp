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
	vector<int> v(n);
	iota(v.begin(), v.end(), 1);


	int q; cin >> q;
	for (int i = 0; i < q; i++)
	{
		int e; cin >> e;
		if (e == 1)
		{
			int a, b; cin >> a >> b;
			swap(v[a - 1], v[b - 1]);	
		}
		else
		{
			int a; cin >> a;
			int qi = a - 1, cont = 0;
			while (v[qi] != a)
			{
				qi = v[qi] - 1;
				cont++;
			}
			cout << cont << endl;
		}
	}

    
    return(0);
}
