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
		if (s[0] == '1' and s[1] == '0' and s.size() > 2) {
			int i = stoi(s.substr(2, 99));	
			if (i >= 2 and s[2] != '0') { 
				cout << "yes" << endl;
			} else {
				cout << "no" << endl;
			}
		} else {
			cout << "no" << endl;
		}
	}
    
    return(0);
}
