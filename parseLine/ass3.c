#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Could not open file");
        return 1;
    }

    char line[256];
    int is_first_line = 1;

    while (fgets(line, sizeof(line), file)) {
        if (is_first_line) {
            is_first_line = 0; // Skip the first line
            continue;
        }

        char rollno[256];
        char name[256];
        char gender[256];
        char year[256];
        char degree[256];

        sscanf(line, " %[^,], %[^,], %[^,], %[^,], %[^,\n]", rollno, name, gender, year, degree);

        if (strcmp(degree, "MSc") == 0 && strcmp(gender, "F") == 0 && strcmp(year, "2024") == 0) {
            char first_name[256];
            sscanf(name, "%s", first_name);
            printf("%s\n", first_name);
        }
    }

    fclose(file);
    return 0;
}

