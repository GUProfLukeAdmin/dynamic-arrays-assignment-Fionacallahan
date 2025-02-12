#include<iostream>
#include <vector> 

using namespace std;

void part1(); //this works 
void part2();

int main()
{
    part1();
    part2();
}

void part1(){
    vector <int> myVec(50000);
    for (int i = 0; i < 50000; i++)
    {
        myVec[i] = i;
    }
    cout << "After adding elements: Size = " << myVec.size() << ", Capacity = " << myVec.capacity() << endl;
    myVec.resize(myVec.size() / 2);
    cout << "After resizing: Size = " << myVec.size() << ", Capacity = " << myVec.capacity() << endl;
    myVec.shrink_to_fit();
    //changes the capacity to exactly what it needs in memory storage, "shrinks" to size
    cout << "After shrink_to_fit(): Size = " << myVec.size() << ", Capacity = " << myVec.capacity() << endl;
}

void part2(){
    std::vector <bool> myVecBools(10000);
    //myVecBools.reserve(10000);
    int counter = 0;
    for (int i = 0; i < 10000; i ++)
    {
        counter ++;
        if (counter%2 == 0){
            myVecBools[i] = true;
        }
        else{
            myVecBools[i] = false;
        }
    }
    int boolMemoryUsage = (myVecBools.size()/8);
    //each bool: one bit //the dividing by 8 makes it so that it is BYTEs not bits 
    std::vector <char> myVecChars;
    for (int i = 0; i < 10000; i ++){
        myVecChars.push_back('a');
    }
    int charMemoryUsage = (myVecChars.size() *sizeof(char));
    cout << "Memory usage of std::vector<bool>: " << boolMemoryUsage << " Bytes" << endl;
    cout << "Memory usage of std::vector<char>: " << charMemoryUsage << " Bytes" << endl;
    //could not do capacity because that only accounts for number of elements, NOT considering different bits and bytes 
}

