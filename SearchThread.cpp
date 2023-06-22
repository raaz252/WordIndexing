#include "SearchThread.h"
#include "SyncQueue.h"
#include <stdio.h>
#include <string>
#include <sys/types.h>
#include <signal.h>
#include <errno.h>
#include <fstream>
#include <vector>
#include <utility>
#include <map>
#include <iterator>
#include <iostream>
#include <windows.h>
#include <Shlwapi.h>

extern unsigned int SearchFinishedFlag;
//to access Queue object
extern  SyncQueue Qobject;

SearchThread::SearchThread() {

};

SearchThread::~SearchThread() {

};


void SearchThread::callback(const wchar_t* filepath, const WIN32_FIND_DATAW& fileData)
{
    if (!(fileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
    {
        // Handle files
        std::wstring filename = filepath;// +std::wstring(L"\\") + fileData.cFileName;
        // Perform necessary operations with the file
        std::wcout <<L"SearchThread:" << filename << std::endl;
        Qobject.AddFileNameinQ(filename);
    }

    //if Serach is over then SearchFinishedFlag =1
    SearchFinishedFlag = 1;
}

void SearchThread::StartSearchTxtFiles(const wchar_t* directory, const wchar_t* filter)
{
    std::wstring searchPath = std::wstring(directory) + L"\\*";

    WIN32_FIND_DATAW fileData;
    HANDLE hFind = FindFirstFileW(searchPath.c_str(), &fileData);
    //cout << "Raj3\n";
    if (hFind != INVALID_HANDLE_VALUE)
    {
        do
        {
            if (wcscmp(fileData.cFileName, L".") != 0 && wcscmp(fileData.cFileName, L"..") != 0)
            {
                std::wstring filepath = std::wstring(directory) + L"\\" + fileData.cFileName;

                if (fileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
                {
                    StartSearchTxtFiles(filepath.c_str(), filter);
                    // std::wcout<< filepath << "\n";
                }
                else
                {
                    if (PathMatchSpecW(fileData.cFileName, filter))
                    {
                        callback(filepath.c_str(), fileData);
                    }
                }
            }
        } while (FindNextFileW(hFind, &fileData));

        FindClose(hFind);
    }
}

