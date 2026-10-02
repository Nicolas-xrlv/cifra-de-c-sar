#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX_PALAVRA 16

/*
    Projeto: Criptografia em Duas Camadas
    Camada 1: Cifra de Cesar com SHIFT fixo
    Camada 2: deslocamento dinamico usando Fibonacci

    Observacao:
    A palavra deve conter somente letras minusculas, sem acentos,
    espacos ou caracteres especiais, com no maximo 15 letras.
*/

void gerarFibonacci(int sequencia[], int tamanho) {
    if (tamanho <= 0) {
        return;
    }

    sequencia[0] = 1;

    if (tamanho == 1) {
        return;
    }

    sequencia[1] = 1;

    for (int i = 2; i < tamanho; i++) {
        sequencia[i] = sequencia[i - 1] + sequencia[i - 2];
    }
}

int palavraValida(const char palavra[]) {
    int tamanho = strlen(palavra);

    if (tamanho < 1 || tamanho > 15) {
        return 0;
    }

    for (int i = 0; i < tamanho; i++) {
        if (palavra[i] < 'a' || palavra[i] > 'z') {
            return 0;
        }
    }

    return 1;
}

void criptografar(const char palavra[], char resultado[], int shift,
                  const int fibonacci[]) {
    int tamanho = strlen(palavra);

    for (int i = 0; i < tamanho; i++) {
        int valor = palavra[i] - 'a';

        valor = (valor + shift) % 26;

        valor = (valor + fibonacci[i]) % 26;

        resultado[i] = (char)('a' + valor);
    }

    resultado[tamanho] = '\0';
}

int salvarResultado(const char palavra[], const char resultado[],
                   int shift, int quantidadeLetras) {
    FILE *arquivo = fopen("resultado/resultado_criptografia.txt", "w");

    if (arquivo == NULL) {
        return 0;
    }

    fprintf(arquivo,
            "Palavra original: %s\n"
            "Palavra codificada: %s\n"
            "SHIFT: %d\n"
            "Tipo: Fibonacci\n"
            "Letras: %d\n",
            palavra, resultado, shift, quantidadeLetras);

    fclose(arquivo);
    return 1;
}

int salvarLog(const char palavra[], const char resultado[],
              int shift, const int fibonacci[]) {
    FILE *log = fopen("logs/execucao.log", "a");

    if (log == NULL) {
        return 0;
    }

    time_t agora = time(NULL);
    struct tm *data = localtime(&agora);

    fprintf(log, "========================================\n");
    fprintf(log, "Data/Hora: %02d/%02d/%04d %02d:%02d:%02d\n",
            data->tm_mday,
            data->tm_mon + 1,
            data->tm_year + 1900,
            data->tm_hour,
            data->tm_min,
            data->tm_sec);
    fprintf(log, "Palavra original: %s\n", palavra);
    fprintf(log, "SHIFT: %d\n", shift);
    fprintf(log, "Sequencia: Fibonacci\n");
    fprintf(log, "Valores utilizados: ");

    int tamanho = strlen(palavra);

    for (int i = 0; i < tamanho; i++) {
        fprintf(log, "%d", fibonacci[i]);

        if (i < tamanho - 1) {
            fprintf(log, ", ");
        }
    }

    fprintf(log, "\n");
    fprintf(log, "Palavra codificada: %s\n", resultado);
    fprintf(log, "========================================\n\n");

    fclose(log);
    return 1;
}

int main(void) {
    char palavra[MAX_PALAVRA];
    char resultado[MAX_PALAVRA];
    int fibonacci[MAX_PALAVRA];
    int shift;

    printf("========================================\n");
    printf("   CRIPTOGRAFIA EM DUAS CAMADAS\n");
    printf("========================================\n\n");

    printf("Digite a palavra (ate 15 letras, sem acentos): ");
    scanf("%15s", palavra);

    if (!palavraValida(palavra)) {
        printf("\nErro: a palavra deve conter de 1 a 15 letras minusculas,\n");
        printf("sem acentos, espacos ou caracteres especiais.\n");
        return 1;
    }

    printf("Digite o SHIFT: ");
    scanf("%d", &shift);

    shift = ((shift % 26) + 26) % 26;

    gerarFibonacci(fibonacci, strlen(palavra));

    criptografar(palavra, resultado, shift, fibonacci);

    printf("\n----------------------------------------\n");
    printf("Palavra original: %s\n", palavra);
    printf("SHIFT: %d\n", shift);
    printf("Sequencia: Fibonacci\n");
    printf("Palavra criptografada: %s\n", resultado);
    printf("----------------------------------------\n");

    if (salvarResultado(palavra, resultado, shift, strlen(palavra))) {
        printf("Arquivo resultado_criptografia.txt: OK\n");
    } else {
        printf("Erro ao criar o arquivo de resultado.\n");
    }

    if (salvarLog(palavra, resultado, shift, fibonacci)) {
        printf("Arquivo execucao.log: OK\n");
    } else {
        printf("Erro ao criar o arquivo de log.\n");
    }

    printf("\nExecucao finalizada.\n");

    return 0;
}
