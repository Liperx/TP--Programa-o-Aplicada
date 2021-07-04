#include <iostream>

using namespace std;

struct tNo{
    float info;
    tNo* proximo;
};

struct tLista{
    tNo* primeiro;
    tNo* ultimo;
    tNo* marcador;
    int tamanho;
};

//inicia uma lista com 1 no e valores nulos
void iniciarLista(tLista* pLista){
    pLista->primeiro = NULL;
    pLista->ultimo = NULL;
    pLista->marcador = NULL;
    pLista->tamanho = 0;
}

//retorna o tamanho da lista
int obterTamanho(tLista* pLista){
    return (pLista->tamanho);
}

//retorna se a lista esta vazia
bool listaVazia(tLista* pLista){
    return (pLista->tamanho==0);
}

//retorna se e o fim da lista
bool finalLista(tLista* pLista){
    return (pLista->marcador == NULL);
}

//cria um no nulo para adicionar os valores
tNo* criaNo(float item){
    tNo* no = new tNo;

    no->info = item;
    no->proximo = NULL;

    return no;
}

//adiciona um elemento na ultima posicao da lista
void incluirElemento(tLista* pLista, float info){
    tNo* no;
    no = criaNo(info);

    if (listaVazia(pLista)){
      pLista->primeiro = no;
    }else{
      pLista->ultimo->proximo = no;
    }

    pLista->ultimo = no;
    pLista->marcador = no;
    pLista->tamanho++;
}

void imprimirLista(tLista* pLista){

  //retorna o marcador para o inicio da lsita
  pLista->marcador = pLista->primeiro;
  cout << "\n\n\n\n\n";
  cout << "-----------------------------------------" << endl;
  while(!finalLista(pLista)){

    //imprime em grupos de 5 em 5 todas as informacoes da lista
    float informacao = pLista->marcador->info;
    pLista->marcador = pLista->marcador->proximo;
  cout << "-----------------------------------------" << endl;
    cout << "            Capital inicial: R$ " << informacao << endl;

    informacao = pLista->marcador->info;
    pLista->marcador = pLista->marcador->proximo;
    cout << "              Taxa de juros: " << (informacao*100) << " %" << endl;

    informacao = pLista->marcador->info;
    pLista->marcador = pLista->marcador->proximo;
    cout << "         Tempo de aplicacao: " << informacao << " ano(s)" << endl;

    informacao = pLista->marcador->info;
    pLista->marcador = pLista->marcador->proximo;
    cout << "    Montante a juro Simples: R$ " << informacao << endl;

    informacao = pLista->marcador->info;
    pLista->marcador = pLista->marcador->proximo;
    cout << "   Montante a juro Composto: R$ " << informacao << endl;

    cout << "-----------------------------------------" << endl;
  }
  cout << "-----------------------------------------" << endl;
  cout << "\n\n\n";
}

void lerInformacoes(tLista* pLista){
  ifstream lerInfo;
  lerInfo.open("arquivo.txt", ios::in);

  //pLista->marcador = pLista->primeiro;

  //a leitura vai ser feita em grupos de 5
  //isso porque no arquivo foi gravado dessa forma: capital taxa tempo montanteSimples montanteComposto
  //a cada loop sera adicionada a informacao sobre um "grupo" completo de informacoes
  while(!lerInfo.eof()){
    float informacao;

    //le a primeira informacao: capital
    lerInfo >> informacao;
    incluirElemento(pLista, informacao);
    pLista->marcador = pLista->marcador->proximo;

    //le a segunda informacao: taxa
    lerInfo >> informacao;
    incluirElemento(pLista, informacao);
    pLista->marcador = pLista->marcador->proximo;

    //le a terceira informacao: tempo
    lerInfo >> informacao;
    incluirElemento(pLista, informacao);
    pLista->marcador = pLista->marcador->proximo;

    //le a quarta informacao: montante a juro simples
    lerInfo >> informacao;
    incluirElemento(pLista, informacao);
    pLista->marcador = pLista->marcador->proximo;

    //le a quinta informacao: montate a juro composto
    lerInfo >> informacao;
    incluirElemento(pLista, informacao);
    pLista->marcador = pLista->marcador->proximo;
  }
  //fecha o arquivo de leitura
  lerInfo.close();
}

void gravarLista(tLista* pLista){
  //define a variavel pra abrir o arquivo e escrever
  ofstream gravarInfo;
  //abre o arquivo para escrita
  gravarInfo.open("arquivo.txt", ios::out);

  //volta o marcador para a primeira posicao
  pLista->marcador = pLista->primeiro;

  //enquanto nao for o fim da lista encadeada ira executar o loop abaixo
  while(!finalLista(pLista)){
    //define uma variavel tipo float para receber a informacao do no
    float informacao = pLista->marcador->info;

    //se eu estiver na ultima posicao da lista entao nao sera adicionado o espaco no fim
    if (pLista->marcador == pLista->ultimo){
      gravarInfo << informacao;
    }else{
      gravarInfo << informacao << " ";
    }

    //adianta o marcador para a proxima posicao da lista
    pLista->marcador = pLista->marcador->proximo;
  }
  //fecha o arquivo de gravacao
  gravarInfo.close();
}