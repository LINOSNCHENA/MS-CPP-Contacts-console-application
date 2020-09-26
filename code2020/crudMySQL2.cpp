//#include <iostream>
//#include <windows.h>
//#include <mysql.h>
//#include <sstream>
//#include <stdio.h>
//
//using namespace std;
//
//bool dbconn();
//void addRecord();
//void increaseRecord();
//void findmed();
//void recordViews();
//void recordUpdate();
//
//MYSQL *conn, mysql;
//const char *server = "localhost";
//const char *user = "root";
//const char *password = "Monze@2019";
//const char *database = "presly";
//
//int main()
//{
//
//    mysql_init(&mysql);
//    conn = mysql_real_connect(&mysql, server, user, password, database, 0, 0, 0);
//    int runforever = 1;
//    int ans;
//
//    while (runforever == 1)
//    {
//
//        cout << endl
//             << endl
//             << "---------------" << endl
//             << endl
//             << "1. Add Contact-Medicine Record" << endl
//             << "2. Edit Contact-Medicine Record" << endl
//             << "3. Find / Sell Contact-Medicine" << endl
//             << "--------=====================-------" << endl
//
//             << "4. Update / Sell Contact-Medicine" << endl
//             << "5. reading View contact book " << endl
//             << "6. End the application" << endl
//             << endl
//             << endl
//             << "---------------" << endl;
//
//        cout << endl
//             << "Your Answer / Selection : ";
//
//        cin >> ans;
//
//        switch (ans)
//        {
//        case 1:
//            addRecord();
//            break;
//        case 2:
//            increaseRecord();
//            break;
//        case 3:
//            findmed();
//            break;
//
//        case 4:
//            recordUpdate();
//        case 5:
//            recordViews();
//            break;
//            break;
//        case 6:
//            runforever = 0;
//            break;
//        }
//    }
//
//    return 0;
//}
//
//void addRecord()
//{
//    string dummy;
//    MYSQL *conn;
//    conn = mysql_init(0);
//    //  conn = mysql_real_connect(conn, "127.0.0.1", "root", "Monze@2019", "presly", 0, NULL, 0);
//    conn = mysql_real_connect(conn, server, user, password, database, 0, 0, 0);
//    if (conn)
//    {
//        int qstate = 0, pnumber2;
//        string name, pnumber1;
//
//        cout << "Enter name/NAME : ";
//        cin >> name;
//
//        cout << "Enter location/Mobile : ";
//        cin >> pnumber1;
//
//        cout << "Enter pnumber1/Office : ";
//        cin >> pnumber2;
//
//        stringstream ss;
//        ss << "INSERT INTO CONTACTSBOOK(pname, pnumber1, pnumber2) VALUES('" << name << "','" << pnumber1 << "'," << pnumber2 << ")";
//
//        string query = ss.str();
//        const char *q = query.c_str();
//        qstate = mysql_query(conn, q);
//        if (qstate == 0)
//        {
//            cout << "Record Inserted..." << endl;
//            cout << "Press B to go back" << endl;
//            cin >> dummy;
//        }
//        else
//        {
//            cout << "Insert Error" << mysql_error(conn) << endl;
//            cout << "Press B to go back" << endl;
//            cin >> dummy;
//        }
//    }
//    else
//    {
//        cout << "Connection Error" << endl;
//        cout << "Press B to go back" << endl;
//        cin >> dummy;
//    }
//
//    system("pause");
//    system("cls");
//}
//
//void recordUpdate()
//{
//    string dummy;
//    MYSQL *conn;
//    conn = mysql_init(0);
//    //  conn = mysql_real_connect(conn, "127.0.0.1", "root", "Monze@2019", "presly", 0, NULL, 0);
//    conn = mysql_real_connect(conn, server, user, password, database, 0, 0, 0);
//    if (conn)
//    {
//        int qstate = 0;
//        int id, pnumber1, pnumber2;
//        string pname;
//
//        cout << "Enter ID. No. to Update : ";
//        cin >> id;
//        cout << "Enter name/NAME pname : ";
//        cin >> pname;
//        cout << "Enter location/Mobile : ";
//        cin >> pnumber1;
//        cout << "Enter pnumber1/Office : ";
//        cin >> pnumber2;
//
//        stringstream ss;
//        ss << "UPDATE CONTACTSBOOK SET pname=" << pname << " , pnumber1 =" << pnumber1 << " , pnumber2= " << pnumber2 << " WHERE id = " << id << "";
//
//        string query = ss.str();
//        const char *q = query.c_str();
//        qstate = mysql_query(conn, q);
//        if (qstate == 0)
//        {
//            cout << "Record Inserted..." << endl;
//            cout << "Press B to go back" << endl;
//            cin >> dummy;
//        }
//        else
//        {
//            cout << "Insert Error" << mysql_error(conn) << endl;
//            cout << "Press B to go back" << endl;
//            cin >> dummy;
//        }
//    }
//    else
//    {
//        cout << "Connection Error" << endl;
//        cout << "Press B to go back" << endl;
//        cin >> dummy;
//    }
//
//    system("pause");
//    system("cls");
//}
//
//void increaseRecord()
//{
//    string dummy;
//    MYSQL *conn;
//    conn = mysql_init(0);
//    conn = mysql_real_connect(conn, server, user, password, database, 0, 0, 0);
//    if (conn)
//    {
//        int qstate = 0;
//        string pname;
//        int id, pnumber1;
//        cout << "Enter Name ID: ";
//        cin >> id;
//        cout << "Enter Name : ";
//        cin >> pname;
//        cout << "Enter Quantity Increases: ";
//        cin >> pnumber1;
//
//        stringstream ss;
//        ss << "UPDATE CONTACTSBOOK SET pnumber1 = pnumber1 + " << pnumber1 << " WHERE id = '" << id << "'";
//        string query = ss.str();
//
//        const char *q = query.c_str();
//        qstate = mysql_query(conn, q);
//        if (qstate == 0)
//        {
//            cout << "Record Updated..." << endl;
//            cout << "Press B to go back" << endl;
//            cin >> dummy;
//        }
//        else
//        {
//            cout << "Insert Error" << mysql_error(conn) << endl;
//            cout << "Press B to go back" << endl;
//            cin >> dummy;
//        }
//    }
//    else
//    {
//        cout << "Connection Error" << endl;
//        cout << "Press B to go back" << endl;
//        cin >> dummy;
//    }
//
//    system("pause");
//    system("cls");
//}
//
//void findmed()
//{
//    string dummy;
//    MYSQL *conn;
//    MYSQL *conn2;
//    MYSQL_ROW row;
//    MYSQL_RES *res;
//    conn = mysql_init(0);
//    conn = mysql_real_connect(conn, server, user, password, database, 0, 0, 0);
//
//    // conn2 = mysql_init(0);
//    // conn = mysql_real_connect(conn, server, user, password, database, 0, 0, 0);
//
//    if (conn)
//    {
//
//        string name;
//        int pnumber1;
//        int id;
//        cout << "Enter Name ID: ";
//        cin >> id;
//        cout << "Enter Name : ";
//        cin >> name;
//        cout << "Enter Quantity : ";
//        cin >> pnumber1;
//
//        int qstate1 = 0;
//
//        stringstream ss1;
//        ss1 << "UPDATE CONTACTSBOOK SET pnumber1 = pnumber1 + " << pnumber1 << " WHERE id = '" << id << "'";
//        string query1 = ss1.str();
//
//        const char *q1 = query1.c_str();
//        qstate1 = mysql_query(conn, q1); //   qstate1 = mysql_query(conn2, q1);
//        if (qstate1 == 0)
//        {
//            cout << "Record Updated..." << endl;
//        }
//        else
//        {
//            cout << "Insert Error" << mysql_error(conn) << endl;
//        }
//    }
//
//    cout << "Press B to go back";
//    cin >> dummy;
//
//    system("pause");
//    system("cls");
//}
//
//void recordViews()
//{
//    string dummy;
//    MYSQL *conn;
//    MYSQL_ROW row;
//    MYSQL_RES *res;
//    conn = mysql_init(0);
//    conn = mysql_real_connect(conn, server, user, password, database, 0, 0, 0);
//    if (conn)
//    {
//        int qstate = mysql_query(conn, "SELECT id, pname, pnumber1, pnumber2 FROM contactsbook");
//
//        if (!qstate)
//        {
//            res = mysql_store_result(conn);
//
//            while (row = mysql_fetch_row(res))
//            {
//                cout << row[0] << "\t | \t" << row[1] << "\t | \t" << row[2] << "\t | \t" << row[3] << endl
//                     << endl;
//            }
//        }
//    }
//
//    cout << "Press B to go back";
//    cin >> dummy;
//
//    system("pause");
//    system("cls");
//}
