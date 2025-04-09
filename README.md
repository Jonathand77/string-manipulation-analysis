# string-manipulation-analysis

## 👥 Integrantes

| 👨‍💻 Nombre | 📧 Correo | 🐙 Usuario GitHub |
|---|---|---|
| **Jonathan David Fernandez Vargas** | jonathand.fernandez@udea.edu.co | [jonathand77](https://github.com/jonathand77) |
| **Valeria Alvarez Fernandez** | valeria.alvarezf@udea.edu.co | [vaf88](https://github.com/vaf88) |

---

# 🏆 Programa en Go y C++

## 🚀 Resumen general (Go)
Este programa en Go:
- Solicita al usuario una cadena de texto (máximo 100 caracteres).
- Verifica que la cadena no esté vacía ni supere los 100 caracteres.
- Limpia la cadena eliminando caracteres no alfabéticos.
- Invierte la cadena.
- Cuenta vocales y consonantes, además de la frecuencia de cada vocal.
- Reemplaza espacios con guiones bajos (`_`).
- Muestra los resultados en la consola.

## 🧩 Análisis del código (Go)

### 📌 Importación de paquetes
```go
import (
    "bufio"
    "fmt"
    "os"
    "strings"
    "unicode"
)
```
- `fmt`: Entrada y salida de datos.
- `bufio` y `os`: Lectura de la entrada del usuario.
- `strings`: Manipulación de cadenas.
- `unicode`: Manejo de caracteres Unicode.

### 🔤 Funciones auxiliares
#### isAlphabetic y toLowerCase
```go
func isAlphabetic(r rune) bool {
    return unicode.IsLetter(r)
}

func toLowerCase(r rune) rune {
    return unicode.ToLower(r)
}
```
- `isAlphabetic`: Verifica si un carácter es una letra.
- `toLowerCase`: Convierte un carácter a minúscula.

#### Limpieza de cadena
```go
func cleanString(input string) string {
    var cleaned strings.Builder
    for _, ch := range input {
        if isAlphabetic(ch) || ch == ' ' {
            cleaned.WriteRune(ch)
        }
    }
    return cleaned.String()
}
```
- Filtra solo letras y espacios utilizando `strings.Builder`.

#### Inversión de cadena
```go
func reverseString(s string) string {
    runes := []rune(s)
    for i, j := 0, len(runes)-1; i < j; i, j = i+1, j-1 {
        runes[i], runes[j] = runes[j], runes[i]
    }
    return string(runes)
}
```
- Usa `rune` para manejar caracteres Unicode.
- Invierte la cadena intercambiando caracteres.

#### Reemplazo de espacios
```go
func replaceSpacesWithUnderscores(s string) string {
    return strings.ReplaceAll(s, " ", "_")
}
```
- Sustituye espacios con `_`.

#### Conteo de vocales y consonantes
```go
func countVowelsAndConsonants(s string) (int, int, [5]int) {
    vowels, consonants := 0, 0
    var vowelCount [5]int // a, e, i, o, u
    
    for _, ch := range s {
        ch = toLowerCase(ch)
        switch ch {
        case 'a': vowels++; vowelCount[0]++
        case 'e': vowels++; vowelCount[1]++
        case 'i': vowels++; vowelCount[2]++
        case 'o': vowels++; vowelCount[3]++
        case 'u': vowels++; vowelCount[4]++
        default:
            if isAlphabetic(ch) {
                consonants++
            }
        }
    }
    return vowels, consonants, vowelCount
}
```
- Convierte a minúsculas para un conteo uniforme.
- Usa un arreglo `[5]int` para contar cada vocal.

### 🏁 Función `main()`
```go
func main() {
    reader := bufio.NewReader(os.Stdin)
    fmt.Print("Enter a string (max 100 characters): ")
    input, _ := reader.ReadString('\n')
    input = strings.TrimSpace(input)
```
- Lee la entrada del usuario y elimina espacios innecesarios.

#### 🚨 Validaciones
```go
    if len(input) == 0 {
        fmt.Println("Error: No se aceptan campos vacíos.")
        return
    }

    if len([]rune(input)) > 100 {
        fmt.Println("Error: Se excedió el límite de 100 caracteres.")
        return
    }
```
- Verifica que la entrada no esté vacía ni supere los 100 caracteres.

#### 🔄 Procesamiento
```go
    cleaned := cleanString(input)
    reversed := reverseString(cleaned)
    vowels, consonants, vowelCount := countVowelsAndConsonants(reversed)
    modified := replaceSpacesWithUnderscores(reversed)
```
- Aplica las transformaciones de la cadena.

#### 📢 Resultados
```go
    fmt.Println("\nReversed string:", reversed)
    fmt.Println("Number of vowels:", vowels)
    fmt.Println("Number of 'a':", vowelCount[0])
    fmt.Println("Number of 'e':", vowelCount[1])
    fmt.Println("Number of 'i':", vowelCount[2])
    fmt.Println("Number of 'o':", vowelCount[3])
    fmt.Println("Number of 'u':", vowelCount[4])
    fmt.Println("Number of consonants:", consonants)
    fmt.Println("Modified string:", modified)
}
```
---

## 🏆 Versión en C++

### 🎯 Objetivo del programa (C++)
- Solicita una cadena (máximo 100 caracteres).
- Verifica que no esté vacía ni supere el límite.
- Limpia caracteres no alfabéticos.
- Invierte la cadena.
- Cuenta vocales y consonantes.
- Sustituye espacios por `_`.
- Muestra los resultados.

### 🔍 Funciones principales
- `isAlphabetic(char c)`: Verifica si un carácter es una letra.
- `toLowerCase(char c)`: Convierte a minúscula.
- `stringLength(char* str)`: Calcula la longitud de la cadena.
- `cleanString(char* str)`: Filtra caracteres no alfabéticos.
- `reverseString(char* str)`: Invierte la cadena.
- `countVowelsAndConsonants(...)`: Cuenta vocales y consonantes.
- `replaceSpacesWithUnderscores(char* str)`: Reemplaza espacios con `_`.

### 🚀 `main()`
#### 📥 Entrada
```cpp
char str[101];
cout << "Enter a string (max 100 characters): ";
```
- Usa un array de 101 (`100` caracteres + `\0`).

#### 🚨 Validaciones
```cpp
if (i == 0) {
    cout << "Error: No se aceptan campos vacíos." << endl;
    return 1;
}
```
- Verifica si la entrada está vacía o excede los 100 caracteres.

#### 🔄 Procesamiento
- Limpia la cadena.
- La invierte.
- Cuenta vocales y consonantes.
- Reemplaza espacios con `_`.

#### 📢 Salida
```cpp
cout << "\nReversed string: " << str << endl;
cout << "Number of vowels: " << vowels << endl;
```
- Muestra los resultados finales.

### 📌 Ejemplo de ejecución
```bash
Entrada: Hola mundo
Salida:
Reversed string: odnum_aloH
Number of vowels: 4
Number of consonants: 5
Modified string: odnum_aloH
