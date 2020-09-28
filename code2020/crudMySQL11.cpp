#include <iostream>
#include <windows.h>
#include <mysql.h>
#include <sstream>
#include <stdio.h>

using namespace std;

bool dbconn();
void recordAdd();
void recordViews();
void recordFind();
void recordUpdate();
void recordIncrease();
void recordDelete();
void recordReset(); //7

MYSQL *conn, mysql;
const char *server = "localhost";
const char *user = "root";
const char *password = "Monze@2019";
const char *database = "presly";

const char *INSERT_INTO_CONTACTS = "INSERT INTO CONTACTSBOOK (pname, pnumber1,pnumber2) VALUES (?,?,?)";
const char *FIND_CONTACT_BY_NAME = "SELECT * FROM CONTACTSBOOK WHERE pname LIKE '%";
const char *FIND_ALL_CONTACTS = "SELECT * FROM CONTACTSBOOK order by id";
const char *UPDATE_ONE_CONTACT = "UPDATE CONTACTSBOOK SET pname=?, pnumber1=?,pnumber2=? WHERE id=?";
const char *DELETE_ONE_CONTACT = "DELETE FROM CONTACTSBOOK WHERE id = ?";
const char *DELETE_ALL_CONTACTS = "DELETE FROM CONTACTSBOOK WHERE id > 6;";
const char *DROP_TABLE = "DROP TABLE IF EXISTS CONTACTSBOOK;";
const char *CREATE_TABLE = "CREATE TABLE CONTACTSBOOK (id SERIAL PRIMARY KEY,pname TEXT NOT NULL, pnumber1 BIGINT NOT NULL,pnumber2 BIGINT, created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP);";
const char *INSERT_TABLE = "INSERT INTO CONTACTSBOOK(pname,pnumber1,pnumber2) VALUES('POLICE-EMERGENCE', 1992020,223467890),('HOSPITAL-EMERGENCY',2882020,12356789);";

string TABLE_DROP = "DROP TABLE IF EXISTS CONTACTSBOOK";
string TABLE_CREAT = "CREATE TABLE CONTACTSBOOK (id SERIAL PRIMARY KEY,pname TEXT NOT NULL, pnumber1 BIGINT NOT NULL,pnumber2 BIGINT, created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP);";
string TABLE_INSERT = "INSERT INTO CONTACTSBOOK(pname,pnumber1,pnumber2) VALUES('ZAMBI-CPP-PG', 1992020,223467890),('HOSPITAL-CPP-PG',2882020,12356789);";
string TABLE_UPDATE = "UPDATE contactsbook SET pname='GERMANY2020' WHERE Id=3";
string TABLE_SELECT = "SELECT * FROM contactsbook order by id LIMIT 10"; // FIVE
string dummy;
string TABLE_DECLARED = "DECLARE myContactsPreset CURSOR FOR select * from contactsbook order by id LIMIT 15";
string TABLE_FETCHED = "FETCH ALL in myContactsPreset";

const char *TABLE_DROPX = TABLE_DROP.c_str();
const char *TABLE_CREATX = TABLE_CREAT.c_str();
const char *TABLE_INSERTX = TABLE_INSERT.c_str();
const char *TABLE_UPDATEX = TABLE_UPDATE.c_str();
const char *TABLE_SELECTX = TABLE_SELECT.c_str();
const char *TABLE_DECLAREX = TABLE_DECLARED.c_str();
const char *TABLE_FETCHEDX = TABLE_FETCHED.c_str();

int main()
{

    mysql_init(&mysql);
    conn = mysql_real_connect(&mysql, server, user, password, database, 0, 0, 0);
    int activeRun = 1;
    int activeChoice;

    while (activeRun == 1)
    {
        cout << endl
             << endl
             << "=====================================================" << endl
             << " CONTACTS APPLICATION CONSOLE MySQL Vers. 1.1" << endl
             << "=====================================================" << endl
             << endl
             << "1. Add new contact-detail in records" << endl
             << "2. Reading contact lists from records" << endl
             << "3. Find an existing contact record" << endl
             << endl
             << "4. Update existing contact book" << endl
             << "5. Upgrade an existing record points" << endl
             << "6. Delete an existing contact record" << endl
             << endl
             << "7. Reset and format all contact records " << endl
             << "8. End the console application and exit" << endl
             << endl
             << endl
             << "=====================================================" << endl;
        cout << endl
             << "Your Option and Selection : ";
        cin >> activeChoice;

        switch (activeChoice)
        {
        case 1:
            recordAdd();
            break;
        case 2:
            recordViews();
            break;
        case 3:
            recordFind();
            break;
        case 4:
            recordUpdate();
            break;
        case 5:
            recordIncrease();
            break;
        case 6:
            recordDelete();
            break;

        case 7:
            recordReset();
            break;
        case 8:
            activeRun = 0;
            break;
        }
    }

    return 0;
}

void recordAdd()
{
    string dummy;
    MYSQL *conn;
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, server, user, password, database, 0, 0, 0);
    if (conn)
    {
        int qstate = 0, pnumber1, pnumber2;
        string name;
        cout << "Enter new contact name  : ";
        cin >> name;
        cout << "Enter new Mobile number : ";
        cin >> pnumber1;
        cout << "Enter new Office number : ";
        cin >> pnumber2;
        stringstream ss;
        ss << "INSERT INTO CONTACTSBOOK(pname, pnumber1, pnumber2) VALUES('" << name << "','" << pnumber1 << "'," << pnumber2 << ")";
        string query = ss.str();
        const char *q = query.c_str();
        qstate = mysql_query(conn, q);
        if (qstate == 0)
        {
            cout << "Record Inserted..." << endl;
            cout << "\n Enter XY to go back >> ... >>";
            cin >> dummy;
        }
    }
    else
    {
        cout << "Connection Error" << endl;
        cout << "Press Z to go back" << endl;
        cin >> dummy;
    }

    system("pause");
    system("cls");
}

void recordViews() ////////////////////////////////////////////////////////////////////////////////////   READING  #2
{
    string dummy;
    MYSQL *conn;
    MYSQL_ROW row;
    MYSQL_RES *res;
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, server, user, password, database, 0, 0, 0);
    if (conn)
    {
        int qstate = mysql_query(conn, "SELECT id, pname, pnumber1, pnumber2,created_at FROM contactsbook");

        if (!qstate)
        {
            res = mysql_store_result(conn);
            while (row = mysql_fetch_row(res))
            {
                cout << row[0] << "\t |X1 \t" << row[1] << "\t |X2 \t" << row[2] << "\t |X3 \t" << row[3] << "\t |X4 \t" << row[4] << endl;
            }
        }
    }

    cout << "\n Enter XY to go back >> ... >>";
    cin >> dummy;

    system("pause");
    system("cls");
}

void recordFind() /////////////////////////////////////
{
    string dummy;
    MYSQL *conn;
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, server, user, password, database, 0, 0, 0);

    if (conn)
    {
        string pname, dummy;
        int id, pnumber1;
        MYSQL_ROW row;
        MYSQL_RES *res;
        MYSQL *conn;

        cout << "Enter name to name search : ";
        cin >> pname;

        conn = mysql_init(0);
        conn = mysql_real_connect(conn, server, user, password, database, 0, 0, 0);

        string FIND_CONTACT_BY_NAME = "SELECT * FROM contactsbook WHERE pname LIKE '%" + pname + "%'";
        const char *q = FIND_CONTACT_BY_NAME.c_str();
        int qstate = mysql_query(conn, q);
        if (!qstate)
        {
            res = mysql_store_result(conn);

            while (row = mysql_fetch_row(res))
            {
                cout << row[0] << "\t |X1 \t" << row[1] << "\t |X2 \t" << row[2] << "\t |X3 \t" << row[3] << "\t |X4 \t" << row[4] << endl
                     << endl;
            }
        }
        else
        {
            cout << "\n ===================== No record found =============== \n";
        }
    }

    cout << "\n Enter XY to go back >> ... >>";
    cin >> dummy;

    system("pause");
    system("cls");
}

void recordUpdate() //////////////////////////////////////////////////////////////////////////////////////////////  #4
{
    string dummy;
    MYSQL *conn;
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, server, user, password, database, 0, 0, 0);
    if (conn)
    {
        int qstate = 0;
        int id, pnumber1, pnumber2;
        string pname;

        cout << "Enter contact-no. to update : ";
        cin >> id;
        cout << "Enter updated contact name : ";
        cin >> pname;
        cout << "Enter Mobile contact number: ";
        cin >> pnumber1;
        cout << "Enter Office contact number : ";
        cin >> pnumber2;

        stringstream ss;
        ss << "UPDATE CONTACTSBOOK SET pname = '" << pname << "' , pnumber1 = " << pnumber1 << " , pnumber2 = " << pnumber2 << " WHERE id = " << id << "";
        string query = ss.str();
        const char *q = query.c_str();
        qstate = mysql_query(conn, q);
        if (qstate == 0)
        {
            cout << "Record Updated..." << endl;
            cout << "\n Enter XY to go back >> ... >>";
            cin >> dummy;
        }
    }
    else
    {
        cout << "Connection Error" << endl;
        cout << "Press Z to go back" << endl;
        cin >> dummy;
    }

    system("pause");
    system("cls");
}

void recordIncrease() /////
{
    string dummy;
    MYSQL *conn;
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, server, user, password, database, 0, 0, 0);
    if (conn)
    {
        int qstate = 0;
        string pname;
        int id, pnumber1;
        cout << "Enter increase on contact points : ";
        cin >> pnumber1;
        cout << "Enter contact-no. id to increase : ";
        cin >> id;

        stringstream ss;
        ss << "UPDATE CONTACTSBOOK SET pnumber1 = pnumber1 + " << pnumber1 << " WHERE id = '" << id << "'";
        string query = ss.str();

        const char *q = query.c_str();
        qstate = mysql_query(conn, q);
        if (qstate == 0)
        {
            cout << "Record mobile number increased ..." << endl;
            cout << "\n Enter XY to go back >> ... >>";
            cin >> dummy;
        }
    }
    else
    {
        cout << "Connection Error" << endl;
        cout << "Press Z to go back" << endl;
        cin >> dummy;
    }

    system("pause");
    system("cls");
}

void recordDelete() ///////////////////////////////////////////////////////  INCREASING ELEMENTS  #1
{
    string dummy;
    MYSQL *conn;

    int qstate = 0;
    string pname;
    int id, pnumber1;
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, server, user, password, database, 0, 0, 0);
    if (conn)
    {

        cout << "Enter the contact-ID to delete: ";
        cin >> id;
        stringstream ss;
        ss << "DELETE from CONTACTSBOOK WHERE id = '" << id << "'";
        string query = ss.str();

        const char *q = query.c_str();
        qstate = mysql_query(conn, q);
        if (qstate == 0)
        {
            cout << "Record deleted..." << endl;
            cout << "\n Enter XY to go back >> ... >>";
            cin >> dummy;
        }
    }
    else
    {
        cout << "Connection Error" << endl;
        cout << "Press X to go back" << endl;
        cin >> dummy;
    }

    system("pause");
    system("cls");
}
void recordReset() //////////////////////////////////////////////////////////////////////////   READING  #2
{

    MYSQL *conn;
    MYSQL_ROW row;
    MYSQL_RES *res;
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, server, user, password, database, 0, 0, 0);
    if (conn)
    {
        mysql_query(conn, TABLE_DROPX);
        mysql_query(conn, TABLE_CREATX);
        mysql_query(conn, TABLE_INSERTX);
        int qstate = mysql_query(conn, TABLE_SELECTX);
        if (!qstate)
        {
            res = mysql_store_result(conn);
            while (row = mysql_fetch_row(res))
            {
                cout << row[0] << "\t |X1 \t" << row[1] << "\t |X2 \t" << row[2] << "\t |X3 \t" << row[3] << "\t |X4 \t" << row[4] << endl
                     << endl;
            }
        }
    }

    cout << "\n Enter XY to go back >> ... >>";
    cin >> dummy;

    system("pause");
    system("cls");
}