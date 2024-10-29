#include "EmployeeModel.h"

// Constructor
EmployeeModel::EmployeeModel(const QString& id, const QString& firstName, const QString& lastName, const QString& password,
    const DepartmentModel& department, const QDate& dateOfBirth, const QDate& startDateOfWork,
    const QString& status, bool isEnabled, const QString& avatar, const QString& role,
    const QString& email, const QString& phoneNumber, const QString& address,
    bool isAllowPassword, const QString& iriRight, const QString& iriLeft)
    : id(id), firstName(firstName), lastName(lastName), password(password), department(department),
    dateOfBirth(dateOfBirth), startDateOfWork(startDateOfWork), status(status), isEnabled(isEnabled),
    avatar(avatar), role(role), email(email), phoneNumber(phoneNumber), address(address),
    isAllowPassword(isAllowPassword), iriRight(iriRight), iriLeft(iriLeft)
{}

// Getters
QString EmployeeModel::getId() const { return id; }
QString EmployeeModel::getFirstName() const { return firstName; }
QString EmployeeModel::getLastName() const { return lastName; }
QString EmployeeModel::getPassword() const { return password; }
DepartmentModel EmployeeModel::getDepartment() const { return department; }
QDate EmployeeModel::getDateOfBirth() const { return dateOfBirth; }
QDate EmployeeModel::getStartDateOfWork() const { return startDateOfWork; }
QString EmployeeModel::getStatus() const { return status; }
bool EmployeeModel::getIsEnabled() const { return isEnabled; }
QString EmployeeModel::getAvatar() const { return avatar; }
QString EmployeeModel::getRole() const { return role; }
QString EmployeeModel::getEmail() const { return email; }
QString EmployeeModel::getPhoneNumber() const { return phoneNumber; }
QString EmployeeModel::getAddress() const { return address; }
bool EmployeeModel::getIsAllowPassword() const { return isAllowPassword; }
QString EmployeeModel::getIriRight() const { return iriRight; }
QString EmployeeModel::getIriLeft() const { return iriLeft; }

// Setters
void EmployeeModel::setId(const QString& id) { this->id = id; }
void EmployeeModel::setFirstName(const QString& firstName) { this->firstName = firstName; }
void EmployeeModel::setLastName(const QString& lastName) { this->lastName = lastName; }
void EmployeeModel::setPassword(const QString& password) { this->password = password; }
void EmployeeModel::setDepartment(const DepartmentModel& department) { this->department = department; }
void EmployeeModel::setDateOfBirth(const QDate& dateOfBirth) { this->dateOfBirth = dateOfBirth; }
void EmployeeModel::setStartDateOfWork(const QDate& startDateOfWork) { this->startDateOfWork = startDateOfWork; }
void EmployeeModel::setStatus(const QString& status) { this->status = status; }
void EmployeeModel::setIsEnabled(bool isEnabled) { this->isEnabled = isEnabled; }
void EmployeeModel::setAvatar(const QString& avatar) { this->avatar = avatar; }
void EmployeeModel::setRole(const QString& role) { this->role = role; }
void EmployeeModel::setEmail(const QString& email) { this->email = email; }
void EmployeeModel::setPhoneNumber(const QString& phoneNumber) { this->phoneNumber = phoneNumber; }
void EmployeeModel::setAddress(const QString& address) { this->address = address; }
void EmployeeModel::setIsAllowPassword(bool isAllowPassword) { this->isAllowPassword = isAllowPassword; }
void EmployeeModel::setIriRight(const QString& iriRight) { this->iriRight = iriRight; }
void EmployeeModel::setIriLeft(const QString& iriLeft) { this->iriLeft = iriLeft; }
