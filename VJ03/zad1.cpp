#include <iostream>
#include <vector>
#include <algorithm>



void input_vector(std::vector<int>& v) {

	int unos;

	do
	{

		std::cout << "Unesite broj: ";
		std::cin >> unos;
		if (unos != 0) {
			v.push_back(unos);
		}

	} while (unos != 0);

	



}

void print_vector(const std::vector<int>& v) {

	for (int i = 0; i < v.size(); i++)
	{

		std::cout << v.at(i) << " ";

	}

}


int main() {

	std::vector<int> v;

	input_vector(v);
	print_vector(v);
	std::cout << "\nUnazada ispis:";
	for (auto it = v.rbegin(); it != v.rend(); ++it)
		std::cout << *it << " ";
	
	std::cout << "\n";

	std::vector<int> prazni;
	for (int i = 1; i < 20; ++i) {
		prazni.push_back(i);
		std::cout << prazni.size() << "/" << prazni.capacity() << " ";


	}

	std::vector<int> novi;
	
	novi.reserve(100);
	std::cout << "\n";

	novi.shrink_to_fit();

	std::cout << novi.capacity();
	








}