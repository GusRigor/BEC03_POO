#include<math.h>
#include<stdio.h>
#include<iostream>

using namespace std;

struct matris{
  char **meuMatriz;
  int linha;
  int coluna;

matris(){ //Gerar a matriz 3x3
  linha=coluna=3
    meuMatriz=new char[linha][coluna];
    for(int i=0; i<linha; i++){
      for(int j=0; j<coluna; j++){
          meuMatriz[i][j]=' ';
      }    
    }
} 

matris(int l, int c){ //Colocar na struct
    meuMatriz[l][c];
}
void joinO(int l, int c, matris velha){//Jogada do jg O
    if(velha !=' '){
      cout<<"Erro"<<endl;
    }else{
    velha(l, c)='O';
    }
}
void joinX(int l, int c, matris velha){//Jogada do jg X
    if(velha !=' '){
      cout<<"Erro"<<endl;
    }else{
    velha(l, c)='X';
    }
}
void verificar(matris velha){//Teste das possibilidades de vitória
    //Horizontal
    if(velha(0,0)=="O" && velha(0,1)=="O" && velha==(0,2)=="O"){
        cout<<"O ganhou!"<<endl;
        system("PAUSE");
    }
    else if(velha(0,0)=="X" && velha(0,1)=="X" && velha==(0,2)=="X"){
        cout<<"X ganhou!"<<endl;
        system("PAUSE");
    }
    else if(velha(1,0)=="O" && velha(1,1)=="O" && velha==(1,2)=="O"){
        cout<<"O ganhou!"<<endl;
        system("PAUSE");
    }
    else if(velha(1,0)=="X" && velha(1,1)=="X" && velha==(1,2)=="X"){
        cout<<"X ganhou!"<<endl;
        system("PAUSE");
    }
    else if(velha(2,0)=="O" && velha(2,1)=="O" && velha==(2,2)=="O"){
        cout<<"O ganhou!"<<endl;
        system("PAUSE");
    }
    else if(velha(2,0)=="X" && velha(2,1)=="X" && velha==(2,2)=="X"){
        cout<<"X ganhou!"<<endl;
        system("PAUSE");
    }
    //Vertical
    else if(velha(0,0)=="O" && velha(1,0)=="O" && velha==(2,0)=="O"){
        cout<<"O ganhou!"<<endl;
        system("PAUSE");
    }
    else if(velha(0,0)=="X" && velha(1,0)=="X" && velha==(2,0)=="X"){
        cout<<"X ganhou!"<<endl;
        system("PAUSE");
    }
    else if(velha(0,1)=="O" && velha(1,1)=="O" && velha==(2,1)=="O"){
        cout<<"O ganhou!"<<endl;
        system("PAUSE");
    }
    else if(velha(0,1)=="X" && velha(1,1)=="X" && velha==(2,1)=="X"){
        cout<<"X ganhou!"<<endl;
        system("PAUSE");
    }
    else if(velha(0,2)=="O" && velha(1,2)=="O" && velha==(2,2)=="O"){
        cout<<"O ganhou!"<<endl;
        system("PAUSE");
    }
    else if(velha(0,2)=="X" && velha(1,2)=="X" && velha==(2,2)=="X"){
        cout<<"X ganhou!"<<endl;
        system("PAUSE");
    }
    //Diagonal
    else if(velha(0,0)=="O" && velha(1,1)=="O" && velha==(2,2)=="O"){
        cout<<"O ganhou!"<<endl;
        system("PAUSE");
    }
    else if(velha(0,0)=="X" && velha(1,1)=="X" && velha==(2,2)=="X"){
        cout<<"X ganhou!"<<endl;
        system("PAUSE");
    }
    else if(velha(0,2)=="O" && velha(1,1)=="O" && velha==(2,0)=="O"){
        cout<<"O ganhou!"<<endl;
        system("PAUSE");
    }
    else if(velha(0,2)=="X" && velha(1,1)=="X" && velha==(2,0)=="X"){
        cout<<"X ganhou!"<<endl;
        system("PAUSE");
    }else{
        cout<<"Vez do outro jogador."<<endl;
    }
}
void mostrar(matris velha){//Imprimir a matriz  
  for(int i=0; i<3; i++){
    for(int j=0; j<3; j++){
        cout<<"| "<<meuMatriz[i][j]<<" |";
    }
    printf("\n");
  }
}
void jogarVelha(matris velha){//Rodando o jogo da Velha
    cout<<"Vamos Jogar"<<endl;//Com as funções anteriores
    velha();
    mostrar(velha);
    cout<<"O jogador X começa.Coloque a posição do X, começando pela linha."<<endl;
    for(int i=0; i<10; i++){
        int l=0;
        int c=0;
        cin>>l;
        cin>>c;
        joinX((l-1),(c-1), velha);
        verificar(velha);
        mostrar(velha);
        cout<<"Jogador O.Coloque a posição do O, começando pela linha."<<endl;
        cin>>l;
        cin>>c;
        joinO((l-1),(c-1), velha);
        verificar(velha);
        mostrar(velha);
        cout<<"Jogador X.Coloque a posição do X, começando pela linha."<<endl;
    }
    cout<<"Deu Velha :( "<<endl;
}
}
