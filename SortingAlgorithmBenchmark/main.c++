
#include "Sorting.c++"
#include "DeterministicQuickSort_2.c++"

int main() {

        Sorting S;
	std::vector<int> vec_num;
	std::vector<int> test_vec_0 = S.getInput( vec_num );
	std::vector<int> test_vec_1 = test_vec_0;
	std::vector<int> test_vec_2 = test_vec_0;
	std::vector<int> test_vec_3 = test_vec_0;
	std::vector<int> test_vec_4 = test_vec_0;
	std::vector<int> test_vec_5 = test_vec_0;
	std::vector<int> test_vec_6 = test_vec_0;

		
	clock_t begin_0 = clock();
	S.insertionSort( test_vec_0 ); 
	clock_t end_0 = clock();
	
	//std::cout <<"InsertionSort Sorted array: "<< std::endl;
	//S.printVector( test_vec_0 ); 

	double duration_0 = double( end_0 - begin_0 ) / CLOCKS_PER_SEC;
        std::cout <<"Insertion Duration: " << duration_0 <<"s"<< std::endl;
	std::cout << std::endl;
	
        clock_t begin_1 = clock();
	S.mergeSortDriver( test_vec_1 );
	clock_t end_1 = clock();
	
	
	//std::cout <<"Merge Sorted Array: " << std::endl;
	//S.printVector( test_vec_1 );

	double duration_1 = double( end_1 - begin_1 ) / CLOCKS_PER_SEC;
	std::cout <<"MergeSort Duration: " << duration_1 <<"s"<< std::endl;
	std::cout << std::endl;
	
	clock_t begin_2 = clock();
	S.QuickSortDriver( test_vec_2 );
	clock_t end_2 = clock();

	std::cout << std::endl;
	
        //std::cout <<"QuickSort Sorted Array: " << std::endl;
	//S.printVector( test_vec_2 );
        
	double duration_2 = double( end_2 - begin_2 ) / CLOCKS_PER_SEC;
        std::cout <<"QuickSort Duration Median of Three: " << duration_2 <<"s"<< std::endl;

	std::cout << std::endl; 

 	clock_t begin_3 = clock();
	S.RandomizedQuickSortDriver( test_vec_3 ); 
	clock_t end_3 = clock();
	
	//std::cout <<"Randomized QuickSort Sorted Array: " << std::endl;
	//S.printVector( test_vec_3 );

	double duration_3 = double( end_3 - begin_3 ) / CLOCKS_PER_SEC;
	std::cout <<"Randomized QuickSort Duration: " << duration_3 <<"s"<< std::endl; 
	std::cout << std::endl;

	
	
	clock_t begin_6 = clock();
        quickSortDeterministicDriver( test_vec_6 );
        clock_t end_6 = clock();
	
        //std::cout <<"Deterministic QuickSort Sorted Array: " << std::endl;
        //S.printVector( test_vec_6 );

         double duration_6 = double( end_6 - begin_6 ) / CLOCKS_PER_SEC;
         std::cout <<"Deterministic QuickSort Duration: " << duration_6 <<"s"<< std::endl;
	
        std::cout << std::endl;

	clock_t begin_4 = clock();
	S.radixSortDriver( test_vec_4 ); 
	clock_t end_4 = clock();
	
	//std::cout <<"RadixSort Sorted Array: " << std::endl;
        //S.printVector( test_vec_4 );

	double duration_4 = double( end_4 - begin_4) / CLOCKS_PER_SEC;

	std::cout <<"RadixSort Duration: " << duration_4 <<"s" << std::endl;

	std::cout << std::endl;

        clock_t begin_5 = clock();
        S.radixSortDiver_1( test_vec_5 );
        clock_t end_5 = clock();

	/*
        std::cout <<"RadixSort Version2 Sorted Array: " << std::endl;
        S.printVector( test_vec_5 );
	*/

        double duration_5 = double( end_5 - begin_5 ) / CLOCKS_PER_SEC;
        std::cout <<"RadixSort version_2 Duration: " << duration_5 <<"s" << std::endl;

        return 0;
}

