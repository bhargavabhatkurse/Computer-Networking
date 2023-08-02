#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// transmitter --------------------------------------------------------------
char* transmitter() {
    char a[20];
    static char b[20];
    scanf("%s", a);

    int j = 1;

    b[0] = 'f';
    for (int i = 0; i < strlen(a); i++) {
        if (a[i] == 'f') {
            b[j++] = 's';
        }
        else if (a[i] == 's') {
            b[j++] = 's';
        }
        b[j++] = a[i];
    }
    b[j] = 'f';

    printf("\nBYTE STUFFED FRAME:\n");
    printf("%s\n", b);

    return b;
}

// receiver --------------------------------------------------------------
void receiver(char b[20]) {
    char result[20];
    int j = 0;
    for (int i = 0; i < strlen(b); i++) {
        if (i == 0 || i == strlen(b) - 1) { // first and last flag
            continue;
        }

        if (b[i] == 's' && b[i + 1] == 'f') {
            result[j] = b[i + 1];
            j++;
            i++;
        }
        else if (b[i] == 's' && b[i + 1] == 's') {
            result[j] = b[i + 1];
            j++;
            i++;
        }
        else {
            result[j++] = b[i];
        }
    }

    printf("\nDE-STUFFED RESULT: %s\n", result);
}

// MAIN FUNCTION ----------------------------------------------------------
int main() {
    int choice;
    printf("\n s - escape");
    printf("\n f - flag delimiter\n\n");

    while (1) {
        char* result;
        printf("1. Transmitter\n2. Receiver\n3. Exit\nEnter choice: ");
        scanf("%d", &choice);
        printf("\n---------------\n");

        switch (choice) {
        case 1:
            result = transmitter();
            break;
        case 2:
            receiver(result);
            break;
        case 3:
            exit(0);
            break;
        default:
            break;
        }
    }

    return 0;
}
