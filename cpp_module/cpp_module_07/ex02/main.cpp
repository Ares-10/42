#include <iostream>
#include "Array.hpp"

int main()
{
    try {
        std::cout << "=== 기본 생성자 테스트 ===" << std::endl;
        Array<int> arr1;
        std::cout << "Size of arr1: " << arr1.size() << std::endl;

        std::cout << "\n=== 파라미터 생성자 테스트 ===" << std::endl;
        Array<int> arr2(5);
        std::cout << "Size of arr2: " << arr2.size() << std::endl;

        for (unsigned int i = 0; i < arr2.size(); i++)
            arr2[i] = i * 2;

        std::cout << "arr2 values: ";
        for (unsigned int i = 0; i < arr2.size(); i++)
            std::cout << arr2[i] << " ";
        std::cout << std::endl;

        std::cout << "\n=== 복사 생성자 테스 ===" << std::endl;
        Array<int> arr3(arr2);
        std::cout << "arr3 values: ";
        for (unsigned int i = 0; i < arr3.size(); i++)
            std::cout << arr3[i] << " ";
        std::cout << std::endl;

        std::cout << "\n=== 대입 연산자 테스트 ===" << std::endl;
        Array<int> arr4(3);
        arr4 = arr2;
        std::cout << "arr4 values: ";
        for (unsigned int i = 0; i < arr4.size(); i++)
            std::cout << arr4[i] << " ";
        std::cout << std::endl;

        std::cout << "\n=== 범위 초과 테스트 ===" << std::endl;
        std::cout << "index 5:" << std::endl;
        arr2[5];
    }
    catch (const std::exception& e) {
        std::cout << "예외 발생: " << e.what() << std::endl;
    }

    std::cout << "\n=== double 테스트 ===" << std::endl;
    Array<double> arr5(3);
    arr5[0] = 1.1;
    arr5[1] = 2.2;
    arr5[2] = 3.3;

    std::cout << "arr5 values: ";
    for (unsigned int i = 0; i < arr5.size(); i++)
        std::cout << arr5[i] << " ";
    std::cout << std::endl;
}