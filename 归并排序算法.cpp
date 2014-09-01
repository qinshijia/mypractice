�鲢�����ǽ����ڹ鲢�����ϵ�һ����Ч�������㷨�����㷨�ǲ��÷��η���Divide and Conquer����һ���ǳ����͵�Ӧ�á�

���ȿ�������ν��������������кϲ�������ǳ��򵥣�ֻҪ�ӱȽ϶������еĵ�һ������˭С����ȡ˭��ȡ�˺���ڶ�Ӧ������ɾ���������Ȼ���ٽ��бȽϣ����������Ϊ�գ���ֱ�ӽ���һ�����е���������ȡ�����ɡ�

[cpp] view plaincopy
//����������a[]��b[]�ϲ���c[]��  
void MemeryArray(int a[], int n, int b[], int m, int c[])  
{  
    int i, j, k;  
  
    i = j = k = 0;  
    while (i < n && j < m)  
    {  
        if (a[i] < b[j])  
            c[k++] = a[i++];  
        else  
            c[k++] = b[j++];   
    }  
  
    while (i < n)  
        c[k++] = a[i++];  
  
    while (j < m)  
        c[k++] = b[j++];  
}  
���Կ����ϲ��������е�Ч���ǱȽϸߵģ����ԴﵽO(n)��

���������ĺϲ������������⣬�������鲢������Ļ���˼·���ǽ�����ֳɶ���A��B�������������ڵ����ݶ�������ģ���ô�Ϳ��Ժܷ���Ľ���������ݽ������������������������������ˣ�

���Խ�A��B������ٷֳɶ��顣�������ƣ����ֳ�����С��ֻ��һ������ʱ��������Ϊ���С�������Ѿ��ﵽ������Ȼ���ٺϲ����ڵĶ���С��Ϳ����ˡ�����ͨ���ȵݹ�ķֽ����У��ٺϲ����о�����˹鲢����

[cpp] view plaincopy
//���ж�����������a[first...mid]��a[mid...last]�ϲ���  
void mergearray(int a[], int first, int mid, int last, int temp[])  
{  
    int i = first, j = mid + 1;  
    int m = mid,   n = last;  
    int k = 0;  
      
    while (i <= m && j <= n)  
    {  
        if (a[i] <= a[j])  
            temp[k++] = a[i++];  
        else  
            temp[k++] = a[j++];  
    }  
      
    while (i <= m)  
        temp[k++] = a[i++];  
      
    while (j <= n)  
        temp[k++] = a[j++];  
      
    for (i = 0; i < k; i++)  
        a[first + i] = temp[i];  
}  
void mergesort(int a[], int first, int last, int temp[])  
{  
    if (first < last)  
    {  
        int mid = (first + last) / 2;  
        mergesort(a, first, mid, temp);    //�������  
        mergesort(a, mid + 1, last, temp); //�ұ�����  
        mergearray(a, first, mid, last, temp); //�ٽ������������кϲ�  
    }  
}  
  
bool MergeSort(int a[], int n)  
{  
    int *p = new int[n];  
    if (p == NULL)  
        return false;  
    mergesort(a, 0, n - 1, p);  
    delete[] p;  
    return true;  
}  
 

�鲢�����Ч���ǱȽϸߵģ������г�ΪN�������зֿ���С����һ��ҪlogN����ÿ������һ���ϲ��������еĹ��̣�ʱ�临�Ӷȿ��Լ�ΪO(N)����һ��ΪO(N*logN)����Ϊ�鲢����ÿ�ζ��������ڵ������н��в��������Թ鲢������O(N*logN)�ļ������򷽷����������򣬹鲢����ϣ�����򣬶�����Ҳ��Ч�ʱȽϸߵġ�

 

�ڱ��˵����϶�ð������ֱ�Ӳ������򣬹鲢����ֱ��ʹ��ϵͳ��qsort()���бȽϣ�����Release�汾�£�

��20000��������ݽ��в��ԣ�



��50000��������ݽ��в��ԣ�



�ٶ�200000��������ݽ��в��ԣ�



 

ע���е���������mergearray()�ϲ���������ʱ������ʱ���飬���ǹ����new������ǳ���ʱ�����������СС�ı仯��ֻ��MergeSort()��newһ����ʱ���顣����Ĳ�����������һ����ʱ���顣
