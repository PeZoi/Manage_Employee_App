#pragma once

#include <QWidget>
#include "ui_ManageBulletin.h"

QT_BEGIN_NAMESPACE
namespace Ui { class ManageBulletinClass; };
QT_END_NAMESPACE

class ManageBulletin : public QWidget
{
	Q_OBJECT

public:
	ManageBulletin(QWidget *parent = nullptr);
	~ManageBulletin();

	Ui::ManageBulletinClass* getUi();


signals:
	void modeEdit();

private:
	Ui::ManageBulletinClass *ui;
};
