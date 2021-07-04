#ifndef tInvesitmentos_H
#define tInvesitmentos_H
#include <math.h>

using namespace std;

struct tInvestimentos{
  float cinValorInicial(){
    float vInicial;
    cout << "Digite o capital inicial: R$"; 
    cin >> vInicial;
    return (vInicial);
  }
  float cinTaxa(){
    float taxa;
    cout << "Digite a taxa anual: "; 
    cin >> taxa;
    taxa = taxa / 100; //transformando pra usar nas contas
    return (taxa);
  }
  float cinTempo(){
    float tempo;
    cout << "Digite o tempo de aplicacao em anos: "; 
    cin >> tempo;
    return (tempo);
  }
};

float Simples(float principal, float taxa, float anos)
{ 
  return (principal * (1 + (taxa * anos)));
}
float Composto(float principal, float taxa, float anos)
{   
  return (principal * pow((1 + taxa), anos));
}
#endif
