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

	int t; cin >> t; cin.ignore();
	while (t--) {
		string s; getline(cin, s);
		reverse(s.begin(), s.begin() + (int)s.size()/2);
		reverse(s.begin() + (int)s.size()/2, s.end());

		cout << s << endl;
	}
    
    return(0);
}
