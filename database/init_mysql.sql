CREATE TABLE IF NOT EXISTS department (
    name VARCHAR(255) PRIMARY KEY,
    description TEXT,
    is_deleted BOOLEAN NOT NULL DEFAULT 0
);

INSERT IGNORE INTO department (name, description)
VALUES ('Others', '');

CREATE TABLE IF NOT EXISTS employee (
    id VARCHAR(255) PRIMARY KEY,
    first_name VARCHAR(255),
    last_name VARCHAR(255),
    password VARCHAR(255),
    department VARCHAR(255),
    date_of_birth VARCHAR(255),
    start_date_of_work VARCHAR(255),
    status VARCHAR(255),
    is_enabled BOOLEAN NOT NULL DEFAULT 1,
    avatar TEXT,
    role VARCHAR(255),
    email VARCHAR(255),
    phone_number VARCHAR(255),
    address TEXT,
    is_allow_password BOOLEAN NOT NULL DEFAULT 0,
    iri_right LONGBLOB,
    iri_left LONGBLOB,
    is_deleted BOOLEAN NOT NULL DEFAULT 0,
    FOREIGN KEY (department) REFERENCES department(name)
);

CREATE TABLE IF NOT EXISTS attendance_event (
    id INT AUTO_INCREMENT PRIMARY KEY,
    type_event VARCHAR(255),
    date_event VARCHAR(255),
    time_event VARCHAR(255),
    exception INT,
    session INT,
    employee_id VARCHAR(255),
    FOREIGN KEY (employee_id) REFERENCES employee(id)
);


BEGIN;

CREATE TABLE IF NOT EXISTS exception (
    id INT AUTO_INCREMENT PRIMARY KEY,
    `name` VARCHAR(255),
    paidHours VARCHAR(255),
    paidCoefficient DOUBLE,
    workCoefficient DOUBLE,
    isCaculate BOOLEAN NOT NULL DEFAULT 0
);

IF NOT EXISTS (SELECT 1 FROM exception WHERE name = 'Sickly') THEN
    INSERT INTO exception (name, paidHours, paidCoefficient, workCoefficient)
    VALUES ('Sickly', '08:00', 1.0, 1.0);
END IF;

IF NOT EXISTS (SELECT 1 FROM exception WHERE name = 'Vacation') THEN
    INSERT INTO exception (name, paidHours, paidCoefficient, workCoefficient)
    VALUES ('Vacation', '08:00', 1.0, 1.0);
END IF;

IF NOT EXISTS (SELECT 1 FROM exception WHERE name = 'Holiday') THEN
    INSERT INTO exception (name, paidHours, paidCoefficient, workCoefficient)
    VALUES ('Holiday', '08:00', 1.0, 1.0);
END IF;

COMMIT;

