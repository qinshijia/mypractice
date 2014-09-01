BOOL QuickSort(U16*p,int num)
{
 int i;
 int n_small=1,n_big=num-1;//升序
 U16 m_key=p[0];
 BOOL xiaokong=true;//小头有空
 int m_free = 0;

 if(num<=1)return true;///递归终止条件
 for(i=0;i<num-1;i++)
 {
    if(xiaokong)//小头有空
    {
     if(p[n_big]<m_key)
     {
      p[m_free]=p[n_big];
      m_free=n_big;
      xiaokong=false;
     }
      n_big--;
    }
    else//大头有空
    {
     if(p[n_small]>m_key)
     {
      p[m_free]=p[n_small];
      m_free=n_small;
      xiaokong=true;
     }
      n_small++;
    }
 }
 if(m_free != 0)
 {
  p[m_free]=m_key;
 }
 //printf("num=%d[", num);
 //for( i = 0; i< num; i++) printf("%d,", p[i]);
 //printf("]key=%d, mid = %d, small=%d, big=%d, from %d num %d && from %d num %d\n",
 // m_key, m_free, n_small, n_big, 0,m_free, m_free+1, num-(m_free+1) );
 if(QuickSort(&p[0],m_free) && QuickSort(&p[m_free+1],num-(m_free+1) ) )
 {
    return true;
 }
 return false;
}


void QuickSortTest(void)
{
 int i;
 U16 sortTest[20] = {23,4,6,9,5,7,4,12,12,23,4,9999,89,1000,1000,4,2334,989,12,20};
 U16 sortTest2[10] = {10,9,8,7,6,5,4,3,2,1};
 U16 sortTest3[10] = {0,1,2,3,4,5,6,7,8,9};
 for( i = 0; i<20; i++) printf("%d，",sortTest[i]);  printf("\n");
 QuickSort( sortTest, 20);
 for( i = 0; i<20; i++) printf("%d，",sortTest[i]); printf("\n");

 for( i = 0; i<10; i++) printf("%d，",sortTest2[i]);  printf("\n");
 QuickSort( sortTest2, 10);
 for( i = 0; i<10; i++) printf("%d，",sortTest2[i]); printf("\n");

 for( i = 0; i<10; i++) printf("%d，",sortTest3[i]);  printf("\n");
 QuickSort( sortTest3, 10);
 for( i = 0; i<10; i++) printf("%d，",sortTest3[i]); printf("\n");
}
