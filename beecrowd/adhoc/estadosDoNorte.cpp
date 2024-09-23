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

	string s; cin >> s;
	cout << (s == "roraima" or
			 s == "acre" or 
			 s == "amapa" or 
			 s == "amazonas" or 
			 s == "para" or 
			 s == "rondonia" or 
			 s == "tocantins" ? "Regiao Norte" : "Outra regiao") << endl; 

    
    return(0);
}
