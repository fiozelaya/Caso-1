/*
Caso 1
Fiorella Zelaya Coto
*/

#include <iostream>
#include "string.h"
#include <vector>
#include <algorithm>
#include <HashTable.h>

using namespace std;


/*
 Ejercicio 1: CompareTriplets
 Se implementaron compareTriplets y compareTriplets2, siendo la segunda función
 mejor que la primera. 

 La diferencia entre estas funciones, es que compareTriplets tiene un for donde realiza
 6 comparaciones y 6 sumas. La función 2 no tiene un for, si no que realiza 3 comparaciones para
 asegurarse de que los números no sean iguales, y realiza en el peor de los casos 11
 operaciones ariméticas.
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
        else if ( b[i] < a[i]) {
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

    if(a[0]!= b[0]){
        int numero=(a[0]-b[0])/abs(a[0]-b[0]); //+1 si ana es mayor
        resultado[0]+=numero+1;                   //-1 si bob es mayor
        resultado[1]+=numero-1;                   //se hace 0
    }
    if(a[1]!=b[1]){
        int numero=(a[1]-b[1])/abs(a[1]-b[1]);
        resultado[0]+=numero+1;        //para tener múltiplos de dos
        resultado[1]+=numero-1;
    }
    if(a[2]!=b[2]){
        int numero=(a[2]-b[2])/abs(a[2]-b[2]);
        resultado[0]+=numero+1;
        resultado[1]+=numero-1;
    }
    resultado[0]=resultado[0]/2;      //divide entre 2 para obtener el resultado
    resultado[1]=abs(resultado[1]/2);
}


/*
Ejercicio 2: timeConversion
Se implementaron las funciones timeConversion y timeConversion2, siendo la segunda mejor
que la primera.

La diferencia entre ambas radica en que la primer función hace uso de un if para verificar
si el formato de la hora es AM o PM, si es PM realiza una conversión de string a int, y suma
12, y le agrega el resto del string (minutos y segundos). Si es AM y es 12, entonces la hora es 00.

En la segunda función se realiza un proceso más arimético, en el que se se le suma a la hora la
multiplicación de un factor por 12, el cual será 0 si no se debe cambiar la hora y 1 si se debe
hacer la conversión a formato de 24 horas.
*/

//Función timeConversion: convierte una hora en formato 12 horas a 24 horas
//parámetros: recibe un string cuyo formato debe ser hh:mm:ssAM o hh:mm:ssPM
//restricciones: N/A
//salidas: retorna un string del parámetros recibido en formato 24 horas.
string timeConversion(string time12){
    //se obtiene el substr de la hora y del formato (AM o PM)
    string hour12 = time12.substr(0,2);
    string formato = time12.substr(8,2);
    time12 = time12.substr(2,6);

    //si el formato es PM y la hora no es 12, se convierte a entero y se suma 12
    if (formato == "PM" && hour12 != "12"){
        int hora = stoi(hour12);
        hora += 12;
        return to_string(hora).append(time12);
    }
    //si es AM y la hora 12, la hora es "00"
    else if (hour12 == "12" && formato == "AM"){
        hour12 = "00";
    }

    //se retorna el string armado (hora en formato 24 horas + resto del string)
    return hour12.append(time12);

}

//Función timeConversion: convierte una hora en formato 12 horas a 24 horas
//parámetros: recibe un string cuyo formato debe ser hh:mm:ssAM o hh:mm:ssPM
//restricciones: N/A
//salidas: retorna un string del parámetros recibido en formato 24 horas.
string timeConversion2(string time12){
    
    string format24h = time12.substr(2, 6); //:mm:ss
	int hrs = stoi(time12.substr(0,2)); //hh
	int factor = ((hrs%12)/hrs); //Para PM: =0 si hrs=12 | =1 en otro caso
	
	if(time12[8]=='A')
        factor--; //Para AM: =-1 si hrs=12 | =0 en otro caso 
	
    hrs += (12 * factor);

	format24h = (hrs<10) ? "0"+to_string(hrs)+format24h : to_string(hrs)+format24h;
	
	return format24h;
}


/*
Ejercicio 3 birthday
Para este ejercicio se implementó un struct Cuadro para poder hacer una
lista dinámica y poder escoger la cntidad de elementos de la lista. Además,
se implementaron las funciones crearYEncolar, descolar, y sizeOfBar.

Para llevar a cabo el ejercicio birthday, se implementaron dos funciones,
birthday y birthday2, siendo la segunda más eficiente que la primera.

La diferencia entre ambas radica en que la primera función tiene un while dentro del for
que ya recorre el array, para recorrer los siguientos numeros en el array, y 
por cada vuelta se realizan al menos 3 oepraciones ariméticas. 
En cambio, en la segunda función, no implementa este while si no que va sumando conforme
recorre el array UNA sola vez.
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
    int auxM = m, actual = 0, acarreo = 0, resultado = 0;
    int length = s.size();
    
    for (int i = 0; i < length; i++) {
        acarreo += s[i];
        auxM--;
        if(auxM == 0){
            if (d == acarreo){
                resultado++;
            }
            acarreo = s[i];
            auxM = m - 1;
        }
        
        
    }

    return resultado;
}



/*
Ejercicio 4: The Minion Game

Esta función consiste en comparar los puntos de Stuart y Kevin y decidir el ganador del juego.
El juego consiste en sacar el máximo de "pedazos" de una palabra. Stuart saca las que empiezan
con consonantes, y Kevin las que empiezan con vocales.

Esta función calcula los puntos de stuart y kevin, calculando las probabilidades de cada
substring. Por ejemplo, la consonante B en la palabra BANANA, tiene 6 posibilidades en total
de substrings, por lo tanto, Stuart gana 6 puntos.

Al final se imprime en pantalla el resultado.
*/

/*
isVowel: determina si el string es una vocal
parámetros: string de la letra
restricciones: N/A
salidas: true si es vocal, false si no
*/
bool isVowel(string c){
    if (c == "A" || c == "E" || c == "I" || c == "O" || c == "U"){
        return true;
    }
    return false;
}

void minion_game(string text) {
    int stuart = 0, kevin = 0, length = text.length(), apariciones = 0;
    vector<string> array;
    string substr;

    for (int i = 0; i < length; i++) {
        //se obtiene el substr de la letra con índice i
        substr = text.substr(i,1);
        //si es vocal, se le suma length - i a kevin, si es consonante, a stuart.
        kevin+= ((isVowel(substr)) ? length-i:0);
        stuart+= ((isVowel(substr)) ? 0:length-i);
    }

    //comparaciones para determinar el ganador
    if (stuart > kevin) {
        cout << "Stuart " << stuart << endl;
    }
    else if (kevin > stuart) {
        cout << "Kevin " << kevin << endl;
    }
    else {
        cout << "Draw" << endl;
    }
}


/*
Ejercicio 5: Cipher

Crear un algoritmo que decodifique el número cifrado de Jack, para el cual
se realiza n desplazamientos del número binario escogido, y luego se hace un
XOR en cada columna. Como resultado, se obtiene el número cifrado.

Para crear el algoritmo de decodificación, se utilizó la siguiente estrategia:

Debido a que inicialmente se debe desplazar el número binario n veces, vamos a
averiguar cada digito hasta k - 1.

Luego, procedemos a calcular los digitos despues de k, haciendo un XOR entre
los k - 1 dígitos anteriores y el actual.

Por último, se realiza la conversión a string para retornarlo.

Y así sucesivamente.

*/

string cipher(int k, string s) {
    // return resul;
    int length = s.length();
    vector<char> result(length - k + 1);

    result[0] = s[0]-48;

    // Calcular los elementos de 1 a k-1
    for (int i = 1; i < k; i++) {
        result[i] = s[i-1] ^ s[i];
    }

    // Calcular los elementos de k en adelante
    char aux;
    for (int i = k; i < length; i++) {
        aux = '0';
        for (int j = i-(k-1); j < i; j++) {
            aux = aux ^ result[j];
        }
        result[i] = aux ^ s[i];
    }

    // Armar el string con el resultado
    string final_result = "";
    for (int i = 0; i < length - k + 1 ; i++) {
        final_result += result[i]+48;
    }
    return final_result;
}

/*
Ejercicio 6: Pairs
Se debe crear un algoritmo que recorra el array de números, comparando que
la diferencia entre pares sea igual a k.

Para resolver este ejercicio, se utilizó un array de enteros donde se va
guardando la diferencia de los números del array original - k para luego hacer
una comparación con los demás números y calcular las parejas cuya diferencia
sea igual a k.

*/

/*
Find: busca un valor en un array
parámetros: int valor a buscar, array en el que se va a buscar el valor
restricciones: N/A
salidas: true si se encuentra, false si no
*/
bool find (int value, vector<int> arr){
    int length = arr.size();

    for (int i = 0; i < length; i++){
        if (arr[i] == value){
            return true;
        }
    }
    return false;
}

/*
Pairs
parámetros: entero k, array de n números
restricciones: N/A
salidas: retorna la cantidad de pareas cuya diferencia es igual a k
*/

int pairs(int k, vector<int> arr) {
    
    //def variables
    vector<int> diferencias;
    diferencias.clear();
    int length = arr.size(), actual = 0, resultado = 0;

    for(int i = 0; i < length; i++){
        actual = arr[i]; //entero actual del array
        
        //se pregunta si el entero actual, o el entero actual -k o el entero actual +k está en el array
        //de diferencias, si está es porque hace pareja con la diferencia de otro número
        if (find(actual,diferencias) || find(actual - k, diferencias) || find(actual + k, diferencias)){
            resultado++;
        }

        //se agrega al array actual -k y actual +k
        diferencias.insert(diferencias.begin(), abs(actual - k));
        diferencias.insert(diferencias.begin(), abs(actual + k));
        
    }

    return resultado;
}

int main() {
    int i = 0;
    //------------------------------------------------------EJERCICIO 1--------------------------------------------------------------------
    //Ejemplo 1
    int a[3] = { 50,90,100 };
    int b[3] = { 80,40,100 };
    int resultado[2];
    cout << "Ejercicio 1: Compare the Triplets" << endl;
    cout << "\nFuncion 1:\nPuntos de alice: 50, 90, 100\nPuntos de Bob: 80, 40, 100\nResultado: ";
    compareTriplets(a, b, resultado);
    cout << resultado[0] << " " << resultado[1] << endl;
    //Ejemplo 1.2
    a[0] = 97, a[1] = 56, a[2] = 10;
    b[0] = 73, b[1] = 78, b[2] = 97;
    resultado[0] = 0, resultado[1] = 0;
    cout << "Puntos de alice: 90, 56, 10\nPuntos de Bob: 73, 78, 97\nResultado: ";
    compareTriplets(a, b, resultado);
    cout << resultado[0] << " " << resultado[1] << endl;

    //Ejemplo 2
    a[0] = 50, a[1] = 90, a[2] = 100;
    b[0] = 80, b[1] = 40, b[2] = 100;
    resultado[0] = 0, resultado[1] = 0;
    compareTriplets2(a, b, resultado);
    cout << "\nFuncion 2:\nPuntos de alice: 50, 90, 100\nPuntos de Bob: 80, 40, 100\nResultado: ";
    cout << resultado[0] << " " << resultado[1] << endl;

    //Ejemplo 2.2
    a[0] = 97, a[1] = 56, a[2] = 10;
    b[0] = 73, b[1] = 78, b[2] = 97;
    resultado[0] = 0, resultado[1] = 0;
    compareTriplets2(a, b, resultado);
    cout << "Puntos de alice: 90, 56, 10\nPuntos de Bob: 73, 78, 97\nResultado: ";
    cout << resultado[0] << " " << resultado[1] << endl;

    //------------------------------------------------------EJERCICIO 2--------------------------------------------------------------------
    string time = "06:05:45PM";
    cout<< "-----------------------------------------------------------------\nEjercicio2: Conversion Time" << endl;
    cout << "\nFuncion 1: \nString inicial: " << time << endl;
    cout << "Resultado: " << timeConversion(time) << endl;
    time = "12:05:45AM";
    cout << "String inicial: " << time << endl;
    cout << "Resultado: " << timeConversion(time) << endl;

    time = "06:05:45PM";
    cout << "\nFuncion 2: \nString inicial: " << time << endl;
    cout << "Resultado: " << timeConversion2(time) << endl;
    time = "12:05:45AM";
    cout << "String inicial: " << time << endl;
    cout << "Resultado: " << timeConversion2(time) << endl;
    

    //------------------------------------------------------EJERCICIO 3--------------------------------------------------------------------
    cout<< "-----------------------------------------------------------------\nEjercicio3: Birthday" << endl;
    cout << "\nFuncion 1:" << endl;

    //Ejemplo 1
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
    
    //Ejemplo 1.2
    vector<int> barraDeChocolate3(5);
    barraDeChocolate3[0] = 1;
    barraDeChocolate3[1] = 2;
    barraDeChocolate3[2] = 1;
    barraDeChocolate3[3] = 3;
    barraDeChocolate3[4] = 2;
    m = 2; d = 3;
    i = 0;

    cout << "\nLa barra de chocolate tiene los siguientes digitos: ";
    while (i < barraDeChocolate3.size()){
        cout << barraDeChocolate3[i] << " ";
        i++;
    }

    cout << "\nLily quiere darle a Ron " << m << " cuadros de chocolate cuyos digitos sumen " << d << endl; 
    cout << "La barra de chocolate puede ser dividida en " << birthday(barraDeChocolate3, d, m) << " formas." << endl;
    
    cout << "\nFuncion 2:" << endl; 

    vector<int> barraDeChocolate4(1);

    //Ejemplo 2
    barraDeChocolate4[0] = 4;
    i = 0;
    m = 1, d = 4;

    cout << "La barra de chocolate tiene los siguientes digitos: ";
    i = 0;
    while (i < barraDeChocolate4.size()){
        cout << barraDeChocolate4[i] << " ";
        i++;
    }
    cout << "\nLily quiere darle a Ron " << m << " cuadros de chocolate cuyos digitos sumen " << d << endl; 
    
    cout << "La barra de chocolate puede ser dividida en " << birthday2(barraDeChocolate4, d, m) << " formas." << endl;

    //Ejemplo 2.2
    vector<int> barraDeChocolate2(5);    
    barraDeChocolate2[0] = 1;
    barraDeChocolate2[1] = 2;
    barraDeChocolate2[2] = 1;
    barraDeChocolate2[3] = 3;
    barraDeChocolate2[4] = 2;
    m = 2; d = 3;
    i = 0;

    cout << "\nLa barra de chocolate tiene los siguientes digitos: ";
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

    cout << "\nPalabra: HOLA \nResultado: " << endl;
    minion_game("HOLA");


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

