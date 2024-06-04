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

	int n;
	while (cin >> n and n)
	{
		int cont = 0;
		while (true)
		{
			cont++;
			vector<int> v(n);
			for (auto& vi : v)
				cin >> vi;

			bool ord = true;
			for (int i = 0; i < n - 1; i++)
				if (v[i] > v[i + 1])
					ord = false;
			if (ord) break;
		}
		cout << cont << endl; 
	}
    
    return(0);
}
