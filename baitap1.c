#include <stdio.h>
int main() {
    FILE *fstr;
    char str[100];

    fstr = fopen("bt01.txt", "w");
    if (fstr==NULL){
        printf("Loi mo file!\n");
        return 1;
    }
    printf("Nhap mot chuoi bat ky: ");
    fgets(str, sizeof(str), stdin);
    fputs(str, fstr);
    fclose(fstr);
    printf("Da ghi vao file bt01.txt\n");
    return 0;
}

