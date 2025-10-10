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
#define erro { cout << "error" << endl; continue; }

int main()
{
    _;

	string s;
	while (getline(cin, s)) {
		if (s.empty()) erro;

		int ruim = 0;
		string res = "";
		for (char c : s) {
			if (c >= '0' and c <= '9') res.push_back(c);
			else if (c == 'O' or c == 'o') res.push_back('0');
			else if (c == 'l') res.push_back('1');
			else if (isalpha(c)) ruim = 1;
		}

		if (ruim) erro;
		
		if (res.empty()) erro;	
		if (res[0] == '0') {
			reverse(res.begin(), res.end());
			while (res.back() == '0') {
				res.pop_back();
			}
			reverse(res.begin(), res.end());
		}

		if (res.empty()) {
			cout << 0 << endl;
			continue;
		}

		string talo = "2147483647";
		if (res.size() > talo.size() or (res.size() == talo.size() and res > talo)) erro;
		cout << res << endl;
	}
    
    return(0);
}
