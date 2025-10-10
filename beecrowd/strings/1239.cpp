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
		int a = 0, b = 0;
		for (char c : s) {
			if (c == '_') {
				cout << (a ? "</i>" : "<i>");
				a ^= 1;
			} else if (c == '*') {
				cout << (b ? "</b>" : "<b>");
				b ^= 1;
			} else {
				cout << c;
			}
		}
		cout << endl;
	}
    
    return(0);
}
