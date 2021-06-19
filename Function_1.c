#include <stdio.h>
int numind(int n)
{
    int sum = 0;
    sum +=(n/1000)+((n%1000)/100)+((n%100)/10)+(n%10);
    return sum;
}
int main()
{
    int n,i,j,arr[100],arr_2[100],init_weight = 0,min,temp,pos,new_weight = 0,flag = 0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
        init_weight=init_weight+((i+1)*numind(arr[i]));
    }
    printf("Weight of given input sequence = %d\n",init_weight);
    for(i=0;i<n-1;i++)
    {min = arr[i];pos = i;
        for(j=i+1;j<n;j++)
        {
            if(arr[j]<=min)
            {
                min = arr[j];
                pos = j;
            }
            
        }
            temp = arr[i];
            arr[i] = arr[pos];
            arr[pos] = temp;
            new_weight = new_weight+((i+1)*(numind(arr[i])));
    }
    for(i=0;i<n;i++){arr_2[i]=arr[i];}
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if((((i+1)*numind(arr_2[i]))==((i+1)*numind(arr_2[j])))&&(arr_2[i]!=arr_2[j]))
            {
                temp = arr_2[i];
                arr_2[i] = arr_2[j];
                arr_2[j] = temp;flag=1;break;
            }
        }
        if(flag)break;
    }
    if(flag)for(i=0;i<n;i++){printf("%d ",arr_2[i]);}if(flag)printf("\n");
    for(i=0;i<n;i++){printf("%d ",arr[i]);}
    new_weight = new_weight+((n)*numind(arr[n-1]));
    printf("\nMaximum sequence weight = %d",new_weight);
	return 0;
}
