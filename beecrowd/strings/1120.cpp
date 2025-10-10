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

	char d; string s;
	while (cin >> d >> s and s != "0") {
		string si = "";
		for (char c : s) {
			if (c == d) continue;
			si.push_back(c);
		}

		if (si == "") {
			cout << 0 << endl;
			continue;
		}
		
		if (si[0] == '0') {
			reverse(si.begin(), si.end());

			while (!si.empty() and si.back() == '0') {
				si.pop_back();
			}

			reverse(si.begin(), si.end());
		}
		
		if (si == "") {
			cout << 0 << endl;
			continue;
		}

		cout << si << endl;
	}
    
    return(0);
}
