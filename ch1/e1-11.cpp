#include <iostream>

int main() {
    int v1, v2;
    std::cin >> v1 >> v2;

    int i = v1;
    while (i >= v1 and i <= v2) {
        std::cout << i << std::endl;
        i++;
    }
    return 0;
}