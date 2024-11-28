#pragma once
#include "DepartmentModel.h"
#include <QString>
#include <QDate>
class EmployeeModel
{
public:
    // Constructor
    EmployeeModel() = default;
    EmployeeModel(const QString& id, const QString& firstName, const QString& lastName, const QString& password,
        const DepartmentModel& department, const QDate& dateOfBirth, const QDate& startDateOfWork,
        const QString& status, bool isEnabled, const QString& avatar, const QString& role,
        const QString& email, const QString& phoneNumber, const QString& address,
        bool isAllowPassword, const QByteArray& iriRight, const QByteArray& iriLeft);

    // Getters
    QString getId() const;
    QString getFirstName() const;
    QString getLastName() const;
    QString getPassword() const;
    DepartmentModel getDepartment() const;
    QDate getDateOfBirth() const;
    QDate getStartDateOfWork() const;
    QString getStatus() const;
    bool getIsEnabled() const;
    QString getAvatar() const;
    QString getRole() const;
    QString getEmail() const;
    QString getPhoneNumber() const;
    QString getAddress() const;
    bool getIsAllowPassword() const;
    QByteArray getIriRight() const;
    QByteArray getIriLeft() const;

    // Setters
    void setId(const QString& id);
    void setFirstName(const QString& firstName);
    void setLastName(const QString& lastName);
    void setPassword(const QString& password);
    void setDepartment(const DepartmentModel& department);
    void setDateOfBirth(const QDate& dateOfBirth);
    void setStartDateOfWork(const QDate& startDateOfWork);
    void setStatus(const QString& status);
    void setIsEnabled(bool isEnabled);
    void setAvatar(const QString& avatar);
    void setRole(const QString& role);
    void setEmail(const QString& email);
    void setPhoneNumber(const QString& phoneNumber);
    void setAddress(const QString& address);
    void setIsAllowPassword(bool isAllowPassword);
    void setIriRight(const QByteArray& iriRight);
    void setIriLeft(const QByteArray& iriLeft);

private:
    QString id;
    QString firstName;
    QString lastName;
    QString password;
    DepartmentModel department;
    QDate dateOfBirth;
    QDate startDateOfWork;
    QString status;
    bool isEnabled;
    QString avatar;
    QString role;
    QString email;
    QString phoneNumber;
    QString address;
    bool isAllowPassword;
    QByteArray iriRight;
    QByteArray iriLeft;
};
