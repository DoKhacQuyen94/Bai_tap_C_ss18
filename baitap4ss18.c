#include<stdio.h>
int main(){
    struct Sinhvien{
    	int id;
        char fullName[100];
        int age;
        char phone[20];
    };
    struct Sinhvien sv[50];
    int i;
    int count=1;
    for (i= 0; i < 5; i++){
	    sv[i].id = count;
	    fflush(stdin);
	    printf("Nhap fullName cho sinh vien: ");
	    fgets(sv[i].fullName,sizeof(sv[i].fullName),stdin);
	    printf("Nhap tuoi cho sinh vien: ");
	    scanf("%d",&sv[i].age);
	    fflush(stdin);
	    printf("Nhap phone cho sinh vien: ");
	    fgets(sv[i].phone,sizeof(sv[i].phone),stdin);
	    count++;
    }
    int j;
	for (j= 0; j < 5; j++){
        printf("In thong tin sinh vien thu %d\n",j+1);
	    printf("%d\n",sv[j].id);
	    printf("%s\n",sv[j].fullName);
	    printf("%d\n",sv[j].age);
	    printf("%s\n",sv[j].phone);
    }
    return 0;
}