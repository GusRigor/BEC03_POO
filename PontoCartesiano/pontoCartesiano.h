#include <iostream>
#include <cmath>
using namespace std;

class pontoCartesiano{
  private:
  double x,y;
  
  public:
  pontoCartesiano(){
    x=y=0.0;
  }
  
  void imprimePonto(){
    cout<<"x = "<<x<<" ; "<<"y = "<<y<<endl;
  }
  
  void alteraX(double X){
    x=X;
  }
  
  void alteraY(double Y){
    y=Y;
  }
  
  void translacao(double dx, double dy){
    x+=dx;
    y+=dy;
  }
  
  void rotacao(double angulo){
    double x_novo, y_novo;
    x_novo=x*cos(angulo)-y*sin(angulo);
    y_novo=x*sin(angulo)+y*cos(angulo);
    x=x_novo;
    y=y_novo;
  }
};
