#pragma once

#include <QDialog>
#include "ui_DialogNotification.h"
#include "BulletinModel.h"
#include <QModelIndex>

QT_BEGIN_NAMESPACE
namespace Ui { class DialogNotificationClass; };
QT_END_NAMESPACE

class DialogNotification : public QDialog
{
	Q_OBJECT

public slots:
	void handleRowClicked(const QModelIndex& index);

public:
	DialogNotification(QList<BulletinModel> list, QWidget *parent = nullptr);
	~DialogNotification();
	Ui::DialogNotificationClass* getUi();

	void renderBulletin();

	BulletinModel bulletinSelected;

private:
	Ui::DialogNotificationClass *ui;
	QList<BulletinModel> bulletinList;
};
