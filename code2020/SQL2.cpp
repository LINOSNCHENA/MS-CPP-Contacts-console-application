//// CHH-VERSION OF FONE BOOK  v 1.2
////  ===================================
//
//#include <mysql.h>
//#include <iostream>
//#include <iomanip>
//#include <fstream>
//
//using namespace std;
//
//MYSQL* conn, mysql;
//MYSQL_RES* res;
//MYSQL_ROW row;
//
//int query_state;
//
//int main()
//{
//    const char* server = "localhost";
//    const char* user = "root";
//    const char* password = "Monze@2019";
//    const char* database = "presly";
//
//    mysql_init(&mysql);
//    conn = mysql_real_connect(&mysql, server, user, password, database, 0, 0, 0);
//    if (conn == NULL)
//    {
//        cout << mysql_error(&mysql) << endl << endl;
//        return 1;
//    }
//    query_state = mysql_query(conn, "select * from contactsbook");
//    if (query_state != 0)
//    {
//        cout << mysql_error(conn) << endl << endl;
//        return 1;
//    }
//    res = mysql_store_result(conn);
//    printf("============================x1=============================\n");
//    cout << "MySQL Tables in mysql database." << endl << endl;
//    while ((row = mysql_fetch_row(res)) != NULL)
//    {
//        cout << left;
//        cout << setw(18) << row[0]
//            << setw(18) << row[1]
//            << setw(18) << row[2]
//            << setw(18) << row[3] << endl;
//    }
//    cout << endl << endl;
//    printf("==============================x2===========================\n");
//    ifstream infile;
//    infile.open("contactsbook.txt");//  infile.open("Instrument.txt");
//    if (infile.fail())
//    {
//        cout << "ERROR. Could not open file!" << endl;
//        return 1;
//    }
//    infile.seekg(0, infile.end);
//    int len = infile.tellg();
//    infile.seekg(0, infile.beg);
//    string instnum, insttype, maker, year, plID, name, salary, startdate;
//    string rating;
//    int pnumber1, pnumber2;
//   // string instrument = "INSERT INTO contactsbook (pname, pnumber1, pnumber2) VALUES ( " + instnum, pnumber1, pnumber2 ")";
//    // statement = connection.prepareStatement(FIND_CONTACT_BY_NAME + pname + "%'");
//    //  prep_stmt = con->prepareStatement("INSERT INTO product(name,price,created) VALUES(?,?,NOW())");
//    string player = "INSERT INTO Player (PlayerID, Name, Salary, StartDate) values (plID, name, salary, startdate)";
//    string plays = "INSERT INTO Plays (InstrumentID, PlayerID, Rating) values (instnum, plID, rating)";
//
//
//   // CREATE TABLE CONTACTSBOOK(id SERIAL PRIMARY KEY, pname TEXT NOT NULL, pnumber1 BIGINT NOT NULL, pnumber2 BIGINT);
//  //  INSERT INTO CONTACTSBOOK(pname, pnumber1, pnumber2) VALUES('POLICE-EMERGENCE', 1992020, 223467890), ('HOSPITAL-EMERGENCY', 2882020, 12356789);
//
//  //  string instrument = "INSERT INTO Instrument (InstrumentID, InstrumentType, MakerName, YearMade) VALUES ( '" + instnum + "', '" + insttype + "', '" + maker + "', '" + year + "')";
//   // string player = "INSERT INTO Player (PlayerID, Name, Salary, StartDate) values (plID, name, salary, startdate)";
//  //  string plays = "INSERT INTO Plays (InstrumentID, PlayerID, Rating) values (instnum, plID, rating)";
//    //   mysql_query(conn, "DELETE FROM Instrument WHERE MakerName='maker'");
//    while (infile)
//    {
//        infile >> instnum;
//        cout << instnum << endl;
//        infile >> insttype;
//        cout << insttype << endl;
//       // infile >> maker;
//      //  cout << maker << endl;
//        infile >> year;
//        cout << year << endl;
//      //  query_state = mysql_query(conn, instrument.c_str());
//    }
//
//    if (query_state != 0)
//    {
//        cout << mysql_error(conn) << endl << endl;
//        return 1;
//    }
//    cout << endl << endl;
//
//    mysql_free_result(res);
//    mysql_close(conn);
//
//    return 0;
//
//
//}