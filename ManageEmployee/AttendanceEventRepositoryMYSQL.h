#pragma once
#include "IAttendanceEventRepository.h"
#include "IDatabaseManager.h"
#include "AttendaceEventModel.h"
class AttendanceEventRepositoryMYSQL : public IAttendanceEventRepository
{
public:
	AttendanceEventRepositoryMYSQL(IDatabaseManager* _db);

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