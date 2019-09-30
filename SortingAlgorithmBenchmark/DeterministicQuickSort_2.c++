// medofmedv2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <unordered_set>
#include <random>
#include <chrono>
#include<fstream>
#include <string>
#include <climits>
using namespace std;


// Function to swap 
void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

// Function to partition around a pivot and return the new pivot location
int partition(vector<int>& A, int left, int right, int pivot) {

	int i;
	for (i = left; i <= right; i++) {
			if (A[i] == pivot) {
				break;
			}

		}

	swap(&A[i], &A[right]);

	int pivot_val = A[right];
	int j = left;
	for (int i = left; i <= right - 1; i++) {
		if (A[i] < pivot_val) {
			swap(&A[i], &A[j]);
			j++;
		}
	}

	swap(&A[j], &A[right]);

	return j;

}

int findMedian(vector<int> arr, int start, int end, int n)
{
	int i, key, j;
	for (int i = start + 1; i <= end; i++) {
		key = arr[i];
		j = i - 1;

		while (j >= start && arr[j] > key) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}

		arr[j + 1] = key;
	}

	return arr[start + n / 2];
}

int SelectionWithMedianOfMedian(vector<int>& A, int left, int right, int k) {

	int n = right - left + 1; // Number of elements in arr[l..r]
	if (left == right) return A[left];
	/*else if (n < 5) return findMedian(A, left, right, n);*/

	// If k is smaller than number of elements in array
	if (k > 0 && k <= right - left + 1)
	{
		//int n = right - left + 1; // Number of elements in arr[l..r]
		// Divide arr[] in groups of size 5, calculate median
		// of every group and store it in median[] array.

		int size = n / 5;

		if (size * 5 < n)
			size++;

		int i = 0;
		vector<int> median(size); // There will be floor((n+4)/5) groups;
		if (n >= 5) {
			for (i = 0; i < n / 5; i++) {
				median[i] = findMedian(A, i * 5 + left, i * 5 + 4 + left, 5);

			}
		}

		if (i * 5 < n) //For last group with less than 5 elements
		{
			median[i] = findMedian(A, i * 5 + left, (i * 5 + left) + (n % 5 - 1), n % 5);
			i++;
		}


		// Find median of all medians using recursive call.
		// If median[] has only one element, then no need
		// of recursive call

		int medOfMed = (size <= 2) ? median[0] :
			SelectionWithMedianOfMedian(median, 0, size - 1, size / 2);

		// Partition the array around a random element and
		// get position of pivot element in sorted array


		/*
		int s = 0;

		for (int i = left; i <= right; i++) {
			if (A[i] == medOfMed) {
				s = i;
				break;
			}

		}
		*/

		int pos = partition(A, left, right, medOfMed );


		// If position is same as k
		if (pos - left == k - 1)
			return A[pos];
		else if (pos - left > k - 1) {  // If position is more, recur for left
			//cout << "pos - " << pos - left << " and k " << k - 1 << "LEFT"<<endl;
			return SelectionWithMedianOfMedian(A, left, pos - 1, k);

		}

		// Else recur for right subarray
		else {

			return SelectionWithMedianOfMedian(A, pos + 1, right, k - pos + left - 1);
		}



	}

	// If k is more than number of elements in array
	return INT_MAX;

}

void quickSortDeterministic( std::vector<int> & my_vec, int left, int right ) {

        //std::cout <<"Calling void Sorting::quickSortDeterministic( std::vector<int> & my_vec, int left, int right )" << std::endl;

        if( left < right ) {

                int k_index = ( right - left + 1 );
		
                //std::cout <<"Test1 " << std::endl;
                int my_index = SelectionWithMedianOfMedian( my_vec, left, right,  k_index / 2 );
                //std::cout <<"Test2 " << std::endl;
                int partition_index = partition( my_vec, left, right, my_index );

                //std::cout <<"My Beautiful test " << std::endl;
                quickSortDeterministic( my_vec, left, partition_index - 1 );
                quickSortDeterministic( my_vec, partition_index + 1, right );

        }
}

void quickSortDeterministicDriver( std::vector<int> & my_vec ) {

        int left = 0;
        int right = my_vec.size() - 1;
        quickSortDeterministic( my_vec, left, right );

}

void printVector( std::vector<int> & my_vec ) {

        for( auto content : my_vec )
                std::cout << content << " ";
        std::cout << std::endl;
}

std::vector<int>  getInput( std::vector<int> & vec_num ) {

        int maxrand;
        std::cout <<"Enter range of numbers: " << std::endl;
        std::cin >> maxrand;

        for( int iter = 0; iter < maxrand; ++iter )
                vec_num.push_back( rand() % maxrand + 1 );

         //std::cout <<"UnSorted Array: " << std::endl;
         //printVector( vec_num );

        return vec_num;
}


/*

int main() {

       
        std::vector<int> vec_num;
        std::vector<int> test_vec = getInput( vec_num );


        clock_t begin_0 = clock();
        quickSortDeterministicDriver( test_vec );
        clock_t end_0 = clock();

        //std::cout <<"Result: " << std::endl;
        //printVector( test_vec );

        double duration_0 = double( end_0 - begin_0 ) / CLOCKS_PER_SEC;
        std::cout <<"Deterministic QuickSort: " << duration_0 <<"ms"<< std::endl;
        std::cout << std::endl;

        return 0;
}
*/
