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

	string s;
	while (getline(cin, s)) {
		for (int i = 0; i < (int)s.size()-1; i++) {
			if (s[i] == ' ' and (s[i+1] == '.' or s[i+1] == ',')) continue;
			cout << s[i];
		}
		cout << s.back() << endl;
	}
    
    return(0);
}
