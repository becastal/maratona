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
	while (t--)
	{
		string s; cin >> s;
		bool good = false;
		good = (s.find("010") != string::npos or s.find("101") != string::npos);
		cout << (good ? "Good" : "Bad") << endl;
	}
    
    return(0);
}
