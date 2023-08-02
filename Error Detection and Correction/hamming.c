#include <stdio.h>
void display(int hammingcode[],int r,int dataLength) {
    printf("\n");
    for (int i = 0; i < dataLength + r; i++)
        printf("%d",hammingcode[i]);
}

void Generation(int hammingcode[],int data[],int r,int dataLength) {
    
    for (int i = 0; i < dataLength + r; i++)
        hammingcode[i] = 0;
    
    int k = 0;
for (int i = 0; i < dataLength + r; i++) {
    if (i == (1 << k) - 1) {
        k++;
    } else {
        hammingcode[i] = data[i - k];
    }
}

    
        for (int i = 0; i < r; i++) {
            int parity = 0;
            int position = (1 << i);
           
            for (int j = position-1; j < dataLength + r; j++) {
                if (((j+1) & position) != 0) {  // Check if the position is influenced by the current parity bit
                    parity ^= hammingcode[j];
                    }
    }

    hammingcode[position-1] = parity;
}
    
}

// Function to detect errors in Hamming code
void detectErrors(int hammingcode[],int r, int dataLength)
{
    int error_loc = 0;
    // Calculate the parity bits and check for errors
    for (int i = 0; i < r; i++) {
        int parity = 0;
        int position = (1 << i);

        for (int j = position - 1; j < dataLength+r; j++) {
            if (((j + 1) & position) != 0) {  // Check if the position is influenced by the current parity bit
                parity ^= hammingcode[j];
            }
        }

        if (parity != 0) {
            error_loc = error_loc|(position);
        }
    }
    hammingcode[error_loc-1] ^=1;       //correction

}


int main()
{   int r =0;
    int hammingcode[30];
    int data[] = {1,1,1,0};
    int dataLength = sizeof(data)/sizeof(int);
    while (dataLength + r + 1 > (1 << r))
        r++;
        
    printf("%d\n",r);
    
    Generation(hammingcode,data,r,dataLength);
    display(hammingcode,r,dataLength);
    hammingcode[3] ^=1;
    display(hammingcode,r,dataLength);
    detectErrors(hammingcode,r,dataLength);
    display(hammingcode,r,dataLength);


    return 0;
}
