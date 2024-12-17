#pragma once
#include <QString>
#ifndef CONSTANT_H
#define CONSTANT_H
class Constant
{
public:
	static constexpr const char* PATH_CONFIG = "D:/IriTech/Code/ManageEmployee/database/config.ini";
	static constexpr const char* PATH_DIR_IMG = "D:/IriTech/Code/ManageEmployee/image";
	static constexpr const char* MYSQL = "MYSQL";
	static constexpr const char* SQLITE = "SQLITE";
	static constexpr const char* SQLServer = "SQLServer";
	
	// TYPE BULLETIN
	static constexpr const char* B_TYPE_ALL = "All";
	static constexpr const char* B_TYPE_DEPARTMENT = "Deparment";
	static constexpr const char* B_TYPE_EMPLOYEE = "Selection";
};
#endif