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
void recordStars();
void recordDelete();
void recordReset(); //7

string dummy;
MYSQL_ROW row;
MYSQL_RES *res;
MYSQL *conn, mysql;

const char *server = "localhost";
const char *user = "root";
const char *password = "Monze@2019";
const char *database = "presly";

string TABLE_DROP = "DROP TABLE IF EXISTS CONTACTSBOOK";
string TABLE_CREAT = "CREATE TABLE CONTACTSBOOK (id SERIAL PRIMARY KEY,pname TEXT NOT NULL, pnumber1 BIGINT NOT NULL,pnumber2 BIGINT,pstars BIGINT, created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP);";
string TABLE_INSERT = "INSERT INTO CONTACTSBOOK(pname,pnumber1,pnumber2,pstars) VALUES('POLICPP-MySQL', 1992020,223467,23),('HOSPCPP-MySQL',2882020,12356,79);";
string TABLE_SELECT = "SELECT * FROM contactsbook order by id LIMIT 10";

const char *TABLE_DROPX = TABLE_DROP.c_str();
const char *TABLE_CREATX = TABLE_CREAT.c_str();
const char *TABLE_INSERTX = TABLE_INSERT.c_str();
const char *TABLE_SELECTX = TABLE_SELECT.c_str();

int main()
{
    int activeRun = 1;
    int activeChoice;

    mysql_init(&mysql);
    conn = mysql_real_connect(&mysql, server, user, password, database, 0, 0, 0);

    while (activeRun == 1)
    {
        cout << endl
             << endl
             << "==================================================================" << endl
             << "         CONTACTS APPLICATION CONSOLE MySQL Vers. 1.1            " << endl
             << "=================================================================" << endl
             << endl
             << "1. Add new contact-detail in records" << endl
             << "2. Reading contact lists from records" << endl
             << "3. Find an existing contact record" << endl
             << endl
             << "4. Update existing contact book" << endl
             << "5. Upgrade favourite points to contact" << endl
             << "6. Delete an existing contact record" << endl
             << endl
             << "7. Reset and format all contact records " << endl
             << "8. End the console application and exit" << endl
             << endl
             << endl
             << "===================================================================" << endl;
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
            recordStars();
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
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, server, user, password, database, 0, 0, 0);
    if (conn)
    {
        int qstate = 0, pnumber1, pnumber2, pstars;
        string name;
        cout << "Enter new contact name  : ";
        cin >> name;
        cout << "Enter new Mobile number : ";
        cin >> pnumber1;
        cout << "Enter new Office number : ";
        cin >> pnumber2;
        cout << "Enter new Favourite number : ";
        cin >> pstars;
        stringstream ss;
        ss << "INSERT INTO CONTACTSBOOK(pname, pnumber1, pnumber2,pstars) VALUES('" << name << "'," << pnumber1 << "," << pnumber2 << "," << pstars << ")";
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
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, server, user, password, database, 0, 0, 0);
    string TABLE_SELECT = "SELECT * FROM contactsbook order by id LIMIT 10";
    const char *TABLE_SELECTX = TABLE_SELECT.c_str();
    if (conn)
    {
        int qstate = mysql_query(conn, TABLE_SELECTX);
        if (!qstate)
        {
            res = mysql_store_result(conn);
            while (row = mysql_fetch_row(res))
            {
         cout << "id| \t" << row[0] << "\t Name|\t" << row[1] << "\t Mobile|\t"
         << row[2] << "\t Office|\t" << row[3] << "\t Stars|\t" << row[4] << endl;
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

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, server, user, password, database, 0, 0, 0);

    if (conn)
    {
        string pname;
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
             cout << "id| \t" << row[0] << "\t Name|\t" << row[1] << "\t Mobile|\t"
             << row[2] << "\t Office|\t" << row[3] << "\t Stars|\t" << row[4] << endl;
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
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, server, user, password, database, 0, 0, 0);
    if (conn)
    {
        int qstate = 0;
        int id, pnumber1, pnumber2, pstars;
        string pname;

        cout << "Enter contact-no. to update : ";
        cin >> id;
        cout << "Enter updated contact name : ";
        cin >> pname;
        cout << "Enter Mobile contact number: ";
        cin >> pnumber1;
        cout << "Enter Office contact number : ";
        cin >> pnumber2;
        cout << "Enter contact star number : ";
        cin >> pstars;

        stringstream ss;
        ss << "UPDATE CONTACTSBOOK SET pname = '" << pname << "' , pnumber1 = " << pnumber1 << " , pnumber2 = "
           << pnumber2 << " , pstars = " << pstars << " WHERE id = " << id << "";
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

void recordStars() /////
{
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, server, user, password, database, 0, 0, 0);
    if (conn)
    {
        int qstate = 0, id, pstars;
        string pname;
        cout << "Enter increase on contact points : ";
        cin >> pstars;
        cout << "Enter contact-no. id to increase : ";
        cin >> id;

        stringstream ss;
        ss << "UPDATE CONTACTSBOOK SET pnumber1 = pstars + " << pstars << " WHERE id = '" << id << "'";
        string query = ss.str();

        const char *q = query.c_str();
        qstate = mysql_query(conn, q);
        if (qstate == 0)
        {
            cout << " Favourite status number increased ..." << endl;
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
    int id, qstate = 0;
    string pname;
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
             cout << "id| \t" << row[0] << "\t Name|\t" << row[1] << "\t Mobile|\t"
             << row[2] << "\t Office|\t" << row[3] << "\t Stars|\t" << row[4] << endl;
            }
        }
    }

    cout << "\n Enter XY to go back >> ... >>";
    cin >> dummy;

    system("pause");
    system("cls");
}
