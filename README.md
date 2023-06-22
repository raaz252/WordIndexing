# WordIndexing


This project consist of the following files:
1.SyncQueue
2.WorkerThread
3.SearchThread

![image](https://github.com/raaz252/WordIndexing/assets/63297432/16cffaa5-90b5-4f1a-b54c-4dfb09f94a81)


SearchThread.cpp search through the folders and files recursively and add the text files to the queue .
Through Syncqueue,WorkerThread get the text file and add the word  to the table and increases its count in the table.

This project is implemented in such a way that the number of worker threads can be increased for efficiency .

![Screenshot 2023-06-22 222557](https://github.com/raaz252/WordIndexing/assets/63297432/885b7c36-eaa7-4174-bdc0-df84bc79b49a)



This is the result 

For future development following things will be done:
1.Add the word to the sql table to increase the score of word count and reading of files

