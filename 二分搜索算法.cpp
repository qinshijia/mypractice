
int search(int array[], int n, int v)
{
    int left, right, middle;

    left = 0, right = n - 1;

    while (left <= right)
    {
        middle = (left + right) / 2;
        if (array[middle] > v)
        {
            right = middle - 1;
        }
        else if (array[middle] < v)
        {
            left = middle + 1;
        }
        else
        {
            return middle;
        }
    }

    return -1;
}

int search_recurse(int array[], int low, int high, int v)
{
    int middle;

    middle = (low + high) / 2;

    if (low < high)
    {
        if (array[middle] > v)
        {
            return search_recurse(array, low, middle, v);
        }
        else if (array[middle] < v)
        {
            return search_recurse(array, middle + 1, high, v);
        }
        else
        {
            return middle;
        }
    }
    else if (low == high)
    {
        if (array[middle] == v)
        {
            return middle;
        }
        else
        {
            return -1;
        }

    }
    else
    {
        return -1;
    }

    return -1;
}

int main()
{
    int array[] = {0, 1, 2, 3, 4, 5, 6, 7, 13, 19};

    int m = search(array, sizeof(array)/sizeof(array[0]), 13);

    printf("m = %d\n", m);

    m = search_recurse(array, 0, sizeof(array)/sizeof(array[0]), 13);

    printf("m = %d\n", m);

    return 0;
}
