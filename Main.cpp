#include <iostream>
using namespace std;
#include <fstream>
#include "vector"
#include "sstream"
#include "Heap.h"
#include "MaxSum.h"
#include "string"

vector<DataPair> GetData(const string& fileName){
    vector<DataPair> Data;
    ifstream file(fileName);
    if(!file.is_open()){
        cout<<"Error in opening the File"<<endl;
    }
    string Line;
    while(getline(file,Line)){
        istringstream iss(Line);
        string string_Data, string_Rate;
        if (getline(iss,string_Data, ',')and getline(iss,string_Rate,',')){
            double Rate= stod(string_Rate);
                    Data.emplace_back(string_Data,Rate);
        }
    }
    file.close();
    return Data;
}

int main()
{
    vector<DataPair> ExchangeRate= GetData("euro-dollar.csv");
    if(ExchangeRate.empty()){
        cout<<"There is no Data"<<endl;
    }
    else {
        double AvgR = Avg(ExchangeRate);
        Mheap maxHeap;
        MinHeap minHeap;
        for (const auto &Data: ExchangeRate) {
            double Change = Data.second - AvgR;
            maxHeap.ADD(Data.first, Change);
            minHeap.ADD(Data.first, Change);
        }
        int N = 10;
        cout << "Top " << N << "of The Max Exchange Rate:" << endl;
        for (int i = 0; i < N; ++i) {
            auto MChange = maxHeap.getMax();
            cout << "The Date: " << MChange.first << ", the Change: " << MChange.second << endl;
        }
        cout << "\nTop " << N << " of The Min/Lowest Exchange Rate: " << endl;
        for (int i = 0; i < N; ++i) {
            auto MinChange = minHeap.getMin();
            cout << "The Date: " << MinChange.first << ", the Change: " << MinChange.second << endl;
        }
        auto Maxsum= GetMAX(ExchangeRate);
        cout<<"\nMax Subsequence Sum Period:" << endl;
        cout << "Start Date:" << Maxsum.first << " ,End Date:" << Maxsum.second << endl;
    }




	return 0;
}

