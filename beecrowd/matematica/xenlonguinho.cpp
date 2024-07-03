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

int qdiv(int x)
{
	int q = 0;
	for (int i = 2; i < x; i++)
		if (x % i == 0)
			q++;
	return q;
}

int main()
{
    _;

	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		int q = 0;
		for (int i = 1; i < n; i++)
			if (qdiv(i) % 2 == 0)
				q++;
		cout << q << endl;
	}
    
    return(0);
}
