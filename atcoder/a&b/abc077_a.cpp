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

	string a, b; cin >> a >> b;
	cout << (a[0] == b[2] and a[1] == b[1] and a[2] == b[0] ? "YES" : "NO") << endl;
    
    return(0);
}