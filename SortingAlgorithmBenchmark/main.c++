
#include "Sorting.c++"

int main() {

        Sorting S;
	std::vector<int> vec_num;
	std::vector<int> test_vec_0 = S.getInput( vec_num );
	std::vector<int> test_vec_1 = test_vec_0;
	std::vector<int> test_vec_2 = test_vec_0;
	std::vector<int> test_vec_3 = test_vec_0;
	std::vector<int> test_vec_4 = test_vec_0;

	clock_t begin_0 = clock();
	S.insertionSort( test_vec_0 ); 
	clock_t end_0 = clock();
	
		
	//std::cout <<"InsertionSort Sorted array: "<< std::endl;
	//S.printVector( test_vec_0 ); 

	double duration_0 = double( end_0 - begin_0 ) / CLOCKS_PER_SEC;
        std::cout <<"Insertion Duration: " << duration_0 <<"ms"<< std::endl;
	std::cout << std::endl;

        clock_t begin_1 = clock();
	S.mergeSortDriver( test_vec_1 );
	clock_t end_1 = clock();

	
	//std::cout <<"Merge Sorted Array: " << std::endl;
	//S.printVector( test_vec_1 );

	double duration_1 = double( end_1 - begin_1 ) / CLOCKS_PER_SEC;
	std::cout <<"MergeSort Duration: " << duration_1 <<"ms"<< std::endl;
	std::cout << std::endl;
	
	clock_t begin_2 = clock();
	S.QuickSortDriver( test_vec_2 );
	clock_t end_2 = clock();

	std::cout << std::endl;

	
        //std::cout <<"QuickSort Sorted Array: " << std::endl;
	//S.printVector( test_vec_2 );
        
	double duration_2 = double( end_2 - begin_2 ) / CLOCKS_PER_SEC;
        std::cout <<"QuickSort Duration: " << duration_2 <<"ms"<< std::endl;

	std::cout << std::endl; 

 	clock_t begin_3 = clock();
	S.RandomizedQuickSortDriver( test_vec_3 ); 
	clock_t end_3 = clock();
	
	//std::cout <<"Randomized QuickSort Sorted Array: " << std::endl;
	//S.printVector( test_vec_3 );

	double duration_3 = double( end_3 - begin_3 ) / CLOCKS_PER_SEC;
	std::cout <<"Randomized QuickSort Duration: " << duration_3 <<"ms"<< std::endl; 

	std::cout << std::endl;

	clock_t begin_4 = clock();
	S.radixSortDriver( test_vec_4 ); 
	clock_t end_4 = clock();
	
	//std::cout <<"RadixSort Sorted Array: " << std::endl;
        //S.printVector( test_vec_4 );

	double duration_4 = double( end_4 - begin_4) / CLOCKS_PER_SEC;

	 std::cout <<"RadixSort Duration: " << duration_4 <<"ms" << std::endl;


        return 0;
}

