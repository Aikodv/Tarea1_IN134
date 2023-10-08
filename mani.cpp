#include <iostream>
#include <fstream>
#include <random>
#include <string>

using namespace std;

struct Naipe {
    int numero;
    char palo;
    char color;

};
/*****
 * void creararray
 * ******
 * Crea un array de 52 naipes y los guarda en un archivo binario
 * ******
 * Input:
 * No hay inputs
 * .......
 * ******
 * Returns:
 * No hay returns
 * ******
 * */

void creararray(){
    Naipe naipes[53];
    int P=1, D = 1,T = 1 ,C = 1;
    for(int i=1; i <= 52; ++i ){
        if (i <= 26){
            naipes[i].color  = 'N';
            if(i <= 13){
                naipes[i].palo   = 'P';
                naipes[i].numero = P;
                ++P;
            }
            else{
                naipes[i].palo   = 'T';
                naipes[i].numero = T;
                ++T;
            }
        }
        else{
            naipes[i].color  = 'R';
            if(i<=39){
                naipes[i].palo   = 'C';
                naipes[i].numero = C;
                ++C;
            }
            else{
                naipes[i].palo   = 'D';
                naipes[i].numero = D;
                ++D;
            }
        }
    }
    fstream fp; /*stream de archivo*/
    fp.open("baraja.dat",  ios::out | ios::binary);
    int numNaipess = 52;
    fp.write(reinterpret_cast<const char*>(&numNaipess), sizeof(numNaipess));
    for(int z=1; z <= 52; ++z ){
        fp.write(reinterpret_cast<const char*>(&naipes[z].numero), sizeof(naipes[z].numero));
        fp.write(&naipes[z].palo, sizeof(naipes[z].palo));
        fp.write(&naipes[z].color, sizeof(naipes[z].color));
    }
    fp.close();
    }
/*****
 * int main
 * ******
 * Ejecuta la funcion creararray
 * ******
 * Input:
 * No hay inputs
 * .......
 * ******
 * Returns:
 * int 0
 * ******
 * */
int main(){
    creararray();
    return 0;
}
