#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

#define f first
#define s second

#define vi vector<int>
#define grafo vector<vector<int>>

#define dbg(x) cout << #x << " = " << x << endl;

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

// LIS sendo calculador por meio de busca binaria, 
// podendo retornar os elementos da maior
// subsequencia ou somente o tamanho dela
// Complexity: O(n * logN) | Space: O(N)
int lis(vector<int>& arr , int n){
	vector<int> d(n+1 , INF) , prev(n , -1) , pos(n+1 , -1);

	d[0] = -INF;

	for(int i = 0 ; i < n ; i++){
		int l = upper_bound(d.begin() , d.end() , arr[i]) - d.begin();

		if(d[l-1] < arr[i] and arr[i] < d[l]){
			d[l] = arr[i];
			pos[l] = i;
			prev[i] = pos[l-1];
		}
	}
	
	int ans = 0;

	for(int l = 0 ; l <= n ; l++){
		if(d[l] < INF)
			ans = l;
	} 
	
	vector<int> subseq;
	int k = pos[ans];
	
	while(k != -1){
		subseq.push_back(arr[k]);
		k = prev[k];
	}

	reverse(subseq.begin() , subseq.end());

	for(int& x : subseq) cout << x << ' ';cout<<endl;

	return ans;
}

int main(){ _
	vector<int> v = {7 , 3 , 5 , 3 , 6 , 2 , 9 , 8};

	cout << lis(v , 8) << endl;

	return 0;
}
