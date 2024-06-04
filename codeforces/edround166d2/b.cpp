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
		int n; cin >> n;
		vector<int> a(n), b(n + 1);
		for (auto& ai : a)
			cin >> ai;
 
		for (auto& bi : b)
			cin >> bi;

		int menorPre = INF;
		for (auto ai : a)
			if (abs(b[n] - ai) < menorPre)
				menorPre = abs(b[n] - ai);
		menorPre++;
 
		int c = 0, menorPos = INF;
		for (int i = 0; i < n; i++)
		{
			if (a[i] != b[i] and max(a[i], b[i]) >= b[n] and min(a[i], b[i]) <= b[n])
				menorPos = min(menorPos, min(abs(a[i] - b[i]), abs(b[i] - b[n])));

			c += abs(a[i] - b[i]);
		}
 
 		if (menorPos != INF)
			c += menorPos;
		else
			c += menorPre;

		cout << c << endl;
	}
	
	return(0);
}
