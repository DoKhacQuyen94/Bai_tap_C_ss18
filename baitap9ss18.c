#include<stdio.h>
#include<string.h>
void displayMenu(void);
struct Dish{
        int id;
        char fullName[100];
        double price;
    };
int main(){
    struct Dish menu[100]={
        {1,"Khoai",35000},
        {2,"Ga",40000},
        {3,"Kem",10000},
        {4,"Com", 30000},
        {5,"Vit",25000},
    };
    int luaChon;
    int so=0;
    int kichThuoc= 5;
    do{
        displayMenu();
        printf("Nhap lua chon cua ban: ");
        scanf("%d",&luaChon);
        getchar();
        switch (luaChon){
        case 1:
            for (int i = 0; i < kichThuoc; i++){ 
                if(menu[i].id==0){
                    break;
                }
                printf("%d. %s: %lf\n",menu[i].id,menu[i].fullName,menu[i].price);
            }
            break;
        case 2:
            menu[kichThuoc].id=kichThuoc+1;
            printf("Nhap ten mon muon them: ");
            fgets(menu[kichThuoc].fullName,sizeof(menu[kichThuoc].fullName),stdin);
            menu[kichThuoc].fullName[strlen(menu[kichThuoc].fullName)-1] = '\0';
            printf("Nhap gia tien: ");
            scanf("%lf",&menu[kichThuoc].price);
            getchar();
            kichThuoc++;
            for (int i = 0; i < kichThuoc; i++){ 
                printf("%d. %s: %lf\n",menu[i].id,menu[i].fullName,menu[i].price);
            }    
                
            break;
        case 3:
                int idThayDoi;
                printf("nhap vao id muon sua: ");
                scanf("%d",&idThayDoi);
                getchar();
                if(idThayDoi>kichThuoc-1||idThayDoi<0){
                    printf("khong ton tai id do\n");
                    break;
                }
                for(int i=0;i<kichThuoc;i++){
                        if(idThayDoi==menu[i].id){
                                printf("nhap vao mon sua: ");
                                fgets(menu[i].fullName,sizeof(menu[i].fullName),stdin);
                                menu[i].fullName[strlen(menu[i].fullName)-1]='\0';
                                printf("nhap vao gia tien muon sua: ");
                                scanf("%lf",&menu[i].price);
                                getchar();
			}
		}
                printf("Menu sau khi thay doi la: \n");
                for(int i=0;i<kichThuoc;i++){
                	printf("%d. %s: %lf\n",menu[i].id,menu[i].fullName,menu[i].price);
                }
	        break;
        case 4:
            kichThuoc--;
            for (int i = 0; i < kichThuoc; i++){ 
                if(menu[i].id==0){
                    break;
                }
                printf("%d. %s: %lf\n",menu[i].id,menu[i].fullName,menu[i].price);
            }
            break;
        case 5:
            for(int i=0;i<kichThuoc-1;i++){
                for(int j=0; j<kichThuoc-i-1;j++){
                        if (menu[j].price > menu[j + 1].price) {
                                struct Dish temp = menu[j];
                                menu[j] = menu[j + 1];
                                menu[j + 1] = temp;
                            }
                        }
                }
            printf("Menu sau khi sắp xếp theo giá tăng dần:\n");
            for (int i = 0; i < kichThuoc; i++){ 
                if(menu[i].id==0){
                    break;
                }
                printf("%d. %s: %lf\n",menu[i].id,menu[i].fullName,menu[i].price);
            }
            break;
        case 6:
            char searchName[40];
            printf("Nhap ten mon an can tim: ");
            scanf("%s", searchName);
            getchar();
            // searchName[strlen(searchName)-1] = '\0';
            int found = 0;
            for (int i = 0; i < kichThuoc; i++) {
                if (strcmp(menu[i].fullName, searchName) == 0) {
                    printf("Tim thay: id: %d, name: %s, price: %.2f\n", menu[i].id, menu[i].fullName, menu[i].price);
                    found = 1;
                    break;
                }
            }
            if (found!=1) {
            	printf("Khong tim thay mon an!\n");
            }
            break;
        case 7: 
            printf("Ban da thoat\n");
            break;
        default:
            printf("Lựa chọn sai\n");
            break;
        }
    } while (luaChon != 7);
    
    return 0 ;
}
void displayMenu(void){
    printf("\n------Menu------\n");
    printf("1. In ra giá trị các phần tử có trong menu món ăn\n");
    printf("2. Thêm một phần từ vào vị trí chỉ định (vị trí cuối)\n");
    printf("3. Sửa một phần từ ở vị trí chỉ định\n");
    printf("4. Xóa một phần từ ở vị trí chỉ định (vị trí cuối)\n");
    printf("5. Sắp xếp các phần tử theo giá tăng dần\n");
    printf("6. TÌm kiếm phần tử theo name nhập vào (Theo tuyến tính)\n");
    printf("7. Thoát\n");

}
