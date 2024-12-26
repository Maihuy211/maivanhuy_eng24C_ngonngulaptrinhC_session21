# include<stdio.h>
# include<string.h>
typedef struct{
	int id;
	char name[50];
	int age;
}Student;
void inputSudent(Student sv[], int *n);
int main(){
	Student students[100];
	int n;
	inputSudent(students,&n);
	FILE *fptr;
	fptr=fopen("students.txt", "w");
	if(fptr==NULL){
    	printf("khong mo duoc file");
    	return 1;
	}
    fread(students,sizeof(Student),5,fptr);
    int i;
    for(i=0;i<5;i++){
    	printf("ID-%d\n",students[i].id);
    	printf("Ten-%s\n",students[i].name);
    	printf("Diem-%d\n",students[i].age);	
	}
    printf("Luu thong tin thanh cong");
    fclose(fptr);
}
void inputSudent(Student sv[], int *n){
	printf("nhap so luong sinh vien: \n");
	scanf("%d",n);
	getchar();
	int i;
    for(i=0;i<*n;i++){
		sv[i].id=i+1;
		printf("Moi ban nhap vao ten sinh vien : ");
		fgets(sv[i].name,100,stdin);
		sv[i].name[strlen(sv[i].name)-1]='\0';
		printf("moi ban nhap tuoi sinh vien");
		scanf("%d",&sv[i].age);
		getchar();
	}
}

