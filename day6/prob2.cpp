#include <iostream>
#include<math.h>  
using namespace std;


  //base class
  class Shape {    
  public:  
  // virtual area function 
    virtual void show_area(void) {  
      cout << "figure not defined ";  
    }

    // virtual perimeter function
    virtual void show_perimeter(void) {  
      cout << "figure not defined";  
    }  
  } ; 


  //derived triangle class 
  class triangle : public Shape {
      private:
      float Ax,Ay,Bx,By,Cx,Cy; // three coordinates

    public: 
    // area function using heron's function 
      void show_area(void) {
          float A,B,C,side,area;
          A=sqrt(((Bx-Ax)*(Bx-Ax))+((By-Ay)*(By-Ay)));
    B=sqrt(((Cx-Bx)*(Cx-Bx))+((Cy-By)*(Cy-By)));
    C=sqrt(((Ax-Cx)*(Ax-Cx))+((Ay-Cy)*(Ay-Cy)));

    side=((A+B+C)/2);

    area=sqrt(side*(side-A)*(side-B)*(side-C));  
        cout << "Triangle with 3 given coordinates ";  
        cout << " has an area of ";  
        cout << area << ".\n";  
      }

      //perimeter using heron's formula
      void show_perimeter(void) { 
         float A,B,C,perimeter; 
          A=sqrt(((Bx-Ax)*(Bx-Ax))+((By-Ay)*(By-Ay)));
          B=sqrt(((Cx-Bx)*(Cx-Bx))+((Cy-By)*(Cy-By)));
          C=sqrt(((Ax-Cx)*(Ax-Cx))+((Ay-Cy)*(Ay-Cy)));

    perimeter=(A+B+C);

       cout << "Triangle with 3 given coordinates ";  
        cout << " has perimeter of ";  
        cout << perimeter << ".\n";  
      } 

      //triangle constructor to initialise coordinates
      triangle(){
          Ax=0;
          Ay=0;
          Bx = 4;
          By=0;
          Cx=0;
          Cy=4;
      } 
  };  


   //derived square    
  class square : public Shape {
      private:
      float x1;
      float y1; 
      float x2;
      float y2; 
      //diagonal coordinates
    public:  
    //area function
      void show_area(void) {  
         cout << "Square with opposite diagonals coordinates ";  
        cout << "(" << x1<<"," << y1<<")" <<" "<<"(" << x2<<"," << y2<<")"; 
        cout << " has an area of ";  
        cout << (pow((x2-x1),2)+pow((y2-y1),2))/2 << "\n";  //diagonal sqaure / 2 is area
       }
       //perimeter function
       void show_perimeter(void) {  
        cout << "Square with opposite diagonals coordinates ";  
        cout << "(" << x1<<"," << y1<<")" <<" "<<"(" << x2<<"," << y2<<")";  
        cout << " has an perimeter of ";  
        cout <<sqrt(pow((x2-x1),2)+pow((y2-y1),2))*2*sqrt(2) << "\n";  //2*sqrt(2)*length of diagonal is perimeter
       } 

       //square constructor to initialise diagonal coordinates
       square(){
           x1 = 0;
           y1 = 0;
           x2 = 8;
           y2 = 8;
       } 
  };  
       
  class circle : public Shape {
      private :
      //coordinates and radius
      float x_coordinate;
      float y_coordinate;
      float radius;  
    public:  
    //show area of rectangle 
      void show_area(void) {  
        cout << "Circle with radius ";  
        cout << radius;  
        cout << " has an area of ";  
        cout << 3.14 * radius * radius<<endl;  
      }

      //circle perimeter
       void show_perimeter(void) {  
        cout << "Circle with radius ";  
        cout << radius;  
        cout << " has an perimeter of ";  
        cout << 3.14 * 2 * radius<<endl;  
      } 
      //circle constructor
      circle(){
          x_coordinate = 0;
          y_coordinate = 0;
          radius = 9;
      } 
  } ;  
       
int  main()  
  {  
    Shape *p;  //base class pointer
    triangle t; 
    square s;  
    circle c;  
       
    p = &t;  // acccessing derived class object from pointer of base class

    p->show_area();//virtual function ensures that correct version of function executes.
    p->show_perimeter();   
       
    p = &s;   
    p->show_area();
    p->show_perimeter();  
       
    p = &c;  
    p->show_area();
    p->show_perimeter();    
       
    return 0;  
  }