#include "webMaker.h"

// void generateHTML(t_item *head) {
//     FILE* file = fopen("pagina.html", "w");
//     if (file == NULL) {
//         printf("Impossibile aprire il file per la scrittura.");
//         return;
//     }

//     fprintf(file, "<!DOCTYPE html>\n<html>\n<head>\n<title>La mia Pagina</title>\n");
//     fprintf(file, "<style>\n");
//     fprintf(file, ".grid-container { display: grid; grid-template-columns: repeat(10, 1fr); grid-template-rows: repeat(10, 1fr); grid-gap: 80px; position: relative; }\n");
//     fprintf(file, ".grid-item { border: 1px solid #000; padding: 10px; position: absolute; }\n");

//     t_item* current = head;
//     while (current != NULL) {
//         fprintf(file, ".%s {", current->class); // Usiamo ".class" come selettore CSS
//         int startCol = round((current->x / 80)); // 80 è la larghezza di una cella
//         int endCol = current->x; // Ad esempio, considerando 4 colonne
//         int startRow = round((current->y / (400 / 10)));
//         int endRow = current->y; // Ad esempio, considerando 3 righe
//         printf("startCol: %d\n", startRow);
//         printf("endCol: %d\n", endCol);
//         fprintf(file, "grid-column: %d / %d;", startCol, endCol);
//         fprintf(file, "grid-row: %d / %d;", startRow, endRow);
//         // Altre proprietà CSS personalizzate per l'elemento, ad esempio background-color, font-size, ecc.
//         fprintf(file, "}\n");
//         current = current->next;
//     }

//     fprintf(file, "</style>\n");
//     fprintf(file, "</head>\n<body>\n");

//     fprintf(file, "<div class=\"grid-container\">\n");

//     current = head;
//     while (current != NULL) {
//         fprintf(file, "<div class=\"%s grid-item\">\n", current->class); // Usiamo ".class" come classe CSS
//         fprintf(file, "<%s>%s</%s>\n", current->tag, "Testo dell'elemento", current->tag);
//         fprintf(file, "</div>\n");
//         current = current->next;
//     }

//     fprintf(file, "</div>\n</body>\n</html>\n");
//     fclose(file);
// }


void generateHTML(t_item *head) {
    FILE* file = fopen("pagina.html", "w");
    if (file == NULL) {
        printf("Impossibile aprire il file per la scrittura.");
        return;
    }

    fprintf(file, "<!DOCTYPE html>\n<html>\n<head>\n<title>La mia Pagina</title>\n");
    fprintf(file, "<link href=\"https://cdn.jsdelivr.net/npm/tailwindcss@2.2.19/dist/tailwind.min.css\" rel=\"stylesheet\">\n"); // Includi Tailwind CSS
   // fprintf(file, "<link rel=\"stylesheet\" href=\"src/PressStart2P-Regular.ttf\">"); // Includi il font 8-bit
    fprintf(file, "<style>\n");
    fprintf(file, "@font-face { font-family: 'Press Start 2P'; src: url('src/PressStart2P-Regular.ttf') format('truetype'); }\n");
    fprintf(file, ".grid-container { display: grid; grid-template-columns: repeat(10, 1fr); grid-template-rows: repeat(10, 1fr); grid-gap: 10px; position: relative; }\n");

    t_item* current = head;
    while (current != NULL) {
        fprintf(file, ".%s {", current->class); // Usiamo ".class" come selettore CSS
        printf("Element: %s\n Position: colon %d / 1, row %d / 1\n", current->class, current->ps_x + 1 , current->ps_y + 1);
        fprintf(file, "grid-column: %d / %d;", current->ps_x + 1, current->to_ps_x);
        printf("TAG: %s\n", current->tag);
        if (strcmp(current->tag, "svg") == 0)
            fprintf(file, "grid-row: %d / span 10;", current->ps_y + 1);
        else
            fprintf(file, "grid-row: %d / %d;", current->ps_y + 1, current->to_ps_y);
        // fprintf(file, "background-color: white;"); // Sfondo nero per il bottone
        // fprintf(file, "border: 1px solid black;");
        // fprintf(file, "color: black;"); // Testo bianco
        fprintf(file, "font-family: 'Press Start 2P', cursive;\n"); // Stile del font 8-bit
        fprintf(file, "font-size: 12px;"); // Dimensione del font
        fprintf(file, "padding: 10px 20px;"); // Padding
        // Altre proprietà CSS personalizzate per l'elemento
        fprintf(file, "}\n");

        current = current->next;
    }

    fprintf(file, "</style>\n");
    fprintf(file, "</head>\n<body>\n");

    fprintf(file, "<div class=\"grid-container\">\n");

    current = head;
    while (current != NULL) {
        if (strcmp(current->tag, "btn") == 0) {
            fprintf(file, "<button class=\"grid-item h-10 px-5 m-2 text-blue-100 transition-colors duration-150 bg-blue-600 rounded-lg focus:shadow-outline hover:bg-blue-700 %s\">BUTTON</button>\n", current->class); // Testo "BUTTON" nel bottone
        }
        if (strcmp(current->tag, "svg") == 0)
        {
            fprintf(file, "<div class=\"%s\">\n", current->class); 
            fprintf(file, "<svg width=\"100\" height=\"100\" xmlns=\"http://www.w3.org/2000/svg\">\n");
            fprintf(file, "<line x1=\"50%%\" y1=\"0\" x2=\"50%%\" y2=\"100%%\" stroke=\"black\" stroke-width=\"2\" />\n");
            fprintf(file, "</svg>\n");
            fprintf(file, "</div>\n");
        }

        current = current->next;
    }

    fprintf(file, "</div>\n</body>\n</html>\n");
    fclose(file);
}
