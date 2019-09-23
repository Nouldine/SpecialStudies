
#include "Sorting.hpp"

/****************************************************************************
 *
 *
 *      INSERTIONSORT PROCEDURES
 *
 *
 ****************************************************************************/                 
void Sorting::insertionSort( std::vector<int> & vec ) { 

	// std::cout << "Calling insertionSort( std::vector<int> & vec )" << std::endl; 
	
	// loop through the container to do the sorting
	// using the iterator library function begin
	// that is the first position in the vector
	// and end() the position of the last element
	// in the vector
	for( auto it = vec.begin() + 1; it != vec.end(); ++it ) { 

		value = *it;
		std::vector<int>::iterator index = it;

		// while the sorting part of the container is greater than
		// the element indexed by index swap the element until
		// we got a fully sorted container
		while( index > vec.begin() && *( index - 1 ) > value ) { 

			*index = *( index  - 1 );
			index = index - 1;
		}

		*index = value; // or insert the element directly at position index
	}
}

void Sorting::insertionSortHybrid( std::vector<int> & vec, int left, int right ) {

        //std::cout <<"Calling insertionSort( std::vector<int> & vec, int left, int right )" << std::endl;
        for( auto it = left + 1; it <= right; ++it ) {

                 value = vec[ it ];
                 int index = it;

                  while(  index > left && vec[ index - 1 ] > value ) {

                          vec[ index ] = vec[ index - 1 ];
                          index = index - 1;
                  }

                  vec[ index ] = value;
        }
}

/****************************************************************************
 *
 *
 *      MERGESORT PROCEDURES
 *
 *
 ****************************************************************************/


void Sorting::Merge(  std::vector<int> & main_vec, std::vector<int> & temp_vec, int left, int middle, int right ) { 

	// std::cout <<"Sorting::Merge( std::vector<int> & main_vec, std::vector<int> & left_vec, std::vector<int> &  right_vec )" << std::endl; 
	
	int left_end = middle - 1; 
	int tmp = left; 
	int num_elements = right - left + 1; 

	while( left <= left_end && middle <= right ) 
	{
		if( main_vec[ left ] <= main_vec[ middle ] )
			temp_vec[ tmp++ ] = std::move( main_vec[ left++ ] );
		
		else
			temp_vec[ tmp++ ] = std::move( main_vec[ middle++ ] ); 
	}

	// std::cout <<"Test 2 " << std::endl; 
	while( left <= left_end ) 
		temp_vec[ tmp++ ] = std::move( main_vec[ left++ ] ) ; 

	// std::cout <<"Test3 " << std::endl; 
	while( middle <= right )
		temp_vec[ tmp++ ] = std::move( main_vec[ middle++ ] );

	// std::cout <<"Test 4" << std::endl; 
	
	for( int iter = 0; iter < num_elements; ++iter, --right ) 
		main_vec[ right ] = std::move( temp_vec[ right ] );

}

void Sorting::mergeSort( std::vector<int> & my_vec, std::vector<int> & temp_vec, int left, int right ) { 

	/*
	if( left + 10 <= right ) { 

		int middle = ( left + right ) / 2; 
		mergeSort( my_vec, temp_vec, left, middle ); 
		mergeSort( my_vec, temp_vec, middle + 1, right );
		Merge( my_vec, temp_vec, left, middle + 1, right ); 
	} else 
		insertionSortHybrid( my_vec, left, right );
	*/

	if( left < right ) {

                int middle = ( left + right ) / 2;
                mergeSort( my_vec, temp_vec, left, middle );
                mergeSort( my_vec, temp_vec, middle + 1, right );
                Merge( my_vec, temp_vec, left, middle + 1, right );
        } 

}

void Sorting::mergeSortDriver( std::vector<int> & my_vec ) {

	// std::cout <<"void Sorting::mergeSortDriver( std::vector<int> & my_vec ) " << std::endl; 
	int left = 0;
	int right = my_vec.size() - 1;
	std::vector<int> temp_vec( my_vec.size() );
	mergeSort( my_vec, temp_vec, left, right );
}

/****************************************************************************
 *
 *	QUICKSORT WITH MEDIAN OF THREE
 *
 ****************************************************************************/ 									
int Sorting::medianOfThreePartition( std::vector<int> & my_vec, int left, int right ) {
 
	//std::cout <<"Calling int Sorting::medianOfThreePartition( std::vector<int> & my_vec, int left, int right )" << std::endl; 
	
	int middle = ( left + right ) / 2; 

	if( my_vec[ middle ] < my_vec[ left ] ) 
		
		std::swap( my_vec[ left ], my_vec[ middle ] );

	if( my_vec[ right ] < my_vec[ left ] )
		
		std::swap( my_vec[ left ], my_vec[ right ] );
	
	if( my_vec[ right ] < my_vec[ middle ] ) 

		std::swap( my_vec[ middle ], my_vec[ right ] );

	return my_vec[ middle ];
}

int Sorting::partition( std::vector<int> & my_vec, int left, int right, int pivot ) {

	// std::cout <<"Calling int Sorting::partition( std::vector<int> & my_vec, int left, int right, int pivot )" << std::endl;
	
	int pivotIndex = left;
	int partitionIndex = ( left - 1 );

	for( int k = left; k <= right; ++k ) {

		if( my_vec[ k ] == pivot )
			pivotIndex = k;
		 
		if( my_vec[ k ]  <= pivot )
			++partitionIndex;
	}

	std::swap( my_vec[ pivotIndex ], my_vec[ partitionIndex ] );
	int i = left;
	int j = right;

	while( i < j ) { 

		 while( i <= partitionIndex && my_vec[ i ] <= pivot ) ++i;

		 while( j > partitionIndex && my_vec[ j ] > pivot ) --j; 

		 if( i < j ) { 

			 std::swap( my_vec[ i ], my_vec[ j ] ); 
			 ++i; 
			 --j;
		 }
	}

	return partitionIndex;

}

void Sorting::quickSort( std::vector<int> & my_vec, int left, int right ) { 

	/*
	if( left + 10 <= right ) { 

		int pivot = medianOfThreePartition( my_vec, left, right );
		int partitionIndex = partition( my_vec, left, right, pivot ); 

		quickSort( my_vec, left, partitionIndex - 1 ); 
		quickSort( my_vec, partitionIndex + 1, right );
	} else
		insertionSortHybrid( my_vec, left, right );
	*/

	if( left <= right ) {

                int pivot = medianOfThreePartition( my_vec, left, right );
                int partitionIndex = partition( my_vec, left, right, pivot );
                quickSort( my_vec, left, partitionIndex - 1 );
                quickSort( my_vec, partitionIndex + 1, right );
        } 

}

void Sorting::QuickSortDriver( std::vector<int> & my_vec ) { 

	int left = 0;
	int right = my_vec.size() - 1;
	quickSort( my_vec, left, right );

}

/**********************************************************************************
 * 
 * QUICKSORT AND RANDONIZATION
 *
 ***********************************************************************************/

int Sorting::random_partition( std::vector<int> & my_vec, int left, int right ) {

	//std::cout <<"Calling int Sorting::random_partition( std::vector<int> & my_vec, int left, int right )" << std::endl;
	
	int my_pivot = my_vec[ right ];
	int partition_index = left - 1; 
	int my_index = right - 1;

	//std::cout <<"partition_index: "<< partition_index << std::endl;
		
	for(  int iter = left;  iter <= my_index; ++iter ) { 
		
		if( my_vec[ iter ] <= my_pivot ) {

		        //std::cout <<"Test 2" << std::endl;
			partition_index = partition_index + 1; 
			std::swap( my_vec[ partition_index ], my_vec[ iter ] );
		}
	}
 	//std::cout <<"Test 3" << std::endl;	
	std::swap( my_vec[ partition_index + 1 ], my_vec[ right ] );
	return ( partition_index + 1 );
}

int Sorting::randomized_partition( std::vector<int> & my_vec, int left, int right ) {

	//std::cout <<"Calling int Sorting:::randomized_partition( std::vector<int> & my_vec, int left, int right )" << std::endl;
	std::srand(time(nullptr));
	int rand_index = left  + rand() % ( right - left );
	std::swap( my_vec[ right ], my_vec[ rand_index ] );

	return random_partition( my_vec, left, right );
	
}

void Sorting::randomizedQuickSort( std::vector<int> & my_vec, int left, int right ) { 

	//std::cout <<"Calling void Sorting::randomizedQuickSort( std::vector<int> & my_vec, int left, int right )" << std::endl;
	if( left < right ) {

		int partionIndex = randomized_partition( my_vec, left, right );
		randomizedQuickSort( my_vec, left, partionIndex - 1 );
		randomizedQuickSort( my_vec, partionIndex + 1, right );
	}
}

void Sorting::RandomizedQuickSortDriver( std::vector<int> & my_vec ) { 

	//std::cout <<"Calling void Sorting::RandomizedQuickSortDriver( std::vector<int> & my_vec )" << std::endl;
	int left = 0; 
	int right = my_vec.size() - 1;
	randomizedQuickSort( my_vec, left, right );
}

/***************************************************************************
 *
 *  RADIX SORT
 *
 ***************************************************************************/

int Sorting::maxElement( std::vector<int> & my_vec ) { 

	int my_max =  0; 
	
	for( int i = 0; i < my_vec.size(); ++i ) {

		if( my_max < my_vec[ i ] )
			my_max = my_vec[ i ];
	}	

	return my_max;
}


void Sorting::radixSort( std::vector<int> & my_vec, int  vec_size ) { 

	 //std::cout <<"void Sorting::radixSort( std::vector<int> & my_vec, int vec_size ) " << std::endl;
	 std::vector<int>  output_vec(vec_size);
	 int maxElem =  maxElement( my_vec );
	 int i;

	 while( maxElem / numDigit  > 0 ) { 

		  std::vector<int> count(vec_count_size);
		  
		  for( i = 0; i < vec_size; ++i )
			  ++count[ ( my_vec[ i ] / numDigit ) % 10 ];

		  for( i = 1; i < vec_count_size; ++i )
			  count[ i ] += count[ i - 1 ];

		  for( i = vec_size - 1; i >= 0; --i )
		  {
			   output_vec[ count[ ( my_vec[ i ] / numDigit ) %  10 ] - 1 ] = my_vec[ i ];

	 		  //std::cout <<"test1 " << std::endl;
			   --count[ ( my_vec[ i ] / numDigit ) % 10 ];
		  }

		  for( i = 0; i < vec_size; ++i )
			  my_vec[ i ] =  output_vec[ i ];

		  numDigit *= vec_count_size;

	 }
}

void Sorting::radixSortDriver( std::vector<int> & my_vec ) { 

	int my_vec_size = my_vec.size();
	radixSort( my_vec, my_vec_size );
}



/***********************************************************************************
 *
 *	GET USER INPUT
 *
 ***********************************************************************************/

std::vector<int> Sorting::getInput( std::vector<int> & vec_num ) { 

	int maxrand;

	std::cout <<"Enter range of numbers: " << std::endl; 
	std::cin >> maxrand;

	for( int iter = 0; iter < maxrand; ++iter )
		vec_num.push_back( rand() % maxrand + 1 );
	
	//std::cout <<"UnSorted Array: " << std::endl;
	//printVector( vec_num );
	
	return vec_num;
}

void Sorting::printVector( std::vector<int> & my_vec ) { 

	for( auto content : my_vec )
		std::cout << content << " "; 
	std::cout << std::endl;
}



















