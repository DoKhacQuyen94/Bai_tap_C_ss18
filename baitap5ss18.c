#include<stdio.h>
int main(){
    struct Sinhvien{
    	int id;
        char fullName[100];
        int age;
        char phone[20];
    };
    struct Sinhvien sv[50]={
		{1,"Do Khac Quyen",18,"09876554436"},
		{2,"Do Thao Minh",18,"012345677"},
		{3,"Pham Quoc Khanh",18,"0956578393"},
		{4,"Dao Quang Huy",18,"03477488339"},
		{5,"Tran Duy Thai",18,"0287647483"},
	};
	int nhapID;
	printf("Nhap id muon tim kiem: ");
	scanf("%d",&nhapID);
	int i,check=0; 
	for(i=0;i<sizeof(sv)/sizeof(sv[0]);i++){
		if(nhapID == sv[i].id){
			check=1;	    
			fflush(stdin);
	    	printf("Nhap fullName cho sinh vien: ");
	    	fgets(sv[i].fullName,sizeof(sv[i].fullName),stdin);
			printf("chinh tuoi: ");
			scanf("%d",&sv[i].age);
		}	
	}
	if(check==0){
		printf("Khong tim thay id ban nhap\n");
	}
	int j;
	for (j= 0; j < sizeof(sv)/sizeof(sv[0]); j++){
        printf("In thong tin sinh vien thu %d\n",j+1);
	    printf("%d\n",sv[j].id);
	    printf("%s\n",sv[j].fullName);
	    printf("%d\n",sv[j].age);
	    printf("%s\n",sv[j].phone);
	    if(sv[j].id==0){
	    	break;
		}
    }
    return 0;
}