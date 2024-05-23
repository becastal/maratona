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

	int l = 1, r = 1e6;

	while (l < r)
	{
		int m = (l + r + 1) / 2;
		cout << m << endl;
		cout << flush;
		
		string resp; 
		cin >> resp;	
		
		if (resp == ">=")
			l = m;
		else
			r = m - 1;
	}

	cout << "! " << l << endl;
	cout << flush;
    
    return(0);
}
