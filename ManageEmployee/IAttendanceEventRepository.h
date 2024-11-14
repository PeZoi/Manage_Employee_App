#pragma once

#include "IDatabaseManager.h"
class IAttendanceEventRepository {
public:
	virtual ~IAttendanceEventRepository() {}
	virtual bool add(AttendanceEventModel attendanceEvent);
	virtual bool update(AttendanceEventModel attendanceEvent);
	virtual bool _delete(int id);
	virtual bool _deleteByEmployeeId(QString employeeId);
	virtual QList<AttendanceEventModel> getAll();
	virtual AttendanceEventModel getById(int id);
	virtual QList<AttendanceEventModel> getByEmployeeId(QString employeeId);
	virtual QList<AttendanceEventModel> getBySession(int session);
	virtual AttendanceEventModel getByDateAndTimeAndEmployeeId(QString date, QString time, QString employeeId);
	virtual bool deleteBySession(int session);
};