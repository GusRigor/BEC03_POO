#include <iostream>
#include <malloc.h>
#ifndef SM_H_INCLUDED
#define SM_H_INCLUDED
#define PI 3.14159265
#include <math.h>

class SM{
  protected:
  float grau;
  float distancia;

  public:
  SM(){
    distancia=0.0;
    grau = 90.0;
  }

  void step(float iniciox, float fimx, float inicioy, float fimy, float giro, int posicao, float **saida){
        //std::cout<<"Step posição "<<((posicao)/2)<<std::endl;
    proximoValor(iniciox, fimx, inicioy, fimy, giro, posicao, saida);
  }

  void transduce(float* entradas,int tamanho,float **saidas){
  	//std::cout<<"I transduce tamanho"<<tamanho<<std::endl;
    for(int i=0, j=0; i <=(tamanho/2)-2; i=i+2,j++){
        //std::cout<<"I transduce "<<i<<std::endl;
        //std::cout<<"Entrada i  "<<entradas[i]<<std::endl;
        //std::cout<<"Entrada 2+i  "<<entradas[2+i]<<std::endl;
        //std::cout<<"Entrada 1+i  "<<entradas[1+i]<<std::endl;
        //std::cout<<"Entrada 3+i  "<<entradas[3+i]<<std::endl;
        if((i+2)<=tamanho){
            step(entradas[i], entradas[2+i], entradas[1+i], entradas[3+i], grau, j, saidas);

        }else{
        	std::cout<<"acabou"<<std::endl;
        }

    }
  }
  float Posicao(){
      //return (x,y);
  return 0;
  }

  virtual float proximoValor(float iniciox, float fimx, float inicioy, float fimy, float giro, int posicao, float **saida) {
  return 0;
  }
};


class Anda:public SM{
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
        //std::cout<<"PASSOU prox valor anda"<<std::endl;
        std::cout<<"POSICAO anda "<<(posicao)<<std::endl;
        distancia = sqrt(pow((fimx-iniciox),2) + pow((fimy-inicioy),2));
        //std::cout<<"Posicao : "<<(posicao)/2<<std::endl;
        for (int i=1, j=2, k=1; i<=20; i=i+2, j=j+2, k++){
            xck=((fimx-iniciox)/10)*(k)+iniciox;
            yck=((fimy-inicioy)/10)*(k)+inicioy;
            saida[posicao][i] = xck;
            saida[posicao][j] = yck;
            //std::cout<<"Anda xck: "<<xck<<"  yck: "<<yck<<std::endl;
            std::cout<<"Anda xck: "<<saida[posicao][i]<<" i: "<<i<<"  yck: "<<saida[posicao][j]<<" j: "<<j<<std::endl;
            //std::cout<<"distancia "<<distancia<<std::endl;
        }
        return distancia;
    }
};

class Giro:public SM{
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
        //std::cout<<"PASSOU prox valor giro"<<std::endl;
        //std::cout<<"posicao prox valor giro "<<((posicao)/2)<<std::endl;
        atanx = (float)atan(sqrt(pow((fimy-inicioy),2))/sqrt(pow((fimx-iniciox),2))) * 180 / PI;
        //atanx = atan((fimy-inicioy)/(fimx-iniciox))* 180 / PI;
        //std::cout<<"giroatual "<<giroAtual<<std::endl;
        //std::cout<<"atanx "<<atanx<<std::endl;
        if (posicao == 0){
            giroAtual = grau;
        }
        if (fimx == iniciox){
            if(fimy < inicioy){
                giroAtual = 180.0;
            }else{
                //std::cout<<"X= Y<: "<<grau<<std::endl;
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
                //std::cout<<"X> Y<: "<<grau<<std::endl;
                giroAtual = grau + atanx;
                grau = grau + giroAtual;
            }
            else{
                //std::cout<<"X> Y>: "<<grau<<std::endl;
                giroAtual = grau - (180.0 - atanx);
                grau = 90.0 + atanx;
            }
        }
        else{
            if (fimy < inicioy){
                //std::cout<<"X< Y<: "<<grau<<std::endl;
                giroAtual =  grau - (270.0 - atanx);
                grau = 180 - atanx;
            }
            else{
                //std::cout<<"X< Y>: "<<grau<<std::endl;
                giroAtual = grau - atanx;
                grau = atanx;
            }
        }
        //std::cout<<"posicao giro fim: "<<((posicao)/2)<<std::endl;
        saida[(posicao)][0] = giroAtual;
        //std::cout<<"GIROATUAL: "<<giroAtual<<std::endl;
        //std::cout<<"GRAU: "<<grau<<std::endl;
        //std::cout<<" "<<std::endl;
        return grau;
  }
};

class Carro:public SM{
private:
    SM *gira;
    SM *ando;
protected:
    float distancia;

public:
    Carro(){
        gira = new Giro();
        ando = new Anda();
    };
    float proximoValor(float iniciox, float fimx, float inicioy, float fimy, float giro, int posicao, float **saida){
        //std::cout<<"PASSOU prox valor carro"<<std::endl;
        //std::cout<<"posicao prox valor carro "<<((posicao)/2)<<std::endl;
        gira->proximoValor(iniciox, fimx, inicioy, fimy, giro, posicao, saida);
        distancia = ando->proximoValor(iniciox, fimx, inicioy, fimy, giro, posicao, saida);
        return distancia;
    }
};


#endif // SM_H_INCLUDED


using namespace std;

int main()
{

    int tamanho=22;
    float entradas[22]={5.0,5.0,7.0,2.0,9.0,5.0,2.0,10.0,1.0,1.0,5.0,5.0,7.0,2.0,9.0,5.0,2.0,10.0,1.0,1.0,5.0,5.0};
    float **saida;
    saida=(float **)malloc((tamanho-2)*sizeof(float*));
    //cout<<"tamanho calculado "<<((tamanho/2)+1)<<endl;
    for(int i=0; i<((tamanho/2)+2); i++){
        saida[i]=(float*)malloc((tamanho-2)*sizeof(float));
    };

    Carro carrox;

    carrox.transduce(entradas,tamanho,saida);

    for(int i=0; i<(tamanho/4);i++){
            //cout<<"iiiiiiii "<<i<<endl;
            cout<<"saida i "<<i<<" angulo "<<" "<<saida[i][0]<<endl;
        for(int j=1, k=2; j<=20;j=j+2, k=k+2){
            cout<<" x "<<" "<<saida[i][j]<<" y "<<saida[i][k]<<endl;
        }
    }
    return 0;

}
