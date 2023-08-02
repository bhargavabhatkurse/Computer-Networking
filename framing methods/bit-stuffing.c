#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// transmitter --------------------------------------------------------------
char* transmitter() {
    char a[20];
    static char b[20];
    scanf("%s", a);

    int j = 0;
    int count = 0;
    for (int i = 0; i < strlen(a); i++) {
        if (a[i] == '0') {
            count = 0;
            b[j++] = a[i];
        }
        else if (a[i] == '1' && count != 5) {
            count++;
            b[j++] = a[i];
        }
        else {
            b[j++] = '0';
            b[j++] = a[i];
            count = 0;
        }
    }

    b[j] = '\0'; // Null-terminate the stuffed frame

    printf("\nBIT STUFFED FRAME:\n");
    printf("%s\n", b);

    return b;
}

// receiver --------------------------------------------------------------
void receiver(char b[20]) {
    char result[20];
    int j = 0;
    int count = 0;
    for (int i = 0; i < strlen(b); i++) {
        if (b[i] == '1' && count != 5) {
            count++;
            result[j++] = b[i];
        }
        else {
            if (b[i] == '0' && count != 5) {
                count = 0;
                result[j++] = b[i];
            }
            else {
                count = 0;
                continue;
            }
        }
    }

    result[j] = '\0'; // Null-terminate the de-stuffed result

    printf("\nDE-STUFFED RESULT: %s\n", result);
}

// MAIN FUNCTION ----------------------------------------------------------
int main() {
    int choice;
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
