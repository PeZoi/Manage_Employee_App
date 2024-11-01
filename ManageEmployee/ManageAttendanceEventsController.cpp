#include "ManageAttendanceEventsController.h"

ManageAttendanceEventsController::ManageAttendanceEventsController(ManageAttendanceEvents* view, QObject* parent)
	: QObject(parent), view(view)
{

}

ManageAttendanceEvents* ManageAttendanceEventsController::getView() {
	return view;
}