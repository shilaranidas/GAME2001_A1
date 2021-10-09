#include "BaseArray.h"
template<class T>
class UnorderedArray: public BaseArray<T>
{
public:
	UnorderedArray<T>(int size, int growBy = 1)
	{
		BaseArray<T>(size, growBy);
	}
	~UnorderedArray<T>() {
		~BaseArray<T>();
	}
	// Insertion
	// Fast insertion for UnorderedArray -- Big-O is O(1)
	void push(T val)
	{
		assert(BaseArray<T>::m_array != nullptr); // Debugging purposes

		if (BaseArray<T>::m_numElements >= BaseArray<T>::m_maxSize)	// Check if the array has to expand to accommodate the new data.
		{
			BaseArray<T>::Expand();
		}

		// My array has space for a new value. Let's add it!
		BaseArray<T>::m_array[BaseArray<T>::m_numElements] = val;
		BaseArray<T>::m_numElements++;
	}
	// Searching
	// Linear Search
	int search(T val)
	{
		assert(BaseArray<T>::m_array != nullptr);

		// Brute-force Search
		for (int i = 0; i < BaseArray<T>::m_numElements; i++)
		{
			if (BaseArray<T>::m_array[i] == val)
			{
				return i;	// Return the index of where the item is located in the array
			}
		}

		return -1;
	}
	// ---------------- SORTING ALGORITHMS --------------------------------
	// Bubble Sort -- Big O = O(N^2)
	void BubbleSort()
	{
		assert(BaseArray<T>::m_array != nullptr);

		T temp;

		for (int k = BaseArray<T>::m_numElements - 1; k > 0; k--)	// Start at the end of the array and move backwards
		{
			for (int i = 0; i < k; i++)	 // Compare elements until k is reached
			{
				// Compare 2 adjacent elements
				if (BaseArray<T>::m_array[i] > BaseArray<T>::m_array[i + 1])
				{
					// Swap the elements
					temp = BaseArray<T>::m_array[i];
					BaseArray<T>::m_array[i] = BaseArray<T>::m_array[i + 1];
					BaseArray<T>::m_array[i + 1] = temp;
				}
			}
		}
	}
	// Selection Sort -- Big O = O(N^2)
	void SelectionSort()
	{
		assert(BaseArray<T>::m_array != nullptr);

		T temp;	// Swapping
		int min = 0;	// Hold the index of the current smallest value

		// The lowest position to swap elements into
		for (int k = 0; k < BaseArray<T>::m_numElements; k++)
		{
			min = k;	// Set the value at index k as a "default" minimum value

			// Iterate through the array to find smallest value, if there is one.
			for (int i = k + 1; i < BaseArray<T>::m_numElements; i++)
			{
				// Compare the value at the current index vs the current "min" index
				if (BaseArray<T>::m_array[i] < BaseArray<T>::m_array[min])
				{
					// Store the index to the smallest element
					min = i;
				}
			}

			// Swap the lowest element with the lowest available index
			if (BaseArray<T>::m_array[k] > BaseArray<T>::m_array[min])
			{
				// Swap
				temp = BaseArray<T>::m_array[k];
				BaseArray<T>::m_array[k] = BaseArray<T>::m_array[min];
				BaseArray<T>::m_array[min] = temp;
			}
		}
	}
	// Insertion Sort -- Big O = O(N^2)
	void InsertionSort()
	{
		assert(BaseArray<T>::m_array != nullptr);

		T temp;
		int i = 0;

		for (int k = 1; k < BaseArray<T>::m_numElements; k++) // Iterate through all elements to be sorted.
		{
			temp = BaseArray<T>::m_array[k];
			i = k;

			// Shifting of elements if necessary. Create a space for an elements
			// to be inserted in the correct location.
			while (i > 0 && BaseArray<T>::m_array[i - 1] >= temp)
			{
				// Push elements to the right
				BaseArray<T>::m_array[i] = BaseArray<T>::m_array[i - 1];
				i--;
			}

			// Place the item in temp into the correct location
			BaseArray<T>::m_array[i] = temp;
		}
	}
	// Merge Srot -- Big O = O(N logN)
	void MergeSort()
	{
		assert(BaseArray<T>::m_array != nullptr);

		T* tempArray = new T[BaseArray<T>::m_numElements];
		assert(tempArray != nullptr);

		MergeSort(tempArray, 0, BaseArray<T>::m_numElements - 1);
		delete[] tempArray;
	}
private:
	// Recursive Merge Sort
void MergeSort(T* tempArray, int lowerBound, int upperBound)
{
	// Base case
	if (lowerBound == upperBound)
	{
		return;
	}

	// Determine the middle of the array
	int mid = (lowerBound + upperBound) >> 1;

	MergeSort(tempArray, lowerBound, mid);	// Mergesort the lower half of the array
	MergeSort(tempArray, mid + 1, upperBound); // Mergesort the upper half of the array

	// Merge
	Merge(tempArray, lowerBound, mid + 1, upperBound);
}
void Merge(T* tempArray, int low, int mid, int upper)
{
	// Lowerbound, Mid+1, Upperbound
	int tempLow = low, tempMid = mid - 1;
	int index = 0;

	while (low <= tempMid && mid <= upper)
	{
		// Which of the 2 values is smaller then move it into the temp array
		if (BaseArray<T>::m_array[low] < BaseArray<T>::m_array[mid])
		{
			tempArray[index++] = BaseArray<T>::m_array[low++];	// Left half lower value is the lowest
		}
		else
		{
			tempArray[index++] = BaseArray<T>::m_array[mid++];	// Right half lower value is the lowest.
		}
	}

	while (low <= tempMid) // Clean up lower half
	{
		tempArray[index++] = BaseArray<T>::m_array[low++];
	}
	while (mid <= upper) // Clean up upper half
	{
		tempArray[index++] = BaseArray<T>::m_array[mid++];
	}

	// Place the stored tempArray into the main array in the correct locations
	for (int i = 0; i < upper - tempLow + 1; i++)
	{
		BaseArray<T>::m_array[tempLow + i] = tempArray[i];
	}
}

};
