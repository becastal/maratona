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
	while (n--)
	{
		int m, v;
		char x; 
		pair<int, int> t1, t2;

		cin >> m >> x >> v;
		t1.f += m, t2.s += v;

		cin >> m >> x >> v;
		t1.s += v, t2.f += m;

		if (t1.f + t1.s > t2.f + t2.s)
			cout << "Time 1" << endl;
		else if (t1.f + t1.s < t2.f + t2.s)
			cout << "Time 2" << endl;
		else
		{
			if (t1.s > t2.s)
				cout << "Time 1" << endl;
			else if (t1.s < t2.s)
				cout << "Time 2" << endl;
			else
				cout << "Penaltis" << endl;
		}
	}
    
    return(0);
}
