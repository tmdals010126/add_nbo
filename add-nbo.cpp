#include<stdio.h>
#include<string.h>
#include<stdint.h>
#include<stddef.h>
#include<netinet/in.h>


uint32_t temp(uint32_t *a){
	uint32_t* p = reinterpret_cast<uint32_t*>(a);
	return htonl(*p);
}

int main(int argc, char*argv[]){
	FILE *fp;
	char file_name_1[100],file_name_2[100];
	char buffer[100];
	uint32_t a,b;
	if(argc != 3)
		printf("인자가 부족하거나 많습니다.");
	fp = fopen(argv[1],"r");
	if(fp==NULL)
		return -1;
	fread(buffer,sizeof(buffer),1,fp);
	fclose(fp);
	a = temp((uint32_t*)&buffer);

	fp = fopen(argv[2],"r");
	if(fp==NULL)
		return -1;
	fread(buffer,sizeof(buffer),1,fp);
	b = temp((uint32_t*)&buffer);
	fclose(fp);
	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)",a,a,b,b,a+b,a+b);
	return 0;


}
