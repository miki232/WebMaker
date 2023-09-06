#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct HTMLElement {
    char tag[50];
    int x;
    int y;
    char id[50];
    char class[50];
    struct HTMLElement* next;
};

void generateHTML(struct HTMLElement* head) {
    FILE* file = fopen("pagina.html", "w");
    if (file == NULL) {
        printf("Impossibile aprire il file per la scrittura.");
        return;
    }

    fprintf(file, "<!DOCTYPE html>\n<html>\n<head>\n<title>La mia Pagina</title>\n");
    fprintf(file, "<style>\n");
    fprintf(file, ".grid-container { display: grid; grid-template-columns: repeat(24, 1fr); grid-template-rows: repeat(19, 1fr); grid-gap: 10px; position: relative; }\n");
    fprintf(file, ".grid-item { border: 1px solid #000; padding: 10px; position: absolute; }\n");

    struct HTMLElement* current = head;
    while (current != NULL) {
        fprintf(file, ".%s {", current->class); // Usiamo ".class" come selettore CSS
        int startCol = current->x; 
        int endCol = current->x + 4; // Ad esempio, considerando 4 colonne
        int startRow = current->y;
        int endRow = current->y + 3; // Ad esempio, considerando 3 righe
        fprintf(file, "grid-column: %d / %d;", startCol, endCol);
        fprintf(file, "grid-row: %d / %d;", startRow, endRow);
        // Altre proprietà CSS personalizzate per l'elemento, ad esempio background-color, font-size, ecc.
        fprintf(file, "}\n");
        current = current->next;
    }

    fprintf(file, "</style>\n");
    fprintf(file, "</head>\n<body>\n");

    fprintf(file, "<div class=\"grid-container\">\n");

    current = head;
    while (current != NULL) {
        fprintf(file, "<div class=\"%s grid-item\">\n", current->class); // Usiamo ".class" come classe CSS
        fprintf(file, "<%s>%s</%s>\n", current->tag, "Testo dell'elemento", current->tag);
        fprintf(file, "</div>\n");
        current = current->next;
    }

    fprintf(file, "</div>\n</body>\n</html>\n");
    fclose(file);
}


int main() {
    struct HTMLElement* head = NULL;
    struct HTMLElement* tail = NULL;
     struct HTMLElement* current = NULL;

    // Aggiungi elementi alla lista collegata
    struct HTMLElement* elemento1 = malloc(sizeof(struct HTMLElement));
    strcpy(elemento1->tag, "button");
    elemento1->x = 1;
    elemento1->y = 1;
    strcpy(elemento1->id, "btn1");
    strcpy(elemento1->class, "my-button");
    elemento1->next = NULL;

    struct HTMLElement* elemento2 = malloc(sizeof(struct HTMLElement));
    strcpy(elemento2->tag, "div");
    elemento2->x = 6;
    elemento2->y = 19;
    strcpy(elemento2->id, "div1");
    strcpy(elemento2->class, "my-div");
    elemento2->next = NULL;

    // Collega gli elementi nella lista
    if (head == NULL) {
        head = elemento1;
        tail = elemento1;
    } else {
        tail->next = elemento1;
        tail = elemento1;
    }

    if (tail != NULL) {
        tail->next = elemento2;
        tail = elemento2;
    }

    // Genera il codice HTML
    generateHTML(head);

    // Dealloca la memoria utilizzata per gli elementi
    current = head;
    while (current != NULL) {
        struct HTMLElement* next = current->next;
        free(current);
        current = next;
    }

    return 0;
}
