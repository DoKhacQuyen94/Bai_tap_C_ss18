#include<stdio.h>
int main(){
    struct Student{
        char name[100];
        int age;
        char phoneNumber[20];
    };
    struct Student svien01={"Do Khac Quyen",18,"0345678912"};
    printf("Thong tin sinh vien: \n");
    printf("Ten: %s\n",svien01.name);
    printf("Tuoi: %d\n",svien01.age);
    printf("So dien thoai: %s\n", svien01.phoneNumber);
    return 0;
}