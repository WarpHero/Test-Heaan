#include <fstream>
#include <vector>
#include <iostream>
#include <sstream>
#include "seal/seal.h"

using namespace std;

vector<vector<double>> load_data(const string& filename) {
    vector<vector<double>> data;
    ifstream file(filename);
    
    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return data;
    }
    
    string line;
    while (getline(file, line)) {
        vector<double> row;
        istringstream iss(line);
        double value;
        
        while (iss >> value) {
            row.push_back(value);
        }
        
        if (!row.empty()) {
            data.push_back(row);
        }
    }
    
    cout << "Loaded " << data.size() << " x " << data[0].size() 
         << " matrix from " << filename << endl;
    
    return data;
}

int main() {
    // 데이터 로드
    string testFileName = "X_test_small50.csv"
    string trainFileName = "X_train_small50.csv"
    
    auto X_train = load_data(testFileName);
    auto X_test = load_data(trainFileName);
    
    cout << "Train: " << X_train.size() << " samples, " 
         << X_train[0].size() << " features" << endl;
    cout << "Test: " << X_test.size() << " samples, " 
         << X_test[0].size() << " features" << endl;
    
    // 여기서 SEAL로 PCA 구현
    
    return 0;
}