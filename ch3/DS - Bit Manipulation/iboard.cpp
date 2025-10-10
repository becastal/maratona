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
		int n = (int)s.size();

		int a = 0, b = 0;
		for (char c : s) {
			for (int i = 0; i < 7; i++) {
				if (c & (1 << i)) {
					a ^= 1; 
				} else {
					b ^= 1;
				}
			}
		}

		cout << (a or b ? "trapped" : "free") << endl;
	}
    
    return(0);
}
