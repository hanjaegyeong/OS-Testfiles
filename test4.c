#include <stdio.h>
#include <pthread.h>
void *threadRoutine(void* arg){
	long argu;
	argu = *((long *)arg);
        return (void*)(argu + 10);
	//부모스레드에서 리턴값을 받기 때문에
}

int main(){
        pthread_t threadID;
        printf("create thread\n");
        long argu = -1;
        int status;
        void *value;

        status = pthread_create(&threadID, NULL, threadRoutine, (void*)&argu);
        printf("Main Thread is now waiting for Thread\n");
        pthread_join(threadID, &value);
        printf("Return value (0: success) :: %d\n", status);
        printf("receive value ::%ld\n", (long)value);
        return 0;

}
