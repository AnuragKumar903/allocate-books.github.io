#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

int countStudents(int arr[],int n, int pages){
  
  int student = 1;
  int pagestudent = 0;
  for(int  i = 0; i < n; i++){
    if (pagestudent + arr[i] <= pages){
      pagestudent += arr[i];
    }
    else{
      student++;
      pagestudent = arr[i];
    }
  }
  return student;
}

int findPages(int arr[], int n, int m){
  if (m >= n) return -1;
  int low = *max_element(arr, arr+n);
  int high = accumulate(arr, arr+n, 0);
  while(low <= high){
    int mid = low + (high - low) / 2;
    int student = countStudents(arr,n, mid);
    if (student > m){
      low = mid + 1;
    }
    else high = mid - 1;
  }
  return low;
}

int main() {
  int nums[5] = {25, 46, 28, 49, 24};
  int no_student = 4; 
  cout<<"The minimum no of possible pages is : "<<findPages(nums, 5, no_student)<<endl;

  int nums2[4] = {10, 20, 30, 40};
  int no_student2 = 2;
  cout<<"The minimum no of possible pages is : "<<findPages(nums2, 4, no_student2)<<endl;
}  