#include <iostream>
#include <string>
using namespace std;

//Faca um template do protótipo 
template <typename G>
G meuMax(G one, G two);

int main(){
   int i_one = 3, i_two = 5;
  float g=1.0 , u=1.1;
  string name="Gus", mname="Rigor";
   cout << "O max entre " << i_one << " e " << i_two << " e "
	<< meuMax(i_one, i_two) << endl;

   //Adicione ao seu código main chamadas utilizando tipos float e string. 
	cout << "O max entre " << g << " e " << u << " e "
	<< meuMax(g, u) << endl;

  cout << "O max entre " << name << " e " << mname << " e "
	<< meuMax(name, mname) << endl;
   return 0;
}

//Transforme esta função em um template. Não se esqueça do tipo que ela retorna.
template <typename G>
G meuMax(G one, G two){
   G maior;
   if (one < two)
   {
      maior = two;
   }
   else
   {
      maior = one;
   }
   return maior;
}
