# WordIndexing

![Screenshot](https://example.com/your-screenshot.png)

## Overview

The "WordIndexing" project is designed to process text files, index the words they contain, and potentially store them in an SQL table. The project follows a multi-threaded approach for efficient text file processing.

## Project Components

### 1. SearchThread

The `SearchThread` component is responsible for recursively searching through folders and files to find text files. Once discovered, these text files are added to the `SyncQueue` for further processing by worker threads.

### 2. SyncQueue

The `SyncQueue` component implements a synchronized queue data structure. It serves as a repository for text files that are identified during the search process. Worker threads retrieve files from this queue for processing.

### 3. WorkerThread

The `WorkerThread` component is responsible for processing text files retrieved from the `SyncQueue`. It reads the files, extracts words, and maintains a word count. The words and their counts are then processed further or potentially stored in an SQL table.

## Project Execution

The project uses a multi-threaded approach to efficiently process text files and index the words they contain. By increasing the number of worker threads, the project aims to improve efficiency.

## Planned Enhancements

For future development, the project plans to include the following features:

1. Storing Words in an SQL Table: The project aims to enhance functionality by storing the indexed words in an SQL table. This can facilitate word count tracking and provide efficient ways to query and manage word data.

## Project Screenshot

![Project Screenshot](https://example.com/your-project-screenshot.png)

---

Feel free to replace the image URLs with the actual URLs or upload the images to your repository. Make sure the README is well-formatted and provides clear information about the project and its components.
