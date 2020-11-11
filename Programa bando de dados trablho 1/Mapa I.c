#include <stdio.h>
#include <string.h>

void process_field(int field_count, char *value) {
    if (field_count == 0) {
        printf("Codigo:\t");
    }
    if (field_count == 1) {
        printf("Titulo no Brasil:\t");
    }
    if (field_count == 2) {
            printf("Produtor :\t");
    }
    if (field_count == 3) {
        printf("Pais de origem:\t");
    }
    if (field_count == 4) {
        printf("Ano de producao:\t");
    }
    if (field_count == 5) {
        printf("Distribuidor do Jogo no Brasil :\t");
    }
    if (field_count == 6) {
        printf("Plataforma:\t");
    }
    if (field_count == 7) {
        printf("Genero:\t");
    }
    if (field_count == 8) {
        printf("Classificacao pretendida:\t");
    }
    if (field_count == 9) {
        printf("Classificacao Atríbuida :\t");
    }
    if (field_count == 10) {
        printf("Contem :\t");
    }
    if (field_count == 11) {
        printf("Tipo de Analise:\t");
    }
    if (field_count == 12) {
        printf("Tipo do Material :\t");
    }
    if (field_count == 13) {
        printf("Requerente:\t");
    }
    if (field_count == 14) {
        printf("Data Portaria:\t");
    }
    if (field_count == 15) {
        printf("Numero Portaria :\t");
    }
    if (field_count == 16) {
        printf("Data DOU :\t");
    }
    if (field_count == 17) {
        printf("Secao 1/ Pagina :\t");
    }
    printf("%s\n", value);
}

int main(void) {
    char buf[1024];
    char token[1024];

    int row_count = 0;
    int field_count = 0;
    int in_double_quotes = 0;
    int token_pos = 0;
    int i = 0;

    FILE *fp = fopen("sample2.csv", "r");

    if (!fp) {
        printf("Can't open file\n");
        return 0;
    }


    while (fgets(buf, 1024, fp)) {
        row_count++;

        if (row_count == 1) {
            continue;
        }

        field_count = 0;
        i = 0;
        do {
            token[token_pos++] = buf[i];

            if (!in_double_quotes && (buf[i] == ',' || buf[i] == '\n')) {
                token[token_pos - 1] = 0;
                token_pos = 0;
                process_field(field_count++, token);
            }

            if (buf[i] == '"' && buf[i + 1] != '"') {
                token_pos--;
                in_double_quotes = !in_double_quotes;
            }

            if (buf[i] == '"' && buf[i + 1] == '"')
                i++;

        } while (buf[++i]);

        printf("\n");
    }

    fclose(fp);

    return 0;
}
