#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;

ofstream salida;


//void generar(int i, int lim);
int main(){
    srand(time(nullptr));
    salida.open("output.txt", ios::out);

/*
    for (int i=0; i<400; i++){
        salida<<rand()%50<<","<<rand()%25<<endl;
    }
*/
    for (int i=0; i<25; i++){
        for (int j=0; j<50; j++){
            if (j<i && i!=j){
                salida<<j<<","<<i<<endl;
            }
        }
    }


    salida.close();
    return 0;
}
/*
void generar(int i, int lim){
    if (i==lim) return;
    else{
        int x=rand()%50;
        int y=rand()%25;
        if ( (x<25 && y>12) || (x>25 && y>12) || (x>25 && y))
        salida<<x<<","<<y<<endl;
        }
    }
    
}
*/