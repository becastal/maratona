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
    
	int r, g, b;
	cin >> r >> g >> b;

	string s; cin >> s;
	if (s == "Red") cout << min(g, b) << endl;
	else if (s == "Green") cout << min(r, b) << endl;
	else if (s == "Blue") cout << min(r, g) << endl;

    return(0);
}
