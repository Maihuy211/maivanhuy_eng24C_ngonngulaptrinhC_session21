#include <stdio.h>
#include <string.h>
typedef struct {
	int id;
	char bookName[100];
	char author[50];
	long long price;
	char category[50];
}Book;
void inputBook(Book book[],  int *n);
void saveBooksToFile(Book book[], int n);
void loadBooksFromFile(Book book[], int *n);
void printBook(Book book[], int n);
int main(){
	Book books[50];
	int n;
	int choice;
	do {
        printf("\n=========== MENU ===========\n");
        printf("1. Nhap so luong va thong tin sach\n");
        printf("2. Luu thong tin sach vao file\n");
        printf("3. Lay thong tin sach tu file\n");
        printf("4. Hien thi thòn tin sach\n");
        printf("5. Thoat\n");
        printf("============================\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                inputBook(books, &n);
                break;
            case 2:
            	saveBooksToFile(books,n);
                break;
            case 3:
            	loadBooksFromFile(books,&n);
                break;
            case 4:
            	printBook(books,n);
                break;
            case 5:
            	printf("Thoat chuong trinh");
                break;
            default:
                printf("Lua chon khong hop le. Vui long nhap lai.\n");
        }
    } while (choice != 5);
	return 0;
}
int i,j;
void inputBook(Book book[],  int *n){
	printf("Nhap so luong sach muon them: \n");
	scanf("%d", n);
	getchar();
	for(i=0; i<*n;i++){
		book[i].id=i+1;
		printf("Moi ban nhap vao ten sach: \n");
		fgets(book[i].bookName, 100, stdin);
		book[i].bookName[strcspn(book[i].bookName, "\n")] = '\0';
		printf("Moi ban nhap vao ten tac gia: \n");
		fgets(book[i].author, 50, stdin);
		book[i].author[strcspn(book[i].author, "\n")] = '\0';
		printf("Moi ban nhap vao gia tien: \n");
		scanf("%d", &book[i].price);
		getchar();
		printf("Moi ban nhap vao the loai: \n");
		fgets(book[i].category, 50, stdin);
		book[i].category[strcspn(book[i].category, "\n")] = '\0';
	}
}
void saveBooksToFile(Book book[], int n){
	FILE *ptr=fopen("book.dat","wb");
	if(ptr==NULL){
		printf("Khong mo duoc file");
	}
	fwrite(book,sizeof(Book),n,ptr);
	printf("Luu thong tin thanh cong");
	fclose(ptr);
}

void loadBooksFromFile(Book book[], int *n){
	FILE *ptr = fopen("book.dat", "rb");
	if(ptr==NULL){
		printf("Khong mo duoc file");
	}
	Book readBook[100];
	*n=fread(readBook,sizeof(Book),50,ptr);
	for(i=0;i<*n;i++){
		printf("Id: %d\n",readBook[i].id);
		printf("Book Name: %s\n",readBook[i].bookName);
		printf("Tac Gia: %s\n",readBook[i].author);
		printf("Gia: %lld\n",readBook[i].price);
		printf("The Loai: %s\n",readBook[i].category);	
	}
	printf("Lay Du Lieu Thanh Cong\n");
}
void printBook(Book book[], int n){
	printf("In toan bo cac sach: \n");
	for(i=0 ;i<n;i++){
		printf("Ma sach: %d\n", book[i].id);
		printf("Ten sach: %s\n", book[i].bookName);
		printf("Gia tien: %d\n", book[i].price);
		printf("Tac gia: %s\n", book[i].author);
		printf("The loai: %s\n", book[i].category);
	}
	printf("\n");
}
