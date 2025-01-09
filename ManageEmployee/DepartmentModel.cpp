
#include "DepartmentModel.h"

DepartmentModel::DepartmentModel(const QString& name, const QString& description)
	: name(name), description(description) {}

DepartmentModel::DepartmentModel(const QString& name, const QString& description, const bool& isDeleted)
	: name(name), description(description), isDeleted(isDeleted) {}

QString DepartmentModel::getName() const { return name; }
void DepartmentModel::setName(const QString& name) { this->name = name; }

QString DepartmentModel::getDescription() const { return description; }
void DepartmentModel::setDescription(const QString& description) { this->description = description; }

bool DepartmentModel::getIsDeleted() const {
	return isDeleted;
}