#include<Stdio.h>
#include<sys/shm.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
    int shmid;
    void *shm;
    char str[100];
    shmid=shmget((key-t)2366,1024,0666\IPC_CREAT);
    printf("key of shared memory is %d \n ",shmid);
    shm=shmat(shmid,NULL,0);
    printf("process is attached at %p \n",shm);
    read(0,str,100);
    strcpy(shm,str);
    printf("value shared is %s \n ",(char *)shm);
    return 0;
}







#include<stdio.h>
#include<sys/shm.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
    int shmid;
    void *shm;
    char str[100];
    shmid = shmget((key-t)2366,1024,0666);
    printf("key of shared memory is %d \n",shmid);
    shm=shmat(shmid,NULL,0);
    printf("Process is attached at %p \n ",shm);
    printf("Value read from shared is %s \n",(char*)shm);
    return 0;
}