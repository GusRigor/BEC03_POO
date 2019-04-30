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
    cout<<"Estado: "<<estado<<endl;
  }
  virtual int proximoValor(int estado, int posicao, int *saida){
    return 0;
  }
  int getestado(){
    return estado;
  }
};
class Portao: public ME{
  int proximoValor(int entrada, int posicao, int *saida){
    
    if(entrada!=0){
      if(entrada!=1){
        estado=estado;
        *saida=estado;
        return estado;
      }//para números inválido
    }
    else
    if(entrada==0 && estado==0){
      estado=estado;
      *saida=entrada;

      return estado;
    }if(entrada==1 && estado==0){
        estado=estado+1;
        *saida=estado;

        return estado;
    }
    if(entrada==1 && estado==1){
      estado=estado+1;
      *saida=estado;

      return estado;
    }
    if(entrada==1 && estado==2){
      estado=estado;
      *saida=estado;

      return estado;
    }
    if(entrada==0 && estado==2){
      estado=estado-1;
      *saida=estado;

      return estado;
    }
    if(entrada==0 && estado==1){
      estado=estado-1;
      *saida=estado;

      return estado;
    }
  }

};
/*entrada = carro na entrada
saida	= estado do Portao
A saida do veiculo não é necessária, uma vez que
se o portao está aberto totalmente e a entrada está
vazia ele não precisa verificar a saida, partindo do 
principio que ele tem um estado intermediário. 
*/ 
int main(){
  Portao G;

  int tamanho=6;
  int entrada[]={0, 1, 1, 1, 0, 0};
  int saida[tamanho];

  cout<<"Portao da garragem"<<endl;

  G.transduce(entrada, tamanho, saida);
  for(int i=0; i<tamanho; i++){ 
    string tempEnt, tempPort;
    cout<<"Momento "<<i<<": ";
    tempEnt="Veículo na entrada e ";
    if(entrada[i]==0){
      tempEnt="Entrada vazia e ";
    }
    tempPort="o portão está fechado.";
    if(saida[i]==1){
      tempPort="o portão está se movendo.";  
    }
    if(saida[i]==2){
      tempPort="o portão está aberto.";  
    }
    cout<<tempEnt<<tempPort<<endl;
  }
  return 0;
} 

