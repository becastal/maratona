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

	double o, b, c; cin >> o >> b >> c;

	if (o < b and o < c)
		cout << "Otavio" << endl;
	else if (b < o and b < c)
		cout << "Bruno" << endl;
	else if (c < o and c < b)
		cout << "Ian" << endl;
	else
		cout << "Empate" << endl;

    return(0);
}
