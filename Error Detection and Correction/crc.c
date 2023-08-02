
#include <stdio.h>
#include <string.h>

// Function to perform modulo-2 division
void CRCgenerator(char* dividend, char* divisor, char* remainder) {
    int dividendLength = strlen(dividend);
    int divisorLength = strlen(divisor);

    // Make a copy of the dividend
    char temp[dividendLength + 1];
    strcpy(temp, dividend);

    // Perform modulo-2 division
    for (int i = 0; i <= dividendLength - divisorLength; i++) {
        if (temp[i] == '1') {
            for (int j = 0; j < divisorLength; j++) {
                temp[i + j] = (temp[i + j] == divisor[j]) ? '0' : '1';
            }
        }
    }

    
   
    //printf("temp: %s\n", temp);
    // Store the remainder
    strcpy(remainder, &temp[dividendLength - divisorLength + 1]);
    
    // Print the remainder
    printf("\nRemainder: %s\n", remainder);
    
}

void CRCchecker(char* dividend, char* divisor, char* remainder) {
    int dividendLength = strlen(dividend);
    int divisorLength = strlen(divisor);

    // Make a copy of the dividend
    char temp[dividendLength + 1];
    strcpy(temp, dividend);

    // Perform modulo-2 division
    for (int i = 0; i <= dividendLength - divisorLength; i++) {
        if (temp[i] == '1') {
            for (int j = 0; j < divisorLength; j++) {
                temp[i + j] = (temp[i + j] == divisor[j]) ? '0' : '1';
            }
        }
    }

   
    //printf("temp: %s\n", temp);
    // Store the remainder
    strcpy(remainder, &temp[dividendLength - divisorLength + 1]);
    
    for(int i=0;i<strlen(remainder);i++) {
        if(remainder[i] != '0')
        {printf("\nerror");
        return;
        }
    }
    
    printf("\nno error");
}

int main() {
    char dataFrame[100];
    char generator[20];
    char remainder[20];

    // Get the data frame and generator from the user
    printf("Enter the data frame: ");
    scanf("%s", dataFrame);
    printf("Enter the generator polynomial: ");
    scanf("%s", generator);

    // Append zeros to the data frame for the remainder
    int dataFrameLength = strlen(dataFrame);
    int generatorLength = strlen(generator);
    
    for (int i = 0; i < generatorLength - 1; i++) {
        dataFrame[dataFrameLength + i] = '0';
    }
    
    dataFrame[dataFrameLength + generatorLength - 1] = '\0';

    CRCgenerator(dataFrame, generator, remainder);
    
    for (int i = 0; i < generatorLength - 1; i++) {
        dataFrame[dataFrameLength + i] = remainder[i];
    }
    
    
    printf("%s",dataFrame);
    
    CRCchecker(dataFrame, generator, remainder);
    dataFrame[2] = '1';
    printf("\n%s",dataFrame);
    CRCchecker(dataFrame, generator, remainder);
    
    


    return 0;
}
