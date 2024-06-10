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
        fgets(linha, 100, arq); // Ignorar a primeira linha
        while (fgets(linha, 100, arq) != NULL)
        {
            viagens[totalViagens].matricula = atoi(strtok(linha, ";"));
            strcpy(viagens[totalViagens].funcionario, strtok(NULL, ";"));
            strcpy(viagens[totalViagens].data, strtok(NULL, ";"));
            strcpy(viagens[totalViagens].origem, strtok(NULL, ";"));
            strcpy(viagens[totalViagens].destino, strtok(NULL, ";"));
            viagens[totalViagens].distancia = atoi(strtok(NULL, ";"));
            viagens[totalViagens].preco = atof(strtok(NULL, ";"));
            totalViagens++;
        }
    }
    fclose(arq);
}

void mostrarDados()
{
    int j;
    float totalFuncionario = 0;
    printf("___________________________________| VIAGENS ACME |____________________________________\n");
    printf("|Matr�cula|\t|Funcion�rio|\t|Data|\t|Origem|\t|Destino|\t|Dist�ncia|\t|Pre�o|\t|Total|\n");
    for(i=0; i < totalViagens; i++)
    {
        printf("|%d|\t|%s|\t|%s|\t|%s|\t|%s|\t|%d|\t|%.2f|\t|%.2f|\n", viagens[i].matricula, viagens[i].funcionario, viagens[i].data, viagens[i].origem,  viagens[i].destino, viagens[i].distancia, viagens[i].preco,  viagens[i].total);
        totalFuncionario += viagens[i].total;
        for(j=i+1; j < totalViagens; j++)
        {
            if(strcmp(viagens[i].funcionario, viagens[j].funcionario)!= 0)
            {
                break;
            }
            totalFuncionario += viagens[j].total;
            i++;
        }
        printf("Total do reembolso do funcion�rio %s: R$ %.2f\n", viagens[i].funcionario, totalFuncionario);
        totalFuncionario = 0;
    }
}


float Reembolso(int distancia, float preco) {
    return distancia * preco / 3;
}

void calcularTotal() {
    float totalGeral = 0;
    for(i=0; i < totalViagens; i++) {
        viagens[i].total = Reembolso(viagens[i].distancia, viagens[i].preco);
        totalGeral += viagens[i].total;
    }
    printf("\nValor total que a empresa vai ter que reembolsar: R$ %.2f\n", totalGeral);
}


int main(){
    setlocale(LC_ALL, "");
    carregaDados();
    calcularTotal();
    mostrarDados();
    return 0;
}
