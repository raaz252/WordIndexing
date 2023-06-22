#pragma once
#include <iostream>
#include<Windows.h>

#define DEBUG_CONFIG

#ifdef DEBUG_CONFIG
#define SQ_DEBUG
#define WKT_DEBUG
#define ST_DEBUG
#endif

#ifdef SQ_DEBUG

#define SQ_LOG (fucn,args) std::wcout <<L"SyncQueue:"<<func <<" "<<args<<std::endl;

#endif

#ifdef WKT_DEBUG

#define WKT_LOG(func,args) std::wcout <<L"WorkerThread: "<<func <<" "<<args<<std::endl;

#endif
#ifdef ST_DEBUG

#define ST_LOG (func,args) std::wcout <<L"SearchThread:"<<func <<" "<<args<<std::endl;

#endif
