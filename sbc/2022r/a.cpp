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
	string x;cin>>x;

	int a = 0 , b = 0 , cont = 0;;

	for(char& c : x){

			if(c == 'b'){if(a!=1)cont+=a;a=0;}

			else a++;
				
		}
		if(a!=1)cont+=a;
		cout << cont << endl;
    return(0);
}
