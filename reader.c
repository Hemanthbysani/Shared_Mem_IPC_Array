#include<stdio.h>  
#include<stdlib.h>  
#include<unistd.h>  
#include<sys/shm.h>  
#include<string.h>

int main(){

	int shmid,shmid1, SizeMem1;

	int *array;

	int *arr3;

	int count = 5;

	int n=5;

	int i = 0;

	int arr[5];

	int temp;

	//key_t key = 12345;

	SizeMem1 = sizeof(*arr3)*(count);

	shmid=shmget((key_t)2345, 1024, 0666); 

	shmid1=shmget((key_t)2346, 1024, 0666|IPC_CREAT);

	array = shmat(shmid, 0, SHM_RDONLY);

	arr3 = (int *)shmat(shmid1, 0, 0);

	for(int j=0; j<5; j++){

	    arr[j] = array[j];

	}



	printf("Sorted array: \n"); 

	for (int i=0;i<n-1;i++)

	{

		for ( int k =i+1;k <= n-1;k++)

		{

			if ( arr[k] > arr[i] )

			{

				temp=arr[k];

				arr[k]=arr[i];

				arr[i]=temp;

			}

		}

	}

	for(i=0; i<5; i++)

	    {

		printf("\n%d---\n", arr[i] );

	    }

	for(int j=0; j<5; j++){

	    arr3[j] = arr[j];

	}

	    printf("\nRead to memory succesful--\n");



	    shmdt((void *) array);

	    shmdt((void *) arr3);

	    return 0;

}