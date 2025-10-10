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

	vector<int> v(n+1);
	
	int MAX = -INF;

	while(k--){
		int a, b;cin>>a>>b;

		v[a]++, v[b]++;

		MAX = max({v[a], v[b], MAX});
	}
   	
	priority_queue<int, vector<int>, greater<int>> pq;

	for(int i = 1; i <= n; i++) pq.push(v[i]);

	while(pq.top() != MAX){
		int a = pq.top(); pq.pop();
		int b = pq.top(); pq.pop();

		a++, b++;
		
		pq.push(a), pq.push(b);
		MAX = max({a, b, MAX});
	}
	cout<<MAX<<endl;
    return(0);
}
