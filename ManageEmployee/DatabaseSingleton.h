#pragma once
#include "IDatabaseManager.h"
class DatabaseSingleton {
private:
	static DatabaseSingleton* instance;
	static IDatabaseManager* db;

	DatabaseSingleton() = default;

public:
	DatabaseSingleton(const DatabaseSingleton&) = delete;
	DatabaseSingleton& operator=(const DatabaseSingleton&) = delete;

	static DatabaseSingleton* getInstance() {
		if (instance == nullptr) {
			instance = new DatabaseSingleton();
		}
		return instance;
	}

	static void setDB(IDatabaseManager* _db) {
		db = _db;
	}

	static IDatabaseManager* getDB() {
		return db;
	}

	static void destroyInstance() {
		if (instance != nullptr) {
			delete instance;
		}
		instance = nullptr;
	}
};