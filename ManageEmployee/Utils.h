#pragma once
#include <QList>
#include <QSet>
#include <QDate>
class Utils
{
public:
	static int getSigleNumber(const QList<int>& numbers);
	static bool isInCurrentWeek(const QDate& date);
	static bool isInCurrentMonth(const QDate& date);
};

