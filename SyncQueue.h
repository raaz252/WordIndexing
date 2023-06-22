#pragma once

#include <string>
#include <mutex>
#include <queue>
#include <iostream>

using namespace std;

class SyncQueue {
public:  
       SyncQueue();
      ~SyncQueue();
      
      /*writes filename in Queue */
      void AddFileNameinQ(wstring filename);

      /*reads the filename from Queue and returns the filename */
      wstring GetFilefrmQ(void);

      /*returns nubmer of files present queue*/
      int GetCount();

      /*returns number of files processed by queue*/
      int GetFileCount();


private://mutext object for synchronization on queue
    mutex MutexObject;

    //synchronized queue to save filename. This queue is processed by Searchthread and Workerthread  
    queue <wstring> Queue;

    //store number of files processed by queue       
    int CountFileSize;
};

