#include<stdio.h>
#include<string.h>
int main(){
	FILE *fptr;
	char ptr[100];
	int n;
	fptr=fopen("bt05.txt", "w");
	if(fptr==NULL){
		printf("Loi mo file!\n");
		return 1;
	}
	printf("Nhap so dong: ");
	scanf("%d", &n);
	getchar();
	
	int i;
	for(i=0; i<n; i++){
		printf("Nhap noi dung dong %d: ", i+1);
		fgets(ptr, sizeof(ptr), stdin);
		fputs(ptr, fptr);
	}
	fclose(fptr);
	fptr=fopen("bt05.txt", "r");
	if(fptr==NULL){
		printf("Loi mo file!\n");
		return 1;
	}
	printf("\nNoi dung tung dong:\n");
	i=1;
	while(fgets(ptr, sizeof(ptr), fptr) != NULL){
		printf("Dong %d file: %s\n",i,ptr);
		i++;
	}
	fclose(fptr);
	return 0;
}
