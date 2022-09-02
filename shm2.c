#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
	int shmid;
	char *shmptr1, *shmptr2;
	//shared memory 생성
	shmid = shmget(IPC_PRIVATE, 10*sizeof(char), IPC_CREAT|0666);
	if(shmid == -1){
		printf("shmget failed\n");
		exit(0);
	}
	//프로세스 생성 시작
	if(fork() == 0){ //자식 프로세스
		//shared memory  연결. 참조
		shmptr1 = (char *) shmat(shmid, NULL, 0);
		for(int i=0;i<10;i++)
			shmptr1[i] = i*10;
		shmdt(shmptr1);
		//자식 프로세스와 shared memory간의 연결참조 해제
		exit(0);
	}
	else{ //부모 프로세스
		wait(NULL);
		//shared memory 연결. 참조
		shmptr2 = (char *) shmat(shmid, NULL, 0);
		for(int i=0;i<10;i++)
			printf("%d\n", shmptr2[i]);
		//부모 프로세스와 shared memory간의 연결참조 해제
		shmdt(shmptr2);

		//shared memory제어, 공유메모리를 os상에서 삭제
		if(shmctl(shmid, IPC_RMID, NULL)==-1)
			printf("shmid faild\n");
	}
	return 0;
}
