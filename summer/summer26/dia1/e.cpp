#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll


signed main()
{
    _;

   	int n;

	while(cin>>n, n != 0){
		queue<int> q;
		stack<int> st;

		for(int i = 0; i < n; i++){
			int x;cin>>x;
			q.push(x);
		}
		
		int act = 1;

		while(q.size()){
			if(q.front() == act) act++;
			else st.push(q.front());
			q.pop();

			while(st.size()){
				if(st.top() == act) act++;
				else break;
				st.pop();
			}

		}

		cout<<(st.empty() ? "yes" : "no")<<endl;
	}
    return(0);
}
