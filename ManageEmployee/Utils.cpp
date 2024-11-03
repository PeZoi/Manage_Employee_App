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