#include "BulletinModel.h"
#include "Constant.h"

// Constructor
BulletinModel::BulletinModel(int id, const QString& title, const QString& content,
    const QString& startDate, const QString& endDate,
    bool isActive, bool isPriority, const QString& type)
    : id(id), title(title), content(content),
    startDate(startDate), endDate(endDate),
    isActive(isActive), isPriority(isPriority), type(type)
{
}

int BulletinModel::getId() const { return id; }
QString BulletinModel::getTitle() const { return title; }
QString BulletinModel::getContent() const { return content; }
QString BulletinModel::getStartDate() const { return startDate; }
QString BulletinModel::getEndDate() const { return endDate; }
bool BulletinModel::getIsActive() const { return isActive; }
bool BulletinModel::getIsPriority() const { return isPriority; }
QString BulletinModel::getType() const { return type; }
QString BulletinModel::getDepartment() const { return department; }
QVector<QString> BulletinModel::getEmployeeIds() const { return employeeIds; }

void BulletinModel::setId(int value) { id = value; }
void BulletinModel::setTitle(const QString& value) { title = value; }
void BulletinModel::setContent(const QString& value) { content = value; }
void BulletinModel::setStartDate(const QString& value) { startDate = value; }
void BulletinModel::setEndDate(const QString& value) { endDate = value; }
void BulletinModel::setIsActive(bool value) { isActive = value; }
void BulletinModel::setIsPriority(bool value) { isPriority = value; }
void BulletinModel::setType(const QString& value) { type = value; }
void BulletinModel::setDepartment(const QString value) { department = value; }
void BulletinModel::setEmployeeIds(const QVector<QString>& value) { employeeIds = value; }

void BulletinModel::addEmployee(QString employeeId) {
    if (type == Constant::B_TYPE_EMPLOYEE)
        employeeIds.append(employeeId);
}