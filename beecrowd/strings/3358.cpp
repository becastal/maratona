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

	auto vog = [](char c) {
		c = tolower(c);	
		return c == 'a' or c == 'e' or c == 'i' or c == 'o' or  c == 'u';
	};

	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		int ok = 1;
		for (int i = 0; i < (int)s.size()-2 and ok; i++) {
			ok &= vog(s[i]) or vog(s[i+1]) or vog(s[i+2]);
		}
		cout << s << (ok ? " eh facil" : " nao eh facil") << endl;
	}
    
    return(0);
}
