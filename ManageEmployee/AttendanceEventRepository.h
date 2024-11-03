#pragma once
#include <QObject>
#include "AttendaceEventModel.h"
#include "DatabaseManager.h"

class AttendanceEventRepository : public QObject
{
	Q_OBJECT
public:
	AttendanceEventRepository();

	static bool add(AttendanceEventModel attendanceEvent);
	static bool update(AttendanceEventModel attendanceEvent);
	static bool _delete(int id);
	static QList<AttendanceEventModel> getAll();
	static AttendanceEventModel getById(int id);
	static QList<AttendanceEventModel> getByEmployeeId(QString employeeId);
	static QList<AttendanceEventModel> getBySession(int session);
	static AttendanceEventModel getByDateAndTime(QString date, QString time);
	static bool deleteBySession(int session);

};