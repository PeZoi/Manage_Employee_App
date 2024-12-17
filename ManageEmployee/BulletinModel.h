#pragma once
#include <QString>
#include <QDate>
#include <QVector>
#include <QDebug>

class BulletinModel
{
private:
    int id;
    QString title;
    QString content;
    QString startDate;
    QString endDate;
    bool isActive;
    bool isPriority;
    QString type;

    QString department;
    QVector<QString> employeeIds;

public: 
    BulletinModel() = default;
    BulletinModel(int id, const QString& title, const QString& content,
        const QString& startDate, const QString& endDate,
        bool isActive, bool isPriority, const QString& type);

    // Getters
    int getId() const;
    QString getTitle() const;
    QString getContent() const;
    QString getStartDate() const;
    QString getEndDate() const;
    bool getIsActive() const;
    bool getIsPriority() const;
    QString getType() const;
    QString getDepartment() const;
    QVector<QString> getEmployeeIds() const;

    // Setters
    void setId(int value);
    void setTitle(const QString& value);
    void setContent(const QString& value);
    void setStartDate(const QString& value);
    void setEndDate(const QString& value);
    void setIsActive(bool value);
    void setIsPriority(bool value);
    void setType(const QString& value);
    void setDepartment(const QString value);
    void setEmployeeIds(const QVector<QString>& value);

    void addEmployee(QString employeeId);
};