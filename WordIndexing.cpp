#include "SyncQueue.h"
#include "WorkerThread.h"
#include "SearchThread.h"
#include <iostream>
#include <stdio.h>
#include <string>
#include <sys/types.h>
#include <windows.h>
#include <signal.h>
#include <errno.h>
#include <fstream>
#include <vector>
#include <utility>
#include <iterator>
#include <map>
#include <iomanip>
using namespace std;

//max 3 worker thread
const unsigned int WThreadCount = 1;

//to know if seraching of txt file is over
unsigned int SearchFinishedFlag = 0;

//Queue object
SyncQueue Qobject;

int main(int argc, wchar_t* argv[]) {

    if (argc < 2) {

        cout << "Please specify the directory name " << endl;
        cout << "Usage :  ./SearchExecutable <dirname>" << endl;
        return -1;
    }
    //convert char * to string
    //std::string dir = argv[1];
    //Convert string to wstring using std::wstring(string.begin(),string.end())
    const wchar_t* directory = L"D:\\#RajDOC\\Projects\\WordIndexing\\logs";
    const wchar_t* filter = L"*.txt";
    wstring searchPath = wstring(directory);

    WIN32_FIND_DATAW fileData;
    HANDLE hFind = FindFirstFileW(searchPath.c_str(), &fileData);
    
    DWORD attributes = GetFileAttributesW(searchPath.c_str());

    if (attributes == INVALID_FILE_ATTRIBUTES) {
      
        std::cout<<"Invalid Direcotry" << std::endl;
        
    }

   // std::cout << endl << "Please wait while process(" << getpid() << ")" << " is processing...." << endl;

    //Creating worker threads
    WorkerThread WThread(WThreadCount);
    

    //Creating Search thread to add .txt file in Queue
    SearchThread STobject;
    STobject.StartSearchTxtFiles(searchPath.c_str(), L"*.txt");
    WThread.CreateThreeWorkerThread();

    while (1) {
        if (SearchFinishedFlag && !(Qobject.GetCount())) {
            cout << "Finished\n";
            break;
        }
    }

    multimap<int, string, greater<int>> MMtable;
    MMtable = WThread.getTableEntry();

    cout << endl << "Total files Processed " << Qobject.GetFileCount() << endl;

    cout << "***********************************************" << endl;
    cout << " " << setw(10) << "Words" << setw(20) << "No of occurences" << endl;
    cout << "***********************************************" << endl;

    int i = 0;
    for (auto iter = MMtable.begin(); iter != MMtable.end(); ++iter) {
        std::cout << " " << setw(10) << iter->second << setw(10) << iter->first << std::endl;
        i++;
        if (i == 10) //To get only top 10 words.
            break;
    }
    cout << "***********************************************" << endl;

    return 0;
}
