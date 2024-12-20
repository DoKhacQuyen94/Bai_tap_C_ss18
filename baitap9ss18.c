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
        {1,"Khoai Chiên",35000},
        {2,"Gà chiên",40000},
        {3,"Kem",10000},
        {4,"Cơm Rang", 30000},
        {5,"Đùi Gà",25000},
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
            kichThuoc++;
            for (int i = 0; i < kichThuoc; i++){ 
                printf("%d. %s: %lf\n",menu[i].id,menu[i].fullName,menu[i].price);
            }    
                
            break;
        case 3:
            printf("Sua phan tu cuoi cung \n");
            printf("Nhap ten mon moi: ");
            fgets(menu[kichThuoc-1].fullName,sizeof(menu[kichThuoc-1].fullName),stdin);
            menu[kichThuoc-1].fullName[strlen(menu[kichThuoc-1].fullName)-1] = '\0';
            printf("Nhap gia tien moi: ");
            scanf("%lf", &menu[kichThuoc-1].price);
            for (int i = 0; i < kichThuoc; i++){ 
                if(menu[i].id==0){
                    break;
                }
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
