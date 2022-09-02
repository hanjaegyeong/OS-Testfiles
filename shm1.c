

	int  shmid;
        key_t key;
	char *shmaddr;

	key = ftok("helloshm", 1);
	shmid = shmget(key, 1023, IPC_CREAT|0644); //shared memory 연결
	//key를 사용해 size 크기의 공유 메모리를 생성하고 ID반환
	if (shmid == -1){
		perror("shmget");
		exit(1);
	}

	printf("shmid: %d", shmid);
	shmaddr = (char *) shmat(shmid, NULL, 0); //shared memory 연결
	//shmid (shared memory)를 메모리위치 shmaddr에 연결하고 주소반환
	strcpy(shmaddr, "hello shared memory");
	return 0;
	}
}
