#include <iostream>
#include <malloc.h>
#define PI 3.14159265
#include <math.h>

class ME{
  protected:
  float grau;
  float distancia;

  public:
  ME(){
    distancia=0.0;
    grau = 90.0;
  }

  void step(float iniciox, float fimx, float inicioy, float fimy, float giro, int posicao, float **saida){
    proximoValor(iniciox, fimx, inicioy, fimy, giro, posicao, saida);
  }

  void transduce(float* entradas,int tamanho,float **saidas){
    for(int i=0, j=0; i <=(tamanho/2)-2; i=i+2,j++){
        if((i+2)<=tamanho){
            step(entradas[i], entradas[2+i], entradas[1+i], entradas[3+i], grau, j, saidas);

        }else{
        	std::cout<<"acabou"<<std::endl;
        }

    }
  }
  float Posicao(){

  return 0;
  }

  virtual float proximoValor(float iniciox, float fimx, float inicioy, float fimy, float giro, int posicao, float **saida) {
  return 0;
  }
};


class Anda:public ME{
protected:
    float distancia;
    float xck;
    float yck;
public:
    Anda(){
    }
    Anda(float distanciai){
        distancia = distanciai;
        xck=0.0;
        yck=0.0;
    }
    float proximoValor(float iniciox, float fimx, float inicioy, float fimy, float giro, int posicao, float **saida){
        //std::cout<<"POSICAO anda "<<(posicao)<<std::endl;
        distancia = sqrt(pow((fimx-iniciox),2) + pow((fimy-inicioy),2));
        for (int i=1, j=2, k=1; i<=20; i=i+2, j=j+2, k++){
            xck=((fimx-iniciox)/10)*(k)+iniciox;
            yck=((fimy-inicioy)/10)*(k)+inicioy;
            saida[posicao][i] = xck;
            saida[posicao][j] = yck;
          //  std::cout<<"Anda xck: "<<saida[posicao][i]<<" i: "<<i<<"  yck: "<<saida[posicao][j]<<" j: "<<j<<std::endl;
        }
        return distancia;
    }
};

class Giro:public ME{
private:
    float atanx;
protected:
    float giroAtual;
public:
    Giro(){
        atanx = 0.0;
        giroAtual = 0.0;
    }
    float proximoValor(float iniciox, float fimx, float inicioy, float fimy, float giro, int posicao, float **saida){
        atanx = (float)atan(sqrt(pow((fimy-inicioy),2))/sqrt(pow((fimx-iniciox),2))) * 180 / PI;
        if (posicao == 0){
            giroAtual = grau;
        }
        if (fimx == iniciox){
            if(fimy < inicioy){
                giroAtual = 180.0;
            }else{
                giroAtual = 0.0;
            }
        }
        if (fimy == inicioy){
            if(fimx > iniciox){
                giroAtual = 90.0;
            }else{
                giroAtual = -90.0;
            }
        }

        if(fimx > iniciox){
            if(fimy < inicioy){
                giroAtual = grau + atanx;
                grau = grau + giroAtual;
            }
            else{
                giroAtual = grau - (180.0 - atanx);
                grau = 90.0 + atanx;
            }
        }
        else{
            if (fimy < inicioy){
                giroAtual =  grau - (270.0 - atanx);
                grau = 180 - atanx;
            }
            else{
                giroAtual = grau - atanx;
                grau = atanx;
            }
        }

        saida[(posicao)][0] = giroAtual;

        return grau;
  }
};

class Carro:public ME{
private:
    ME  *gira;
    ME  *ando;
protected:
    float distancia;

public:
    Carro(){
        gira = new Giro();
        ando = new Anda();
    };
    float proximoValor(float iniciox, float fimx, float inicioy, float fimy, float giro, int posicao, float **saida){

        gira->proximoValor(iniciox, fimx, inicioy, fimy, giro, posicao, saida);
        distancia = ando->proximoValor(iniciox, fimx, inicioy, fimy, giro, posicao, saida);
        return distancia;
    }
};





using namespace std;

int main()
{

    int tamanho=22;
    float entradas[22]={5.0,5.0,7.0,2.0,9.0,5.0,2.0,10.0,1.0,1.0,5.0,5.0,7.0,2.0,9.0,5.0,2.0,10.0,1.0,1.0,5.0,5.0};
    float **saida;
    saida=(float **)malloc((tamanho-2)*sizeof(float*));

    for(int i=0; i<((tamanho/2)+2); i++){
        saida[i]=(float*)malloc((tamanho-2)*sizeof(float));
    };

    Carro relampagoMarquinhos;

    relampagoMarquinhos.transduce(entradas,tamanho,saida);

    for(int i=0; i<(tamanho/4);i++){
            cout<<endl;
            cout<<"Ponto: "<<(i+1)<<" & Ângulo para rotação: "<<saida[i][0]<<"º."<<endl;
        for(int j=1, k=2, l=1; j<=20;j=j+2, k=k+2, l++){
            cout<<"Tempo "<<l<<": ("<<saida[i][j]<<", "<<saida[i][k]<<");"<<endl;
        }
    }
    return 0;

}
