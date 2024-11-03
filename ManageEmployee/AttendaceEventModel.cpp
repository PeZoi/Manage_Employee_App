#include "AttendaceEventModel.h"

// Default Constructor
AttendanceEventModel::AttendanceEventModel() : id(0), exception(0), session(0) {}

// Full Constructor
AttendanceEventModel::AttendanceEventModel(int id, const QString& typeEvent, const QString& dateEvent, const QString& time,
    int exception, int session, const QString& employeeId)
    : id(id), typeEvent(typeEvent), dateEvent(dateEvent), time(time), exception(exception), session(session), employeeId(employeeId) {}

// Getters
int AttendanceEventModel::getId() const {
    return id;
}

QString AttendanceEventModel::getTypeEvent() const {
    return typeEvent;
}

QString AttendanceEventModel::getDateEvent() const {
    return dateEvent;
}

QString AttendanceEventModel::getTime() const {
    return time;
}

int AttendanceEventModel::getException() const {
    return exception;
}

int AttendanceEventModel::getSession() const {
    return session;
}

QString AttendanceEventModel::getEmployeeId() const {
    return employeeId;
}

// Setters
void AttendanceEventModel::setId(int id) {
    this->id = id;
}

void AttendanceEventModel::setTypeEvent(const QString& typeEvent) {
    this->typeEvent = typeEvent;
}

void AttendanceEventModel::setDateEvent(const QString& dateEvent) {
    this->dateEvent = dateEvent;
}

void AttendanceEventModel::setTime(const QString& time) {
    this->time = time;
}

void AttendanceEventModel::setException(int exception) {
    this->exception = exception;
}

void AttendanceEventModel::setSession(int session) {
    this->session = session;
}

void AttendanceEventModel::setEmployeeId(const QString& employeeId) {
    this->employeeId = employeeId;
}
