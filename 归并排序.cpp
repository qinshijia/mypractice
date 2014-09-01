示例代码为C语言，输入参数中，需要排序的数组为array[],起始索引为first，终止索引为last。调用完成后，array[]中从first到last处于升序排列。
void merge_sort(int array[], unsigned int first, unsigned int last)
{
        int mid = 0;
        if(first<last)
        {
                /*mid = (first+last)/2;*/ /*注意防止溢出*/
                /*mid = first/2 + last/2;*/
                /*mid = （(first & last) + (first ^ last) >> 1);*/
                mid = ((first & last) + ((first ^ last) >> 1));    /*修正上一句优先级错误*/
                merge_sort(array, first, mid);
                merge_sort(array, mid+1,last);
                merge(array,first,mid,last);
        }
}
如果不使用递归，而是迭代，则C代码为：
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
