#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <unistd.h>
#include <fcntl.h>
#define READ_SIZE 16

int main(int argc, char **argv){
	int fd, flag = PROT_WRITE | PROT_READ;
	struct stat sb;
	char *addr;

	if((fd = open(argv[1], O_RDWR|O_CREAT)) < 0){
		printf("file open error\n");
		return -1;
	}
	if(fstat(fd, &sb) < 0){
		printf("fstat error\n");
		return -1;
	}
	addr = mmap(NULL, READ_SIZE, flag, MAP_SHARED, fd, 0);
	if (addr == MAP_FAILED){
		printf("mmap error\n");
	}
	printf("%s\n", addr);
	memset(addr, 0x00, READ_SIZE);
	munmap(addr, READ_SIZE);

	close(fd);

}
