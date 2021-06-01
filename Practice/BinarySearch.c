#include <stdio.h>

int BinarySearchRecursion(int x, int begin, int end, int *ptr){
    
    int answer;
    
    if (begin > end) return -1;  // FALSE, 0
    
    int mid = (end + begin)/2;
    if (ptr[mid] < x) answer = BinarySearchRecursion(x, mid+1, end, ptr);
    else if (ptr[mid] > x) answer = BinarySearchRecursion(x, begin, mid-1, ptr);
    else return mid;    // TRUE, 1
    
    return answer;
    
}

int BinarySearch(int x, int begin, int end, int *ptr){
    
    int mid;
    
    while(begin <= end){
        mid = (end + begin)/2;
        if (ptr[mid] < x) begin = mid +1;
        else if (ptr[mid] > x) end = mid-1;  
        else return mid;    // TRUE, 1
    }
    
    return -1;  // FLASE, 0
}

int main()
{
    
    int arr[10] = {2,3,6,18,20,35,65,75,76,100};
    int ans;
    
    // Recursion
    ans = BinarySearchRecursion(2, 0, sizeof(arr)/sizeof(arr[0])-1, &arr[0]);
    printf("%d\n",ans);
    ans = BinarySearchRecursion(100, 0, sizeof(arr)/sizeof(arr[0])-1, &arr[0]);
    printf("%d\n",ans);  
    ans = BinarySearchRecursion(35, 0, sizeof(arr)/sizeof(arr[0])-1, &arr[0]);
    printf("%d\n",ans); 
    ans = BinarySearchRecursion(700, 0, sizeof(arr)/sizeof(arr[0])-1, &arr[0]);
    printf("%d\n",ans);
    
    // While Loop
    ans = BinarySearch(2, 0, sizeof(arr)/sizeof(arr[0])-1, &arr[0]);
    printf("%d\n",ans);
    ans = BinarySearch(100, 0, sizeof(arr)/sizeof(arr[0])-1, &arr[0]);
    printf("%d\n",ans);  
    ans = BinarySearch(35, 0, sizeof(arr)/sizeof(arr[0])-1, &arr[0]);
    printf("%d\n",ans);
    ans = BinarySearch(700, 0, sizeof(arr)/sizeof(arr[0])-1, &arr[0]);
    printf("%d\n",ans);
    
    return 0;
}
