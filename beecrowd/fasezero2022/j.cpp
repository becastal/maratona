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
		int oi; cin >> oi;
		string tempo; cin >> tempo;
		
		int diff = (tempo == "2T" ? 45 : 0);

		if (oi <= 45)
			cout << oi + diff << endl;
		else
			cout << oi - (oi % 45) + diff << '+' << (oi % 45) << endl;
	}
    
    return(0);
}
