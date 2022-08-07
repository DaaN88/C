#include <iostream>

int main()
{
    long long num;

    std::cout << "Enter number: " << std::endl;
    std::cin >> num;

    while (true) {
        std::cout << num << " ";

	if (num == 1) {
	    break;
	}

	if (num % 2 == 0) {
	    num /= 2;
	} else {
	    num = (num * 3) + 1;
	}

	std::cout << "\n" << std::endl;
    }
}
