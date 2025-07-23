#include <iostream>
#include <map>
#include <string>

using namespace std;


void printEntries(map<string, int>dict){
    for(auto pair : dict){
        cout << pair.first << "-" << pair.second << endl;
    }
}

void insertInDict(map<string, int>& dict, string name, int age){
    dict.insert(pair<string,int>(name,age));    
}

int main(){
    map<string, int> myDict;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string name;
        int age;
        cin >> name >> age;
        insertInDict(myDict, name, age);
    }

    printEntries(myDict);
    
}


// orders the element in ascending order -- if you dont want them to be ordered you can use <unordered_map>
//Use dict[name] = value; instead of insert(), as it updates existing values.
//Use const map<string, int>& in printEntries() to avoid copying the entire map.
//Use const string& in function parameters to avoid unnecessary string copying.