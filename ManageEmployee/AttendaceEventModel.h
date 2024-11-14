#pragma once
#include <QString>

class AttendanceEventModel
{
private:
    int id;
    QString typeEvent;
    QString dateEvent;
    QString time;
    int exception;
    int session;
    QString employeeId;

public:
    // Constructors
    AttendanceEventModel();
    AttendanceEventModel(int id, const QString& typeEvent, const QString& dateEvent, const QString& time,
        int exception, int session, const QString& employeeId);

    // Getters
    int getId() const;
    QString getTypeEvent() const;
    QString getDateEvent() const;
    QString getTime() const;
    int getException() const;
    int getSession() const;
    QString getEmployeeId() const;

    // Setters
    void setId(int id);
    void setTypeEvent(const QString& typeEvent);
    void setDateEvent(const QString& dateEvent);
    void setTime(const QString& time);
    void setException(int exception);
    void setSession(int session);
    void setEmployeeId(const QString& employeeId);
};
