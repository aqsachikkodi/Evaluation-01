#include<stdio.h>

int main()
{
    int n,i,x,j,temp;
    int arr[100];

    FILE *fp;
    fp=fopen("C:\\Users\\dell\\Documents\\c codes\\myfile.txt","r+");// Open first file for reading
    printf("Enter the number of numbers to be taken from the file 1 to sort\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        fscanf(fp,"%d",&x);// read n numbers from file
        arr[i]=x;
    }
    for(i=0;i<n;i++)//bubble sort
    {
        for(j=0;j<n;j++)
        {
            if(arr[j+1]>arr[j])
            {
                temp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
            }
        }
    }
    fclose(fp);//closing the first file
    for(i=0;i<n;i++)
    {
        printf("%d\n",arr[i]);//printing the array after sorting the numbers taken from first file
    }
    fp=fopen("C:\\Users\\dell\\Documents\\c codes\\myfile1.txt","r+");// Open second file for writing the sorted numbers from array
      for(i=0;i<n;i++)
    {
        x=arr[i];

        fprintf(fp,"%d\n",x);
    }
    fclose(fp);//closing the second file
}
