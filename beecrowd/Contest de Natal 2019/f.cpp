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
		for (char& c : s) {
			if (c == '@') c = 'a';
			if (c == '&') c = 'e';
			if (c == '!') c = 'i';
			if (c == '*') c = 'o';
			if (c == '#') c = 'u';
		}
		
		cout << s << endl;
	}
    
    return(0);
}
