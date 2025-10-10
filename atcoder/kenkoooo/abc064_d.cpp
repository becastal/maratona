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
	string s; cin >> s;

	int bal = 0, mn = 0;
	for (int i = 0; i < n; i++) {
		bal += (s[i] == '(' ? 1 : -1);
		mn = min(mn, bal);
	}

	mn *= -1;
	cout << string(mn, '(') + s + string(bal + mn, ')') << endl;
    
    return(0);
}
