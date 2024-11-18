#pragma once
#include "AttendaceEventModel.h"
class IAttendanceEventRepository {
public:
	virtual ~IAttendanceEventRepository() {}
	virtual bool add(AttendanceEventModel attendanceEvent) = 0;
	virtual bool update(AttendanceEventModel attendanceEvent) = 0;
	virtual bool _delete(int id) = 0;
	virtual bool _deleteByEmployeeId(QString employeeId) = 0;
	virtual QList<AttendanceEventModel> getAll() = 0;
	virtual AttendanceEventModel getById(int id) = 0;
	virtual QList<AttendanceEventModel> getByEmployeeId(QString employeeId) = 0;
	virtual QList<AttendanceEventModel> getBySession(int session) = 0;
	virtual AttendanceEventModel getByDateAndTimeAndEmployeeId(QString date, QString time, QString employeeId) = 0;
	virtual bool deleteBySession(int session) = 0;
};