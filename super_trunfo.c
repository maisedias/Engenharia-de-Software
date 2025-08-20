// super_trunfo.c
// Nível mestre: duas cartas + cálculos + comparações + "Super Poder".
// Compilar:  gcc -std=c99 -Wall -Wextra -O2 super_trunfo.c -o super_trunfo

#include <stdio.h>

int main(void) {
    // -------- Carta 1 --------
    char estado1;
    char codigo1[4];           // "A01" + '\0'
    char cidade1[50];          // até 49 chars + '\0'
    unsigned long int pop1;    // agora cabe cidade gigante
    float area1;               // km^2
    float pib1_bilhoes;        // bilhões de reais (entrada do usuário)
    int pontos1;

    // -------- Carta 2 --------
    char estado2;
    char codigo2[4];
    char cidade2[50];
    unsigned long int pop2;
    float area2;
    float pib2_bilhoes;
    int pontos2;

    // ===== Entrada: Carta 1 =====
    printf("=== Cadastro da Carta 1 ===\n");
    printf("Estado (A-H): ");
    scanf(" %c", &estado1);

    printf("Codigo da Carta (ex.: A01): ");
    scanf(" %3s", codigo1);

    printf("Nome da Cidade: ");
    scanf(" %49[^\n]", cidade1);

    printf("Populacao (habitantes): ");
    scanf(" %lu", &pop1);

    printf("Area em km2 (use ponto): ");
    scanf(" %f", &area1);

    printf("PIB em bilhoes de reais (use ponto): ");
    scanf(" %f", &pib1_bilhoes);

    printf("Numero de Pontos Turisticos: ");
    scanf(" %d", &pontos1);

    // ===== Entrada: Carta 2 =====
    printf("\n=== Cadastro da Carta 2 ===\n");
    printf("Estado (A-H): ");
    scanf(" %c", &estado2);

    printf("Codigo da Carta (ex.: B03): ");
    scanf(" %3s", codigo2);

    printf("Nome da Cidade: ");
    scanf(" %49[^\n]", cidade2);

    printf("Populacao (habitantes): ");
    scanf(" %lu", &pop2);

    printf("Area em km2 (use ponto): ");
    scanf(" %f", &area2);

    printf("PIB em bilhoes de reais (use ponto): ");
    scanf(" %f", &pib2_bilhoes);

    printf("Numero de Pontos Turisticos: ");
    scanf(" %d", &pontos2);

    // ===== Conversões auxiliares =====
    // PIB em reais para cálculos que exigem moeda absoluta
    float pib1_reais = pib1_bilhoes * 1000000000.0f;
    float pib2_reais = pib2_bilhoes * 1000000000.0f;

    // ===== Cálculos: densidade e PIB per capita =====
    float dens1 = (area1 > 0.0f) ? ( (float)pop1 / area1 ) : 0.0f;             // hab/km^2
    float dens2 = (area2 > 0.0f) ? ( (float)pop2 / area2 ) : 0.0f;

    float pib_pc1 = (pop1 > 0UL) ? ( pib1_reais / (float)pop1 ) : 0.0f;        // R$ por hab
    float pib_pc2 = (pop2 > 0UL) ? ( pib2_reais / (float)pop2 ) : 0.0f;

    // Inverso da densidade (quanto menor a densidade, maior esse termo)
    // 1/densidade = area/pop. Usamos essa forma para evitar dividir por 0 caso densidade 0.
    float inv_dens1 = (pop1 > 0UL) ? ( area1 / (float)pop1 ) : 0.0f;
    float inv_dens2 = (pop2 > 0UL) ? ( area2 / (float)pop2 ) : 0.0f;

    // ===== Super Poder =====
    // Soma de: população + área + PIB (em reais) + pontos + PIB per capita + inverso da densidade.
    // Observação: unidades diferentes somadas de propósito (regra do jogo).
    float super1 = (float)pop1 + area1 + pib1_reais + (float)pontos1 + pib_pc1 + inv_dens1;
    float super2 = (float)pop2 + area2 + pib2_reais + (float)pontos2 + pib_pc2 + inv_dens2;

    // ===== Saída: dados completos =====
    printf("\n===========================\n");
    printf("Carta 1:\n");
    printf("Estado: %c\n", estado1);
    printf("Codigo: %s\n", codigo1);
    printf("Nome da Cidade: %s\n", cidade1);
    printf("Populacao: %lu\n", pop1);
    printf("Area: %.2f km^2\n", area1);
    printf("PIB: %.2f bilhoes de reais\n", pib1_bilhoes);
    printf("Numero de Pontos Turisticos: %d\n", pontos1);
    printf("Densidade Populacional: %.2f hab/km^2\n", dens1);
    printf("PIB per Capita: %.2f reais\n", pib_pc1);
    printf("Super Poder: %.2f\n", super1);

    printf("\nCarta 2:\n");
    printf("Estado: %c\n", estado2);
    printf("Codigo: %s\n", codigo2);
    printf("Nome da Cidade: %s\n", cidade2);
    printf("Populacao: %lu\n", pop2);
    printf("Area: %.2f km^2\n", area2);
    printf("PIB: %.2f bilhoes de reais\n", pib2_bilhoes);
    printf("Numero de Pontos Turisticos: %d\n", pontos2);
    printf("Densidade Populacional: %.2f hab/km^2\n", dens2);
    printf("PIB per Capita: %.2f reais\n", pib_pc2);
    printf("Super Poder: %.2f\n", super2);

    // ===== Comparações =====
    // Resultado booleano: 1 se Carta 1 venceu; 0 se Carta 2 venceu.
    int r_pop   = (pop1   > pop2);
    int r_area  = (area1  > area2);
    int r_pib   = (pib1_bilhoes > pib2_bilhoes);   // comparação na unidade digitada (bilhões)
    int r_pts   = (pontos1 > pontos2);
    int r_dens  = (dens1  < dens2);                // menor densidade vence
    int r_pcap  = (pib_pc1 > pib_pc2);
    int r_super = (super1 > super2);

    printf("\n=== Comparacao de Cartas ===\n");
    printf("Populacao: %s (%d)\n",  r_pop   ? "Carta 1 venceu" : "Carta 2 venceu", r_pop);
    printf("Area: %s (%d)\n",        r_area  ? "Carta 1 venceu" : "Carta 2 venceu", r_area);
    printf("PIB: %s (%d)\n",         r_pib   ? "Carta 1 venceu" : "Carta 2 venceu", r_pib);
    printf("Pontos Turisticos: %s (%d)\n", r_pts ? "Carta 1 venceu" : "Carta 2 venceu", r_pts);
    printf("Densidade Populacional: %s (%d)\n", r_dens ? "Carta 1 venceu" : "Carta 2 venceu", r_dens);
    printf("PIB per Capita: %s (%d)\n", r_pcap ? "Carta 1 venceu" : "Carta 2 venceu", r_pcap);
    printf("Super Poder: %s (%d)\n", r_super ? "Carta 1 venceu" : "Carta 2 venceu", r_super);

    return 0;
}