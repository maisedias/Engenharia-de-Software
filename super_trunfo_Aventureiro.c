// super_trunfo.c
// Nível aventureiro: cadastro de duas cartas + densidade populacional e PIB per capita.
// Restrições: sem loops e sem condicionais.

#include <stdio.h>

int main(void) {
    // --- Carta 1 ---
    char estado1;
    char codigo1[4];        // "A01" + '\0'
    char cidade1[50];       // até 49 chars + '\0'
    int populacao1;
    float area1;            // km^2
    float pib1_bilhoes;     // bilhões de reais
    int pontos1;

    // --- Carta 2 ---
    char estado2;
    char codigo2[4];
    char cidade2[50];
    int populacao2;
    float area2;
    float pib2_bilhoes;
    int pontos2;

    // Entrada Carta 1
    printf("=== Cadastro da Carta 1 ===\n");
    printf("Estado (A-H): ");
    scanf(" %c", &estado1);

    printf("Codigo da Carta (ex.: A01): ");
    scanf(" %3s", codigo1);

    printf("Nome da Cidade: ");
    scanf(" %49[^\n]", cidade1);

    printf("Populacao: ");
    scanf(" %d", &populacao1);

    printf("Area em km2 (use ponto): ");
    scanf(" %f", &area1);

    printf("PIB em bilhoes de reais (use ponto): ");
    scanf(" %f", &pib1_bilhoes);

    printf("Numero de Pontos Turisticos: ");
    scanf(" %d", &pontos1);

    // Entrada Carta 2
    printf("\n=== Cadastro da Carta 2 ===\n");
    printf("Estado (A-H): ");
    scanf(" %c", &estado2);

    printf("Codigo da Carta (ex.: B03): ");
    scanf(" %3s", codigo2);

    printf("Nome da Cidade: ");
    scanf(" %49[^\n]", cidade2);

    printf("Populacao: ");
    scanf(" %d", &populacao2);

    printf("Area em km2 (use ponto): ");
    scanf(" %f", &area2);

    printf("PIB em bilhoes de reais (use ponto): ");
    scanf(" %f", &pib2_bilhoes);

    printf("Numero de Pontos Turisticos: ");
    scanf(" %d", &pontos2);

    // --- Cálculos ---
    // Densidade = população / área (hab/km^2)
    float dens1 = (float)populacao1 / area1;
    float dens2 = (float)populacao2 / area2;

    // PIB per capita = (PIB em bilhões * 1e9) / população  -> reais por habitante
    float pib_pc1 = (pib1_bilhoes * 1000000000.0f) / (float)populacao1;
    float pib_pc2 = (pib2_bilhoes * 1000000000.0f) / (float)populacao2;

    // --- Saída ---
    printf("\n===========================\n");
    printf("Carta 1:\n");
    printf("Estado: %c\n", estado1);
    printf("Codigo: %s\n", codigo1);
    printf("Nome da Cidade: %s\n", cidade1);
    printf("Populacao: %d\n", populacao1);
    printf("Area: %.2f km^2\n", area1);
    printf("PIB: %.2f bilhoes de reais\n", pib1_bilhoes);
    printf("Numero de Pontos Turisticos: %d\n", pontos1);
    printf("Densidade Populacional: %.2f hab/km^2\n", dens1);
    printf("PIB per Capita: %.2f reais\n", pib_pc1);

    printf("\nCarta 2:\n");
    printf("Estado: %c\n", estado2);
    printf("Codigo: %s\n", codigo2);
    printf("Nome da Cidade: %s\n", cidade2);
    printf("Populacao: %d\n", populacao2);
    printf("Area: %.2f km^2\n", area2);
    printf("PIB: %.2f bilhoes de reais\n", pib2_bilhoes);
    printf("Numero de Pontos Turisticos: %d\n", pontos2);
    printf("Densidade Populacional: %.2f hab/km^2\n", dens2);
    printf("PIB per Capita: %.2f reais\n", pib_pc2);

    return 0;
}