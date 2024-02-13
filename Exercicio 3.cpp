#include <stdio.h>
#include <stdlib.h>
#include <jansson.h>

int main() {
    FILE *file;
    file = fopen("dados.json", "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *json_data = (char*)malloc(file_size + 1);
    fread(json_data, 1, file_size, file);
    json_data[file_size] = '\0';

    fclose(file);

    json_error_t error;
    json_t *root = json_loads(json_data, 0, &error);
    free(json_data);

    if (!root) {
        printf("Erro ao carregar o JSON: %s\n", error.text);
        return 1;
    }

    // Acessando o array 
    json_t *faturamento_diario = json_object_get(root, "faturamento_diario");
    int tamanho = json_array_size(faturamento_diario);

    int menor = INT_MAX;
    int maior = INT_MIN;
    int total = 0;
    int dias_com_faturamento = 0;

    // Calculando o menor, o maior, media mensal e dias com faturamento acima da media 
    for (int i = 0; i < tamanho; i++) {
        int valor = (int)json_integer_value(json_array_get(faturamento_diario, i));

        if (valor > 0) {
            total += valor;
            dias_com_faturamento++;

            if (valor < menor) menor = valor;
            if (valor > maior) maior = valor;
        }
    }

    int media_mensal = total / dias_com_faturamento;

    int dias_acima_media = 0;
    for (int i = 0; i < tamanho; i++) {
        int valor = (int)json_integer_value(json_array_get(faturamento_diario, i));
        if (valor > media_mensal) {
            dias_acima_media++;
        }
    }

    printf("Menor valor de faturamento diario: %d\n", menor);
    printf("Maior valor de faturamento diario: %d\n", maior);
    printf("Numero de dias com faturamento superior a media mensal: %d\n", dias_acima_media);

    json_decref(root);

    return 0;
}

