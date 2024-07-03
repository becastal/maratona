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

	int cont = 0;

	string pal; cin >> pal;

	int cm = 0;
	int cf = 0;

	for(int i = 1 ; i < pal.size() ; i++){
			if(pal[i] == 'M'){
					cm++;
					
					if((cm + cf) % 2 == 0)
						cont += (cont + 1) % mod;

					if(pal[i - 1] == 'F' and ((cf + cm - 2) % 2 == 0)
						cont++;
			}else{
					cf++;
					
					if((cm + cf) % 2 == 0) 
						cont++;

					if(pal[i - 1] == 'M' and ((cf + cm - 2)) % 2 == 0)
						cont++;
				}

		}
    
    return(0);
}
