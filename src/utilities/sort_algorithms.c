void merge(int *array, int left, int right){
    int middle = (left + right) / 2;

    int leftSize = middle - left + 1;;
    int rightSize = right - middle;

    int leftArray[leftSize];
    int rightArray[rightSize];

    for (int i = 0; i < leftSize; i++){
        leftArray[i] = array[left + i];
    }
    for (int i = 0; i < rightSize; i++){
        rightArray[i] = array[middle + 1 + i];
    }
    

    int i, j, k;
    i = j = 0;
    k = left;
    while (i < leftSize && j < rightSize){
        if (leftArray[i] < rightArray[j]){
            array[k] = leftArray[i];
            i++;
        }
        else{
            array[k] = rightArray[j];
            j++;
        }
        k++;
    }

    while (i < leftSize){
        array[k] = leftArray[i];
        i++;
        k++;
    }

    while (j < rightSize){
        array[k] = rightArray[j];
        j++;
        k++;
    }
}

void MergeSort(int *array, int left, int right){
    if (left < right){
        int middle = (left + right) / 2;

        MergeSort(array, left, middle);
        MergeSort(array, middle + 1, right);

        merge(array, left, right);
    }
}
