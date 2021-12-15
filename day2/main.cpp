#include <iostream>
#include <fstream>


using namespace std;

int main() {
    string line;
    ifstream commands ("data.txt");
    int depth = 0;
    int lin = 0;
    int aim = 0;
    if(commands.is_open()){
        while(getline(commands,line)){
            string cmd = line.substr(0,line.find(' '));
            int dist = stoi(line.substr(line.find(' '),line.size()-1));
            if(cmd == "forward"){
                lin += dist;
                depth += dist*aim;
                printf("F lin: %d    depth: %d    aim: %d\n",lin,depth,aim);
            } else if(cmd == "up"){
                aim -= dist;
                printf("U lin: %d    depth: %d    aim: %d\n",lin,depth,aim);
            } else if(cmd == "down"){
                aim += dist;
                printf("D lin: %d    depth: %d    aim: %d\n",lin,depth,aim);
            } else {
                cout << "WTF?" << endl;
            }
        }
        commands.close();
    }

    printf("Product: %d\n", lin * depth);

    return 0;
}