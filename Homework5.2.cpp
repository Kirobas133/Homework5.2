#include <iostream>

class smart_array {
private:
	int* array;
	int arraysize;
	int elementcounts;

public:
	smart_array(int elems) {
		elementcounts = 0;
		array = new int[elems];
		arraysize = elems;
	}
	~smart_array() {
		delete[] array;
	}
	void add_element(int elem) {
		if (elementcounts < arraysize) {
			array[elementcounts] = elem;
		}
		else {
			std::cout << "Warning! You have exceeded the size of the array, the size of the array has been doubled!\n";
			arraysize *= 2;
			int* temp = array;
			array = new int[arraysize];
			for (int i = 0; i < (arraysize / 2); i++) {
				array[i] = temp[i];
			}
			delete[] temp;
			array[elementcounts] = elem;
		}
		elementcounts++;
	}
	int get_element(int indx) {
		if (indx < arraysize) {
			return array[indx];
		}
		else {
			throw ("Empty index");
		}
	}
	smart_array operator = (smart_array sa) {
		int* temp = array;
		array = new int[sa.arraysize];
		arraysize = sa.arraysize;
		elementcounts = sa.elementcounts;
		for (int i = 0; i < arraysize; i++) {
			array[i] = sa.array[i];
		}
		delete[] temp;
	}
};


int main()
{

	try {
		smart_array arr(5);
		arr.add_element(1);
		arr.add_element(4);
		arr.add_element(155);
		arr.add_element(14);
		arr.add_element(15);
		arr.add_element(17);
		std::cout << arr.get_element(5) << std::endl;
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}
}