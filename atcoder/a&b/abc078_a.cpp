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

	char a, b; cin >> a >> b;
	if (a == b) return cout << '=' << endl, 0;
	if (a < b) return cout << '<' << endl, 0;
	cout << '>' << endl;
    
    return(0);
}