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

	double melhor = INF;
	for (int i = 0; i < n; i++)
	{
		double p, g; cin >> p >> g;
		melhor = min(melhor, 1000 / g * p);
	}

	cout << fixed << setprecision(2) << melhor << endl;
    
    return(0);
}
