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
	int n, k;cin>>n>>k;    
	
	queue<int> q;
	int c;

	for(int i = 0; i < k; i++){
		cin>>c;
		q.push(c);
	}

	vector<int> v;
	int cont = 0;

	for(int i = 1; i <= n; i++){
		cont++;
		if(i == q.front()){
			q.pop();
			v.push_back(cont);
			cont = 0;
		}
	}

	int r = 0;
	for(int i = 0; i < v.size(); i++){
		r+= v[i] * (1<<i+1); 
		cout << r << endl;
	}

	cout << r + n - c << endl;

    return(0);
}
