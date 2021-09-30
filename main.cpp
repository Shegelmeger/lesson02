#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <string_view>
#include <fstream>
#include "Timer.h"

//Exercise 2.1

template <typename T>
void Swap(T*& p1, T*& p2)
{
    T* temp = p1;
    p1 = p2;
    p2 = temp;
}

//Exercise 2.2

template <typename T>
void Sort(std::vector<T*>& numbers)
{
    std::sort(numbers.begin(), numbers.end(), [](auto i1, auto i2) {
        return *i1 < *i2;
    });
}


//Exercise 2.3


size_t CountIfFind(std::string_view text, std::string_view find)
{
    return std::count_if(text.begin(), text.end(), [&](auto c) {
        return find.find(c) != std::string::npos;
    });
}

size_t CountIfFor(std::string_view text, std::string_view find)
{
    return std::count_if(text.begin(), text.end(), [&](auto c) {
        for (size_t i = 0; i < find.size() ; ++i)
        {
            if (c == find[i])
                return true;
        }
        return false;
    });
}

size_t ForFind(std::string_view text, std::string_view find)
{
    size_t count = 0;
    for (size_t i = 0; i < text.size(); ++i)
    {
        if (find.find(text[i]) != std::string::npos)
            count++;
    }
    return count;
}

size_t ForFor(std::string_view text, std::string_view find)
{
    size_t count = 0;
    for (size_t i = 0; i < text.size(); i++)
    {
        for (size_t j = 0; j < find.size(); j++)
        {
            if (text[i] == find[j])
            {
                count++;
                break;
            }
        }
    }
    return count;
}


int main()
{

    //Exercise 2.1
    std::cout << "Exercise 2.1:\n\n";
    int a = 5;
    int b = 6;

    int* ptr_a = &a;
    int* ptr_b = &b;

    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "*pointer to a = " << *ptr_a << ", *pointer to b = " << *ptr_b << std::endl;

    Swap(ptr_a, ptr_b);

    std::cout << "after swap a = " << a << ", after swap b =  " << b << std::endl;
    std::cout << "after swap *pointer to a = " << *ptr_a << ", after swap *pointer to b = " << *ptr_b << std::endl;


    //Exercise 2.2

    std::cout << "\n\nExercise 2.2:\n\n";

    std::vector<int*> numbers;

    int arr[] = {5, 6, -9, 4, 1, 8, 100, -300};

    for (auto &item : arr)
        numbers.push_back(&item);

    Sort(numbers);

    for (int* num : numbers) {
        std::cout << *num << " ";
    }
    std::cout << std::endl;

    //Exercise 2.3
    std::cout << "\n\nExercise 2.3:\n\n";

    std::ifstream file("War and peace.txt");
    file.seekg(0, std::ios::end);
    size_t size = file.tellg();
    file.seekg(0);
    std::string s(size, ' ');
    file.read(&s[0], size);

    const std::string vowels = "aeiouAEIOU";

    size_t count = 0;
    Timer timer1("Method with count_if and find. Time elapsed: ");
    count = CountIfFind(s, vowels);
    timer1.print();
    std::cout << "Count of vowels in the text: " << count << std::endl;


    Timer timer2("Method with count_if and for. Time elapsed: ");
    count = CountIfFor(s, vowels);
    timer2.print();
    std::cout << "Count of vowels in the text: " << count << std::endl;

    Timer timer3("Method with for and find. Time elapsed: ");
    count =  ForFind(s, vowels);
    timer3.print();
    std::cout << "Count of vowels in the text: " << count << std::endl;

    Timer timer4("Method with for and for. Time elapsed: ");
    count = ForFor(s, vowels);
    timer4.print();
    std::cout << "Count of vowels in the text: " << count << std::endl;

    file.close();
}
