

#ifndef ADS_ASSIGNMENT_5_HEAP_H
#define ADS_ASSIGNMENT_5_HEAP_H
#include <vector>
#include <string>
using namespace std;
typedef pair<string, double> DataPair;
class Mheap{
public:
    void ADD(const string& Date, double V);
    DataPair getMax();
private:
    vector<DataPair> Heap;
    void HeapifyUp(int Index);
    void HeapifyDown( int Index);
    void CreateHeap();
};

class MinHeap{
public:
    void ADD(const string & Date, double V);
    DataPair getMin();
private:
    vector<DataPair> Heap;
    void HeapifyUp(int Index);
    void HeapifyDown( int Index);
    void CreateHeap();
};
#endif //ADS_ASSIGNMENT_5_HEAP_H
