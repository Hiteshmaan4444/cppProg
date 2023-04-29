#include<iostream>
#include<fstream>
using namespace std;

int main(){
    ifstream fr("File1.txt");
    ofstream fo("File2.txt");
    string line;
    while(getline(fr,line)){
        fo<<line;
    }
    fr.close();
    fo.close();
}
