#include <iostream>

using namespace std;

//estrutura criada para implementar uma 
//fracao e as operacoes correspondentes
//e tambem manipular fracoes.

class fracao{
  private:
    int numerador;
    int denominador;


  public:
    fracao(){//construtor basico de fracao
      numerador=denominador=1;
  }
  
  //construtor de fracao onde sao
  //passados os valores do numerador e
  //do denominador
  fracao(int A, int B){
    if(B!=0){
      verificaSinal(&A,&B);
      numerador=A;
      denominador=B; 
    }
    else{
      cout<<"ERRO: Denominador nao pode ser zero!"<<endl;
      cout<<"Definindo fracao padrao: 1/1"<<endl;
      numerador=1;
      denominador=1;
    }
  }
  
  //verifica o sinal de cada termo da 
  //fracao de modo que o sinal negativo
  //esteja sempre no numerador da fracao
  private: void verificaSinal(int* A, int* B){
    if (((*A<0)&&(*B<0))||((*A>0)&&(*B<0))){
      *A=*A*-1;
      *B=*B*-1;
    }
  }
  
  //altera o valor do numerador
  public: void alteraNumerador(int A){
    numerador=A;
  }
  
  //altera o valor do denominador
  void alteraDenominador(int B){
    denominador=B;
  }
  
  //mostra uma fracao na tela.
  void mostraFracao(){
    cout<<numerador<<"/"<<denominador<<endl;
  }
  //mostra na tela a operacao sendo executada
  private: void imprimeOperacao(int a, int b, int c, int d, int e, int f, char operacao){
    cout<<a<<"/"<<b;
    cout<<" "<<operacao<<" ";
    cout<<c<<"/"<<d;
    cout<<" = ";
    cout<<e<<"/"<<f<<endl;
  }
  
  //realiza a operacao de soma entre 
  //duas fracoes
 public: fracao soma(fracao f){
    fracao temp;
    int num1=numerador;
    int den1=denominador;
    int num2=f.numerador;
    int den2=f.denominador;
    temp.numerador=num1*den2+den1*num2;
    temp.denominador=den1*den2;
    imprimeOperacao(num1,den1,num2,den2, temp.numerador, temp.denominador, '+');
    
    return temp;
  }
  
  //realiza a operacao de subtracao
  //entre duas fracoes
  fracao subtracao(fracao f){
    fracao temp;
    int num1=numerador;
    int den1=denominador;
    int num2=f.numerador;
    int den2=f.denominador;
    temp.numerador=num1*den2-den1*num2;
    temp.denominador=den1*den2;
    imprimeOperacao(num1,den1,num2,den2, temp.numerador, temp.denominador, '-');
    
    return temp;
  }
  
  //realiza a operacao de multiplicacao
  //entre duas fracoes
  fracao multiplicacao(fracao f){
    fracao temp;
    int num1=numerador;
    int den1=denominador;
    int num2=f.numerador;
    int den2=f.denominador;
    temp.numerador=num1*num2;
    temp.denominador=den1*den2;
    imprimeOperacao(num1,den1,num2,den2, temp.numerador, temp.denominador, 'x');
    return temp;
  }
  
  //realiza a operacao de divisao
  //entre duas fracoes
  fracao divisao(fracao f){
    fracao temp;
    int num1=numerador;
    int den1=denominador;
    int num2=f.numerador;
    int den2=f.denominador;
    temp.numerador=num1*den2;
    temp.denominador=den1*num2;
    verificaSinal(&temp.numerador,&temp.denominador);
    imprimeOperacao(num1,den1,num2,den2, temp.numerador, temp.denominador, '/');
    return temp;
  }
  
}; 
