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
	

	int n, alt;

	cin >> n >> alt;

	int cont = 0;

	while(n--){
		int alt2;

		cin >> alt2;

		if(alt >= alt2){
			cont++;	
		}
	}

	cout << cont << endl;
    return(0);
}
