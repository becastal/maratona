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
    
	string s; cin >> s;
	int n = (int)s.size();
	if (n >= 3 and s[n-1] == 'n' and s[n-2] == 'a' and s[n-3] == 's') cout << "Yes" << endl;
	else cout << "No" << endl;

    return(0);
}
