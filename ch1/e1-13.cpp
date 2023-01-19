#include <iostream>

int main() {
    int sum = 0;
    for (int i = 50; i <= 100; i++) {
        sum += i;
    }
    std::cout << "sum of 50 to 100 is " << sum << std::endl;

    for (int i = 10; i>= 0; i-- ){
        std::cout << i << std::endl;
    }

    int v1, v2;
    std::cin >> v1 >> v2;

    if (v1 >= v2) {
        for (int j = v2; j<= v1; j++) {
            std::cout << j << std::endl;
        }
    } else
    {
        for (int j = v1; j<= v2; j++) {
            std::cout << j << std::endl;
        }
    }
    

}