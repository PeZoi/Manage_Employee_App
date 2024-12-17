#pragma once
#include <QString>
#include <QList>

class DepartmentModel
{
public:
    DepartmentModel() = default;
    DepartmentModel(const QString & name, const QString & description);

    QString getName() const;
    void setName(const QString & name);

    QString getDescription() const;
    void setDescription(const QString & description);

private:
    QString name;
    QString description;
};

