#include <iostream>
using namespace std;
//abstract class (shape is base class)
class shape{
public:
//pure virtual function
    virtual void area()=0;
    void displaytype(){
        cout<<"This is a shape"<<endl;
    }
};
class Square:public shape{
    private:
        int side;
    public:
        Square(int s):side(s){} //square is a constructor - it has to be public
        void area() override{
            cout<<"Area of square:"<<side*side<<endl;
        }
};
class Triangle:public shape{
    private:
        int base, height;
    public:
        Triangle(int b,int h):base(b),height(h){}

        void area() override{
            cout<<"Area of triangle:"<<0.5*base*height<<endl;
        }
};
class Circle:public shape{
    private:
        double radius;
    public:
        Circle(double r):radius(r){}
        void area() override{
            cout<<"Area of circle:"<<3.14*radius*radius<<endl;
        }
};
class Rectangle:public shape{
    private:
        float length,breadth;
    public:
        Rectangle(float l,float b):length(l),breadth(b){}
        void area() override{
            cout<<"Area of rectangle:"<<length*breadth<<endl;
        }
};

int main(){
    shape* shape1=new Square(5);
    shape* shape2=new Triangle(5,7);
    shape* shape3=new Circle(6.5);

    shape1->displaytype();
    shape1->area();

    shape2->displaytype();
    shape2->area();

    shape3->displaytype();
    shape3->area();

}