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
	
	ll sp,sm,dp,dm,tp,tm,e; cin >> sp >> sm >> dp >> dm >> tp >> tm >> e;

	ll MIN = min(dp,dm);


	ll dia = 0, minu = dia;

	if(MIN == dp){
		dia = e - sp;
		if (!dia) dia++, minu = tp;
		else minu = dia * 4 * tp;

		ll pts = dia * dm;
		ll temp = 4 * tm * dia;

		minu+= temp;

		ll obj = e - dp;


		while(pts - dm >= obj){
			pts-= dm;
			minu-=tm*2*3;
		}

		cout << dia << endl;
		cout<< minu<<endl;
	
	}

	else{
		dia = e - sm;
		if (!dia) dia++, minu = tm;
		else minu = dia * 4 * tm;

		ll pts = dia * dp;
		ll temp = 4 * tp * dia;

		minu+= temp;

		ll obj = e - dm;


		while(pts - dp >= obj){
			pts-= dp;
			minu-=tp*2*3;
		}

		cout << dia << endl;
		cout<< minu<<endl;
	}

	


    return(0);
}
