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

	int a, b; cin >> a >> b;
	if (a >= 0 and b <= 2)
		cout << "nova" << endl;
	else if (a < b and b <= 96)
		cout << "crescente" << endl;
	else if (a >= b and b <= 96)
		cout << "minguante" << endl;
	else
		cout << "cheia" << endl;
    
    return(0);
}
