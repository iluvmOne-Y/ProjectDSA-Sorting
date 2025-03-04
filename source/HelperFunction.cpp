#include "HelperFunction.hpp"

using namespace std;
int *readDataFromFile(const string& filename,int &n){
    ifstream file(filename);
    
    file >> n;
    int *a = new int[n];
    for(int i = 0; i < n; i++){
        file >> a[i];
    }
    file.close();
    return a;
}
AlgorithmInfo* findAlgorithm(const string& name){
    for(auto& algorithm : algorithms){
        if(algorithm.name == name){
            return &algorithm;
        }
    }
    return nullptr;
}