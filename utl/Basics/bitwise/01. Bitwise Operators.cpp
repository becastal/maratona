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

	int n, k; cin >> n >> k;
	int mand = -INF, mor = -INF, mxor = -INF;
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
		{
			if ((i & j) > mand and (i & j) < k) mand = i & j;
			if ((i | j) > mor  and (i | j) < k) mor = i | j;
			if ((i ^ j) > mxor and (i ^ j) < k) mxor = i ^ j;
		}

	cout << mand << endl << mor << endl << mxor << endl;
    
    return(0);
}
