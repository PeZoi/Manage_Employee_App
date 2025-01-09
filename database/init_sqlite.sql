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

BEGIN;

CREATE TABLE IF NOT EXISTS exception (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    name VARCHAR(255),
    paidHours VARCHAR(255),
    paidCoefficient DOUBLE,
    workCoefficient DOUBLE,
    isCaculate INTEGER NOT NULL DEFAULT 0
);

INSERT OR IGNORE INTO exception (name, paidHours, paidCoefficient, workCoefficient)
VALUES 
    ('Sickly', '08:00', 1.0, 1.0),
    ('Vacation', '08:00', 1.0, 1.0),
    ('Holiday', '08:00', 1.0, 1.0);

COMMIT;

CREATE TABLE IF NOT EXISTS Bulletin (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    title VARCHAR(255) NOT NULL,
    content TEXT NOT NULL,
    start_date VARCHAR(255) NOT NULL,
    end_date VARCHAR(255) NOT NULL,
    is_active INTEGER DEFAULT 0,
    is_priority INTEGER DEFAULT 0,
    type VARCHAR(50) NOT NULL
);

CREATE TABLE IF NOT EXISTS Bulletin_Detail (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    bulletin_id INTEGER NOT NULL,
    department_id INTEGER,
    employee_id INTEGER,
    FOREIGN KEY (bulletin_id) REFERENCES Bulletin(id)
);