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
const int MAX = 1e6+10;

int sum(int num){
	int s = 0;

	while(num != 0){
		s += num%10;
		num/=10;
	}
	return s;
}

int v[MAX];
int main()
{
    _;
   	memset(v, 0, sizeof v);

	int n, pos;cin>>n>>pos;
	int maxi = -INF;	
	for(int i = 0 ; i < n; i++){
		int flor;cin>>flor;
		maxi =max(maxi,flor);
		v[flor]++;
	}
	int save = 0;
	for(int i = maxi; i >= 0; i--){
		if(v[i]==0)continue;
		if(pos <= 0)break;	
		pos-=v[i];
		save = sum(i);
		v[i-save]+=v[i];
	}
	cout << save << endl;
    return(0);
}
