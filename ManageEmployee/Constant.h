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

	// AUDIO
	static constexpr const char* AUDIO_WELCOME_EN = "D:/IriTech/Code/ManageEmployee/audio/welcome.wav";
	static constexpr const char* AUDIO_WELCOME_VI = "D:/IriTech/Code/ManageEmployee/audio/welcome_vi.wav";
	static constexpr const char* AUDIO_GOODBYE_EN = "D:/IriTech/Code/ManageEmployee/audio/goodbye.wav";
	static constexpr const char* AUDIO_GOODBYE_VI = "D:/IriTech/Code/ManageEmployee/audio/goodbye_vi.wav";

	// LANGUAGE
	static constexpr const char* EN = "en";
	static constexpr const char* VI = "vi";
	static constexpr const char* PATH_TRANSLATES_VI = "D:/IriTech/Code/ManageEmployee/languages/iritracker_vi.qm";
	static constexpr const char* PATH_TRANSLATES_EN = "D:/IriTech/Code/ManageEmployee/languages/iritracker_en.qm";


};
#endif