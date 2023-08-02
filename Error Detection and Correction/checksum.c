#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int C = 0, b_size;
char data[50], rem[20];

void print() {
printf("%s \n",rem);
}

char add(char a, char b)
{
    if (C == 0 && (a == '0' && b == '0'))
    {
        C = 0;
        return '0';
    }

    if (C == 0 && (a == '0' && b == '1'))
    {
        C = 0;
        return '1';
    }

    if (C == 0 && (a == '1' && b == '0'))
    {
        C = 0;
        return '1';
    }
    if (C == 0 && (a == '1' && b == '1'))
    {
        C = 1;
        return '0';
    }
    if (C == 1 && (a == '0' && b == '0'))
    {
        C = 0;
        return '1';
    }
    if (C == 1 && (a == '0' && b == '1'))
    {
        C = 1;
        return '0';
    }
    if (C == 1 && (a == '1' && b == '0'))
    {
        C = 1;
        return '0';
    }

    if (C == 1 && (a == '1' && b == '1'))
    {
        C = 1;
        return '1';
    }
    
    return 0;
}

void complement()
{
    
    for(int k=b_size-1;k>=0;k--)
        if(rem[k] == '1')
            rem[k] = '0';
        else
            rem[k] = '1';
}

void sender()
{
    char temp[100];


    for(int i=0;i<b_size;i++)   //copy first block
    rem[i] = data[i];


    for(int i=b_size;i<strlen(data);i += b_size) {

        for(int j=0;j<b_size;j++) {
            temp[j] = data[i+j];        //copy the next block
        }


        for(int k=b_size-1;k>=0;k--) {
            rem[k] = add(rem[k],temp[k]);       //add both the blocks
        }

        
        if(C==1) {                  //if carry is generated, add the carry back
        for(int k=b_size-1;k>=0;k--) {
            if(C==1) {
                C=0;
                rem[k]=add(rem[k],'1');   
            }
        }    
    }
}    
    
    complement();

    printf("checksum is : ");
    print();
}

void receiver()
{
    char temp[100];


    for(int i=0;i<b_size;i++)   //copy first block
    rem[i] = data[i];


    for(int i=b_size;i<strlen(data);i += b_size) {

        for(int j=0;j<b_size;j++) {
            temp[j] = data[i+j];        //copy the next block
        }


        for(int k=b_size-1;k>=0;k--) {
            rem[k] = add(rem[k],temp[k]);       //add both the blocks
        }

        
        if(C==1) {                  //if carry is generated, add the carry back
        for(int k=b_size-1;k>=0;k--) {
            if(C==1) {
                C=0;
                rem[k]=add(rem[k],'1');   
            }
        }    
    }
}
    for (int i = 0; i < b_size; i++)
    {
        if(rem[i] != '1') {printf("\nerror \n"); return;}
    }
    printf("\nno error");
        
}


int main()
{

   strcpy(data, "10011001111000100010010010000100");
   // strcpy(data, "10110011101010110101101011010101");
   b_size = 8;

    // strcpy(data, "00011001");
    // b_size = 4;


    sender();

    strcat(data,rem);
    printf("final data sent: %s",data);
    receiver();

    //added error
    data[2] = '1';
    printf("\nfinal data sent with error: %s",data);
    receiver();

    return 0;
}
