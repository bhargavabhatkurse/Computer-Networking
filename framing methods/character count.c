#include <stdio.h>
#include <string.h>
#include <ctype.h>
void unstuffing(char p[],int no_of_frames) {
    char decode[strlen(p)-no_of_frames+1];
    int size;
    int read = 0;
    
    for(int i=0;i<strlen(p);i++) {
        if(isdigit(p[i])) {
            size = p[i]-'0';
    
        while(size-1>0) {
            decode[read++] = p[++i];
            size--;
        }
        
        }
    }
    
    decode[strlen(p)-no_of_frames] = '\0';
    
    printf("%s \n",decode);
    
}

void stuffing(char p[], int frame_size) {
    int complete_frames = strlen(p) / (frame_size-1);
    int incomplete_frames = 0;
    
    if(strlen(p) % (frame_size-1) != 0) {
        incomplete_frames += 1;
    }
    
    int no_of_frames = complete_frames+incomplete_frames;
    int encode_size = strlen(p) + no_of_frames;
    printf("original size: %d, encode string size: %d\n", (int)strlen(p),encode_size);
    char encode[encode_size + 1];

    int i = 0, j = 0;

    while (i < complete_frames*frame_size) {
        if (i % (frame_size) == 0) {
           
            encode[i++] = frame_size + '0';
        } else {
           
            encode[i++] = p[j++];
        }


    }
    //handling last incomplete frame
    if(incomplete_frames == 1) {
        encode[i++] = (strlen(p) % (frame_size-1) + 1) + '0';
        while(j<strlen(p)) {
            encode[i++] = p[j++];
        }
    }

    encode[encode_size] = '\0';

    printf("%s\n", encode);
    
    unstuffing(encode,no_of_frames);
}


int main() {
    char p[] = "abacadefgh";
    int frame_size = 3;

    stuffing(p, frame_size);
    //unstuffing(p, frame_size);

    return 0;
}
