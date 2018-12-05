#include <iostream>
#include <cstdlib>
using namespace std;

int* generaPoblacion(int* arre,int n){
 for(int i=0;i<n;i++){
  arre[i] = 20 + rand() % 31;
 }
 return arre;
}

void imprime(int* arre,int n){
 for(int i=0;i<n;i++){
  cout<<arre[i]<<" "; 
 }
}

string deEnteroaCadena(int numero,string dato){
 dato = "000000";
 int valor = numero;
 if(numero >= 32){ dato[0]=49; valor-=32; }else{ dato[0]=48;}
 if(valor >= 16){dato[1]=49; valor-=16;} else {dato[1]=48;}
 if(valor >= 8){dato[2]=49; valor-=8;} else {dato[2]=48;}
 if(valor >= 4){dato[3]=49; valor-=4;} else {dato[3]=48;}
 if(valor >= 2){dato[4]=49; valor-=2;} else {dato[4]=48;}
 if(valor >= 1){dato[5]=49;} else { dato[5]=48;}
 return dato;
}


int main(){
    int n = 8;
    int* ar = new int[n];
    generaPoblacion(ar,n);
    imprime(ar,n);
    return 0;
}