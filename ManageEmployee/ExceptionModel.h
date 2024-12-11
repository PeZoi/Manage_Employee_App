#pragma once
#include <QString>
class ExceptionModel
{
private:
	int id;
	QString name;
	QString paidHours;
	float paidCoefficient;
	float workCoefficient;
	bool isCaculate;
public:
    // Constructor
    ExceptionModel(int id, const QString &name, const QString &paidHours, float paidCoefficient, float workCoefficient, bool isCaculate);

    // Default constructor
    ExceptionModel();

    // Getters
    int getId() const;
    QString getName() const;
    QString getPaidHours() const;
    float getPaidCoefficient() const;
    float getWorkCoefficient() const;
    bool getIsCaculate() const;

    // Setters
    void setId(int value);
    void setName(const QString &value);
    void setPaidHours(const QString &value);
    void setPaidCoefficient(float value);
    void setWorkCoefficient(float value);
    void setIsCaculate(bool value);
};

