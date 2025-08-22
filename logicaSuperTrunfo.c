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
    int escolhaCarta;
    char nomeEscolhaCarta[20];
    char primeiroAtributo, segundoAtributo;
    float valorAtributo, valorAtributo2;
    int resultado, resultado2;
    float somaAtributo, somaAtributo2;

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
    

    // Escolha dos atributos
    printf("\n********************************************\n");
    printf("Escolha o primeiro atributo para comparação:\n");
    printf("1. População\n");
    printf("2. Área\n");
    printf("3. PIB\n");
    printf("4. Número de Pontos Turísticos\n");
    printf("5. Densidade Demográfica\n");

    printf("Faça sua escolha: ");
    scanf(" %c", &primeiroAtributo);

    //Função para o usuario não escolher o mesmo atributo 2x, renos do menu o atributo ja escolhido
    printf("\nEscolha o segundo atributo para comparação:\n");
    if (primeiroAtributo != '1')
        printf("1. População\n");
    if (primeiroAtributo != '2')
        printf("2. Área\n");
    if (primeiroAtributo != '3')
        printf("3. PIB\n");
    if (primeiroAtributo != '4')
        printf("4. Número de Pontos Turísticos\n");
    if (primeiroAtributo != '5')
        printf("5. Densidade Demográfica\n");

    printf("Faça sua escolha: ");
    scanf(" %c", &segundoAtributo);

    switch (primeiroAtributo)
    {
    case '1':
        resultado = populacao == populacao2 ? 2 : populacao > populacao2 ? 1 : 0;
        sprintf(nomeEscolhaCarta, "População");
        valorAtributo = (float)populacao;
        valorAtributo2 = (float)populacao2;
        break;
    case '2':
        resultado = area == area2 ? 2 : area > area2 ? 1 : 0;
        sprintf(nomeEscolhaCarta, "Área");
        valorAtributo = area;
        valorAtributo2 = area2;
        break;
    case '3':
        resultado = pib == pib2 ? 2 : pib > pib2 ? 1 : 0;
        sprintf(nomeEscolhaCarta, "PIB");
        valorAtributo = pib;
        valorAtributo2 = pib2;
        break;
    case '4':
        resultado = numeroDePontosTuristicos == numeroDePontosTuristicos2 ? 2 : numeroDePontosTuristicos > numeroDePontosTuristicos2 ? 1 : 0;
        sprintf(nomeEscolhaCarta, "Número de Pontos Turísticos");
        valorAtributo = (float)numeroDePontosTuristicos;
        valorAtributo2 = (float)numeroDePontosTuristicos2;
        break;
    case '5':
        resultado = densidadePopulacional == densidadePopulacional2 ? 2 : densidadePopulacional < densidadePopulacional2 ? 1 : 0;
        sprintf(nomeEscolhaCarta, "Densidade Demográfica");
        valorAtributo = densidadePopulacional;
        valorAtributo2 = densidadePopulacional2;
        break;
    default:
        printf("Você escolheu uma opção inválida!");
        return 0;
        break;
    }

    if(primeiroAtributo == segundoAtributo)
    {
        printf("Você escoheu o mesmo atributo!");
    } else {
        switch (segundoAtributo)
        {
        case '1':
            // Escolha do segundo atributo
            resultado2 = populacao == populacao2 ? 2 : populacao > populacao2 ? 1 : 0;

            printf("\nPaíses: %s e %s", nomeDoPais, nomeDoPais2);
            printf("\nAtributos escolhidos: %s e População", nomeEscolhaCarta);
            printf("\n%s:", nomeEscolhaCarta);
            printf("\n   %s -> %.2f", nomeDoPais, valorAtributo);
            printf("\n   %s -> %.2f", nomeDoPais2, valorAtributo2);

            if(resultado == 1)
            {
                printf("\nResultado: Carta 1 venceu neste atributo!\n");
            }else if(resultado == 0){
                printf("\nResultado: Carta 2 venceu neste atributo!\n");
            }else {
                printf("\nEmpatou nesse atributo!");
            } 

            printf("\nPopulação:");
            printf("\n   %s -> %lu", nomeDoPais, populacao);
            printf("\n   %s -> %lu", nomeDoPais2, populacao2);

            if(resultado2 == 1)
            {
                printf("\nResultado: Carta 1 venceu neste atributo!\n");
            }else if(resultado2 == 0){
                printf("\nResultado: Carta 2 venceu neste atributo!\n");
            }else {
                printf("\nEmpatou nesse atributo!");
            } 
        
            somaAtributo = valorAtributo + populacao;
            somaAtributo2 = valorAtributo2 + populacao2;

            if (somaAtributo > somaAtributo2)
            {
                printf("\nResultado final: Carta 1 venceu a rodada!\n");
            }
            else if (somaAtributo < somaAtributo2){
                printf("\nResultado final: Carta 2 venceu a rodada!\n");
            }
            else {
                printf("\nResultado final: Empatou a rodada!\n");
            }

            break;
        case '2':
            resultado2 = area == area2 ? 2 : area > area2 ? 1 : 0;

            printf("\nPaíses: %s e %s", nomeDoPais, nomeDoPais2);
            printf("\nAtributos escolhidos: %s e Área", nomeEscolhaCarta);
            printf("\n%s:", nomeEscolhaCarta);
            printf("\n   %s -> %.2f", nomeDoPais, valorAtributo);
            printf("\n   %s -> %.2f", nomeDoPais2, valorAtributo2);

            if(resultado == 1)
            {
                printf("\nResultado: Carta 1 venceu neste atributo!\n");
            }else if(resultado == 0){
                printf("\nResultado: Carta 2 venceu neste atributo!\n");
            }else {
                printf("\nEmpatou nesse atributo!");
            } 

            printf("\nÁrea:");
            printf("\n   %s -> %.2f", nomeDoPais, area);
            printf("\n   %s -> %.2f", nomeDoPais2, area2);

            if(resultado2 == 1)
            {
                printf("\nResultado: Carta 1 venceu neste atributo!\n");
            }else if(resultado2 == 0){
                printf("\nResultado: Carta 2 venceu neste atributo!\n");
            }else {
                printf("\nEmpatou nesse atributo!");
            } 
        
            somaAtributo = valorAtributo + area;
            somaAtributo2 = valorAtributo2 + area2;

            if (somaAtributo > somaAtributo2)
            {
                printf("\nResultado final: Carta 1 venceu a rodada!\n");
            }
            else if (somaAtributo < somaAtributo2){
                printf("\nResultado final: Carta 2 venceu a rodada!\n");
            }
            else {
                printf("\nResultado final: Empatou a rodada!\n");
            }
            break;
        case '3':
            resultado2 = pib == pib2 ? 2 : pib > pib2 ? 1 : 0;

            printf("\nPaíses: %s e %s", nomeDoPais, nomeDoPais2);
            printf("\nAtributos escolhidos: %s e PIB", nomeEscolhaCarta);
            printf("\n%s:", nomeEscolhaCarta);
            printf("\n   %s -> %.2f", nomeDoPais, valorAtributo);
            printf("\n   %s -> %.2f", nomeDoPais2, valorAtributo2);

            if(resultado == 1)
            {
                printf("\nResultado: Carta 1 venceu neste atributo!\n");
            }else if(resultado == 0){
                printf("\nResultado: Carta 2 venceu neste atributo!\n");
            }else {
                printf("\nEmpatou nesse atributo!");
            } 

            printf("\nPIB:");
            printf("\n   %s -> %.2f", nomeDoPais, pib);
            printf("\n   %s -> %.2f", nomeDoPais2, pib2);

            if(resultado2 == 1)
            {
                printf("\nResultado: Carta 1 venceu neste atributo!\n");
            }else if(resultado2 == 0){
                printf("\nResultado: Carta 2 venceu neste atributo!\n");
            }else {
                printf("\nEmpatou nesse atributo!");
            } 
        
            somaAtributo = valorAtributo + pib;
            somaAtributo2 = valorAtributo2 + pib2;

            if (somaAtributo > somaAtributo2)
            {
                printf("\nResultado final: Carta 1 venceu a rodada!\n");
            }
            else if (somaAtributo < somaAtributo2){
                printf("\nResultado final: Carta 2 venceu a rodada!\n");
            }
            else {
                printf("\nResultado final: Empatou a rodada!\n");
            }
            break;
        case '4':
            resultado2 = numeroDePontosTuristicos == numeroDePontosTuristicos2 ? 2 : numeroDePontosTuristicos > numeroDePontosTuristicos2 ? 1 : 0;

            printf("\nPaíses: %s e %s", nomeDoPais, nomeDoPais2);
            printf("\nAtributos escolhidos: %s e Número de Pontos Turísticos", nomeEscolhaCarta);
            printf("\n%s:", nomeEscolhaCarta);
            printf("\n   %s -> %.2f", nomeDoPais, valorAtributo);
            printf("\n   %s -> %.2f", nomeDoPais2, valorAtributo2);

            if(resultado == 1)
            {
                printf("\nResultado: Carta 1 venceu neste atributo!\n");
            }else if(resultado == 0){
                printf("\nResultado: Carta 2 venceu neste atributo!\n");
            }else {
                printf("\nEmpatou nesse atributo!");
            } 

            printf("\nPIB:");
            printf("\n   %s -> %d", nomeDoPais, numeroDePontosTuristicos);
            printf("\n   %s -> %d", nomeDoPais2, numeroDePontosTuristicos2);

            if(resultado2 == 1)
            {
                printf("\nResultado: Carta 1 venceu neste atributo!\n");
            }else if(resultado2 == 0){
                printf("\nResultado: Carta 2 venceu neste atributo!\n");
            }else {
                printf("\nEmpatou nesse atributo!");
            } 
        
            somaAtributo = valorAtributo + numeroDePontosTuristicos;
            somaAtributo2 = valorAtributo2 + numeroDePontosTuristicos2;

            if (somaAtributo > somaAtributo2)
            {
                printf("\nResultado final: Carta 1 venceu a rodada!\n");
            }
            else if (somaAtributo < somaAtributo2){
                printf("\nResultado final: Carta 2 venceu a rodada!\n");
            }
            else {
                printf("\nResultado final: Empatou a rodada!\n");
            }
            break;
        case '5':
            resultado2 = densidadePopulacional == densidadePopulacional2 ? 2 : densidadePopulacional < densidadePopulacional2 ? 1 : 0;

            printf("\nPaíses: %s e %s", nomeDoPais, nomeDoPais2);
            printf("\nAtributos escolhidos: %s e Densidade Demográfica", nomeEscolhaCarta);
            printf("\n%s:", nomeEscolhaCarta);
            printf("\n   %s -> %.2f", nomeDoPais, valorAtributo);
            printf("\n   %s -> %.2f", nomeDoPais2, valorAtributo2);

            if(resultado == 1)
            {
                printf("\nResultado: Carta 1 venceu neste atributo!\n");
            }else if(resultado == 0){
                printf("\nResultado: Carta 2 venceu neste atributo!\n");
            }else {
                printf("\nEmpatou nesse atributo!");
            } 

            printf("\nDensidade Demográfica:");
            printf("\n   %s -> %.2f", nomeDoPais, densidadePopulacional);
            printf("\n   %s -> %.2f", nomeDoPais2, densidadePopulacional2);

            if(resultado2 == 1)
            {
                printf("\nResultado: Carta 1 venceu neste atributo!\n");
            }else if(resultado2 == 0){
                printf("\nResultado: Carta 2 venceu neste atributo!\n");
            }else {
                printf("\nEmpatou nesse atributo!");
            } 
        
            somaAtributo = valorAtributo + densidadePopulacional;
            somaAtributo2 = valorAtributo2 + densidadePopulacional2;

            if (somaAtributo > somaAtributo2)
            {
                printf("\nResultado final: Carta 1 venceu a rodada!\n");
            }
            else if (somaAtributo < somaAtributo2){
                printf("\nResultado final: Carta 2 venceu a rodada!\n");
            }
            else {
                printf("\nResultado final: Empatou a rodada!\n");
            }
            break;
        default:
            printf("Você escolheu uma opção inválida!");
            break;
        }
    }

    return 0;
}