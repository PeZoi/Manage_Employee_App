CREATE TABLE IF NOT EXISTS department (
	name TEXT PRIMARY KEY, 
	description TEXT,
	is_deleted BOOLEAN NOT NULL DEFAULT 0
);
INSERT OR IGNORE INTO department (name, DESCRIPTION, is_deleted) VALUES ('Others', '', 0);

CREATE TABLE IF NOT EXISTS employee (
id TEXT PRIMARY KEY, 
first_name TEXT, 
last_name TEXT, 
password TEXT, 
department TEXT, 
date_of_birth TEXT, 
start_date_of_work TEXT, 
status TEXT, 
is_enabled BOOLEAN NOT NULL DEFAULT 1, 
avatar TEXT, 
role TEXT, 
email TEXT UNIQUE, 
phone_number TEXT, 
address TEXT, 
is_allow_password BOOLEAN NOT NULL DEFAULT 0, 
iri_right LONGBLOB, 
iri_left LONGBLOB, 
is_deleted BOOLEAN NOT NULL DEFAULT 0,
FOREIGN KEY (department) REFERENCES department(name));

CREATE TABLE IF NOT EXISTS attendance_event (
id INTEGER PRIMARY KEY AUTOINCREMENT, 
type_event TEXT, 
date_event TEXT, 
time_event TEXT, 
exception INTEGER, 
session INTEGER, 
employee_id TEXT, 
FOREIGN KEY(employee_id) REFERENCES employee(id));
