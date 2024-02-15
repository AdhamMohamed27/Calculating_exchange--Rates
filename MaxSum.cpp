//
// Created by Lenovo
#include "MaxSum.h"
#include "vector"
#include"utility"
#include "string"
using namespace std;
typedef pair<string , double> DataPair;
double Avg(const vector<DataPair>& sequence);
pair<string, string> GetMAX(const vector<DataPair>& sequence);

double Avg(const vector<DataPair>& sequence){
    double Sum=0.0;
    for (const auto& Data: sequence){
        Sum=Sum+Data.second;
    }
    return Sum/ static_cast<double>(sequence.size());
}

pair<string, string> GetMAX(const vector<DataPair>& sequence){
    double MaxSum,CurrentSum=0.0;
    pair<string, string> MaxPeriod;
    int beginning,CurrentBeginning=0;
    for (int i = 0; i < sequence.size(); ++i) {
        CurrentSum =CurrentSum+ sequence[i].second;

        if (CurrentSum < 0) {
            CurrentSum = 0;
            CurrentBeginning = i + 1;
        }

        if (CurrentSum > MaxSum) {
            MaxSum = CurrentSum;
            MaxPeriod.first = sequence[CurrentBeginning].first;
            MaxPeriod.second = sequence[i].first;
        }
    }

    return MaxPeriod;
}



