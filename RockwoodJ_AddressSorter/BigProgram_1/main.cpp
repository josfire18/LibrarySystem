#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>
#include <time.h>
using namespace std;

//Struct for containing the address in 5 separate parts
struct address{
    string name;
    string street;
    string city;
    string state;
    string zip;
};

//Function Declaration
void merge(address arr[], int low, int mid, int high, int sortChoiceNum);
void mergeSort(address arr[], int low, int high, int sortChoiceNum);
void printArray(address arr[], int num);
int lineCount(string file);


int main()
{
    //Variable Declaration
    string oneHundred = "100.txt";
    string twoHundred = "200.txt";
    string fiveHundred = "500.txt";
    string oneThousand = "1000.txt";
    int arrSize;
    string filename = "null";
    clock_t timer;
    string sortType;
    int sortChoiceNum;


    //0----Start----0


    while (1) {

        //File Selection
        cout << "Please choose a file: \n";
        cout << "1. 100 \n";
        cout << "2. 200 \n";
        cout << "3. 500 \n";
        cout << "4. 1000 \n";
        char temp;
        cout << "Choice: ";
        cin >> temp;
        switch (temp)
        {
        case '1':
            filename = oneHundred;
            arrSize = lineCount(filename);
            break;
        case '2':
            filename = twoHundred;
            arrSize = lineCount(filename);
            break;
        case '3':
            filename = fiveHundred;
            arrSize = lineCount(filename);
            break;
        case '4':
            filename = oneThousand;
            arrSize = lineCount(filename);
            break;
        default:
            filename = "Values are from 1 to 4, inclusive. NO LETTERS, SYMBOLS, OR ANY NUMBERS OTHER THAN 1-4";
            arrSize = 0;
        }

        //Choose What To Sort
        cout << "Please Choose What to Sort: \n";
        cout << "1. Name \n";
        cout << "2. Address \n";
        cout << "3. City \n";
        cout << "4. State \n";
        cout << "5. Zip \n";
        cout << "6. Nested \n";
        cout << "Choice: ";
        cin >> temp;
        switch (temp)
        {
        case '1':
            sortChoiceNum = 1;
            sortType = "Name";
            break;
        case '2':
            sortChoiceNum = 2;
            sortType = "Address";
            break;
        case '3':
            sortChoiceNum = 3;
            sortType = "City";
            break;
        case '4':
            sortChoiceNum = 4;
            sortType = "State";
            break;
        case '5':
            sortChoiceNum = 5;
            sortType = "Zip";
            break;
        case '6':
            sortChoiceNum = 6;
            sortType = "Nested";
            break;
        default:
            cout << endl << "WRONG VALUE ENTERED. DEFAULT: State \n";
            sortChoiceNum = 4;
            sortType = "State";
        }

        cout << "Select File: " << filename << "\nSort Type: " << sortType << endl;
        \

        //Open file
        ifstream file;
        file.open(filename.c_str());
        address arr[1010];

        if (file.is_open()) {
            cout << endl << "File Opened Sucessfully \n" << endl;
            string line;
            while (file.good())
            {
                for (int i = 1; i <= arrSize; i++) {
                    getline(file, line, '|');
                    arr[i].name = line;
                    getline(file, line, '|');
                    arr[i].street = line;
                    getline(file, line, '|');
                    arr[i].city = line;
                    getline(file, line, '|');
                    arr[i].state = line;
                    getline(file, line);
                    arr[i].zip = line;
                }
            }

            file.close();

            //Start timer
            timer = clock();
            mergeSort(arr, 1, arrSize, sortChoiceNum);
            if (sortChoiceNum == 6) {
                mergeSort(arr, 1, arrSize, 3);
                mergeSort(arr, 1, arrSize, 4);
            }
            //End timer
            timer = clock() - timer;
            printArray(arr, arrSize);

            //Shows time data on console
            cout << "Time taken: " << timer << " Clock Cycles\n" << (float)timer / CLOCKS_PER_SEC <<" Seconds \n";
            cout << "Time per input: " << timer / arrSize << " Clock Cycles. " << (float)timer / (CLOCKS_PER_SEC * arrSize) << " Seconds. \n";
        }
        else {
            cout << "Failed to open file. \n";
        }
        //Format time output to the top of the window
        for(int i = 0; i < 21; i++)
            cout << endl;
    }
    return 0;
}//End Main



//---Functions Section---



void mergeSort(address arr[], int low, int high, int sortChoiceNum)
{
    if (low<high)
    {
        int mid = low + (high - low) / 2;
        mergeSort(arr, low, mid, sortChoiceNum);
        mergeSort(arr, mid + 1, high, sortChoiceNum);
        merge(arr, low, mid, high, sortChoiceNum);
    }
}

void merge(address arr[], int low, int mid, int high, int sortChoiceNum)
{
    int originalLow, outputLow, midpoint, comparison;
        address outputArr[1010];
        originalLow = low;
        outputLow = low;
        midpoint = mid + 1;

        while ((originalLow <= mid) && (midpoint <= high))
        {
            switch (sortChoiceNum) {
            case 1:
                if (arr[originalLow].name <= arr[midpoint].name){
                    outputArr[outputLow] = arr[originalLow];
                    originalLow++;}
                else{
                    outputArr[outputLow] = arr[midpoint];
                    midpoint++;}
                break;
            case 2:
                if (arr[originalLow].street <= arr[midpoint].street){
                    outputArr[outputLow] = arr[originalLow];
                    originalLow++;}
                else{
                    outputArr[outputLow] = arr[midpoint];
                    midpoint++;}
                break;
            case 3:
                if (arr[originalLow].city <= arr[midpoint].city){
                    outputArr[outputLow] = arr[originalLow];
                    originalLow++;}
                else{
                    outputArr[outputLow] = arr[midpoint];
                    midpoint++;}
                break;
            case 4:
                if (arr[originalLow].state <= arr[midpoint].state) {
                    outputArr[outputLow] = arr[originalLow];
                    originalLow++;
                }
                else {
                    outputArr[outputLow] = arr[midpoint];
                    midpoint++;
                }
                break;
            case 5:
                if (arr[originalLow].zip <= arr[midpoint].zip) {
                    outputArr[outputLow] = arr[originalLow];
                    originalLow++;
                }
                else {
                    outputArr[outputLow] = arr[midpoint];
                    midpoint++;
                }
                break;
            default:
                if (arr[originalLow].zip <= arr[midpoint].zip) {
                    outputArr[outputLow] = arr[originalLow];
                    originalLow++;
                }
                else {
                    outputArr[outputLow] = arr[midpoint];
                    midpoint++;
                }
            }
            outputLow++;
        }
        if (originalLow>mid)
        {
            for (comparison = midpoint; comparison <= high; comparison++)
            {
                outputArr[outputLow] = arr[comparison];
                outputLow++;
            }
        }
        else
        {
            for (comparison = originalLow; comparison <= mid; comparison++)
            {
                outputArr[outputLow] = arr[comparison];
                outputLow++;
            }
        }
        for (comparison = low; comparison <= high; comparison++)
            arr[comparison] = outputArr[comparison];
}

void printArray(address arr[], int num)
{
    ofstream out;
    out.open("sorted.txt");
    if (out.is_open())
    {
        for (int i = 1; i <= num; i++)
            out << arr[i].name << " | " << arr[i].street << " | " << arr[i].city << " | " << arr[i].state << " | " << arr[i].zip << endl;
    }
    ifstream in;
    in.open("sorted.txt");
    if(in.is_open())
    {
        cout << endl << "READEING FROM sorted.txt " << endl;
        for (int i = 1; i <= num; i++)
        {
            stringstream buffer;
            buffer << in.rdbuf();
            string info = buffer.str();
            cout << info << endl;
        }
    }

}
int lineCount(string file)
{
    ifstream myfile(file.c_str());
    string line;
    int lineNum = 0;
    //Count Lines
    while (getline(myfile, line))
        ++lineNum;
    cout << "\nTotal Lines: " << lineNum << endl;
    return lineNum;
}
