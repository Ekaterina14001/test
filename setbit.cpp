
#include <iostream>
#include <vector>
#include <algorithm>

void printBit(int num)
{
	std::vector <bool> Bit;
	while (num > 1)
	{
		Bit.push_back(num % 2);
		num = num / 2;
	}
	Bit.push_back(num);
	std::reverse(Bit.begin(), Bit.end());

	for (auto it = Bit.begin(); it != Bit.end(); it++)
		std::cout << *it;
	
}

int main()
{
    int num=123;
	printBit(num);

}

// Соколенко Екатерина Романовна
// 26.04.2023 30 мин
