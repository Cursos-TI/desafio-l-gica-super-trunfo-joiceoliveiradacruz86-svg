#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Função para remover \n, espaços e tabs do final da string
void rstrip(char *s) {
    size_t len = strlen(s);
    while (len > 0 && isspace((unsigned char)s[len - 1])) {
        s[--len] = '\0';
    }
}

int main() {
    // Variáveis da carta 1 e carta 2
    char estado, estado2;
    char codigoDaCarta[4], codigoDaCarta2[4];
    char nomeDaCidade[20], nomeDaCidade2[20];
    unsigned long int populacao, populacao2;
    float area, area2;
    float pib, pib2;
    int numeroDePontosTuristicos, numeroDePontosTuristicos2;
    float densidadePopulacional, densidadePopulacional2;
    float pibperCapita, pibperCapita2;
    float superpoder, superpoder2;

    // Solicita para o usuário as informações da carta 1
    printf("Digite os dados da Carta 1: \n");

    printf("Estado: ");
    scanf(" %c", &estado);

    printf("Código: ");
    scanf("%3s", codigoDaCarta);

    getchar(); // consome o \n do buffer

    printf("Nome da Cidade: ");
    fgets(nomeDaCidade, sizeof(nomeDaCidade), stdin);
    rstrip(nomeDaCidade);

    printf("População: ");
    scanf("%lu", &populacao);

    printf("Área: ");
    scanf("%f", &area);

    printf("PIB: ");
    scanf("%f", &pib);

    printf("Número de pontos turísticos: ");
    scanf("%d", &numeroDePontosTuristicos);

    densidadePopulacional = populacao / area;
    pibperCapita = pib / populacao;
    superpoder = (float)populacao + area + pib + (float)numeroDePontosTuristicos + pibperCapita + (1.0f / densidadePopulacional);

    // Solicita para o usuário as informações da carta 2
    printf("\n********************************************\n");
    printf("Digite os dados da Carta 2: \n");

    printf("Estado: ");
    scanf(" %c", &estado2);

    printf("Código: ");
    scanf("%3s", codigoDaCarta2);

    getchar(); // consome o \n do buffer

    printf("Nome da Cidade: ");
    fgets(nomeDaCidade2, sizeof(nomeDaCidade2), stdin);
    rstrip(nomeDaCidade2);

    printf("População: ");
    scanf("%lu", &populacao2);

    printf("Área: ");
    scanf("%f", &area2);

    printf("PIB: ");
    scanf("%f", &pib2);

    printf("Número de pontos turísticos: ");
    scanf("%d", &numeroDePontosTuristicos2);

    densidadePopulacional2 = populacao2 / area2;
    pibperCapita2 = pib2 / populacao2;
    superpoder2 = (float)populacao2 + area2 + pib2 + (float)numeroDePontosTuristicos2 + pibperCapita2 + (1.0f / densidadePopulacional2);

    // Imprime as informações das cartas
    printf("\n********************************************\n");
    printf("\nResultados: \n");

    printf("Carta 1: \n");
    printf("Estado: %c\n", estado);
    printf("Código: %.3s\n", codigoDaCarta);
    printf("Nome da Cidade: %s\n", nomeDaCidade);
    printf("População: %lu\n", populacao);
    printf("Área: %.2f Km²\n", area);
    printf("PIB: %.2f bilhões de reais\n", pib);
    printf("Número de Pontos Turísticos: %d\n", numeroDePontosTuristicos);
    printf("Densidade Populacional: %.3f hab/km²\n", densidadePopulacional);
    printf("PIB per Capita: %.3f reais\n", pibperCapita);

    printf("\n\nCarta 2: \n");
    printf("Estado: %c\n", estado2);
    printf("Código: %.3s\n", codigoDaCarta2);
    printf("Nome da Cidade: %s\n", nomeDaCidade2);
    printf("População: %lu\n", populacao2);
    printf("Área: %.2f Km²\n", area2);
    printf("PIB: %.2f bilhões de reais\n", pib2);
    printf("Número de Pontos Turísticos: %d\n", numeroDePontosTuristicos2);
    printf("Densidade Populacional: %.3f hab/Km²\n", densidadePopulacional2);
    printf("PIB per Capita: %.3f reais\n", pibperCapita2);

    // Comparação de Número de Pontos Turísticos
    printf("\n********************************************\n");
    printf("\nComparação das cartas (Atributo: Número de Pontos Turísticos):\n");
    printf("Carta 1- %s: %d\n", nomeDaCidade, numeroDePontosTuristicos);
    printf("Carta 2- %s: %d\n", nomeDaCidade2, numeroDePontosTuristicos2);

    if(numeroDePontosTuristicos > numeroDePontosTuristicos2) { 
        printf("Resultado: Carta 1 venceu!\n\n"); 
    } else { 
        printf("Resultado: Carta 2 venceu!\n\n"); 
    }

    return 0;
}
