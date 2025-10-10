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

	string a, b; cin >> a >> b;

	if (a == "sick" and b == "fine") {
		cout << 2 << endl;
	} else if(a == "fine" and b == "sick")  {
		cout << 3 << endl;
	}  else if (a == "fine" and b == "fine"){
		cout << 4 << endl;
	} else {
		cout << 1 << endl;

	}
    
    return(0);
}
