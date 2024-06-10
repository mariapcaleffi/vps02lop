#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

typedef struct
{
    int matricula;
    char funcionario[50];
    char data[12];
    char origem[50];
    char destino[50];
    int distancia;
    float preco;
    float total;
} Viagem;

Viagem viagens[50];
int totalViagens = 0, i;

void carregaDados()
{
    FILE *arq;
    char linha[100];
    arq = fopen("viagens.csv", "r");
    if (arq == NULL)
    {
        printf("Erro ao abrir o arquivo\n");
    }
    else
    {
        fgets(linha, 100, arq); 
        while (fgets(linha, 100, arq) != NULL)
        {
            viagens[totalViagens].matricula = atoi(strtok(linha, ";"));
            strcpy(viagens[totalViagens].funcionario, strtok(NULL, ";"));
            strcpy(viagens[totalViagens].data, strtok(NULL, ";"));
            strcpy(viagens[totalViagens].origem, strtok(NULL, ";"));
            strcpy(viagens[totalViagens].destino, strtok(NULL, ";"));
            viagens[totalViagens].distancia = atoi(strtok(NULL, ";"));
            viagens[totalViagens].preco = atof(strtok(NULL, ";"));
            viagens[totalViagens].total = 0; 
            totalViagens++;
        }
    }
    fclose(arq);
}

float calcularReembolso(float preco, int distancia)
{
    return (preco * distancia) / 3.0;
}

void calcularTotais()
{
    float totalGeral = 0;
    float totalPorFuncionario[totalViagens];
    memset(totalPorFuncionario, 0, sizeof(totalPorFuncionario)); 
    
    for(i = 0; i < totalViagens; i++)
    {
        viagens[i].total = calcularReembolso(viagens[i].preco, viagens[i].distancia);
        totalGeral += viagens[i].total;
        totalPorFuncionario[i] += viagens[i].total;
    }
    FILE *relatorio = fopen("RelatorioViagens.md", "w");
    if (relatorio == NULL)
    {
        printf("Erro ao criar o arquivo de relatório\n");
        return;
    }
    fprintf(relatorio, "# Relatório de Viagens\n\n");
    fprintf(relatorio, "## Dados das Viagens\n\n");
    fprintf(relatorio, "| Matrícula | Funcionário | Data | Origem | Destino | Distância | Preço | Total por Funcionário|\n");
    fprintf(relatorio, "|-----------|-------------|------|--------|---------|-----------|-------|----------------------|\n");
    for(i = 0; i < totalViagens; i++)
    {
        fprintf(relatorio, "| %d | %s | %s | %s | %s | %d | %.2f | %.2f |\n", viagens[i].matricula, viagens[i].funcionario, viagens[i].data, viagens[i].origem, viagens[i].destino, viagens[i].distancia, viagens[i].preco, totalPorFuncionario[i]);
    }
    fprintf(relatorio, "\n## Totais\n\n");
    fprintf(relatorio, "### Total Geral: %.2f\n\n", totalGeral);
    
    
    fclose(relatorio);
    printf("Relatório criado com sucesso: RelatorioViagens.md\n");
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    carregaDados();
    calcularTotais(); 
    return 0;
}
