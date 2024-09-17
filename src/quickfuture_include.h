#pragma once 
#include <QtGlobal>

#ifdef QUICK_FUTURE_LIB
#define QUICK_FUTURE_EXPORT Q_DECL_EXPORT
#else
#define QUICK_FUTURE_EXPORT Q_DECL_IMPORT
#endif