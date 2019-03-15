#include "fracao.h"
using namespace std;

int main() {
  fracao f1(3,-4), f2, f3(5,6), f4;
  
  f2.mostraFracao();
  f2.alteraNumerador(4);
  f2.alteraDenominador(5);
  f1.mostraFracao();
  f2.mostraFracao();
  f3.mostraFracao();
  f4=f2.soma(f3);
  f4.mostraFracao();
  f4=f1.subtracao(f3);
  f4=f1.multiplicacao(f3);
  f4=f2.divisao(f1);
  return 0;
}
