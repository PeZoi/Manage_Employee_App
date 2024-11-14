#pragma once
#include "IAttendanceEventRepository.h"
class AttendanceEventRepositorySQLite : public IAttendanceEventRepository
{
public:
	AttendanceEventRepositorySQLite(IDatabaseManager* _db);

	bool add(AttendanceEventModel attendanceEvent) override;
	bool update(AttendanceEventModel attendanceEvent) override;
	bool _delete(int id) override;
	bool _deleteByEmployeeId(QString employeeId) override;
	QList<AttendanceEventModel> getAll() override;
	AttendanceEventModel getById(int id) override;
	QList<AttendanceEventModel> getByEmployeeId(QString employeeId) override;
	QList<AttendanceEventModel> getBySession(int session) override;
	AttendanceEventModel getByDateAndTimeAndEmployeeId(QString date, QString time, QString employeeId) override;
	bool deleteBySession(int session) override;

private:
	IDatabaseManager* db;
};

