#include <stdio.h>
#include <stdlib.h>

void createFile() {
    char filename[100], text[1000];
    printf("Enter the file name to create: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error creating file!\n");
        return;
    }

    printf("Enter the text to write into the file: ");
    getchar(); // Consume the newline character
    fgets(text, sizeof(text), stdin);
    fprintf(file, "%s", text);
    fclose(file);

    printf("File '%s' created successfully.\n", filename);
}

void readFile() {
    char filename[100], ch;
    printf("Enter the file name to read: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file! It may not exist.\n");
        return;
    }

    printf("Contents of the file '%s':\n", filename);
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }
    fclose(file);
}

void appendToFile() {
    char filename[100], text[1000];
    printf("Enter the file name to append data: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "a");
    if (file == NULL) {
        printf("Error opening file! It may not exist.\n");
        return;
    }

    printf("Enter the text to append: ");
    getchar(); // Consume the newline character
    fgets(text, sizeof(text), stdin);
    fprintf(file, "%s", text);
    fclose(file);

    printf("Data appended successfully to '%s'.\n", filename);
}

void deleteFile() {
    char filename[100];
    printf("Enter the file name to delete: ");
    scanf("%s", filename);

    if (remove(filename) == 0) {
        printf("File '%s' deleted successfully.\n", filename);
    } else {
        printf("Error deleting file! It may not exist.\n");
    }
}

int main() {
    int choice;

    while (1) {
        printf("\nFile Operations Menu:\n");
        printf("1. Create a file and add text\n");
        printf("2. Read file data\n");
        printf("3. Append data to file\n");
        printf("4. Delete file\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createFile();
                break;
            case 2:
                readFile();
                break;
            case 3:
                appendToFile();
                break;
            case 4:
                deleteFile();
                break;
            case 5:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
