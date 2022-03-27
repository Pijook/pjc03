#include <iostream>

void ord3(double& a, double& b, double& c);
void ord3(double* a, double* b, double* c);

void getMinMax(const double &a, const double& b,const double& c,const double*& pMin, const double*& pMax);
void getMinMax(const double *a, const double* b,const double* c,const double** pMin, const double** pMax);

void printOrd(const double* a, const double* b,const double* c) {
    using std::cout;
    using std::endl;
    cout << *a << " " << *b << " " << *c << endl;
}

void printMinMax(const double* pmn, const double* pmx) {
    using std::cout;
    using std::endl;
    std:: cout << "Min = " << *pmn << "; "<< "Max = " << *pmx << std::endl;
}

int main(){
    double a, b, c;
    const double *pMin, *pMax;

    a = 2; b = 1; c = 3;ord3(a,b,c);
    printOrd(&a, &b, &c);

    a = 3; b = 2; c = 1;
    ord3(&a,&b,&c);
    printOrd(&a, &b, &c);

    a = -1; b = -1; c = 1;
    ord3(&a,&b,&c);
    printOrd(&a, &b, &c);

    a = 2; b = 3; c = 1;
    getMinMax(a,b,c,pMin,pMax);
    printMinMax(pMin, pMax);

    a = 3; b = 1; c = 2;
    getMinMax(&a,&b,&c,&pMin,&pMax);
    printMinMax(pMin, pMax);

    a = 3; b = 3; c = -1;
    getMinMax(&a,&b,&c,&pMin,&pMax);
    printMinMax(pMin, pMax);
}

void ord3(double& a, double& b, double& c){
    double temp;
    if(a > b){
        temp = a;
        a = b;
        b = temp;
    }
    if(a > c){
        temp = a;
        a = c;
        c = temp;
    }
    if(b > c){
        temp = b;
        b = c;
        c = temp;
    }
}

void ord3(double* a, double* b, double* c){
    if(*a > *b){
        double temp = *a;
        *a = *b;
        *b = temp;
    }
    if(*a > *c){
        double temp = *a;
        *a = *c;
        *c = temp;
    }
    if(*b > *c){
        double temp = *b;
        *b = *c;
        *c = temp;
    }
}

void getMinMax(const double &a, const double& b,const double& c,const double*& pMin, const double*& pMax){
    if(a < b && a < c){
        pMin = &a;
        if(b > c){
            pMax = &b;
        }
        else{
            pMax = &c;
        }
    }
    else if(b < c){
        pMin = &b;
        if(a > c){
            pMax = &a;
        }
        else{
            pMax = &c;
        }
    }
    else{
        pMin = &c;
        if(b > a){
            pMax = &b;
        }
        else{
            pMax = &a;
        }
    }
}

void getMinMax(const double *a, const double* b,const double* c,const double** pMin, const double** pMax){
    if(*a < *b && *a < *c){
        *pMin = a;
        if(*b > *c){
            *pMax = b;
        }
        else{
            *pMax = c;
        }
    }
    else if(*b < *c){
        *pMin = b;
        if(*a > *c){
            *pMax = a;
        }
        else{
            *pMax = c;
        }
    }
    else{
        *pMin = c;
        if(*b > *a){
            *pMax = b;
        }
        else{
            *pMax = a;
        }
    }
}
