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

void rec(int n)
{
	if (n - 1) rec(n - 1);	
	cout << "I love Recursion" << endl;
}

int main()
{
    _;

	int n; cin >> n;
	rec(n);
    
    return(0);
}
