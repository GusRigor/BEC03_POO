#include<iostream>
#include<string>
#include <sstream>
#include <fstream>
using namespace std;

class funcionario{
  protected:
  
    int id;
    string nome;
    string sobrenome;
    string data;
    double salario;
    ofstream saida;
  public:
    funcionario(){
      id=0;
      nome="Fulano";
      sobrenome="da Silva";
      data="31/12/99";
      salario=1000.00;
    }
  void setId(int identeficador){
      id=identeficador;
    
    }
    
    void setnome(string Nome){
      nome=Nome;
  
    }

    void setsobrenome(string Sobrenome){
      sobrenome=Sobrenome;
    
    }

    void setdata(string Data){
      data=Data;
    
    }

    void setsalario(double dinheiros){
      if(dinheiros>0.0){
      salario=dinheiros;}
      else{
        cout<<"Erro, valor inválido"<<endl;
      }
    }
    void declFunc(int ident, string Nme, string Sobrenme, string Dta,double cash){
      setId(ident);
      setnome(Nme);
      setsobrenome(Sobrenme);
      setdata(Dta);
      setsalario(cash);
    }

    void trocaSalario(double newSalario){
      if(newSalario>0.0){
        salario=newSalario;}
      else{
        cout<<"Erro, valor inválido"<<endl;
      }
    }
    
    virtual void imprimir(){ }

    void printF(){
      saida<<endl;
      saida << id << " " << nome << " " << sobrenome << " " << data << " R$" << salario;
    }
};


class gerente: public funcionario{
  private:

    string atuacao;
    string tempo;
    int nfunc;


  public:
    gerente(){
    id=0;
    nome="Fulano";
    sobrenome="da Silva";
    data="31/12/99";
    salario=1000.00;
    atuacao="Flemis";
    tempo="2 anos";
    nfunc= 3;
    }
    void trcNumFuncionario(int n){
      if(n>0){
        nfunc=n;}
      else{
        cout<<"Erro, valor inválido"<<endl;
      }
    }

    void setAtuacao(string Atuacao){
      atuacao=Atuacao;
    }

    void setTempo(string Tempo){
      tempo=Tempo;
    }

    void setnFunc(int Nfunc){
      nfunc=Nfunc;
    }
    void declGerente(int idn, string nme, string sobrenme, string dta, double Cash, int x, string a, string t){
      declFunc(idn,nme, sobrenme, dta, Cash);
      setnFunc(x);
      setAtuacao(a);
      setTempo(t);
      
      
    }

    void imprimir(){
      printF();
      saida << " " << atuacao << " " << nfunc<<" funcionários";     
    }
   };

class engenheiro:public funcionario{
  private:
    string atuacao;
    string gerencia;
  
  public:
    engenheiro(){
      id=0;
      nome="Fulano";
      sobrenome="da Silva";
      data="31/12/99";
      salario=1000.00;
      atuacao="Civil";
      gerencia="Flemis";
    }
    void setatuacao(string Atuacao){
      atuacao=Atuacao;
    }

    void setgerencia(string Gerencia){
      gerencia=Gerencia;
    
    }
    void declEngenheiro(int idn, string nme, string sobrenme, string dta, double Cash,string a,string g){
      declFunc(idn, nme, sobrenme, dta, Cash);
      setatuacao(a);
      setgerencia(g);
    }

    void imprimir(){
        printF();
          saida << " " << atuacao << " " << gerencia;
    }
      
};

class desenvolvedor:public funcionario{
  private:
    string linguagem;
    string gerencia;
    string instrucao;

  public:
    desenvolvedor(){
      id=0;
      nome="Fulano";
      sobrenome="da Silva";
      data="31/12/99";
      salario=1000.00;
      linguagem="C#";
      gerencia="Flemis";
      instrucao="Pleno";
    }
    void setlinguagem(string Linguagem){
      linguagem=Linguagem;
    }

    void setgerencia(string Gerencia){
      gerencia=Gerencia;
    }

    void setinstrucao(string Instrucao){
      instrucao=Instrucao;
    }
    void declDesenvolvedor(int idn, string nme, string sobrenme, string dta, double Cash,string lin,string gen, string inst){
      declFunc(idn, nme, sobrenme, dta, Cash);
      setlinguagem(lin);
      setgerencia(gen);
      setinstrucao(inst);
    }

    void imprimir(){
        printF();
          saida<< linguagem << " " << gerencia << " " << instrucao;
    }
      
};

class rh:public funcionario{
  private:

  string recrutamento;
  string instrucao;
  public:
  
  rh(){
    id=0;
    nome="Fulano";
    sobrenome="da Silva";
    data="31/12/99";
    salario=1000.00;
    recrutamento="Flemis";
    instrucao="formado";
  }
  void setrecrutamento(string Recrutamento){
    recrutamento=Recrutamento;
  }

  void setinstrucao(string Instrucao){
    instrucao=Instrucao;
  }
  void declRh(int idn, string nme, string sobrenme, string dta, double Cash,string rec, string inst){
    declFunc(idn, nme, sobrenme, dta, Cash);
    setrecrutamento(rec);
    setinstrucao(inst);
  }
  void imprimir(){
    printF();
    saida << " " << recrutamento << " " << instrucao;
  }
};

class auxliar:public funcionario{
  private:
    string gerencia;
    string instrucao;
  public:
    auxliar(){
      id=0;
      nome="Fulano";
      sobrenome="da Silva";
      data="31/12/99";
      salario=1000.00;
      gerencia="Flemis";
      instrucao="formado";
    }
    void setGerencia(string Gerencia){
      gerencia=Gerencia;
    }
    void setInstrucao(string Instrucao){
      instrucao=Instrucao;
    }
    void declAuxiliar(int idn, string nme, string sobrenme, string dta, double Cash,string gen, string inst){
      declFunc(idn, nme, sobrenme, dta, Cash);
      setGerencia(gen);
      setInstrucao(inst);
    }
    void imprimir(){
      printF();
        saida << " " << gerencia << " " << instrucao;
      }
};
