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

	set<string> S;
	string s;
	while (getline(cin, s)) {
		string b = "";
		for (char c : s) {
			if ((c >= 'A' and c <= 'Z') or (c >= 'a' and c <= 'z')) b.push_back(tolower(c));
			else {
				if (b.size()) S.emplace(b);
				b = "";
			}
		}
		if (b.size()) S.emplace(b);
	}

	for (auto si : S) {
		cout << si << endl;
	}
    
    return(0);
}
