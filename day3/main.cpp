#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

int bin2dec(const char *data, int len){
    int num = 0;
    for(int i = len-1; i >= 0; i--) {
        num += ((int)data[i]-48) * pow(2, len-1-i);
    }
    return num;
}

int getCommon(vector<string> data, int pos) {
    int count = 0;
    for(int i = 0; i < data.size(); i++) {
        if (data[i][pos] == '1') {
            count++;
        } else {
            count--;
        }
    }
    return count;
}

int p2filter(vector<string> data, bool hi) {
    int len = data[0].size();
    vector<string> list;
    vector<string> prev = data;

    for(int i = 0; i < len; i++) {
        char key;
        int on = getCommon(prev,i);
        if(hi){
            key = (on >= 0) ? '1' : '0';
        } else {
            key = (on >= 0) ? '0' : '1';
        }

        for(int j = 0; j < prev.size(); j++){
            if(prev[j][i] == key){
                list.push_back(prev[j]);
            }
        }

        prev = list;
        list.clear();
        if(prev.size() == 1) {
            cout << prev[0] << endl;
            return bin2dec(prev[0].c_str(),len);
        }
    }
    return -111;
}

int main() {
    string line;
    string file;
    vector<string> data;

    cout << "ENTER FILE: ";
    cin >> file;
    cout << endl;
    
    ifstream input (file);

    if (input.is_open()) {
        while (getline(input,line))
        {
            data.push_back(line);
        }
        
    }
    input.close();

    int strSize = data[0].size();
    char epsilon[strSize], gamma[strSize];

    for(int i = 0; i < strSize; i++){
    //     int on = 0;
    //     int off = 0;
    //     for(int k = 0; k < data.size(); k++){
    //         if (data[k][i] == '0') {
    //             off++;
    //         } else {
    //             on++;
    //         }
    //     }
        int on = getCommon(data, i);
        gamma[i] = (on > 0) ? '1' : '0';
        epsilon[i] = (on < 0) ? '1' : '0';
        
    }
    printf("%s %s \n",gamma,epsilon);
    cout << bin2dec(gamma, strSize) * bin2dec(epsilon, strSize) <<endl;
    int o2 = p2filter(data, true);
    int co2 = p2filter(data, false);
    printf("O2: %d\tCO2: %d\tRATIING: %d\n",o2,co2,o2*co2);
    return 0;
}

