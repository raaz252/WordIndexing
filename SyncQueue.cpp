#include "SyncQueue.h"

using namespace std;

SyncQueue::SyncQueue() {
	CountFileSize = 0;
};

SyncQueue::~SyncQueue() {

};


void SyncQueue::AddFileNameinQ(wstring filename) {
	MutexObject.lock();
	Queue.push(filename);
	CountFileSize++;
	MutexObject.unlock();
}

wstring SyncQueue::GetFilefrmQ(void) {
	wstring filename = L"";
	MutexObject.lock();
	if (!Queue.empty()) {
		filename = Queue.front();
		Queue.pop();
		std::wcout << "File from queue:" << filename << std::endl;
	}
	MutexObject.unlock();
	return filename;
}

int SyncQueue::GetCount() {
	int sz = 0;
	
	if (!Queue.empty())
	{
		sz = Queue.size();
	}
	return sz;
}

int SyncQueue::GetFileCount() {
	return CountFileSize;
}
