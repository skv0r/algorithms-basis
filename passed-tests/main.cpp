#include <iostream>
#include <time.h>
#include <string>
#include <fstream>
using namespace std; // std не писать можно

int main()
{

    //Comment
    /*

    A lot of comments

    */
    setlocale(LC_ALL, "RU");

    int a;
    int b;
    //std::cin >> b; //ввод значений 

    a = 4;
    short num_32_32 = -123;
    unsigned long num0_2 = 12344123;
    float floated = 1.232f;
    double floated_x2 = 1.1234312f;
    char symbol = '&';
    bool isHappy = true;
    std::cout <<"Num b = "<< b << std::endl;
    std::cout << "Значение: "<< a << std::endl;
    std::cout << "Hello world!\n";
    std::cout << "Привет мир!" << std::endl;
    if (a > b) {
        std::cout << "a > b\n";
    }
    int num1;
    //std::cin >> num1;

    switch (num1){
        case 5: 
            std::cout << "Num1 = 5\n";
            break;
        case 0: 
            std::cout << "Num1 = ZeroBlock\n";
            break;
        default: 
            std::cout << "Num1 isn't num1\n";
    }

    srand(time(NULL));
    int result = 1 + rand() % 20; // 1-20 rand int

    for (int i = 0; i <= 5; i++) {
        cout <<"Num is "<< i << endl;
    }

    int j = 3;
    while (j != 0) {
        cout << "Wut = " << j << endl;
        j -= 1;
    }
    do {
        cout << j << endl;
        j = 0;
    } while (j > 5);

    int nums[3]; //creating massive
    nums[0] = 1; 
    nums[1] = -3; 
    nums[2] = 4; 
    cout << nums[1] << endl;
    float nums2[3] = {4,2,0};

    string s1 = "Valid Volume Andrew 22.2 asdhe";
    cout << s1.substr(1, 4) << endl;
    cout << s1.rfind("e") << endl;

}