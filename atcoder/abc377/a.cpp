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
	set<char> S = {s[0], s[1], s[2]};
	if (S.count('A') and S.count('B') and S.count('C')) return cout << "Yes" << endl, 0;
	cout << "No" << endl;
    
    return(0);
}
