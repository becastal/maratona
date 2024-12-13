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
	int to;
	for (int i = 0; i < 26; i++) {
		if (s[i] == 'A') to = i;
	}

	int res = 0;
	for (int i = 1; i < 26; i++) {
		int novo;
		for (int j = 0; j < 26; j++) {
			if (s[j] == char('A' + i)) {
				novo  = j;
				break;
			}
		}

		res += abs(to - novo);
		to = novo;
	}
	cout << res << endl;
    
    return(0);
}
