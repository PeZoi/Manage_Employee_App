#include "ExceptionModel.h"

// Constructor
ExceptionModel::ExceptionModel(int id, const QString& name, const QString& paidHours, float paidCoefficient, float workCoefficient, bool isCaculate)
    : id(id), name(name), paidHours(paidHours), paidCoefficient(paidCoefficient), workCoefficient(workCoefficient), isCaculate(isCaculate) {}

// Default constructor
ExceptionModel::ExceptionModel() : id(0), paidCoefficient(0.0), workCoefficient(0.0), isCaculate(false) {}

// Getters
int ExceptionModel::getId() const { return id; }
QString ExceptionModel::getName() const { return name; }
QString ExceptionModel::getPaidHours() const { return paidHours; }
float ExceptionModel::getPaidCoefficient() const { return paidCoefficient; }
float ExceptionModel::getWorkCoefficient() const { return workCoefficient; }
bool ExceptionModel::getIsCaculate() const { return isCaculate; }

// Setters
void ExceptionModel::setId(int value) { id = value; }
void ExceptionModel::setName(const QString& value) { name = value; }
void ExceptionModel::setPaidHours(const QString& value) { paidHours = value; }
void ExceptionModel::setPaidCoefficient(float value) { paidCoefficient = value; }
void ExceptionModel::setWorkCoefficient(float value) { workCoefficient = value; }
void ExceptionModel::setIsCaculate(bool value) { isCaculate = value; }