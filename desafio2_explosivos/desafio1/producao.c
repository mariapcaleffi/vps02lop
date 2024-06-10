#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define MAX_LINE_LENGTH 100

int main() {
	setlocale(LC_ALL,"");
    FILE *file;
    int i;
    char line[MAX_LINE_LENGTH];
    int machine_count[5] = {0}; 

    file = fopen("producao.csv", "r");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    fgets(line, MAX_LINE_LENGTH, file);

    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        int machine_number;
        char date[20], time[20];

        sscanf(line, "%[^;];%[^;];%d", date, time, &machine_number);

        if (machine_number >= 1 && machine_number <= 4) {
            machine_count[machine_number]++;
        }
    }
    fclose(file);
    for (i = 1; i <= 4; i++) {
        printf("Máquina %d: %d explosivos produzidos\n", i, machine_count[i]);
    }

    return 0;
}

