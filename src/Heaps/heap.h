#include <vector>

class Heap {
    std::vector<int> v;
    std::string type;
    bool compare(int x, int y) {
        if (type == "min") {
            return x < y;
        }
        else if (type == "max") {
            return x > y;
        }
    }
    void heapify(int i) {
        
        int left = 2 * i;
        int right = 2 * i + 1;
        
        int minIdx = i;
        
        if (left < v.size() && compare(v.at(left), v.at(i))) {
            minIdx = left;
        }
        if (right < v.size() && compare(v.at(right), v.at(minIdx))) {
            minIdx = right;
        }
        
        if (minIdx != i) {
            std::swap(v.at(i),v.at(minIdx));
            heapify(minIdx);
        }
    }
public:
    Heap(std::string t="min", int default_size=10) :type{t} {
        v.reserve(default_size+1);
        v.push_back(-1);
    }
    
    void push(int d) {
        // add data to the end of the heap
        v.push_back(d);
        int idx = v.size()-1;
        int parent = idx/2;
        
        while (idx > 1 && compare(v.at(idx), v.at(parent))) { 
            std::swap(v[idx],v[parent]);
            idx = parent;
            parent /= 2;
        }
    }
    
    // return min element
    int top() { return v.at(1); }
    
    // Remove min element
    void pop() {
        // 1. Swap first and last element
        int idx = v.size() - 1;
        std::swap(v.at(1), v.at(idx));
        v.pop_back();
        heapify(1);
    }
    
    void remove_min() {
        std::vector<int> temp{};
        temp.push_back(-1);
        for (int i = 2; i < v.size(); i++) {
            temp.push_back(v.at(i));
        }
        v = temp;
    }
    
    bool empty() {
        return v.size() == 1;
    }
    
    void print() {
        for (int x: v) {
            std::cout << x << " ";
        }
        std::cout << "\n";
    }
    
};