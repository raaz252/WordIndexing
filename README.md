# WordIndexing


The project "WordIndexing" consists of the following files:

1. SearchThread: This file likely contains the implementation of a search thread. The search thread recursively searches through folders and files to find text files. These text files are then added to the SyncQueue for further processing by the worker threads.

2. SyncQueue: This file likely contains the implementation of a synchronized queue data structure. It is used to store the text files that are discovered during the search process.

3. WorkerThread: This file contains the implementation of a worker thread. The worker threads retrieve text files from the SyncQueue, process them, and add the words to a table while increasing their count.

![image](https://github.com/raaz252/WordIndexing/assets/63297432/16cffaa5-90b5-4f1a-b54c-4dfb09f94a81)

The project uses a multi-threaded approach to efficiently process text files and index the words they contain. By increasing the number of worker threads, the project aims to improve efficiency.

The provided images seem to showcase the project's execution and results, but unfortunately, the links are not accessible. It appears that these images demonstrate the project's functionality and possibly the output generated during execution.

For future development, the following tasks are mentioned:

1. Adding words to an SQL table: The project aims to enhance the functionality by storing the words in an SQL table, potentially to increase the score of word counts and facilitate the reading of files.


Overall, the WordIndexing project focuses on indexing words from text files using multiple worker threads and provides potential plans for further development and documentation improvements.


This is the result 
![Screenshot 2023-06-22 222557](https://github.com/raaz252/WordIndexing/assets/63297432/885b7c36-eaa7-4174-bdc0-df84bc79b49a)


