#include <stdio.h>
#include<string.h>
int main() {
    FILE *fptr;
    FILE *fptr1;
    char str[100];
    fptr = fopen("bt01.txt", "r");
    if (fptr==NULL) {
        printf("Loi mo file!\n");
        return 1;
    }
    fptr1=fopen("bt06.txt", "w");
    if (fptr==NULL) {
        printf("Loi mo file!\n");
        return 1;
    }
    while(fgets(str, sizeof(str), fptr) != NULL){
		fputs(str,fptr1);
	}
	fclose(fptr);
	fclose(fptr1);
	printf("Da sao chep noi dung tu file bt01.txt thanh cong\n");
    return 0;
}
