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

	int t; cin >> t;
	while (t--) {
		string s; cin >> s;
	
		reverse(s.begin(), s.end());
		for (char& c : s) {
			if (c == 'p') c = 'q';
			else if (c == 'q') c = 'p';
		}

		cout << s << endl;
	}
    
    return(0);
}
