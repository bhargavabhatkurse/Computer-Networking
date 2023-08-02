#include <stdio.h>
#include <string.h>

void print(int a[],int n) {
	printf("\n");
	for (int i = 0; i < n; ++i)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}
void manchester(char s[]) {

	char prev = '0';
	int encoding[2*strlen(s)+1];

	for(int i=0;i<strlen(s);i++){

		if(s[i] == '1') {
			if(prev == '0') {
				printf("-|_");
			}
			else {
				printf("|-|_");
				
			}
			prev = '1';
			encoding[2*i] = 1;
			encoding[2*i+1] = 0;

		}
		else {
			if(prev == '0') {
				printf("|_|-");
			}
			else {
				printf("_|-");
				
			}
			prev = '0';
			encoding[2*i] = 0;
			encoding[2*i+1] = 1;
		}

	}
	print(encoding,2*strlen(s));
}

void diff_manchester(char s[]) {
	//transition for 0, no transition for 1
	char prev = '0'; int lastvalue = 0;
	int encoding[2*strlen(s)];

	for(int i=0;i<strlen(s);i++){

		if(s[i] == '1') {
			if(prev == '1') {
				printf("-|_");
				prev = '0';
			}
			else {
				printf("_|-");
				prev = '1';
				
			}
			encoding[2*i] = lastvalue;
			encoding[2*i+1] = !lastvalue;

			lastvalue = !lastvalue;

		}
		else {
			if(prev == '0') {
				printf("|-|_");
				prev = '0';
			}
			else {
				printf("|_|-");
				prev = '1';
				
			}
			
			encoding[2*i] = !lastvalue;
			encoding[2*i+1] = lastvalue;
		}

	}
	print(encoding,2*strlen(s));

}

int main() {

	char *s = "10100";
	manchester(s);
	diff_manchester(s);

	return 0;
}