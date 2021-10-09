#include "BaseArray.h"
template<class T>
class OrderedArray : public BaseArray<T>
{
public:
	bool isDuplicationAllow;
	OrderedArray(int size, int growBy = 2, bool allowDup=true) 
		//BaseArray<T>::m_array(NULL)//, BaseArray<T>::m_maxSize(0)
		//, BaseArray<T>::m_growSize(0), BaseArray<T>::m_numElements(0)
	{
		BaseArray<T>::SetSize(0);
		BaseArray<T>::SetMaxSize(0);
		BaseArray<T>::SetGrowSize(0);
		isDuplicationAllow = allowDup;
		if (size)	// Is this a legal size for an array?
		{
			//BaseArray<T>::m_maxSize = size;
			BaseArray<T>::SetMaxSize(size);
			BaseArray<T>::m_array = new T[BaseArray<T>::GetMaxSize()];		// Dynamically allocating an array to m_maxSize
			memset(BaseArray<T>::m_array, 0, sizeof(T) * BaseArray<T>::GetMaxSize());	// Explicitly set 0 to all elements in the array
			BaseArray<T>::SetGrowSize(((growBy > 0) ? growBy : 0));
			
		}
	}
	~OrderedArray<T>() {
		if (BaseArray<T>::m_array != nullptr)
		{
			delete[] BaseArray<T>::m_array;
			BaseArray<T>::m_array = nullptr;
		}
	}
	// Insertion -- Big-O = O(N)
	void push(T val)
	{
		assert(BaseArray<T>::m_array != nullptr);

		if (BaseArray<T>::GetSize() >= BaseArray<T>::GetMaxSize())
		{
			BaseArray<T>::Expand();
		}

		int i, k;	// i - Index to be inserted. k - Used for shifting purposes
		// Step 1: Find the index to insert val
		for (i = 0; i < BaseArray<T>::GetSize(); i++)
		{
			if (BaseArray<T>::m_array[i] == val && !isDuplicationAllow)
			{
				std::cout << "Duplication value is not allowed" << std::endl;
				return;
			}
			if (BaseArray<T>::m_array[i] > val)
			{
				break;
			}
		}

		// Step 2: Shift everything to the right of the index(i) forward by one. Work backwards
		for (k = BaseArray<T>::GetSize(); k > i; k--)
		{
			BaseArray<T>::m_array[k] = BaseArray<T>::m_array[k - 1];
		}

		// Step 3: Insert val into the array at index
		BaseArray<T>::m_array[i] = val;

		BaseArray<T>::IncreamentSize();

		// return i;
	}
	// Searching
	// Binary Search
	int search(T searchKey)
	{
		// Call to binary search recursive function
		// Binary Search: searchKey, initial lowerBound, initial upperBound
		return binarySearch(searchKey, 0, BaseArray<T>::GetSize() - 1);
	}

	// Recursive Binary Search
	int binarySearch(T searchKey, int lowerBound, int upperBound)
	{
		assert(BaseArray<T>::m_array != nullptr);
		assert(lowerBound >= 0);
		assert(upperBound < BaseArray<T>::GetSize());

		// Bitwise divide by 2
		int current = (lowerBound + upperBound) >> 1;

		// Check 1 "Base case": Did we find the searchKey at the current index?
		if (BaseArray<T>::m_array[current] == searchKey)
		{
			// We found it! Return the index
			return current;
		}
		// Check 2 "Base base": Are we done searching? 
		else if (lowerBound > upperBound)
		{
			// Did not find searchKey within m_array
			return -1;
		}
		// Check 3: Which half of the array is searchKey in?
		else
		{
			if (BaseArray<T>::m_array[current] < searchKey)
			{
				// Search the upper half of the array
				return binarySearch(searchKey, current + 1, upperBound);
			}
			else
			{
				// Search the lower half of the array
				return binarySearch(searchKey, lowerBound, current - 1);
			}
		}

		return -1;
	}

};
