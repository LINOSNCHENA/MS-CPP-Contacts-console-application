#include <iostream>
#include <windows.h>
#include <mysql.h>
#include <sstream>
#include <stdio.h>

using namespace std;

bool dbconn();
void addRecord();
void increaseRecord();
void findmed();
void recordViews();
void recordUpdate();
void recordReset();

MYSQL *conn, mysql;
const char *server = "localhost";
const char *user = "root";
const char *password = "Monze@2019";
const char *database = "presly";

int main()
{

    mysql_init(&mysql);
    conn = mysql_real_connect(&mysql, server, user, password, database, 0, 0, 0);
    int runforever = 1;
    int ans;

    while (runforever == 1)
    {

        cout << endl
             << endl
             << "=====================================================" << endl
             << endl
             << "1. Add Contact-phone Record" << endl
             << "2. Edit Contact-phone Record" << endl
             << "3. Find / upgrade Contact-record" << endl
              << "4. Update / Sell Contact" << endl
             << "5. Reading View contact book " << endl
             << "6. Reset and Format contact book " << endl
             << "7. End the console application" << endl
             << endl
             << endl
             << "=====================================================" << endl;

        cout << endl
             << "Your Option and Selection : ";

        cin >> ans;

        switch (ans)
        {
        case 1:
            addRecord();
            break;
        case 2:
            increaseRecord();
            break;
        case 3:
            findmed();
            break;
        case 4:
            recordUpdate();
            break;
        case 5:
            recordViews();
            break;
        case 6:
            recordReset();
            break;
        case 7:
            runforever = 0;
            break;
        }
    }

    return 0;
}

void addRecord() //////////////////////////////////////// #5
{
    string dummy;
    MYSQL *conn;
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, server, user, password, database, 0, 0, 0);
    if (conn)
    {
        int qstate = 0, pnumber1, pnumber2;
        string name;
        cout << "Enter contact name  : ";
        cin >> name;
        cout << "Enter Mobile number : ";
        cin >> pnumber1;
        cout << "Enter Office number : ";
        cin >> pnumber2;
        stringstream ss;
        ss << "INSERT INTO CONTACTSBOOK(pname, pnumber1, pnumber2) VALUES('" << name << "','" << pnumber1 << "'," << pnumber2 << ")";
        string query = ss.str();
        const char *q = query.c_str();
        qstate = mysql_query(conn, q);
        if (qstate == 0)
        {
            cout << "Record Inserted..." << endl;
            cout << "Press B to go back" << endl;
            cin >> dummy;
        }
        else
        {
            cout << "Insert Error" << mysql_error(conn) << endl;
            cout << "Press B to go back" << endl;
            cin >> dummy;
        }
    }
    else
    {
        cout << "Connection Error" << endl;
        cout << "Press B to go back" << endl;
        cin >> dummy;
    }

    system("pause");
    system("cls");
}

void recordUpdate() ///////////////////////////  #4
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

        cout << "Enter ID. No. to Update : ";
        cin >> id;
        cout << "Enter updated Nname : ";
        cin >> pname;
        cout << "Enter Mobile number: ";
        cin >> pnumber1;
        cout << "Enter Office number : ";
        cin >> pnumber2;

        stringstream ss;
        ss << "UPDATE CONTACTSBOOK SET pname = '" << pname << "' , pnumber1 = " << pnumber1 << " , pnumber2 = " << pnumber2 << " WHERE id = " << id << "";
        string query = ss.str();
        const char *q = query.c_str();
        qstate = mysql_query(conn, q);
        if (qstate == 0)
        {
            cout << "Record Updated..." << endl;
            cout << "Press B to go back" << endl;
            cin >> dummy;
        }
        else
        {
            cout << "Insert Error" << mysql_error(conn) << endl;
            cout << "Press B to go back" << endl;
            cin >> dummy;
        }
    }
    else
    {
        cout << "Connection Error" << endl;
        cout << "Press B to go back" << endl;
        cin >> dummy;
    }

    system("pause");
    system("cls");
}

void findmed() /// UPDATE OR FIND  #3
{
    string dummy;
    MYSQL *conn;
    MYSQL *conn2;
    MYSQL_ROW row;
    MYSQL_RES *res;
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, server, user, password, database, 0, 0, 0);

    // conn2 = mysql_init(0);
    // conn = mysql_real_connect(conn, server, user, password, database, 0, 0, 0);

    if (conn)
    {
        string name;
        int pnumber1;
        int id;
        cout << "Enter Find Name ID: ";
        cin >> id;
        cout << "Enter Find Name : ";
        cin >> name;
        cout << "Enter Find pnumber1 : ";
        cin >> pnumber1;
        int qstate1 = 0;

        stringstream ss1;
        ss1 << "UPDATE CONTACTSBOOK SET pnumber1 = pnumber1 + " << pnumber1 << " WHERE id = '" << id << "'";
        string query1 = ss1.str();

        const char *q1 = query1.c_str();
        qstate1 = mysql_query(conn, q1); //   qstate1 = mysql_query(conn2, q1);
        if (qstate1 == 0)
        {
            cout << "Record Updated..." << endl;
        }
        else
        {
            cout << "Insert Error" << mysql_error(conn) << endl;
        }
    }

    cout << "Press B to go back";
    cin >> dummy;

    system("pause");
    system("cls");
}

void recordViews() ///////////////   READING  #2
{
    string dummy;
    MYSQL *conn;
    MYSQL_ROW row;
    MYSQL_RES *res;
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, server, user, password, database, 0, 0, 0);
    if (conn)
    {
        int qstate = mysql_query(conn, "SELECT id, pname, pnumber1, pnumber2 FROM contactsbook");

        if (!qstate)
        {
            res = mysql_store_result(conn);

            while (row = mysql_fetch_row(res))
            {
                cout << row[0] << "\t | \t" << row[1] << "\t | \t" << row[2] << "\t | \t" << row[3] << endl
                     << endl;
            }
        }
    }

    cout << "Press B to go back";
    cin >> dummy;

    system("pause");
    system("cls");
}

void recordReset() ///////////////   READING  #2
{
    string dummy;
    MYSQL *conn;
    MYSQL_ROW row;
    MYSQL_RES *res;
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, server, user, password, database, 0, 0, 0);
    if (conn)
    {
        mysql_query(conn, "DROP TABLE IF EXISTS CONTACTSBOOK; ");
        mysql_query(conn, "CREATE TABLE CONTACTSBOOK (id SERIAL PRIMARY KEY,pname TEXT NOT NULL, pnumber1 BIGINT NOT NULL,pnumber2 BIGINT);");
        mysql_query(conn, "INSERT INTO CONTACTSBOOK(pname,pnumber1,pnumber2) VALUES('POLICE-EMERGENCE', 1992020,223467890),('HOSPITAL-EMERGENCY',2882020,12356789);");
        int qstate = mysql_query(conn, "SELECT id, pname, pnumber1, pnumber2 FROM contactsbook");
        if (!qstate)
        {
            res = mysql_store_result(conn);

            while (row = mysql_fetch_row(res))
            {
                cout << row[0] << "\t | \t" << row[1] << "\t | \t" << row[2] << "\t | \t" << row[3] << endl
                     << endl;
            }
        }
    }

    cout << "Press B to go back";
    cin >> dummy;

    system("pause");
    system("cls");
}

void increaseRecord() ///////////////  INCREASING ELEMENTS  #1
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
        cout << "Enter INCREASE Name ID: ";
        cin >> id;
        cout << "Enter Name : ";
        cin >> pname;
        cout << "Enter Quantity Increases: ";
        cin >> pnumber1;

        stringstream ss;
        ss << "UPDATE CONTACTSBOOK SET pnumber1 = pnumber1 + " << pnumber1 << " WHERE id = '" << id << "'";
        string query = ss.str();

        const char *q = query.c_str();
        qstate = mysql_query(conn, q);
        if (qstate == 0)
        {
            cout << "Record Increased tally..." << endl;
            cout << "Press B to go back" << endl;
            cin >> dummy;
        }
        else
        {
            cout << "Insert Error" << mysql_error(conn) << endl;
            cout << "Press B to go back" << endl;
            cin >> dummy;
        }
    }
    else
    {
        cout << "Connection Error" << endl;
        cout << "Press B to go back" << endl;
        cin >> dummy;
    }

    system("pause");
    system("cls");
}
