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

	string a, b;
	while (cin >> a >> b) {
		reverse(a.begin(), a.end());
		string res = "";

		int cont = 0;
		for (char c : a) {
			if (cont++ % 3 == 0 and cont != 1) res.push_back(',');
			res.push_back(c);
		}
		reverse(res.begin(), res.end());
		cout << "$" << res << "." << setw(2) << setfill('0') << b << endl;
	}
    
    return(0);
}
