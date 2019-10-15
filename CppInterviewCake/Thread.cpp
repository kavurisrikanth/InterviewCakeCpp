#include <vector>
#include <stdexcept>

class Thread
{
private:
    std::vector<int> arr;

public:
    Thread()
    {
    }

    void insert(int num)
    {
        arr.push_back(num);
    }

    int remove()
    {
        if (empty())
        {
            throw std::underflow_error("Nothing to remove.");
        }

        int x = arr[0];
        arr.pop_back();
        return x;
    }

    bool empty() {
        return arr.empty();
    }

    std::string display() {
        std::string s;
        for (int i = 0; i < arr.size(); i++) {
            s += i;
            s += ' ';
        }
        return s;
    }
};