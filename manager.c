#include "manager.h"
#include<stdlib.h>

int selectMenu(){
    int menu;
    printf("\n*** 제품 관리 ***\n");
    printf("1. 조회\n");
    printf("2. 추가\n");
    printf("3. 수정\n");
    printf("4. 삭제\n");
    printf("5. 저장\n");
    printf("0. 종료\n\n");
    printf("=> 원하는 메뉴는? ");
    scanf("%d", &menu);
    return menu;
}
void listProduct(Product *p,int count){

    printf("\nNo. Name          weight price\n");
    printf("================================\n");
    for(int i=0; i<count; i++){
        if( p[i].weight == -1 || p[i].price == -1 ) continue;
        printf("%2d.", i+1);
        readProduct(&p[i]);
    }
    printf("\n");
}

int selectDataNo(Product *p, int count){
    int no;
    listProduct(p,count);
    printf("번호는 (취소:0)?");
    scanf("%d",&no);
    getchar();
    return no;
}

//배열데이터를 파일에 저장하는 함수
void saveData(Product p[], int count){
	        FILE* fp;

        //중량 가격 제품명
        fp= fopen("product.txt","wt");

        for(int i=0; i<count;i++){
                if(p[i].price==-1||p[i].weight==-1) continue;
                fprintf(fp,"\n%s\n",p[i].name);
                fprintf(fp,"%d\n",p[i].weight);
                fprintf(fp,"%d",p[i].price);
        }
        fclose(fp);
        printf("=> 저장되었습니다");
}


//파일에서 데이터 불러오는 함수
int loadData(Product *p){



        int count=0,i=0,fileno=0;
        FILE *fp;
         fp=fopen("product.txt","rt");
         if(fp==NULL){
                 printf("=> 파일 없음\n");
                 fp=fopen("product.txt","w");
                fileno=1;
         }
         else{
         for(;i<100;i++){
          if(feof(fp)) break; //feof은 파일의 마지막이라는 뜻
                 fscanf(fp," %[^\n]s",p[i].name);
                 fscanf(fp,"%d",&p[i].weight);
                 fscanf(fp,"%d",&p[i].price);
         }
}
         fclose(fp);
         if(fileno==0)printf("=> 로딩 성공!\n");
         return i;
}
