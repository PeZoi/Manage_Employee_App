#pragma once
#include <QString>
#include <QList>

class DepartmentModel
{
public:
    DepartmentModel() = default;
    DepartmentModel(const QString & name, const QString & description);
    DepartmentModel(const QString & name, const QString & description, const bool & isDeleted);

    QString getName() const;
    void setName(const QString & name);

    QString getDescription() const;
    void setDescription(const QString & description);

    bool getIsDeleted() const;

private:
    QString name;
    QString description;
    bool isDeleted;
};

