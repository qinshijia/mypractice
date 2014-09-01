#include<stdio.h>
#include<stdlib.h>


int swap(int a[], int i, int j) {  
        int t = a[i];  
        a[i] = a[j];  
        a[j] = t;  
  
        return 0;  
}  

int partition(int a[], int low, int high) {  
        int x = a[low];  
        int m = low;  
        int i;  
        for (i = low + 1; i <= high; i++) {  
                if (a[i] < x) {  
                        swap(a, ++m, i);  
                }  
        }  
        swap(a, low, m);  
  
        return m;  
}  

int selection(int a[], int left, int right, int k) {   
        if (left > right || (k - 1) > right - left) {  
                return -1;  
        }  
  
        if (left == right) {  
                return a[left];  
        }  
  
        int mid = partition(a, left, right);    
        int len = mid - left;  
        if ((k - 1) == len) {  
                return a[mid];  
        } else if ((k - 1) < len) {                    //要找的数在左集合中  
                return selection(a, left, mid - 1, k);  
        } else {                                       // 要找的数在右集合中 
                return selection(a, mid + 1, right, k - len - 1);  
        }  
}  

int main()  
{  
        int a[100000];  
        long k;  
        long i;
        FILE *fp;
        fp1=fopen("a.txt","r");
        for(i=0;i<100000;i++)  fscanf(fp,"%d",&a[i]);
        printf("Please input k: ");  
        scanf("%d",&k);  
        printf("%d",selection(a, 0, 6, k));  
        fclose(fp);
        system("pause");
        return 0;  
} 
