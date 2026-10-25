#include<iostream>
using namespace std;
class complex {
    private:
    float real;
    float imag;

    public:
    complex(){
        real=0;
        imag=0;
    
    }
    complex(float r,float i){
        real=r;
        imag=i;

    }
    ~complex(){ }
    void display(void){
        cout<<real<<"+"<<imag<<"i"<<endl;
    }
    complex operator+(complex c2){
        float r = real+c2.real;
        float i = imag+c2.imag;
        return(complex(r,i));
    }
    
    complex operator-(complex c2){
        float r= real-c2.real;
        float i= imag-c2.imag;
        return(complex(r,i));
    }
    complex operator*(complex c2){
        float r= real*c2.real - imag*c2.imag;
        float i= real*c2.real + imag*c2.imag;
        return(complex(r,i));
    }

};
int main(){
    complex c1(4,1);
    complex c2(4,6);

     cout<<"first complex number :";
    c1.display();
    cout<<"second complex number :";
    c2.display();

    complex sum = c1+c2;
    cout<<"addition is :";
    sum.display();

    complex diff = c1-c2;
    cout<<"substraction is :";
    diff.display();

    complex prod = c1*c2;
    cout<<"multiplication is :";
    prod.display();

    return 0;
}

//Output
PS D:\Zaid.46> cd "d:\Zaid.46\" ; if ($?) { g++ complex.cpp -o complex } ; if ($?) { .\complex }
first complex number :4+1i
second complex number :4+6i
addition is :8+7i
substraction is :0+-5i
multiplication is :10+22i