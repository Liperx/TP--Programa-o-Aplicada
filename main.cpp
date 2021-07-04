#include <iostream>
#include <math.h>
#include <fstream>
#include "investimento.h"
#include "listaEncadeada.h"
using namespace std;

int main() {
  //define as variaveis a serem utilizadas
  char menu, opmenu;
  int n=0;
  tInvestimentos valores;

  //iniciar a lista
  tLista* invest = new tLista;
  //guarda um espaco de memoria para a lista nula
  iniciarLista(invest);
  do{
    cout<<"\n\n--------------------------------------\n\n";
    cout<<"*    CALCULADORA DE JUROS V1.0    *\n\n";
    cout<<"--------------------------------------\n";
    cout<<" 1 - Gravar informacoes no arquivo\n";
    cout<<" 2 - Ler informacoes do arquivo\n";
    cout<<" 0 - SAIR\n";
    cout<<"\n \n";
    cout<<"DIGITE UMA OPÇÃO DESEJADA: ";
    cin >> menu;

    switch (menu) {
      case '1': {
        system("clear");
        fflush(stdin);
        cout<<"--------------------------------------\n\n";
        cout<<"*    GRAVAR INFORMACOES NO ARQUIVO    *\n\n";
        cout<<"--------------------------------------\n";
        cout << " Quantos valores de capital, taxa e tempo deseja adicionar? ";
        cin >> n;

        for(int i=0; i<n; i++){
          //recebe o valor do capital digitado
          float capital = valores.cinValorInicial();

          //recebe o valor da taxa digitado
          float taxa = valores.cinTaxa();

          //recebe o valor do tempo digitado
          float tempo = valores.cinTempo();

          //calcula o valor do montate simples
          float montanteS = Simples(capital, taxa, tempo);

          //calcula o valor do montate composto
          float montanteC = Composto(capital, taxa, tempo);

          //Inclui os valoers na lista encadeada;
          incluirElemento(invest, capital);
          incluirElemento(invest, taxa);
          incluirElemento(invest, tempo);
          incluirElemento(invest, montanteS);
          incluirElemento(invest, montanteC);
        }

        //grava todos valores da lista no aarquivo
        gravarLista(invest);
        
        //volta a lista para o valor nulo
        iniciarLista(invest);
    
        break;
      }
      case '2': {
        //le as informacoes do arquivo
        lerInformacoes(invest);

        //imprime os valores lidos do arquivo
        imprimirLista(invest);

        //volta a lista para o valor nulo
        iniciarLista(invest);
        break;
      }
      default: {
        cout<<"FECHANDO... \n";
        break;  
      }
    }
  }while (menu!='0');
}