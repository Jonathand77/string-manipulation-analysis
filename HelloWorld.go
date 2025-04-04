package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
	"unicode"
)

// Verifica si un carácter es alfabético
func isAlphabetic(r rune) bool {
	return unicode.IsLetter(r)
}

// Convierte a minúscula
func toLowerCase(r rune) rune {
	return unicode.ToLower(r)
}

// Elimina caracteres no alfabéticos excepto espacios
func cleanString(input string) string {
	var cleaned strings.Builder
	for _, ch := range input {
		if isAlphabetic(ch) || ch == ' ' {
			cleaned.WriteRune(ch)
		}
	}
	return cleaned.String()
}

// Invierte una cadena
func reverseString(s string) string {
	runes := []rune(s)
	for i, j := 0, len(runes)-1; i < j; i, j = i+1, j-1 {
		runes[i], runes[j] = runes[j], runes[i]
	}
	return string(runes)
}

// Reemplaza espacios con guiones bajos
func replaceSpacesWithUnderscores(s string) string {
	return strings.ReplaceAll(s, " ", "_")
}

// Cuenta vocales y consonantes
func countVowelsAndConsonants(s string) (int, int, [5]int) {
	vowels := 0
	consonants := 0
	var vowelCount [5]int // a, e, i, o, u

	for _, ch := range s {
		ch = toLowerCase(ch)
		switch ch {
		case 'a':
			vowels++
			vowelCount[0]++
		case 'e':
			vowels++
			vowelCount[1]++
		case 'i':
			vowels++
			vowelCount[2]++
		case 'o':
			vowels++
			vowelCount[3]++
		case 'u':
			vowels++
			vowelCount[4]++
		default:
			if isAlphabetic(ch) {
				consonants++
			}
		}
	}

	return vowels, consonants, vowelCount
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Enter a string (max 100 characters): ")
	input, _ := reader.ReadString('\n')
	input = strings.TrimSpace(input)

	if len(input) == 0 {
		fmt.Println("Error: No se aceptan campos vacíos.")
		return
	}

	if len([]rune(input)) > 100 {
		fmt.Println("Error: Se excedió el límite de 100 caracteres.")
		return
	}

	// Limpiar la cadena
	cleaned := cleanString(input)

	// Invertir
	reversed := reverseString(cleaned)

	// Contar
	vowels, consonants, vowelCount := countVowelsAndConsonants(reversed)

	// Reemplazar espacios
	modified := replaceSpacesWithUnderscores(reversed)

	// Resultados
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
