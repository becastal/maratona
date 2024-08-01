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
	int res = 0;
 
	int r = 0;
	for (int l = 0; l < (int)s.size(); l++)
	{
		while (s[l] == s[r])
			r++;
 
		res = max(res, r - l);
	}
 
	cout << res << endl;
    
    return(0);
}
