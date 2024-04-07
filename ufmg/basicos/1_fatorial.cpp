// https://neps.academy/br/course/introducao-a-programacao/lesson/fatorial

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
using namespace std;

int main()
{ _
	int n; cin >> n;
    int resultado = 1;
    
    for (int i = 2; i <= n; i++)
    {
        resultado *= i;
    }
    cout << resultado << endl;
}