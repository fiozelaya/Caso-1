/*
Caso 1
Fiorella Zelaya Coto
*/

#include <iostream>
#include "string.h"

using namespace std;


/*
 Ejercicio 1: CompareTriplets
 Se implementaron compareTriplets y compareTriplets2, siendo la segunda función
 mejor que la primera. 

 La diferencia entre estas funciones, es que compareTriplets tiene 4 comparaciones (ifs):
 2 para validar restricciones y 2 para sumar los puntos según corresponda, mientras
 que compareTriplets2 tiene únicamente 2 ifs y 1 if else, en las cuales se utiliza
 1 para validar restricciones, y 1 if e if else para sumar los puntos según corresponda.

Otra diferencia radica en que compareTriplets usa constantemente a[i] y b[i], mientras
que compareTriplets2 declara 2 variables (actualA y actualB) a las que se les asignan estos 
elementos para no tener que buscar el elemento en el Cuadro resultado cada vez que se necesite.
*/

//compareTriplets: Esta función compara los puntos de Alice y Bob en 3 categorías.
//párametros: un Cuadro "a" y "b" de 3 elementos, de los puntos de Alice y Bob respectivamente
//            un Cuadro "resultado" de 2 elementos, para guardar los resultados de la función
//restricciones: los puntos de Alice y Bob deben estar en el rango 1-100
//salidas: se modifica el Cuadro "resultado" de modo que: [puntos_de_alice, puntos_de_bob]
int compareTriplets(int a[3], int b[3], int resultado[2]) {
    //inicialización de variables
    int ptsA = 0, ptsB = 0;

    for (int i = 0; i <= 2; i++) {
        //asignación de variables
        //restricciones
        if (a[i] < 1 || a[i] > 100) {
            return NULL;
        }
        if ( b[i] < 1 ||  b[i] > 100) {
            return NULL;
        }
        //comparación de puntos
        if (a[i] <  b[i]) {
            ptsB++;
        }
        if ( b[i] < a[i]) {
            ptsA++;
        }
    }
    //asignación de puntos al Cuadro de resultados
    resultado[0] = ptsA;
    resultado[1] = ptsB;
}

//compareTriplets2: Esta función compara los puntos de Alice y Bob en 3 categorías. Es la versión
//                 "optimizada" de compareTriplets.
//párametros: un Cuadro "a" y "b" de 3 elementos, de los puntos de Alice y Bob respectivamente
//            un Cuadro "resultado" de 2 elementos, para guardar los resultados de la función
//restricciones: los puntos de Alice y Bob deben estar en el rango 1-100
//salidas: se modifica el Cuadro "resultado" de modo que: [puntos_de_alice, puntos_de_bob]
int compareTriplets2(int a[3], int b[3], int resultado[2]) {
    //inicialización de variables
    int actualA, actualB, ptsA = 0, ptsB = 0;

    for (int i = 0; i <= 2; i++) {
        actualA = a[i];
        actualB = b[i];
        //restricciones
        if (actualA < 1 || actualA > 100 || actualB < 1 || actualB > 100) {
            return NULL;
        }
        //comparación de puntos
        if (actualA < actualB) {
            ptsB++;
        }
        else if (actualB < actualA) {
            ptsA++;
        }
    }
    //asignación de puntos al Cuadro de resultados
    resultado[0] = ptsA;
    resultado[1] = ptsB;
}


/*
Ejercicio 2: timeConversion
Se implementaron las funciones timeConversion y timeConversion2, siendo la segunda mejor
que la primera.

La diferencia entre ambas radica en que la primer función hace uso de múltiples 
condicionales if, if else, mientras que la segunda función no realiza esta gran
cantidad de condicionales, solamente para saber si el formato es AM o PM. Luego,
realiza la conversión de string a int para realizar una suma que determinará
la hora en formato 24 horas, y luego lo convierte a string de nuevo.

Por último, ambas funciones juntan el string de la hora con lo demás del
string original y lo retornan, con la diferencia de que la segunda opción
retorna directamente la operación, y la primera la asigna a una variable antes
de retornarla.
*/

//Función timeConversion: convierte una hora en formato 12 horas a 24 horas
//parámetros: recibe un string cuyo formato debe ser hh:mm:ssAM o hh:mm:ssPM
//restricciones: N/A
//salidas: retorna un string del parámetros recibido en formato 24 horas.
string timeConversion(string time12){
    string time24;
    string hour12 = time12.substr(0,2);
    string formato = time12.substr(8,2);
    time12 = time12.substr(2,6);
    
    if(formato == "PM"){
        if (hour12 == "01"){
            hour12 = "13";
        }
        else if(hour12 == "02"){
            hour12 = "14";
        }
        else if(hour12 == "03"){
            hour12 = "15";
        }
        else if(hour12 == "04"){
            hour12 = "16";
        }
        else if(hour12 == "05"){
            hour12 = "17";
        }
        else if(hour12 == "06"){
            hour12 = "18";
        }
        else if(hour12 =="07"){
            hour12 = "19";
        }
        else if(hour12 =="08"){
            hour12 = "20";
        }
        else if(hour12 =="09"){
            hour12 = "21";
        }
        else if(hour12 == "10"){
            hour12 = "22";
        }
        else if(hour12 == "11"){
            hour12 = "23";
        }

    }
    else if (formato == "AM"){
        if (hour12 == "12"){
            hour12 = "00";
        }
    }
    
    time24 = hour12.append(time12);
    return time24;
}

//Función timeConversion: convierte una hora en formato 12 horas a 24 horas
//parámetros: recibe un string cuyo formato debe ser hh:mm:ssAM o hh:mm:ssPM
//restricciones: N/A
//salidas: retorna un string del parámetros recibido en formato 24 horas.
string timeConversion2(string time12){
    string hour12 = time12.substr(0,2);
    string formato = time12.substr(8,2);
    time12 = time12.substr(2,6);

    if (formato == "PM" && hour12 != "12"){
        int hora = stoi(hour12);
        hora += 12;
        return to_string(hora).append(time12);
    }
    else if (hour12 == "12" && formato == "AM"){
        hour12 = "00";
    }

    return hour12.append(time12);
}


/*
Ejercicio 3 birthday
Para este ejercicio se implementó un struct Cuadro para poder hacer una
lista dinámica y poder escoger la cntidad de elementos de la lista. Además,
se implementaron las funciones crearYEncolar, descolar, y sizeOfBar.

Para llevar a cabo el ejercicio birthday, se implementaron dos funciones,
birthday y birthday2, siendo la segunda más eficiente que la primera.

La diferencia entre ambas radica en que para poder analizar cada cuadro
de la barra de chocolate, se asigna en casa vuelta del for la lista S a la
variable Aux, y con un while se descolan los elementos según corresponda. 
Mientras que en la segunda función, también se utiliza una variable auxiliar,
sin embargo, no se realiza el proceso de descolar los elementos en cada vuelta,
sino que se descolan según se realizan las demás instrucciones en la función.

Al hacerlo de esta forma, la función 2 es más eficiente al no tener que
repetir constantemente el descolar los elementos de la lista dinámica.
*/

//Struct Cuadro
typedef struct Cuadro{
    int digito;
    Cuadro *PtrSiguiente;
}*PtrCuadro;

//Función crearYEncolarDigito: Crea un nuevo cuadro con su digito y lo
//                             encola.
//parámetros: La lista que simula la barra de chocolate de tipo PtrCuadro
//            y el digito del Cuadro
//restricciones: N/A
//salidas: N/A
void crearYEncolarDigito(PtrCuadro &lista, int n){
    PtrCuadro Aux = lista;
    PtrCuadro nuevo = new(Cuadro);
    nuevo->digito = n;
    nuevo->PtrSiguiente = NULL;
        if (Aux != NULL){
            while (Aux->PtrSiguiente != NULL){
                Aux = Aux->PtrSiguiente;
            }
            Aux->PtrSiguiente = nuevo;
        }
        else{
            lista = nuevo;
        }
}

//Función sizeOfBar: calcula la longitud de la lista que simula la barra de
//                   chocolate
//parámetros: La lista que simula la barra de chocolate de tipo PtrCuadro
//restricciones: N/A
//salidas: retorna la longitud de la lista.
int sizeOfBar(PtrCuadro Lista){
    int n = 0;
    while (Lista != NULL){
        n++;
        Lista = Lista->PtrSiguiente;
    }
    return n;
}

//Función descolar: descola un elemento de la lista.
//parámetro:  lista que simula la barra de chocolate de tipo PtrCuadro
//restricciones: N/A
//salidas: N/A
void descolar(PtrCuadro &Lista){
    Lista = Lista->PtrSiguiente;
}

//Función birthday: Calcula la cantidad total de formas en las que Lily
//                  puede darle m cuadros de chocolate a Ron, cuyos digitos
//                  sumados sean igual a d
//parámetros: La lista s que simula la barra de chocolate de tipo PtrCuadro
//            y 2 enteros d y m
//restricciones: N/A
//salidas: retorna la cantidad total de formas en las que se puede dividir
//         la barra
int birthday(PtrCuadro s, int d, int m){
    int auxM = m;
    int suma = 0;
    int resultado = 0;
    PtrCuadro Aux;
    int length = sizeOfBar(s);
    for (int i = 0; i < length; i++) {
        Aux = s;
        while (sizeOfBar(Aux) != length - i) {
            descolar(Aux);
        }
        
        while (auxM != 0) {
            if (Aux != NULL) {
                suma += Aux->digito;
                auxM--;
                Aux = Aux->PtrSiguiente;
            }
            else {
                break;
            }
        }

        if (auxM == 0 && suma == d) {
            resultado++;
        }
        auxM = m;
        suma = 0;
        
    }

    return resultado;
}

//Función birthday2: Calcula la cantidad total de formas en las que Lily
//                  puede darle m cuadros de chocolate a Ron, cuyos digitos
//                  sumados sean igual a d
//parámetros: La lista s que simula la barra de chocolate de tipo PtrCuadro
//            y 2 enteros d y m
//restricciones: N/A
//salidas: retorna la cantidad total de formas en las que se puede dividir
//         la barra
int birthday2(PtrCuadro s, int d, int m){
    int auxM = m;
    int suma = 0;
    int resultado = 0;
    int length = sizeOfBar(s);
    PtrCuadro aux = s;
    for (int i = 0; i < length; i++) {
        while (auxM != 0) {
            if (aux != NULL) {
                suma += aux->digito;
                auxM--;
                aux = aux->PtrSiguiente;
            }
            else {
                break;
            }
        }

        if (auxM == 0 && suma == d) {
            resultado++;
        }
        auxM = m;
        suma = 0;
        descolar(s);
        aux = s;
        
    }

    return resultado;
}



/*
Ejercicio 4: The Minion Game

*/

void minion_game(string text){

}

int main() {
    int i = 0;
    //------------------------------------------------------EJERCICIO 1--------------------------------------------------------------------
    int a[3] = { 50,90,100 };
    int b[3] = { 80,40,100 };
    int resultado[2];
    cout << "Ejercicio 1: Compare the Triplets" << endl;
    cout << "\nFuncion 1:\nPuntos de alice: 50, 90, 100\nPuntos de Bob: 80, 40, 100\nResultado: ";
    compareTriplets(a, b, resultado);
    cout << resultado[0] << " " << resultado[1] << endl;

    a[0] = 97, a[1] = 56, a[2] = 10;
    b[0] = 73, b[1] = 78, b[2] = 97;
    compareTriplets2(a, b, resultado);
    cout << "\nFuncion 2:\nPuntos de alice: 90, 56, 10\nPuntos de Bob: 73, 78, 97\nResultado: ";
    cout << resultado[0] << " " << resultado[1] << endl;

    //------------------------------------------------------EJERCICIO 2--------------------------------------------------------------------
    string time = "06:05:45PM";
    cout<< "-----------------------------------------------------------------\nEjercicio2: Conversion Time" << endl;
    cout << "\nFuncion 1: \nString inicial: " << time << endl;
    cout << "Resultado: " << timeConversion(time) << endl;

    time = "12:05:45AM";
    cout << "\nFuncion 2: \nString inicial: " << time << endl;
    cout << "Resultado: " << timeConversion2(time) << endl;

    //------------------------------------------------------EJERCICIO 3--------------------------------------------------------------------
    cout<< "-----------------------------------------------------------------\nEjercicio3: Birthday" << endl;
    cout << "\nFuncion 1:" << endl;
    PtrCuadro Lista = NULL;
    PtrCuadro Lista2 = NULL;
    PtrCuadro Aux = NULL;

    crearYEncolarDigito(Lista, 4);
    int m = 1, d = 4;

    Aux = Lista;
    cout << "La barra de chocolate tiene los siguientes digitos: ";
    while (Aux != NULL){
        cout << Aux->digito << " ";
        Aux = Aux->PtrSiguiente;
    }
    cout << "\nLily quiere darle a Ron " << m << " cuadros de chocolate cuyos digitos sumen " << d << endl; 
    cout << "La barra de chocolate puede ser dividida en " << birthday(Lista, d, m) << " formas." << endl;
    
    cout << "\nFuncion 2:" << endl; 

    crearYEncolarDigito(Lista2, 1);
    crearYEncolarDigito(Lista2, 2);
    crearYEncolarDigito(Lista2, 1);
    crearYEncolarDigito(Lista2, 3);
    crearYEncolarDigito(Lista2, 2);
    m = 2; d = 3;

    Aux = Lista2;
    cout << "La barra de chocolate tiene los siguientes digitos: ";
    while (Aux != NULL){
        cout << Aux->digito << " ";
        Aux = Aux->PtrSiguiente;
    }
    cout << "\nLily quiere darle a Ron " << m << " cuadros de chocolate cuyos digitos sumen " << d << endl; 
    
    cout << "La barra de chocolate puede ser dividida en " << birthday2(Lista2, d, m) << " formas." << endl;

    //------------------------------------------------------EJERCICIO 4--------------------------------------------------------------------
    cout<< "-----------------------------------------------------------------\nEjercicio4: The Minion Game" << endl;
    

}