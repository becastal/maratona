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
	cin.ignore();

	while (t--) {
		string s; getline(cin, s);
		vector<int> cont(26, 0);
		int mx = 0;

		for (char& c : s) {
			if (c >= 'A' and c <= 'Z') c -= 'A' - 'a';
			if (c >= 'a' and c <= 'z') cont[c-'a']++, mx = max(mx, cont[c-'a']);
		}

		for (int i = 0; i < 26; i++) {
			if (cont[i] == mx) {
				cout << char('a'+i);
			}
		}
		cout << endl;
	}
    
    return(0);
}
