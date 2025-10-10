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

	double a, c, x, y;
	cin >> a >> c >> x >> y;

	if (a + 1 <= c - (x + y))
		cout << "Igor feliz!" << endl;
	else
		if (x > y / 2.0)
			cout << "Caio, a culpa eh sua!" << endl;
		else
			cout << "Igor bolado!" << endl;
    
    return(0);
}
