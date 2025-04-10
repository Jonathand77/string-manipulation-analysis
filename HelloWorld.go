package main

import (
	"fmt"
	"os"
	"strings"
	"unicode"
)

// Verifica si un carácter es alfabético
func isAlphabetic(r rune) bool {
	return unicode.IsLetter(r)
}

// Convierte un carácter a minúscula
func toLowerCase(r rune) rune {
	return unicode.ToLower(r)
}

// Limpia la cadena eliminando todo lo que no sea letra o espacio
func cleanString(input string) string {
	var cleaned strings.Builder
	for _, ch := range input {
		if isAlphabetic(ch) || ch == ' ' {
			cleaned.WriteRune(ch) // Agrega el carácter si es válido
		}
	}
	return cleaned.String() // Retorna la cadena limpia
}

// Invierte una cadena
func reverseString(s string) string {
	runes := []rune(s) // Convierte la cadena en un slice de runas para soportar caracteres Unicode
	for i, j := 0, len(runes)-1; i < j; i, j = i+1, j-1 {
		runes[i], runes[j] = runes[j], runes[i] // Intercambia los caracteres
	}
	return string(runes) // Retorna la cadena invertida
}

// Reemplaza espacios por guiones bajos
func replaceSpacesWithUnderscores(s string) string {
	return strings.ReplaceAll(s, " ", "_")
}

// Cuenta las vocales (a, e, i, o, u) y consonantes en una cadena
func countVowelsAndConsonants(s string) (int, [5]int) {
	consonants := 0
	var vowelCount [5]int // Índices: 0=a, 1=e, 2=i, 3=o, 4=u

	for _, ch := range s {
		ch = toLowerCase(ch)
		switch ch {
		case 'a':
			vowelCount[0]++
		case 'e':
			vowelCount[1]++
		case 'i':
			vowelCount[2]++
		case 'o':
			vowelCount[3]++
		case 'u':
			vowelCount[4]++
		default:
			if isAlphabetic(ch) {
				consonants++ // Cuenta consonantes si es letra y no es vocal
			}
		}
	}

	return consonants, vowelCount
}

func main() {
	// Verifica si se pasó al menos un argumento
	if len(os.Args) < 2 {
		fmt.Println("Error: Debes proporcionar una cadena como argumento.")
		return
	}

	// Une todos los argumentos en una sola cadena (para frases con espacios)
	input := strings.Join(os.Args[1:], " ")
	input = strings.TrimSpace(input) // Elimina espacios al inicio y final

	// Verifica si la cadena está vacía
	if len(input) == 0 {
		fmt.Println("Error: No se aceptan campos vacíos.")
		return
	}

	// Verifica si la cadena tiene más de 100 caracteres
	if len([]rune(input)) > 100 {
		fmt.Println("Error: Se excedió el límite de 100 caracteres.")
		return
	}

	// Aplica las transformaciones
	cleaned := cleanString(input)                         // Limpia la cadena
	reversed := reverseString(cleaned)                    // Invierte la cadena limpia
	modified := replaceSpacesWithUnderscores(reversed)    // Reemplaza espacios por _
	consonants, vowelCount := countVowelsAndConsonants(reversed) // Cuenta vocales y consonantes

	var result []string

	// Agrega la cadena invertida al resultado
	result = append(result, reversed)

	// Agrega los conteos de vocales, solo si son mayores que cero
	for _, v := range vowelCount {
		if v > 0 {
			result = append(result, fmt.Sprintf("%d", v))
		}
	}

	// Agrega el total de consonantes
	result = append(result, fmt.Sprintf("%d", consonants))

	// Agrega la cadena modificada con guiones bajos
	result = append(result, modified)

	// Imprime todo el resultado final separado por espacios
	fmt.Println(strings.Join(result, " "))
}
