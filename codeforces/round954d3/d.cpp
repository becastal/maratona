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
		int n; cin >> n;
		string s; cin >> s;
		// achar o maior numero de dois digitos, colocar alguma expressao entre todos os outros.
		// depois, entre num a e b colocar sempre '*' a nao ser que a ou b <= 1

		if (n == 2) { cout << s << endl; continue; }

		vector<vector<int>> perm;
		vector<int> v(n - 1, 1)
		for (int i = 0; i < n - 1; i++)
		{
			
		}
	}
    
    return(0);
}
