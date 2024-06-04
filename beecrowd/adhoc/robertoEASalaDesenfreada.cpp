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

	int n;
	while (cin >> n)
	{
		vector<int> v(3);
		while (n--)
		{
			int num; cin >> num;
			string s; cin >> s;
			if (s == "EPR") v[0]++;
			else if (s == "EHD") v[1]++;
			else v[2]++;
		}

		cout << "EPR: " << v[0] << endl;
		cout << "EDH: " << v[1] << endl;
		cout << "INTRUSOS: " << v[2] << endl;
	}
    
    return(0);
}
