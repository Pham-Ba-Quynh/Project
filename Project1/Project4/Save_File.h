#pragma once
#include<iostream>
using namespace std;

#define RANGE_SPEED 3
#define MSCN 8
class Save_File
{
    int arrMSCN[MSCN];
    int arrRANGESPEED[RANGE_SPEED];
public:
    Save_File() {
    }
    void setMSCN(int* p) {
        for (int i = 0; i < MSCN; i++)
        {
            arrMSCN[i] = p[i];
        }
    }
    void setRANGED(int* p) {
        for (size_t i = 0; i < RANGE_SPEED; i++)
        {
            arrRANGESPEED[i] = p[i];
        }
    } 

    void getMSCN(int* p) {
        for (int i = 0; i < MSCN; i++)
        {
            p[i] = arrMSCN[i];
        }
    }
    void get_RANGED(int* arr) {
        for (int i = 0; i < RANGE_SPEED; i++) {
            arr[i] = arrRANGESPEED[i];
        }
    }

    void printDATA() {
        // print MSCN
        cout << "\n===========MSCN=================\n";

        for (size_t i = 0; i < MSCN; i++)
        {
            cout << arrMSCN[i] << " ";
        }
        cout << "\n===========RANGE=================\n";
        for (size_t i = 0; i < RANGE_SPEED; i++)
        {
            cout << arrRANGESPEED[i] << " ";
        }
    }
    ~Save_File() {}

};

