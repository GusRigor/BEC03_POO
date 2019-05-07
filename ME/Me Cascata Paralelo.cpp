#include <iostream>
using namespace std;
class ME{
  protected:
    int estado;
  public:
    ME(){
      estado=0;
    }
    ME(int valor){
      estado=valor;
    }
  void step(int entrada, int posicao, int *saida){
    estado=proximoValor(entrada, posicao, saida);
  }
  void transduce(int *entrada, int tamanho, int *saida){
    for(int i=0;i<tamanho;i++){
      step(entrada[i],i ,&saida[i]);
    }
  }
  void imprime(){
    cout<<"estado: "<<estado<<endl;
  }
  virtual int proximoValor(int estado, int posicao, int *saida){
    return 0;
  }
  int getestado(){
    return estado;
  }
};

class Acumulador:public ME{
  protected:
    int valor;
  public:
    Acumulador(int valor){
      estado=valor;
  }
  int proximoValor(int entrada, int posicao, int *saida){   
    estado=estado+entrada;
    *saida=estado;
    return estado;
  }
};
class Delay:public ME{
  protected:
    int valor;
  public:
    Delay(int valor){
      estado=valor;
  }
  int proximoValor(int entrada, int posicao, int *saida){
    int temp = estado;
    estado=entrada;
    *saida=temp;
    return estado;
  }
};
class CascataParalelo:public ME{
  protected:
  ME *me1, *me2;
  public:
  CascataParalelo(ME *m1, ME *m2){  
    me1=m1;
    me2=m2;
  }
  int proximoValor(int entrada, int posicao, int *saida){
    int temp;
    me1-> proximoValor(entrada, posicao, &temp);
    me2-> proximoValor(entrada, posicao, saida);

    *saida=*saida+temp;
    return *saida;
  }
};
int main() {
  Delay U(0);
  Acumulador S(0);
  CascataParalelo cst(&S,&U);
  int tamanho=5;
  int entrada[]={1, 3, 1, 1, 5};
  int saida[tamanho];
  
  cout<<endl;
  cout<<"Cascata"<<endl;
  cst.transduce(entrada, tamanho, saida);
  for(int i=0; i<tamanho; i++)
  cout<<"entrada "<<entrada[i]<<" saída "<<saida[i]<<endl;

}
