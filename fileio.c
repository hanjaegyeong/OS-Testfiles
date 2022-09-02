#include <stdio.h>
#define MAX_NAME_SIZE 20
typedef struct _Member Member;
struct _Member{
	char name[MAX_NAME_SIZE+1];
	int age;
	int num;
};

void Write(){
	Member base[4] = {{"홍길동", 20, 30}, {"강감찬", 30, 4}, {"김유신", 70, 1}};
	FILE *fp = fopen("memdata", "wb");
	fwrite(base, sizeof(Member), 4, fp);
	fclose(fp);
}
void Read(){
	int i = 0;
	Member base[4];
	FILE *fp = fopen("memdata", "rb");
	fread(base, sizeof(Member), 4, fp);
	fclose(fp);
	printf("이름/번호/나이\n");
	for(i=0;i<4;i++){
		printf("%s/%d/%d\n", base[i].name, base[i].num, base[i].age);
	}
}
int main(){
	Write();
	Read();
	return 0;
}
