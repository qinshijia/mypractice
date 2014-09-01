ʾ������ΪC���ԣ���������У���Ҫ���������Ϊarray[],��ʼ����Ϊfirst����ֹ����Ϊlast��������ɺ�array[]�д�first��last�����������С�
void merge_sort(int array[], unsigned int first, unsigned int last)
{
        int mid = 0;
        if(first<last)
        {
                /*mid = (first+last)/2;*/ /*ע���ֹ���*/
                /*mid = first/2 + last/2;*/
                /*mid = ��(first & last) + (first ^ last) >> 1);*/
                mid = ((first & last) + ((first ^ last) >> 1));    /*������һ�����ȼ�����*/
                merge_sort(array, first, mid);
                merge_sort(array, mid+1,last);
                merge(array,first,mid,last);
        }
}
�����ʹ�õݹ飬���ǵ�������C����Ϊ��
void merge_sort(int *list, int length){
        int i, left_min, left_max, right_min, right_max, next;
        int *tmp = (int*)malloc(sizeof(int) * length);
        if (tmp == NULL){
                fputs("Error: out of memory\n", stderr);
                abort();
        }
        for (i = 1; i < length; i *= 2)
                for (left_min = 0; left_min < length - i; left_min = right_max){ 
                        right_min = left_max = left_min + i;
                        right_max = left_max + i;
                        if (right_max > length)
                                right_max = length;
                        next = 0;
                        while (left_min < left_max && right_min < right_max)
                                tmp[next++] = list[left_min] > list[right_min] ? list[right_min++] : list[left_min++];
                        while (left_min < left_max)
                                list[--right_min] = list[--left_max];
                        while (next > 0)
                                list[--right_min] = tmp[--next];
                }
        free(tmp);
}
