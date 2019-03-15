#include <iostream>
#include<time.h>
#include<stdlib.h>
using namespace std;
//Estrutura para definir um vetor 
struct vetor{
  int tamanho;
  int max;
  int min;
  int *vet;
}
bool Existe(int val[], int tam, int valor){//Verifica se é novidade
  for(int i=0;i<tam;i++){
    if(val[i]==valor){
      return true;
    }
    return false;
  }
}
void Gera(int nums[], int quantNums, int lim int ini){//Gerar Num Random
  
}srand(time(NULL));
  int v;
  for(int i=0; i<quantNums; i++){
    v=rand()% lim;
    while(!Existe(nums, i, v)&& v<ini){
      v=rand()% (lim+1);
   }
    nums[i]=v;
  }

vetor(){
  tamanho=19;
  vet= new int[tamanho];
  max=100;
  min=0;
  Gera(vet, tamanho, max, min);
}
vetor(int A){//Só com tam
  tamanho=(A-1);
  max=100;
  min=0;
  vet= new int[tamanho];
  Gera(vet, tamanho, max, min);
}
vetor(int A, int M){//Com tam e max
  tamanho=(A-1);
  max=M;
  min=0;
  vet=new int[tamanho];
  Gera(vet, tamanho, max, min);
}
vetor(int A, int M, int m){
  tamanho=(A-1);
  max=M;
  min=m;
  vet= new int[tamanho];
  Gera(vet, tamanho, max, min);
}
int busca(int chave){//retorna a posição da chave
  for(int i=0; i<tamanho; i++){
    if(vet[i]==chave)
      return i;
  }
  return -1;
}
imprimindo(vetor v){
  for(int i=0; i<tamanho; i++){
    cout<<vet[i]<<" , ";
  }
}
combina(int V, int sVet){//Não sei como fazer, estou pulando.
  int *temp=0;
  int size=0;
  size= sVet + tamanho;
  temp= new int[size];
  int t=0;
  for(int i=0; i<tamanho; i++){
    for(int j=0; j<sVet;j++){
      if(vet[i]==Vett[j]){
        t++;
      }
      temp[t]=Vett[]

    }
  }
}
