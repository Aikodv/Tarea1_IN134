
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
* int randin
******
* Crea un numero aleatorio
******
* Input:
* Recibe los parametros del numero aleatorio
* .......
******
* Returns:
* int numero aleatorio(Numero aleatorio usando los parametros del input)
*****/

int randin(int max,int min){
    random_device rd;
    mt19937 gen(rd()); // Mersenne Twister
    uniform_int_distribution<int> distribution(min, max);
    int numeroAleatorio = distribution(gen);
    return numeroAleatorio;
}
/*****
* String NaipeToString
******
* Lee el naipe y lo transforma en una string
******
* Input:
* const naipe(recibe el struct del naipe directo del archivo binario)
* .......
******
* Returns:
* String del naipe
*****/


string naipeToString(const Naipe& n) {
    string naipeStr = to_string(n.numero);
    naipeStr += n.palo;
    naipeStr += n.color;
    return naipeStr;
}
/*****
 * int poker
 * ******
 * Crea un archivo con las cartas aleatorias y cuenta la cantidad de cartas rojas y negras
 * ******
 * Input:
 * int N (cantidad de jugadores)
 * .......
 * ******
 * Returns:
 * int 0
 * ******
 * */
int poker(int N){
    Naipe naipes[53];
    int contador = 1;
    if ( N >= 2 && N <= 7 ){
        int cartas = 5 * N;
        int numeroAleatorio[cartas];
        for (int i = 1; i <= cartas ; i++) {
            numeroAleatorio[i] = randin(52, 1);
            for(int j = 1 ; j<= contador-1;j++){
                int contador2 = 0;
                    while(contador2 <= 0){
                        if(numeroAleatorio[i] == numeroAleatorio[j]){
                            numeroAleatorio[i] = randin(52, 1);
                        }
                        else{
                            contador2++;
                        }
                    }        
            }
        contador++;
        }
        int contador_red = 0;
        int contador_blck = 0;
        ifstream fp;
        string s;
        fp.open("baraja.dat",  ios::in | ios::binary);
        int numNaipes;
        fp.read(reinterpret_cast<char*>(&numNaipes), sizeof(numNaipes)); // Lee el número de naipes
        char prefijo = 'P';
        string nombreArchivo = string(1, prefijo) + to_string(N) + ".txt";
        ofstream fz;
        fz.open(nombreArchivo,ios::out);
        int contador_epico = 1;
        for( int hans = 1 ; hans <= cartas; hans++){
            if(contador_epico == 5){
                fz << numeroAleatorio[hans] <<endl;
                contador_epico = 1;
            }
            else{
                contador_epico++;
                fz << numeroAleatorio[hans] << " ";
            }
        } 

        for(int g = 1 ; g<=52 ;g++){
            fp.read(reinterpret_cast<char*>(&naipes[g].numero), sizeof(naipes[g].numero));
            fp.read(&naipes[g].palo, sizeof(naipes[g].palo));
            fp.read(&naipes[g].color, sizeof(naipes[g].color));
            s = naipeToString(naipes[g]);
            for(int e = 0 ; e <= cartas; e++){
                if (g == numeroAleatorio[e]){
                    char ultimaLetra = s[s.size() - 1];
                    if(ultimaLetra == 'N'){
                        contador_blck++;
                    }
                    if(ultimaLetra == 'R'){

                        contador_red++;
                    }
                }
            }
        }
        fz.close();
        fp.close();
        cout << "Cantidad de cartas Negras: " << contador_blck << endl;
        cout << "Cantidad de cartas Rojas : " << contador_red << endl;
        return 0;
    }
    else{
        cout<< "Cantidad de jugadores insuficientes o sobrepasa el limite"<< endl;

        return 0;
    }
}
/*****
 * int brisca
 * ******
 * Crea un archivo con las cartas aleatorias y cuenta la cantidad de cartas rojas y negras
 * ******
 * Input:
 * int N (cantidad de jugadores)
 * .......
 * ******
 * Returns:
 * int 0
 * ******
 * */
int brisca(int N){
    Naipe naipes[53];
    int contador = 1;
    if ( N >= 2 && N <= 6 ){
        int cartas = 4 * N;
        int numeroAleatorio[cartas];
        for (int i = 1; i <= cartas ; i++) {
            numeroAleatorio[i] = randin(52, 1);
            for(int j = 1 ; j<= contador-1;j++){
                int contador2 = 0;
                    while(contador2 <= 0){
                        if(numeroAleatorio[i] == numeroAleatorio[j]){
                            numeroAleatorio[i] = randin(52, 1);
                        }
                        else{
                            contador2++;
                        }
                    }        
            }
        contador++;
        }
        int contador_red = 0;
        int contador_blck = 0;
        ifstream fp;
        string s;
        fp.open("baraja.dat",  ios::in | ios::binary);
        int numNaipes;
        fp.read(reinterpret_cast<char*>(&numNaipes), sizeof(numNaipes)); // Lee el número de naipes
        char prefijo = 'B';
        string nombreArchivo = string(1, prefijo) + to_string(N) + ".txt";
        ofstream fz;
        fz.open(nombreArchivo,ios::out);
        int contador_epico = 1;
        for( int hans = 1 ; hans <= cartas; hans++){
            if(contador_epico == 4){
                fz << numeroAleatorio[hans] <<endl;
                contador_epico = 1;
            }
            else{
                contador_epico++;
                fz << numeroAleatorio[hans] << " ";
            }
        } 

        for(int g = 1 ; g<=52 ;g++){
            fp.read(reinterpret_cast<char*>(&naipes[g].numero), sizeof(naipes[g].numero));
            fp.read(&naipes[g].palo, sizeof(naipes[g].palo));
            fp.read(&naipes[g].color, sizeof(naipes[g].color));
            s = naipeToString(naipes[g]);
            for(int e = 0 ; e <= cartas; e++){
                if (g == numeroAleatorio[e]){
                    char ultimaLetra = s[s.size() - 1];
                    if(ultimaLetra == 'N'){
                        contador_blck++;
                    }
                    if(ultimaLetra == 'R'){
                        contador_red++;
                    }
                }
            }
        }
        fz.close();
        fp.close();
        cout << "Cantidad de cartas Negras: " << contador_blck << endl;
        cout << "Cantidad de cartas Rojas : " << contador_red << endl;
        return 0;
    }
    else{
        cout<< "Cantidad de jugadores insuficientes o sobrepasa el limite"<< endl;

        return 0;
    }
}
/*****
 * int canasta
 * ******
 * Crea un archivo con las cartas aleatorias y cuenta la cantidad de cartas rojas y negras
 * ******
 * Input:
 * int N (cantidad de jugadores)
 * .......
 * ******
 * Returns:
 * int 0
 * ******
 * */
int canasta(int N){
    Naipe naipes[53];
    int contador = 1;
    if ( N >= 2 && N <= 6 ){
        int cartas = 15 * N;
        int numeroAleatorio[cartas];
        for (int i = 1; i <= cartas ; i++) {
            numeroAleatorio[i] = randin(104, 1);
            for(int j = 1 ; j<= contador-1;j++){
                int contador2 = 0;
                    while(contador2 <= 0){
                        if(numeroAleatorio[i] == numeroAleatorio[j]){
                            numeroAleatorio[i] = randin(104, 1);
                        }
                        else{
                            contador2++;
                        }
                    }        
            }
        contador++;
        }
        int contador_red = 0;
        int contador_blck = 0;
        ifstream fp;
        string s;
        fp.open("baraja.dat",  ios::in | ios::binary);
        int numNaipes;
        fp.read(reinterpret_cast<char*>(&numNaipes), sizeof(numNaipes)); // Lee el número de naipes

        char prefijo = 'C';
        string nombreArchivo = string(1, prefijo) + to_string(N) + ".txt";
        ofstream fz;
        fz.open(nombreArchivo,ios::out);
        int contador_epico = 1;
        for( int hans = 1 ; hans <= cartas; hans++){
            if(contador_epico == 15){
                fz << numeroAleatorio[hans] <<endl;
                contador_epico = 1;
            }
            else{
                contador_epico++;
                fz << numeroAleatorio[hans] << " ";
            }
        } 
        int l = 0;
        for(int g = 0 ; g<=106 ;g++){
            if (g == 53){

                fp.close();
                fp.open("baraja.dat",  ios::in | ios::binary);       
                fp.read(reinterpret_cast<char*>(&numNaipes), sizeof(numNaipes)); // Lee el número de naipes
            }
            if (g > 53){
                l =0;
            }
            else{
                l++;
            }
            fp.read(reinterpret_cast<char*>(&naipes[l].numero), sizeof(naipes[l].numero));
            fp.read(&naipes[l].palo, sizeof(naipes[l].palo));
            fp.read(&naipes[l].color, sizeof(naipes[l].color));
            s = naipeToString(naipes[l]);
            for(int e = 0 ; e <= cartas; e++){
                if (g == numeroAleatorio[e]){
                    char ultimaLetra = s[s.size() - 1];
                    if(ultimaLetra == 'N'){
                        contador_blck++;
                    }
                    if(ultimaLetra == 'R'){
                        contador_red++;
                    }
                }
            }
        }
        fz.close();
        fp.close();
        cout << "Cantidad de cartas Negras: " << contador_blck << endl;
        cout << "Cantidad de cartas Rojas : " << contador_red << endl;
        return 0;
    }
    else{
        cout<< "Cantidad de jugadores insuficientes o sobrepasa el limite"<< endl;

        return 0;
    }
}
/*****
 * int main
 * ******
 * Pregunta el juego y la cantidad de jugadores
 * ******
 * Input:
 * char gamemode (juego)
 * int players (cantidad de jugadores)
 * .......
 * ******
 * Returns:
 * int 0
 * ******
 * */
int main(){
    int players;
    char gamemode, P = 'P', C = 'C', B = 'B';
    cout << "Ingrese Juego(P, C o B) " << endl;
    cin >> gamemode;
    cout << "Ingrese cantidad de jugadores: " << endl;
    cin >> players;
    if (gamemode == P ){
        cout<< "Bienvenido a poker" << endl;
        poker(players);
    }
    else if (gamemode == C ){
        cout<< "Binvenido a canasta" << endl;
        canasta(players);
    }
    else if (gamemode == B ){
        cout<< "Bienvenido a brisca" << endl;
        brisca(players);
    }
    return 0;
}
