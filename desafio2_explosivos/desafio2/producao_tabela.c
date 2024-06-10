#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define MAX_LINE_LENGTH 100
#define MAX_DATE_LENGTH 11
#define MAX_DAYS 31
#define MAX_MACHINES 5

typedef struct {
    char date[MAX_DATE_LENGTH];
    int machine_count[MAX_MACHINES];
} DailyProduction;

int find_or_add_date(DailyProduction productions[], int *num_days, const char *date) {
	int i;
    for (i = 0; i < *num_days; i++) {
        if (strcmp(productions[i].date, date) == 0) {
            return i;
        }
    }
    strcpy(productions[*num_days].date, date);
    memset(productions[*num_days].machine_count, 0, sizeof(int) * MAX_MACHINES);
    return (*num_days)++;
}

int main() {
	int i, j;
	setlocale(LC_ALL,"");
    FILE *file;
    char line[MAX_LINE_LENGTH];
    DailyProduction productions[MAX_DAYS];
    int num_days = 0;

    file = fopen("producao.csv", "r");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    fgets(line, MAX_LINE_LENGTH, file);

    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        int machine_number;
        char date[MAX_DATE_LENGTH], time[20];

        sscanf(line, "%[^;];%[^;];%d", date, time, &machine_number);

        int day_index = find_or_add_date(productions, &num_days, date);

        if (machine_number >= 1 && machine_number < MAX_MACHINES) {
            productions[day_index].machine_count[machine_number]++;
        }
    }

    fclose(file);

    file = fopen("explosivos.md", "w");
    if (file == NULL) {
        perror("Erro ao criar o arquivo de relat�rio");
        return 1;
    }

    fprintf(file, "| Data       | M�quina 1 | M�quina 2 | M�quina 3 | M�quina 4 |\n");
    fprintf(file, "|------------|-----------|-----------|-----------|-----------|\n");

    for (i = 0; i < num_days; i++) {
        fprintf(file, "| %s |", productions[i].date);
        for (j = 1; j < MAX_MACHINES; j++) {
            fprintf(file, "     %d    |", productions[i].machine_count[j]);
        }
        fprintf(file, "\n");
    }

    fclose(file);

    for (i = 1; i < MAX_MACHINES; i++) {
        int total = 0;
        for (j = 0; j < num_days; j++) {
            total += productions[j].machine_count[i];
        }
        printf("M�quina %d: %d explosivos produzidos\n", i, total);
    }

    return 0;
}
