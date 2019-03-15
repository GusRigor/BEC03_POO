#include "pontoCartesiano.h"

int main() {
  pontoCartesiano p1;//p1 Ã© um pontoCartesiano
  pontoCartesiano *p2;//p2 Ã© um ponteiro para um pontoCartesiano
  //alocacao de memoria em C++, faz a 
  //mesma coisa que o malloc em C.
  p2=new pontoCartesiano;
  
  //atribui para o ponto p1 os valores de
  //5.6 para x e 3.2 para y
  p1.alteraX(5.6);
  p1.alteraY(3.2);
  //atribui para o ponto p2 os valores de
  //7.3 para x e 1.5 para y
  p2->alteraX(7.3);
  p2->alteraY(1.5);
  //imprime os pontos p1 e p2.
  p1.imprimePonto();
  p2->imprimePonto();
  
  p1.translacao(1.4, 2.8);
  p2->rotacao(0.5236);
  
  p1.imprimePonto();
  p2->imprimePonto();
}
