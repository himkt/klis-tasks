# include <stdio.h>
# include <string.h>
#include <stdlib.h>

struct goods{
  char code[20];
  char name[20];
  int price;
};



int main(){
	FILE *fp;
	char str[20];
  int i = 1;
  int j = 0;
  char code[20];
  char name[20];
  int price;
  char query[20];
  struct goods goods_list[1000];

	fp = fopen("goods.txt","r");

	while((fgets(str,256,fp))!=NULL){

    if(i % 4 == 1){
      if(strlen(str) == 2){break;}
      strcpy(code,str);
    }else if(i % 4 == 2){
			/* lntrim(str); */
      strcpy(name,str);
    }else if(i % 4 == 3){
      price = atoi(str);
    }else if(i % 4 == 0 && i != 0){
      strcpy(goods_list[j].code, code);
      strcpy(goods_list[j].name, name);
      goods_list[j].price = price;
      j++;
    }
    i++;
	}

	fclose(fp);

  /* printf("input goods name: "); */
  /* scanf("%s", query); */
  strcpy(query, "aa");

  for(i = 0; i < j-1; i++){
    printf("%s", goods_list[i].name);
    if(strcmp(query, goods_list[i].name) == 0){
      printf("%s", goods_list[i].code);
      printf("%s", goods_list[i].name);
      printf("%d", goods_list[i].price);
    }
  }
}
