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
class CascataSerie:public ME{
  protected:
  ME *me1, *me2;
  public:
  CascataSerie(ME *m1, ME *m2){  
    me1=m1;
    me2=m2;
  }
  int proximoValor(int entrada, int posicao, int *saida){
    int temp;
    me1-> proximoValor(entrada, posicao, &temp);
    me2-> proximoValor(temp, posicao, saida);
    return *saida;
  }
};
class Feedback:public ME{
  protected:
  ME *g;
  int vlrLoop;
  public:
  Feedback(ME *m){
    g=m;
  }
  int proximoValor(int entrada, int posicao, int *saida){
    if(posicao==0){
      g->proximoValor(estado, posicao, saida);
    }else{
      g->proximoValor(vlrLoop, posicao, saida);
    }
    cout<<"Feedback estado"<<estado<<endl;
    cout<<"Feedback loop"<<vlrLoop<<endl;
    cout<<"Feedback saida"<<*saida<<endl;
    vlrLoop=*saida;
    return*saida;

  }
    
};
int main() {
  
  Delay G(1),U(1),S(0);

  CascataSerie cst(&U, &S);

  CascataParalelo cstP(&G, &cst);

  Feedback fbk(&cstP);

  
  int tamanho=11;
  int entrada[]={1, 0, 1, 1, 5,1,1,1,1,1,1};
  int saida[tamanho];
  
  cout<<endl;
  cout<<"FIBONACCI"<<endl;
  fbk.transduce(entrada, tamanho, saida);
  for(int i=0; i<tamanho; i++)
  cout<<"entrada "<<entrada[i]<<" saída "<<saida[i]<<endl;

}
