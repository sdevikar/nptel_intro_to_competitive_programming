#include <iostream>
#include <vector>

void print(const std::vector<int> &v, int start, int end)
{
    for (int i = start; i <= end; i++)
        std::cout << v[i] << ",";

    std::cout << std::endl;
}

int min_index(int start, const std::vector<int> &v)
{
    int min = v[start];
    int min_index = start;
    for (int i = start + 1; i < v.size(); ++i)
    {
        if (v[i] < min)
        {
            min_index = i;
            min = v[min_index];
        }
    }

    return min_index;
}

void reverse(int start, int end, std::vector<int>& v)
{
    std::reverse(v.begin()+start, v.begin()+end+1);

}

void reversort(std::vector<int> &v)
{
    int end = v.size() - 1;

    // iterate upto the second last element
    for (int i = 0; i < end; ++i)
    {
        int mi = min_index(i, v);
        std::cout << "min index = " << mi << std::endl;
        reverse(i, mi, v);
    }
}

int main(void)
{

    std::vector<int> input{2, 4, 3, 1};
    std::cout << "Before..." << std::endl;
    print(input, 0, input.size()-1);
    reversort(input);

    std::cout << "After..." << std::endl;
    print(input, 0,input.size()-1);
    return 0;
}