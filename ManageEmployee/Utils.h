#pragma once
#include <QList>
#include <QSet>
#include <QDate>
#include <QByteArray>
class Utils
{
public:
	static int getSigleNumber(const QList<int>& numbers);
	static bool isInCurrentWeek(const QDate& date);
	static bool isInCurrentMonth(const QDate& date);
	static bool isInLastWeek(const QDate& date);
	static bool isInLastMonth(const QDate& date);
	static bool isInCurrentYear(const QDate& date);

	static bool deleteFile(const QString& filePath);
	static QByteArray templateConvertToByte(const unsigned char* buffer, int size);
	static void byteConvertToBuffer(const QByteArray& byteArray, unsigned char*& buffer, int& size);
};

