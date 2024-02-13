#include <stdio.h>

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int verificarSequenciaFibonacci(int num) {
    int i = 0;
    while (fibonacci(i) <= num) {
        if (fibonacci(i) == num) {
            return 1; // Pertence 
        }
        i++;
    }
    return 0; // Não pertence 
}

int main() {
    int numero;
    
    printf("Informe um numero para verificar se pertence a sequencia de Fibonacci: ");
    scanf("%d", &numero);
    
    if (verificarSequenciaFibonacci(numero)) {
        printf("O numero informado pertence a sequencia de Fibonacci.\n");
    } else {
        printf("O numero informado NAO pertence a sequencia de Fibonacci.\n");
    }
    
    return 0;
}

