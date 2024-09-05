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
	int disp, c, r;cin>>disp>>c>>r;

	queue<int> pos, neg;

	int n;

	for(int i = 0; i < c; i++){
		cin>>n;
		neg.push(n);
	}
	for(int i = 0; i < r; i++){
		cin>>n;
		pos.push(n);
	}
	int cont = 0;
	while(1){
		if(neg.empty())break;
		if(disp < neg.front()){
			if(pos.empty())break;
			cont++;
			disp += pos.front();pos.pop();
		}else{
			disp -= neg.front();neg.pop();
			cont++;
		}	
	}
	cont += pos.size();
	cout << cont << endl;
    return(0);
}
