#include "Utils.h"

int Utils::getSigleNumber(const QList<int>& numbers) {
    QSet<int> uniqueSet;

    for (int number : numbers) {
        if (uniqueSet.contains(number)) {
            uniqueSet.remove(number);
        }
        else {
            uniqueSet.insert(number);
        }
    }

    // uniqueSet sẽ chứa phần tử không có cặp
    return uniqueSet.isEmpty() ? -1 : *uniqueSet.begin();
}

bool Utils::isInCurrentWeek(const QDate& date) {
    int currentWeekNumber, currentYear;
    int dateWeekNumber = date.weekNumber(&currentYear);

    QDate today = QDate::currentDate();
    int todayWeekNumber = today.weekNumber();

    return (dateWeekNumber == todayWeekNumber && date.year() == today.year());
}

bool Utils::isInCurrentMonth(const QDate& date) {
    QDate today = QDate::currentDate();
    return (date.month() == today.month() && date.year() == today.year());
}