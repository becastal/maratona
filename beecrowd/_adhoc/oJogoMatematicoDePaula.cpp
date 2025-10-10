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
	for (int i = 0; i < t; i++)
	{
		char a, b, c; cin >> a >> b >> c;
		int ai = a - '0';
		int ci = c - '0';

		if (ai == ci)
			cout << ai * ci << endl;
		else if (b >= 'A' and b <= 'Z')
			cout << ci - ai << endl;
		else if (b >= 'a' and b <= 'z')
			cout << ci + ai << endl;
	}
    
    return(0);
}
