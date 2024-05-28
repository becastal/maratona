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

bool solve()
{
	int n, la, lb, sa, sb; cin >> n >> la >> lb >> sa >> sb;
	return (n >= la and n <= lb and n >= sa and n <= sb);
}

int main()
{
    _;
    
	cout << (solve() ? "possivel" : "impossivel") << endl;
	
    return(0);
}
