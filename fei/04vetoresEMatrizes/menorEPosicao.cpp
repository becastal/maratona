#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main()
{
    vector<int> nums;
    int i;
    cin>>i;

    nums.push_back(0);
    cin>>nums[0];
    int menor = nums[0], posicaoMenor = 0;
    for (int j = 1; j < i; j++)
    {
        nums.push_back(0);
        cin>>nums[j];
        if (nums[j] < menor)
        {
            menor = nums[j];
            posicaoMenor = j;
        }
    }
    
    cout<<"Menor valor: "<<menor<<endl;
    cout<<"Posicao: "<<posicaoMenor<<endl;
    return 0;
}