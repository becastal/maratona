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
		string a, b; cin >> a >> b;
		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());
		bool r = true;
		
		for (int i = 0; i < b.size(); i++)
			r = r and b[i] == a[i];

		cout << (r ? "encaixa" : "nao encaixa") << endl;
	}
    
    return(0);
}
