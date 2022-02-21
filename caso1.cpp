/*
Caso 1
Fiorella Zelaya Coto
*/

#include <iostream>
#include "string.h"
#include <vector>

using namespace std;


/*
 Ejercicio 1: CompareTriplets
 Se implementaron compareTriplets y compareTriplets2, siendo la segunda función
 mejor que la primera. 

 La diferencia entre estas funciones, es que compareTriplets tiene 6 comparaciones más
 las comparaciones que realiza el for y 7 sumas, además de 2 deficiniciones de variables 
 y 2 asignaciones de resultados al final del for. 

 Mientras que la funcion 2 tiene solamente 6 comparaciones en total, 6 sumas
 y solamente 2 asignaciones en total.
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
    resultado[0] = (a[0] > b[0] ? 1 : 0) +  (a[1] > b[1] ? 1 : 0) + (a[2] > b[2] ? 1 : 0);
    resultado[1] = (a[0] < b[0] ? 1 : 0) +  (a[1] < b[1] ? 1 : 0) + (a[2] < b[2] ? 1 : 0);

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

La diferencia entre ambas radica en que .
*/


//Función birthday: Calcula la cantidad total de formas en las que Lily
//                  puede darle m cuadros de chocolate a Ron, cuyos digitos
//                  sumados sean igual a d
//parámetros: La lista s que simula la barra de chocolate de tipo PtrCuadro
//            y 2 enteros d y m
//restricciones: N/A
//salidas: retorna la cantidad total de formas en las que se puede dividir
//         la barra
int birthday(vector<int> s, int d, int m){
    int auxM = m, suma = 0, resultado = 0, j;
    int length = s.size();
    
    for (int i = 0; i < length; i++) {
        j = i;

        while (auxM != 0 && j < length) {
            suma += s[j];
            j++;
            auxM--;
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

int birthday2(vector<int> s, int d, int m){
    int auxM = m, suma = 0, resultado = 0, j;
    int length = s.size();
    
    for (int i = 0; i < length; i++) {
        j = i;

        while (auxM != 0 && j < length) {
            suma += s[j];
            j++;
            auxM--;
        }

        if (auxM == 0 && suma == d) {
            resultado++;
        }
        auxM = m;
        suma = 0;
        
        
    }

    return resultado;
}



/*
Ejercicio 4: The Minion Game

*/

bool isVowel(char c){
    if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'){
        return true;
    }
    return false;
}

int count(string text, string s){
    int length = text.length(), i = 1, result = 0;
    string subst;

    while(i != 0){ //BANANA BANANA
        i = text.find(s) + 1;
        result++;
        text = text.substr(i);
    }

    return result;
}

void minion_game(string text){
    int stuart = 0, kevin = 0, i= 0, length = text.length();

}


/*
Ejercicio 5: Cipher

Crear un algoritmo que decodifique el número cifrado de Jack, para el cual
se realiza n desplazamientos del número binario escogido, y luego se hace un
XOR en cada columna. Como resultado, se obtiene el número cifrado.

Para crear el algoritmo de decodificación, se utilizó la siguiente estrategia:

Debido a que inicialmente se debe desplazar el número binario n veces, vamos a
averiguar cada digito y lo vamos a desplazar n veces en un Array. El primer dígito
es sencillo de averiguar, puesto que no realiza un XOR con nada.

Ejemplo:

Número a decodificar: 1110100110
Desplazamientos: 4

1
 1 <---- desplazamos el digito k veces (2)
  1
   1
__________
1110100110  <----- el primer digito es 1 (1)

Luego, en la segunda columna, podemos observar que el resultado del XOR entre los
digitos de las columnas es un 1. El único dígito que tenemos en la columna 2 es un 1,
por lo tanto, si el resultado del XOR es un 1, quiere decir que el dígito "anterior"
es un 0, puesto que 1 ^ 0 = 1.

Entonces:

10
 10 <---- desplazamos el digito k veces (2)
  10
   10
__________
1110100110  <----- el segundo digito es 0, puesto que 1 XOR 0 es 1 (1)

Y así sucesivamente.

*/

string cipher(int k, string s) {
    int length = s.length();
    char sArray[length + 1];
    strcpy_s(sArray, length + 1, s.c_str());
    char matriz[k][length];
    string resul = "";
    
    int auxK, actual, bitAnterior;
    char actualC, bit;
    int bitTotal = -1;

    for (int i = 0; i < length - k + 1; i++) {
        auxK = k;
        actual = sArray[i] == '1' ? 1:0;

        while (auxK - 1 != 0) {
                if (auxK - 2 > 0) {

                    bitAnterior = matriz[auxK-2][i] == '1' ? 1:0;
                    if (bitTotal != -1) {
                        bitTotal = bitTotal ^ bitAnterior;
                    }
                    else {
                        bitTotal = matriz[auxK - 1][i] == '1' ? 1:0;
                        bitTotal = bitTotal ^ bitAnterior;
                    }
                }

                else {

                    if (bitTotal == -1) {
                        bitTotal = matriz[auxK - 1][i] == '1' ? 1 : 0;
                    }

                    if (actual == 1) {
                        bitTotal = bitTotal == 1 ? 0 : 1;
                    }

                }
            
            auxK--;
        }

        bit = bitTotal == 1 ? '1':'0';
        resul += bit;
        while (auxK != k) {
            matriz[auxK][i + auxK] = bit;
            auxK++;
        }

        bitTotal = -1;
    }

    
    return resul;
}

/*
Ejercicio 6: Pairs
Se debe crear un algoritmo que recorra el array de números, comparando que
la diferencia entre pares sea igual a k.

parámetros: entero k, array de n números
restricciones: N/A
salidas: retorna la cantidad de pareas cuya diferencia es igual a k

*/

int pairs(int k, vector<int> array){
    int length = array.size(), i = 0, j = 0, actual, resultado = 0;

    while(i < length){
        actual = array[i];
        while (j < length){
            if (actual - array[j] == k) { resultado++; }
            j++;
        }
        j = 0; i++;
    }

    return resultado;
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

    vector<int> barraDeChocolate(1);
    barraDeChocolate[0] = 4;
    i = 0;
    int m = 1, d = 4;

    cout << "La barra de chocolate tiene los siguientes digitos: ";
    while (i < barraDeChocolate.size()){
        cout << barraDeChocolate[i] << " ";
        i++;
    }
    cout << "\nLily quiere darle a Ron " << m << " cuadros de chocolate cuyos digitos sumen " << d << endl; 
    cout << "La barra de chocolate puede ser dividida en " << birthday(barraDeChocolate, d, m) << " formas." << endl;
    
    cout << "\nFuncion 2:" << endl; 

    vector<int> barraDeChocolate2(5);
    barraDeChocolate2[0] = 1;
    barraDeChocolate2[1] = 2;
    barraDeChocolate2[2] = 1;
    barraDeChocolate2[3] = 3;
    barraDeChocolate2[4] = 2;
    m = 2; d = 3;

    cout << "La barra de chocolate tiene los siguientes digitos: ";
    i = 0;
    while (i < barraDeChocolate2.size()){
        cout << barraDeChocolate2[i] << " ";
        i++;
    }
    cout << "\nLily quiere darle a Ron " << m << " cuadros de chocolate cuyos digitos sumen " << d << endl; 
    
    cout << "La barra de chocolate puede ser dividida en " << birthday2(barraDeChocolate2, d, m) << " formas." << endl;

    //------------------------------------------------------EJERCICIO 4--------------------------------------------------------------------
    cout<< "-----------------------------------------------------------------\nEjercicio4: The Minion Game" << endl;
    cout << "\nPalabra: BANANA \nResultado: " << endl;
    minion_game("BANANA");




     //------------------------------------------------------EJERCICIO 5--------------------------------------------------------------------
    cout<< "-----------------------------------------------------------------\nEjercicio5: Cipher" << endl;
    
    cout << "\nEl mensaje a descodificar es: " << "1110100110 con 4 desplazamientos" << endl;
    cout << "Descodificando... \nMensaje descodificado: "<< cipher(4, "1110100110") << endl;

    cout << "\nEl mensaje a descodificar es: " << "1110001 con 2 desplazamientos" << endl;
    cout << "Descodificando... \nMensaje descodificado: "<< cipher(2, "1110001") << endl;

    cout << "\nEl mensaje a descodificar es: " << "1110011011 con 3 desplazamientos" << endl;
    cout << "Descodificando... \nMensaje descodificado: "<< cipher(3, "1110011011") << endl;

    //------------------------------------------------------EJERCICIO 6--------------------------------------------------------------------
    cout<< "-----------------------------------------------------------------\nEjercicio6: Pairs" << endl;

    vector<int> array(4);
    array[0] = 1;
    array[1] = 2;
    array[2] = 3;
    array[3] = 4;

    cout << "\nArray actual: {1, 2, 3, 4} y k = 1 \nResultado: ";
    cout << pairs(1, array) << endl;

    vector<int> array2(5);
    array2[0] = 1;
    array2[1] = 5;
    array2[2] = 3;
    array2[3] = 4;
    array2[4] = 2;

    cout << "\nArray actual: {1, 5, 3, 4, 2} y k = 2 \nResultado: ";
    cout << pairs(2, array2) << endl;
}