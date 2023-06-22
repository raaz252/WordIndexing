#pragma once

#include <iostream>
#include <windows.h>
#include <string>

class SearchThread {
public:
	SearchThread();
	~SearchThread();

	void StartSearchTxtFiles(const wchar_t* filePath,const wchar_t* filter);
	void callback(const wchar_t* filepath, const WIN32_FIND_DATAW& fileData);


};