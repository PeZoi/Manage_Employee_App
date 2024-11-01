#pragma once
#include <QString>
#include <QList>

class DepartmentModel
{
public:
    // Constructors
    DepartmentModel() = default;
    DepartmentModel(const QString & name, const QString & description);

    // Getter và Setter cho `name`
    QString getName() const;
    void setName(const QString & name);

    // Getter và Setter cho `description`
    QString getDescription() const;
    void setDescription(const QString & description);

private:
    QString name;
    QString description;
};

