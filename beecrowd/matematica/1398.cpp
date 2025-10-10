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

	const int p = 131071;

	string bin = "";
	char c;
	while (cin >> c) {
		if (c == '#') {
			int res = 0;
			for (int i = 0; i < (int)bin.size(); i++) {
				res = (res * 2 + bin[i] - '0') % p;
			}
			cout << (res ? "NO" : "YES") << endl;
			bin.clear();
		} else {
			if (c == '1' or c == '0') bin.push_back(c);
		}
	}
    
    return(0);
}
