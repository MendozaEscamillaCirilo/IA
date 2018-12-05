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

int deCadenaaEntero(int numero,string dato){
 numero = 0;
 if(dato[0] == 49){ numero += 32;}
 if(dato[1] == 49){ numero += 16;}
 if(dato[2] == 49){ numero += 8;}
 if(dato[3] == 49){ numero += 4;}
 if(dato[4] == 49){ numero += 2;}
 if(dato[5] == 49){ numero += 1;}
 return numero;
}

string creahijo(string p1,string p2,string h1){
 for(int i=0;i<6;i++){
       if(i<3){
            h1[i] = p1[i];   
       }else{
            h1[i] = p2[i];   
       }
 }
 return h1;
}
int* conbinarycrearhijos(int* padres,int* hijos,int n){
    for(int i = 0;i < n;i++){
        int p1 = rand() % (n+1);
        int p2 = rand() % (n+1);
        string ps1 = deEnteroaCadena(padres[p1],ps1);
        string ps2 = deEnteroaCadena(padres[p2],ps2);
        string h1 = creahijo(ps1,ps2,h1);
        string h2 = creahijo(ps2,ps1,h2);
        hijos[i] = deCadenaaEntero(hijos[i],h1);
        cout<<hijos[i]<<"  /  ";
        i++;
        hijos[i] = deCadenaaEntero(hijos[i],h2);
        cout<<hijos[i]<<"  /  ";
    }
    return hijos;
}
int volumen(int l){
 int largo = 200 - (2 * l);   
 int ancho = 100 - (2 * l);
 int vol = (largo * ancho) * l;
 return vol;
}
int* obtenernuevospadres(int* padres,int* hijos, int n){
    for(int i=0;i<n;i++){
        if(volumen(padres[i]) < volumen(hijos[i])){
            padres[i] = hijos[i];
        }
    }
     return padres;
}

int main(){
    int n = 8;
    int* padres = new int[n];
    generaPoblacion(padres,n);
    //imprime(padres,n);
    int* hijos = new int[n];
    //hijos = conbinarycrearhijos(padres,hijos,n);
    //imprime(hijos,n);
    //cout<<volumen(21)<<endl;
    //cout<<volumen(27)<<endl;
    int iteraciones = 10;
    for(int i = 0;i < iteraciones;i++){
        hijos = conbinarycrearhijos(padres,hijos,n);
        padres = obtenernuevospadres(padres,hijos,n);
        int* hijos = new int[n];
    }
    return 0;
}
