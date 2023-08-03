#include <stdio.h>  
int main()  
{  
    int n, m, i, j, k;  
    n = 5;                        
    m = 3;                         
    int alloc[5][3] = {{0, 1, 0},   
                       {2, 0, 0},  
                       {3, 0, 2},  
                       {2, 1, 1},  
                       {0, 0, 2}}; 
  
    int max[5][3] = {{7, 5, 3},  
                     {3, 2, 2}, 
                     {9, 0, 2},  
                     {2, 2, 2}, 
                     {4, 3, 3}}; 
  
    int total_avail[3] = {10, 5, 7}; 

    int avail[3];
    
    int column_sum[3];
    
    for(int i=0;i<3;i++){
        int sum=0;
        for(int j=0;j<5;j++){
            sum+=alloc[j][i];
        }
        column_sum[i]=sum;
    }
    
    printf("Available is: ");
    
    for(int i=0;i<3;i++){
        avail[i]=total_avail[i]-column_sum[i];
        printf("%d ",avail[i]);
    }
    printf("\n");
    



    int f[n], ans[n], ind = 0;  
    for (k = 0; k < n; k++)  
    {  
        f[k] = 0;  
    }  
    int need[n][m];  
    for (i = 0; i < n; i++)  
    {  
        for (j = 0; j < m; j++)  
            need[i][j] = max[i][j] - alloc[i][j];  
    }  
    int y = 0;  
    for (k = 0; k < 5; k++)  
    {  
        for (i = 0; i < n; i++)  
        {  
            if (f[i] == 0)  
            {  
                int flag = 0;  
                for (j = 0; j < m; j++)  
                {  
                    if (need[i][j] > avail[j])  
                    {  
                        flag = 1;  
                        break;  
                    }  
                }  
                if (flag == 0)  
                {  
                    ans[ind++] = i;  
                    for (y = 0; y < m; y++)  
                        avail[y] += alloc[i][y];  
                    f[i] = 1;  
                }  
            }  
        }  
    } 



    int flag = 1;  
    for (int i = 0; i < n; i++)  
    {  
        if (f[i] == 0)  
        {  
            flag = 0;  
            printf("The following system is not safe\n");  
            break;  
        }  
    }  
    if (flag == 1)  
    {  
        printf("The Safe Sequence is : \n");  
        for (i = 0; i < n - 1; i++)  
            printf(" P%d ->", ans[i]);  
        printf(" P%d", ans[n - 1]);  
    }  
    printf("\n");


    int avail2[3] = {3, 3, 2}; 

    int request[3]={0,2,0};
    int flag2=1;
    for(int i=0;i<m;i++){
        if(request[i]>need[0][i]||request[i]>avail2[i]){
            flag2=0;
            break;
        
        }
    }

    if(flag2==0){
        printf("This request can't be granted \n");
    }
    
    else{
        printf("This request can be granted\n");
        for(int i=0;i<m;i++){    
            alloc[0][i]+=request[i];
            avail[i]-=request[i];
            
        }


    ind = 0;  
    for (k = 0; k < n; k++)  
    {  
        f[k] = 0;  
    }  
     
    for (i = 0; i < n; i++)  
    {  
        for (j = 0; j < m; j++)  
            need[i][j] = max[i][j] - alloc[i][j];  
    }  
     y = 0;  
    for (k = 0; k < 5; k++)  
    {  
        for (i = 0; i < n; i++)  
        {  
            if (f[i] == 0)  
            {  
                 flag = 0;  
                for (j = 0; j < m; j++)  
                {  
                    if (need[i][j] > avail[j])  
                    {  
                        flag = 1;  
                        break;  
                    }  
                }  
                if (flag == 0)  
                {  
                    ans[ind++] = i;  
                    for (y = 0; y < m; y++)  
                        avail[y] += alloc[i][y];  
                    f[i] = 1;  
                }  
            }  
        }  
    } 



    flag = 1;  
    for (int i = 0; i < n; i++)  
    {  
        if (f[i] == 0)  
        {  
            flag = 0;  
            printf("The following system is not safe\n");  
            break;  
        }  
    }  
    if (flag == 1)  
    {  
        printf("The Safe Sequence is : \n");  
        for (i = 0; i < n - 1; i++)  
            printf(" P%d ->", ans[i]+1);  
        printf(" P%d", ans[n - 1]+1);  
    }  
    printf("\n");  
        
    }

     return (0);  
}  
