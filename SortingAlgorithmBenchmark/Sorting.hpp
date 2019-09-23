 
#ifndef SORTING_H
#define SORTING_H

#include <iostream>
#include <vector>
#include <iterator>
#include <random>
#include <ctime>

class Sorting {	

	public:
		
		/******************** INSERTION SORT ********************/
		void insertionSort( std::vector<int> & );
		void insertionSortHybrid( std::vector<int> &, int, int );

		/************** MERGE SORT ******************************/
		// function to merge subarrays
		void Merge( std::vector<int> &, std::vector<int> &, int, int, int ); 
		void mergeSort( std::vector<int> &, std::vector<int> &, int, int );
		void mergeSortDriver( std::vector<int> &  );
		

		/*************** QUICKSORT *******************************/
		int medianOfThreePartition( std::vector<int> &, int, int ); 
		int partition( std::vector<int> &, int, int, int ); 
		int select( std::vector<int> &, int, int, int );
	
		void quickSort( std::vector<int> &, int, int );	
		void QuickSortDriver( std::vector<int> & );
		void randomDriver( std::vector<int> & );
		void randomDriver_1( std::vector<int> & );
		int randomized_partition_1(  std::vector<int> &, int, int );
		void quickSortRandomized( std::vector<int> &, int, int );
		
		int random_partition( std::vector<int> &, int, int ); 
		int randomized_partition( std::vector<int> &, int, int );
		void randomizedQuickSort( std::vector<int> &, int, int );
		void RandomizedQuickSortDriver( std::vector<int> & );
	
		
		/********************* RADIX SORT **************************/ 

		int maxElement( std::vector<int> &  );
		void radixSort( std::vector<int> &, int );
		void radixSortDriver( std::vector<int> & );
		
		/**************** HELPER FUNCTIONS *************************/	
		std::vector<int> getInput( std::vector<int> & );
		void printVector( std::vector<int> & );

		/*************** DESTRUCTOR  ****************************/
			
		~Sorting() {}
		
	private: 
		int numDigit = 1;
		const int vec_count_size = 10;
		int value;

};


#endif
