#pragma once

#include "ManageException.h"
#include "ExceptionModel.h"
#include "DialogFormException.h"
#include <QObject>

class ManageExceptionController : public QObject
{
	Q_OBJECT

public slots:
	void handleRenderTable();
	void onClickAdd();
	void onClickEdit();
	void onClickDelete();

	void submitException(const ExceptionModel& exception, bool isEditMode, DialogFormException* exceptionView);

	void handleRowClicked(const QModelIndex& index);

	ManageException* getMexView();

public:
	ManageExceptionController(ManageException* view, QObject *parent);
	~ManageExceptionController();
	ExceptionModel exceptionSelected;

private:
	ManageException* mexView;
};
