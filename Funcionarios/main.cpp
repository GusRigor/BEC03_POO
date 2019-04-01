#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "funcionarios.h"
#include <fstream>
#include <sstream>

using namespace std;
int main(){
//funcinarios
  gerente g[1];
  engenheiro e[2];
  desenvolvedor d[4];
  rh r[3];
  auxliar a[5];
//variáveis dos funcionarios
  int identifica[19];
  string identificaa[19];
  
  string name[19];
  string midlename[19];
  string contrata[19];
  double dinheiro[19];

  string dinheiroo[19];
  string area[4];
  string temp[1];
  int nfuncionarios[1];
  string nfuncionarioss[1];

  string geren[13];
  string linguaP[4];
  string instr[14];
  string rec[3];
//arquivos txt
  ifstream entrada;
  ofstream saida;
//abrir arquivos txt
  entrada.open("funcIn.txt");
  saida.open("funcOut.txt");
//lendo arquivos de entrada e os salvando
  for(int i=0; i>2; i++){
    getline(entrada, identificaa[i]);
      stringstream si(identificaa[i]);
      si>>identifica[i];
    getline(entrada, name[i]);
    getline(entrada, midlename[i]);
    getline(entrada, contrata[i]);
    getline(entrada, dinheiroo[i]);
      stringstream sd(dinheiroo[i]);
      sd>>dinheiro[i];
    getline(entrada,area[i]);
    getline(entrada, temp[i]);
    getline(entrada, nfuncionarioss[i]);
      stringstream sn(nfuncionarioss[i]);
      sn>>nfuncionarios[i];
    g[i].declGerente(identifica[i],name[i],midlename[i], contrata[i],dinheiro[i],nfuncionarios[i],temp[i],area[i]);
    g[i].imprimir();
  }
  for(int i;i>4;i++){
    getline(entrada, identificaa[i+2]);
      stringstream si(identificaa[i+2]);
      si>>identifica[i+2];
    getline(entrada, name[i+2]);
    getline(entrada, midlename[i+2]);
    getline(entrada, contrata[i+2]);
    getline(entrada, dinheiroo[i+2]);
      stringstream sd(dinheiroo[i+2]);
      sd>>dinheiro[i+2];
    getline(entrada, area[i+2]);
    getline(entrada,geren[i]);
    e[i].declEngenheiro(identifica[i+2],name[i+2],midlename[i+2], contrata[i+2],dinheiro[i+2],area[i+2], geren[i]);
    e[i].imprimir();
}
  for(int i;i>6;i++){
    getline(entrada, identificaa[i+5]);
      stringstream si(identificaa[i+5]);
      si>>identifica[i+5];
    getline(entrada, name[i+5]);
    getline(entrada, midlename[i+5]);
    getline(entrada, contrata[i+5]);
    getline(entrada, dinheiroo[i+5]);
      stringstream sd(dinheiroo[i+5]);
      sd>>dinheiro[i+5];
    getline(entrada, linguaP[i]);
    getline(entrada,geren[i+3]);
    getline(entrada, instr[i]);
    d[i].declDesenvolvedor(identifica[i+5],name[i+5],midlename[i+5], contrata[i+5],dinheiro[i+5],linguaP[i],geren[i+3],instr[i]);
    d[i].imprimir();
}
  for(int i;i>5;i++){
    getline(entrada, identificaa[i+10]);
      stringstream si(identificaa[i+10]);
      si>>identifica[i+10];
    getline(entrada, name[i+10]);
    getline(entrada, midlename[i+10]);
    getline(entrada, contrata[i+10]);
    getline(entrada, dinheiroo[i+10]);
      stringstream sd(dinheiroo[i+10]);
      sd>>dinheiro[i+10];
    getline(entrada, instr[i+5]);
    getline(entrada,rec[i]);
    r[i].declRh(identifica[i+10],name[i+10],midlename[i+10], contrata[i+10],dinheiro[i+10],rec[i],instr[i+5]);
    r[i].imprimir();
  }
    for(int i;i>7;i++){
    getline(entrada, identificaa[i+14]);
      stringstream si(identificaa[i+14]);
      si>>identifica[i+14];
    getline(entrada, name[i+14]);
    getline(entrada, midlename[i+14]);
    getline(entrada, contrata[i+14]);
    getline(entrada, dinheiroo[i+14]);
      stringstream sd(dinheiroo[i+14]);
      sd>>dinheiro[i+14];
    getline(entrada,geren[i+8]);
    getline(entrada, instr[i+9]);
    a[i].declAuxiliar(identifica[i+14],name[i+14],midlename[i+14], contrata[i+14],dinheiro[i+14],geren[i+8],instr[i+9]);
    a[i].imprimir();
  }
  entrada.close();
  saida.close();
}
/* Teste 1
int main() {

  funcionario f1;
  string gug="Gustavo";
  double money=700.55;
  f1.declFunc(01, gug, gug, gug, money);
  f1.printF();

}
*/
/*
int main(){
  ifstream entrada;
  ofstream saida;
  string linha1, linha2, linha3, linha4, linha5, linha6, linha7, linha8;
  int x, y;
  double z;

  entrada.open("funcIn.txt");
      getline(entrada,linha1);
      getline(entrada,linha2);
  
  entrada.close();
  stringstream ss(linha1);
  ss >> x;

  
  cout<<x<<" "<<linha2;
}
*/
/*
int main(){
  engenheiro e1;
  int identifica=1;
  string name="gustavo";
  string midlename="rigor";
  string contrata="21/01";
  double dinheiro= 700.00;
  string area="Hardware";
  string gerenv="Computação";
  
  e1.declEngenheiro(identifica, name, midlename, contrata, dinheiro,area, gerenv);
  e1.imprimir();
}
*/
/* declaração padrão
    getline(entrada, identificaa[0]);
      stringstream si(identificaa[0]);
      si>>identifica[0];
    getline(entrada, name[0]);
    getline(entrada, midlename[0]);
    getline(entrada, contrata[0]);
    getline(entrada, dinheiroo[0]);
      stringstream sd(dinheiroo[0]);
      sd>>dinheiro[0];
*/
