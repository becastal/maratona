#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    int inicioDia, inicioHora, inicioMinuto, inicioSegundo, inicioTotal;
    int fimDia, fimHora, fimMinuto, fimSegundo, fimTotal;
    int total, rDia, rHora, rMinuto, rSegundo;
    string nul;

    cin>>nul;
    cin>>inicioDia;
    cin>>inicioHora;
    cin>>nul;
    cin>>inicioMinuto;
    cin>>nul;
    cin>>inicioSegundo;
    cin>>nul;
    cin>>fimDia;
    cin>>fimHora;
    cin>>nul;
    cin>>fimMinuto;
    cin>>nul;
    cin>>fimSegundo;
    cin>>nul;

    inicioTotal = (inicioDia * 86400) + (inicioHora * 3600) + (inicioMinuto * 60) + inicioSegundo;
    fimTotal = (fimDia * 86400) + (fimHora * 3600) + (fimMinuto * 60) + fimSegundo;
    total = fimTotal - inicioTotal;

    rDia = total / 86400;
    total -= rDia*86400;
    rHora = total / 3600;
    total -= rHora*3600;
    rMinuto = total / 60;
    total -= rMinuto*60;
    rSegundo = total;

    cout<<rDia<<" dia(s)"<<endl;
    cout<<rHora<<" hora(s)"<<endl;
    cout<<rMinuto<<" minuto(s)"<<endl;
    cout<<rSegundo<<" segundo(s)"<<endl;
}
