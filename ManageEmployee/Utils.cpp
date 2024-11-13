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

bool Utils::isInLastWeek(const QDate& date) {
    QDate today = QDate::currentDate();
    int currentWeekNumber, currentYear;
    int lastWeekNumber = today.addDays(-7).weekNumber(&currentYear);
    int dateWeekNumber = date.weekNumber();

    return (dateWeekNumber == lastWeekNumber && date.year() == currentYear);
}

bool Utils::isInLastMonth(const QDate& date) {
    QDate today = QDate::currentDate();
    QDate firstDayOfCurrentMonth(today.year(), today.month(), 1);
    QDate firstDayOfLastMonth = firstDayOfCurrentMonth.addMonths(-1);

    return (date >= firstDayOfLastMonth && date < firstDayOfCurrentMonth);
}

// Kiểm tra xem ngày có nằm trong năm hiện tại không
bool Utils::isInCurrentYear(const QDate& date) {
    QDate today = QDate::currentDate();
    return date.year() == today.year();
}