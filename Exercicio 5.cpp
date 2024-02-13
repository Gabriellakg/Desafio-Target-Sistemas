#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "Hello, World!"; // String de exemplo a ser invertida
    int tamanho = strlen(str);
    
    printf("String original: %s\n", str);
    
    // Invertendo os caracteres da string
    for (int i = 0; i < tamanho / 2; i++) {
        char temp = str[i];
        str[i] = str[tamanho - i - 1];
        str[tamanho - i - 1] = temp;
    }
    
    printf("String invertida: %s\n", str);
    
    return 0;
}

