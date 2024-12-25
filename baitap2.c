#include <stdio.h>
int main() {
    FILE *fstr;
    char str[100]="mai van huy";
    fstr = fopen("bt01.txt", "r");
    if(fstr==NULL){
    	printf("Loi mo file!\n");
        return 1;
    }
    fputc(str[0],fstr);
    int result=fgetc(fstr);
    printf("%c\n",(char)result);
    fclose(fstr);
    printf("doc file thanh cong\n");
    return 0;
}
