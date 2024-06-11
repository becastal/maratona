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
		int a; cin >> a;
		double r = sqrt((double) a / (4.0 * 3.14));

		string cor = ""; double valor = 0;
		if (r < 12.0)
		{
			cor = "vermelho";
			valor =  a * 0.09;
		}
		else if (r >= 12.0 and r <= 15.0)
		{
			cor = "azul";
			valor = a * 0.07;
		}
		else
		{
			cor = "amarelo";
			valor = a * 0.05;
		}
		
		cout << cor << " = R$ " << fixed << setprecision(2) << valor << endl;
	}
    
    return(0);
}
