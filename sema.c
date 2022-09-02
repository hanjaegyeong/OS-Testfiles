#include <semaphore.h>
#include <pthread.h>
#include <stdio.h>

sem_t semaphore;
int num = 2;

void *threadF1(void *arg){
	int i;
	if(num != 0){
		num--;
		sem_wait(&semaphore);
		printf("스레드 1이 화장실 이용을 시작합니다.\n");

		//화장실 이용하는 시간
		for(i=0;i<1000000;i++){}

		printf("스레드 1이 화장실 이용을 마쳤습니다.\n");
		num++;
		sem_post(&semaphore);
	}
	else if(num == 0){
		printf("화장실이 꽉 차 스레드 1이 기다리고 있습니다.\n");
		while(num == 0){}
		printf("스레드 1이 화장실 이용을 마쳤습니다.\n");
		num++;
		sem_post(&semaphore);
	}
	return NULL;
}

void *threadF2(void *arg){
	int i;
	if(num != 0){
		num--;
		sem_wait(&semaphore);
		printf("스레드 2가 화장실을 이용하기 시작합니다.\n");

		//화장실 이용 중인 시간
		for(i=0;i<1000000;i++){}

		printf("스레드 2가 화장실 이용을 마쳤습니다.\n");
		num++;
		sem_post(&semaphore);
	}
	else if(num == 0){
		printf("화장실이 꽉 차 스레드 2가 기다리고 있습니다.\n");

		while(num == 0){}
		printf("스레드 2가 화장실 이용을 마쳤습니다.\n");
		num++;
		sem_post(&semaphore);
	}
	return NULL;
}

void *threadF3(void *arg){
        int i;
        if(num != 0){
                num--;
                sem_wait(&semaphore);
                printf("스레드 3이 화장실을 이용하기 시작합니다.\n");

                //화장실 이용 중인 시간
                for(i=0;i<1000000;i++){}

                printf("스레드 3이 화장실 이용을 마쳤습니다.\n");
                num++;
                sem_post(&semaphore);
        }
        else if(num == 0){
                printf("화장실이 꽉 차 스레드 3이 기다리고 있습니다.\n");

                while(num == 0){}
                printf("스레드 3이 화장실 이용을 마쳤습니다.\n");
                num++;
                sem_post(&semaphore);
        }
        return NULL;
}

int main(){
	pthread_t thread1, thread2, thread3;
	sem_init(&semaphore, 0, 2);
	printf("semaphore test start!\n");

	pthread_create(&thread1, NULL, threadF1, NULL);
	pthread_create(&thread2, NULL, threadF2, NULL);
	pthread_create(&thread3, NULL, threadF3, NULL);

	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	pthread_join(thread3, NULL);

	printf("모든 스레드가 화장실 이용을 끝냈습니다\n");

	return 0;
}
