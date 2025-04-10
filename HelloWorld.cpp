#include <iostream>      // Para entrada/salida estándar
#include <cstring>       // Para funciones de manejo de cadenas: strcpy, strlen, strncpy
#include <stdexcept>     // Aunque en este código no se usa, permite lanzar/excepciones si se quisiera

using namespace std;

// Verifica si un carácter es una letra (mayúscula o minúscula)
bool isAlphabetic(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

// Convierte una letra mayúscula a minúscula
char toLowerCase(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c + ('a' - 'A'); // Diferencia entre códigos ASCII
    }
    return c; // Si ya es minúscula o no es letra, se devuelve igual
}

// Calcula la longitud de una cadena sin usar strlen
int stringLength(char* str) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

// Elimina todos los caracteres no alfabéticos excepto los espacios
void cleanString(char* str) {
    char* src = str; // puntero de lectura
    char* dst = str; // puntero de escritura
    while (*src) {
        if (isAlphabetic(*src) || *src == ' ') {
            *dst++ = *src; // copia si es letra o espacio
        }
        src++;
    }
    *dst = '\0'; // marca el final de la cadena limpiada
}

// Invierte la cadena usando punteros
void reverseString(char* str) {
    int len = stringLength(str);
    char* start = str;            // inicio
    char* end = str + len - 1;    // final
    while (start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

// Cuenta las vocales y consonantes en la cadena
void countVowelsAndConsonants(char* str, int& consonants, int vowelCount[5]) {
    consonants = 0;
    for (char* ptr = str; *ptr != '\0'; ptr++) {
        char ch = toLowerCase(*ptr);
        if (ch == 'a') vowelCount[0]++;
        else if (ch == 'e') vowelCount[1]++;
        else if (ch == 'i') vowelCount[2]++;
        else if (ch == 'o') vowelCount[3]++;
        else if (ch == 'u') vowelCount[4]++;
        else if (isAlphabetic(ch)) consonants++; // cuenta como consonante
    }
}

// Reemplaza todos los espacios con guiones bajos
void replaceSpacesWithUnderscores(char* str) {
    for (char* ptr = str; *ptr != '\0'; ptr++) {
        if (*ptr == ' ') {
            *ptr = '_';
        }
    }
}

// Función principal
int main(int argc, char* argv[]) {
    // Validación: se espera exactamente un argumento (además del nombre del programa)
    if (argc != 2) {
        cout << "Uso: " << argv[0] << " \"cadena de texto entre comillas\"" << endl;
        return 1;
    }

    // Copiamos el argumento a una cadena local con límite de 100 caracteres
    char str[101];
    strncpy(str, argv[1], 100);
    str[100] = '\0'; // Asegura que termine en '\0'

    // Validaciones de entrada
    if (strlen(str) == 0) {
        cout << "Error: No se aceptan campos vacíos." << endl;
        return 1;
    }

    if (strlen(str) > 100) {
        cout << "Error: Se excedió el límite de 100 caracteres." << endl;
        return 1;
    }

    // Limpieza de la cadena (eliminar caracteres no alfabéticos)
    cleanString(str);

    // Inversión de la cadena
    reverseString(str);

    // Se guarda una copia antes de modificarla más
    char original[101];
    strcpy(original, str);

    // Conteo de vocales y consonantes
    int consonants = 0;
    int vowelCount[5] = {0}; // a, e, i, o, u
    countVowelsAndConsonants(str, consonants, vowelCount);

    // Reemplazo de espacios por guiones bajos
    replaceSpacesWithUnderscores(str);

    // Impresión del resultado
    cout << original << " ";        // Cadena original (invertida y limpia)
    for (int j = 0; j < 5; j++) {
        if (vowelCount[j] > 0) {
            cout << vowelCount[j] << " "; // Número de cada vocal si hay al menos una
        }
    }
    cout << consonants << " ";      // Número total de consonantes
    cout << str << endl;            // Cadena final (con guiones bajos)

    return 0;
}
