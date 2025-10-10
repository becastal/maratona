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

	vector<string> r = {"Rolien", "Naej", "Elehcim", "Odranoel"};
	int n; cin >> n;
	while (n--)
	{
		int k; cin >> k;
		for (int i = 0; i < k; i++)
		{
			int cat; cin >> cat;
			cout << r[cat - 1] << endl;
		}
	}
    
    return(0);
}
