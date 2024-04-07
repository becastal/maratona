#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    int inicioHora, inicioMinuto;
    cin>>inicioHora>>inicioMinuto;

    int fimHora, fimMinuto;
    cin>>fimHora>>fimMinuto;

    int fim, inicio;
    fim = fimHora * 60 + fimMinuto;
    inicio = inicioHora * 60 + inicioMinuto;

    int totalHora, totalMinuto;
    if (inicio == fim)
    {
        totalHora = 24;
        totalMinuto = 0;
    }
    else
    {
        if (inicio > fim)
        {
            fim += 24*60;
        }
        totalHora = (fim - inicio) / 60;
        totalMinuto = fim - inicio - ((fim - inicio) / 60)*60;
    }
    cout<<"O JOGO DUROU "<<totalHora<<" HORA(S) E "<<totalMinuto<<" MINUTO(S)"<<endl;
}
