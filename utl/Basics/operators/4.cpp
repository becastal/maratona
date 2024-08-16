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
	
	cout << n / 365 << " years" << endl;
	n -= n / 365 * 365;
	cout << n / 30 << " months" << endl;
	n -= n / 30 * 30;
	cout << n << " days" << endl;
    
    return(0);
}
