#include "DatabaseSingleton.h"

DatabaseSingleton* DatabaseSingleton::instance = nullptr;
IDatabaseManager* DatabaseSingleton::db = nullptr;