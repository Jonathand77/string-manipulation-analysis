#include <iostream>
#include <stdexcept> // Para std::runtime_error
using namespace std;

// Verifica si un carácter es alfabético
bool isAlphabetic(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

// Convierte un carácter a minúscula si es mayúscula
char toLowerCase(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c + ('a' - 'A');
    }
    return c;
}

// Calcula la longitud de una cadena manualmente
int stringLength(char* str) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

// Elimina caracteres no alfabéticos excepto espacios
void cleanString(char* str) {
    char* src = str;
    char* dst = str;
    while (*src) {
        if (isAlphabetic(*src) || *src == ' ') {
            *dst++ = *src;
        }
        src++;
    }
    *dst = '\0';
}

// Invierte la cadena usando punteros
void reverseString(char* str) {
    int len = stringLength(str);
    char* start = str;
    char* end = str + len - 1;
    while (start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

// Cuenta vocales y consonantes
void countVowelsAndConsonants(char* str, int& vowels, int& consonants, int vowelCount[5]) {
    vowels = consonants = 0;
    for (char* ptr = str; *ptr != '\0'; ptr++) {
        char ch = toLowerCase(*ptr);
        if (ch == 'a') { vowels++; vowelCount[0]++; }
        else if (ch == 'e') { vowels++; vowelCount[1]++; }
        else if (ch == 'i') { vowels++; vowelCount[2]++; }
        else if (ch == 'o') { vowels++; vowelCount[3]++; }
        else if (ch == 'u') { vowels++; vowelCount[4]++; }
        else if (isAlphabetic(ch)) {
            consonants++;
        }
    }
}

// Reemplaza espacios con guiones bajos
void replaceSpacesWithUnderscores(char* str) {
    for (char* ptr = str; *ptr != '\0'; ptr++) {
        if (*ptr == ' ') {
            *ptr = '_';
        }
    }
}

int main() {
    char str[101];
    std::cout << "Enter a string (max 100 characters): ";

    int i = 0;
    char ch;
    while (i < 100 && cin.get(ch) && ch != '\n') {
        str[i++] = ch;
    }

    // Verificar si no se ingresó ningún carácter
    if (i == 0) {
        cout << "Error: No se aceptan campos vacíos." << endl;
        return 1;
    }

    // Verificar si se superó el límite de caracteres
    if (ch != '\n') {
        cout << "Error: Se excedió el límite de 100 caracteres." << endl;
        return 1;
    }

    str[i] = '\0';

    // Limpiar caracteres no válidos
    cleanString(str);

    // Invertir
    reverseString(str);

    // Contar
    int vowels = 0, consonants = 0;
    int vowelCount[5] = {0}; // a, e, i, o, u
    countVowelsAndConsonants(str, vowels, consonants, vowelCount);

    // Reemplazar espacios
    replaceSpacesWithUnderscores(str);

    // Resultados
    cout << "\nReversed string: " << str << endl;
    cout << "Number of vowels: " << vowels << endl;
    cout << "Number of 'a': " << vowelCount[0] << endl;
    cout << "Number of 'e': " << vowelCount[1] << endl;
    cout << "Number of 'i': " << vowelCount[2] << endl;
    cout << "Number of 'o': " << vowelCount[3] << endl;
    cout << "Number of 'u': " << vowelCount[4] << endl;
    cout << "Number of consonants: " << consonants << endl;
    cout << "Modified string: " << str << endl;

    return 0;
}
