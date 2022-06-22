#include<stdio.h>  
#include<stdlib.h>  
#include<unistd.h>  
#include<sys/shm.h>  
#include<string.h>  

int main()

{

int shmid,shmid1;

int *array;

int *arr3;

int count = 5;

int i = 0;

int j=0;

int SizeMem;

//key_t key = 12345;



SizeMem = sizeof(*array)*(count);



shmid=shmget((key_t)2345, 1024, 0666|IPC_CREAT);



array = (int *)shmat(shmid, 0, 0);

shmid1=shmget((key_t)2346, 1024, 0666);

arr3 = shmat(shmid1, 0, SHM_RDONLY);

int input;

printf("Enter what to perform\n 1: Enter new array \n 2:Print previous value \n");

scanf("%d", &input);

printf("\n");

if(input==2){

	printf("Sorted array: \n");

	for(i=0; i<5; i++)

	    {

		printf("\n%d---\n", arr3[i] );

	    }

}

else if(input==1){

for(i=0; i<5; i++)

{

    scanf("%d",&j);

    array[i] = j;

}



for(i=0; i<count; i++)

{

    printf("\n%d---\n", array[i]);

}

printf("\nWritting to memory succesful--\n");

}



shmdt((void *) array);

shmdt((void *) arr3);


return 0;

}