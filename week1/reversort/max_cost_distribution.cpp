// Here we will create an array that will result in the maximum cost when sorted by reversort

#include <iostream>
#include <vector>

std::vector<int> create_distribution(int size)
{
    std::vector<int> v(size);
    int left = 0;
    int right = size - 1;
    int counter = 0;

    while ((left <= right) && counter < size)
    {

        if(left == right){
            v[left] = counter+1;
            break;
        }
        v[right--] = counter+1;
        counter++;
        v[left++] = counter+1;
        counter++;
    }

    return v;
}

int main(void)
{

    std::vector<int> dist = create_distribution(5);
    for (int x : dist)
    {
        std::cout << x << ", ";
    }
    std::cout << std::endl;
}