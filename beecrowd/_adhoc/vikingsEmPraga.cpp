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

	int m, c = 0;
	while (cin >> m and m)
	{
		cout << "Instancia " << ++c << endl;
		vector<char> alf(26);
		iota(alf.begin(), alf.end(), 'A');

		for (int i = 0; i < m; i++)
		{
			int ai; cin >> ai; ai--;
			char ch = alf[ai];
			alf.erase(alf.begin() + ai);
			alf.insert(alf.begin(), ch);
			cout << ch;
		}
		cout << endl << endl;
	}
    
    return(0);
}
