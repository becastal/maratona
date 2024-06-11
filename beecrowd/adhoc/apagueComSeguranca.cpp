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

	int n; cin >> n;
	n %= 2;
	string a, b; cin >> a >> b;
	
	bool ok = true;
    n %= 2;
    if(!n)
        if(a != b)
			ok = false;
	else
	{
        for(int i = 0; i < a.size(); i++)
            if(a[i] == b[i])
			{
                ok = false;
                break;
            }
    }

	cout << (ok ? "Deletion succeeded" : "Deletion failed") << endl;

    return(0);
}
