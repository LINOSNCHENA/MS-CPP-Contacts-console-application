FLUSH PRIVILEGES;
DROP USER 'postgres'@'localhost';
CREATE USER 'postgres'@'localhost' IDENTIFIED BY 'Monze@2019';
GRANT ALL PRIVILEGES ON *.* TO 'postgres'@'localhost' WITH GRANT OPTION;
FLUSH PRIVILEGES;


DROP TABLE IF EXISTS Account;
CREATE TABLE Account(  
        user_id serial PRIMARY KEY,
        username VARCHAR (50) NOT NULL,
        balance integer NOT NULL
);
INSERT INTO Account VALUES(1,'johndoe',52642);
INSERT INTO Account VALUES(2,'janedoe',45672);
INSERT INTO Account VALUES(3,'leotolo',34322);
INSERT INTO Account VALUES(4,'stephanfera',323);
INSERT INTO Account VALUES(5,'markzuc',3325);
INSERT INTO Account VALUES(6,'ahmadbala',6544);



DROP TABLE IF EXISTS CONTACTSBOOK;
CREATE TABLE CONTACTSBOOK (id SERIAL PRIMARY KEY,pname TEXT NOT NULL, pnumber1 BIGINT NOT NULL,pnumber2 BIGINT, created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP);
INSERT INTO CONTACTSBOOK(pname,pnumber1,pnumber2) VALUES('POLICE-EMERGENCE', 1992020,223467890),('HOSPITAL-EMERGENCY',2882020,12356789);
select * from CONTACTSBOOK;

