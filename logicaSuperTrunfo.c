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
    char nomeDoPais[20], nomeDoPais2[20];
    unsigned long int populacao, populacao2;
    float area, area2;
    float pib, pib2;
    int numeroDePontosTuristicos, numeroDePontosTuristicos2;
    float densidadePopulacional, densidadePopulacional2;
    float pibperCapita, pibperCapita2;
    float superpoder, superpoder2;
    int escolhaCarta;

    // Solicita para o usuário as informações da carta 1
    printf("Digite os dados da Carta 1: \n");

    printf("Estado: ");
    scanf(" %c", &estado);

    printf("Código: ");
    scanf("%3s", codigoDaCarta);

    getchar(); // consome o \n do buffer

    printf("Nome do País: ");
    fgets(nomeDoPais, sizeof(nomeDoPais2), stdin);
    rstrip(nomeDoPais);

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

    printf("Nome do País: ");
    fgets(nomeDoPais2, sizeof(nomeDoPais2), stdin);
    rstrip(nomeDoPais2);

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

    // Resultado final da informações das cartas
    printf("\n********************************************\n");
    printf("\nResultados: \n");

    printf("Carta 1: \n");
    printf("Estado: %c\n", estado);
    printf("Código: %.3s\n", codigoDaCarta);
    printf("Nome do País: %s\n", nomeDoPais);
    printf("População: %lu\n", populacao);
    printf("Área: %.2f Km²\n", area);
    printf("PIB: %.2f bilhões de reais\n", pib);
    printf("Número de Pontos Turísticos: %d\n", numeroDePontosTuristicos);
    printf("Densidade Populacional: %.3f hab/km²\n", densidadePopulacional);
    printf("PIB per Capita: %.3f reais\n", pibperCapita);

    printf("\n\nCarta 2: \n");
    printf("Estado: %c\n", estado2);
    printf("Código: %.3s\n", codigoDaCarta2);
    printf("Nome do País: %s\n", nomeDoPais2);
    printf("População: %lu\n", populacao2);
    printf("Área: %.2f Km²\n", area2);
    printf("PIB: %.2f bilhões de reais\n", pib2);
    printf("Número de Pontos Turísticos: %d\n", numeroDePontosTuristicos2);
    printf("Densidade Populacional: %.3f hab/Km²\n", densidadePopulacional2);
    printf("PIB per Capita: %.3f reais\n", pibperCapita2);

    printf("\n********************************************\n");
    printf("\n*** Hora de comparar as cartas ***\n");
    printf("Escolha uma opção:\n");
    printf("1. Nome do País\n");
    printf("2. População\n");
    printf("3. Área\n");
    printf("4. PIB\n");
    printf("5. Número de Pontos Turísticos\n");
    printf("6. Densidade demográfica\n");
    printf("Escolha um atributo para comparar as cartas: ");
    scanf("%d", &escolhaCarta);
    
     switch (escolhaCarta)
    {
    case 1:
            printf("\nPaíses: %s e %s", nomeDoPais, nomeDoPais2);
            printf("\nO atributo usado para comparação foi: População\n");
            printf("Os valores dos atributos escolhidos são: %s e %s\n", nomeDoPais, nomeDoPais2);
            if (nomeDoPais > nomeDoPais2)
                printf("Resultado: Carta 1 venceu!\n");
            else if (nomeDoPais < nomeDoPais2)
                printf("Resultado: Carta 2 venceu!\n", nomeDoPais2);
            else
                printf("Resultado: Empate!\n");
            break;

    case 2:
            printf("\nPaíses: %s e %s", nomeDoPais, nomeDoPais2);
            printf("\nO atributo usado para comparação foi: População\n");
            printf("Os valores dos atributos escolhidos são: %lu e %lu \n", populacao, populacao2);
            if (populacao > populacao2)
                printf("Resultado: Carta 1 venceu!\n");
            else if (populacao < populacao2)
                printf("Resultado: Carta 2 venceu!\n");
            else
                printf("Resultado: Empate!\n");
            break;
    
    case 3:
            printf("\nPaíses: %s e %s", nomeDoPais, nomeDoPais2);
            printf("\nO atributo usado para comparação foi: Área\n");
            printf("Os valores dos atributos escolhidos são: %.2fKm² e %.2fKm²\n", area, area2);
            if (area > area2)
                printf("Resultado: Carta 1 venceu!\n");
            else if (area < area2)
                printf("Resultado: Carta 2 venceu!\n");
            else
                printf("Resultado: Empate!\n");
            break;

    case 4:
            printf("\nPaíses: %s e %s", nomeDoPais, nomeDoPais2);
            printf("\nO atributo usado para comparação foi: PIB\n");
            printf("Os valores dos atributos escolhidos são: %.2f e %.2f\n", pib, pib2);
            if (pib > pib2)
                printf("Resultado: Carta 1 venceu!\n");
            else if (pib < pib2)
                printf("Resultado: Carta 2 venceu!\n");
            else
                printf("Resultado: Empate!\n");
            break;

    case 5:
            printf("\nPaíses: %s e %s", nomeDoPais, nomeDoPais2);
            printf("\nO atributo usado para comparação foi: Número de Pontos Turísticos\n");
            printf("Os valores dos atributos escolhidos são: %d e %d\n", numeroDePontosTuristicos, numeroDePontosTuristicos2);
            if (numeroDePontosTuristicos > numeroDePontosTuristicos2)
                printf("Resultado: Carta 1 venceu!\n");
            else if (numeroDePontosTuristicos < numeroDePontosTuristicos2)
                printf("Resultado: Carta 2 venceu!\n");
            else
                printf("Resultado: Empate!\n");
            break;

    case 6:
            printf("\nPaíses: %s e %s", nomeDoPais, nomeDoPais2);
            printf("\nO atributo usado para comparação foi: Densidade Demográfica\n");
            printf("Os valores dos atributos escolhidos são: %.3f hab/km² e %.3f hab/km²\n", densidadePopulacional, densidadePopulacional2);
            if (densidadePopulacional < densidadePopulacional2)
                printf("Resultado: Carta 1 venceu!\n");
            else if (densidadePopulacional > densidadePopulacional2)
                printf("Resultado: Carta 2 venceu!\n");
            else
                printf("Resultado: Empate!\n");
            break;

        default:
            printf("Opção inválida!\n");
    }

    return 0;
}
