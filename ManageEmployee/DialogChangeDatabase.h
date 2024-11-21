#pragma once

#include <QDialog>
#include "ui_DialogChangeDatabase.h"

QT_BEGIN_NAMESPACE
namespace Ui { class DialogChangeDatabaseClass; };
QT_END_NAMESPACE

class DialogChangeDatabase : public QDialog
{
	Q_OBJECT

signals:
	void changeDB(QString type);

public:
	DialogChangeDatabase(QWidget *parent = nullptr);
	~DialogChangeDatabase();

	Ui::DialogChangeDatabaseClass* getUi();

	void handleChangeSQLList(QString name);
	void handleConnectDB();
	bool isFileDB(QString path);

private:
	Ui::DialogChangeDatabaseClass *ui;
};
