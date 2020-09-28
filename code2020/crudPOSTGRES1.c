//#include <stdio.h>
//#include <stdlib.h>
//#include <libpq-fe.h>
//
//void do_exit(PGconn *conn)
//{
//    PQfinish(conn);
//    exit(1);
//}
//
//int main()
//{
//
//    char *TABLE_DROPX = "DROP TABLE IF EXISTS CONTACTSBOOK";
//    char *TABLE_CREATX = "CREATE TABLE CONTACTSBOOK (id SERIAL PRIMARY KEY,pname TEXT NOT NULL, pnumber1 BIGINT NOT NULL,pnumber2 BIGINT, created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP);";
//    char *TABLE_INSERTX = "INSERT INTO CONTACTSBOOK(pname,pnumber1,pnumber2) VALUES('POLICE-PG', 1992020,223467890),('HOSPITAL-PG',2882020,12356789);";
//    char *TABLE_UPDATEX = "UPDATE contactsbook SET pname='GERMANY2020' WHERE Id=3";
//    char *TABLE_SELECTX = "SELECT * FROM contactsbook order by id LIMIT 10"; // FIVE
//    char *TABLE_DECLARED = "DECLARE myContactsPreset CURSOR FOR select * from contactsbook order by id LIMIT 15";
//    char *TABLE_FETECHED = "FETCH ALL in myContactsPreset";
//
//    PGconn *conn = PQconnectdb("user=postgres password=Monze@2019 dbname=presly host=127.0.0.1 port=5433");
//    if (PQstatus(conn) == CONNECTION_BAD)
//    {
//        fprintf(stderr, "Connection to database failed: %s\n", PQerrorMessage(conn));
//        do_exit(conn);
//    }
//
//    printf("\n===============================FIRST_TRANSACTION_START======================================\n\n");
//    PGresult *res = PQexec(conn, "BEGIN");
//
//    if (PQresultStatus(res) != PGRES_COMMAND_OK)
//    {
//        printf("BEGIN command failed\n");
//        PQclear(res);
//        do_exit(conn);
//    }
//
//    PQclear(res);
//
//    res = PQexec(conn, TABLE_DROPX);
//    if (PQresultStatus(res) != PGRES_COMMAND_OK)
//    {
//        printf("DROP command failed\n");
//        PQclear(res);
//        do_exit(conn);
//    }
//
//    res = PQexec(conn, TABLE_CREATX);
//    if (PQresultStatus(res) != PGRES_COMMAND_OK)
//    {
//        printf("CREATE command failed\n");
//        PQclear(res);
//        do_exit(conn);
//    }
//
//    res = PQexec(conn, TABLE_INSERTX);
//    if (PQresultStatus(res) != PGRES_COMMAND_OK)
//    {
//        printf("INSERT command failed\n");
//        PQclear(res);
//        do_exit(conn);
//    }
//
//    res = PQexec(conn, TABLE_INSERTX);
//    if (PQresultStatus(res) != PGRES_COMMAND_OK)
//    {
//        printf("INSERT command failed\n");
//        PQclear(res);
//        do_exit(conn);
//    }
// 
//
//    res = PQexec(conn, TABLE_UPDATEX);
//    if (PQresultStatus(res) != PGRES_COMMAND_OK)
//    {
//        printf("UPDATE command failed\n");
//        PQclear(res);
//        do_exit(conn);
//    }
//
//       res = PQexec(conn, TABLE_INSERTX);
//    if (PQresultStatus(res) != PGRES_COMMAND_OK)
//    {
//        printf("INSERT command failed\n");
//        PQclear(res);
//        do_exit(conn);
//    }
//
//    res = PQexec(conn, TABLE_SELECTX);
//    if (PQresultStatus(res) != PGRES_TUPLES_OK)
//    {
//        printf("No data retrieved\n");
//        PQclear(res);
//        do_exit(conn);
//    }
//    int rows = PQntuples(res);
//    for (int i = 0; i < rows; i++)
//    {
//
//        printf("Id :%s  Name :%s Mobile :%s Office :%s Date :%s \n", PQgetvalue(res, i, 0),
//               PQgetvalue(res, i, 1), PQgetvalue(res, i, 2), PQgetvalue(res, i, 3), PQgetvalue(res, i, 4));
//    }
//        res = PQexec(conn, "COMMIT");
//    if (PQresultStatus(res) != PGRES_COMMAND_OK)
//    {
//        printf("COMMIT command failed\n");
//        PQclear(res);
//        do_exit(conn);
//    }
//    printf("\n\n================================FIRST_TRANSACTION_END======================================\n\n");
//
//    int fieldIndex, i, j;
//    // Start a transaction block
//    res = PQexec(conn, "BEGIN");
//    if (PQresultStatus(res) != PGRES_COMMAND_OK)
//    {
//        fprintf(stderr, "BEGIN command failed: %s", PQerrorMessage(conn));
//        do_exit(conn);
//    }
//    PQclear(res);
//
//    res = PQexec(conn, TABLE_DECLARED);
//    if (PQresultStatus(res) != PGRES_COMMAND_OK)
//    {
//        fprintf(stderr, "DECLARE CURSOR failed: %s", PQerrorMessage(conn));
//        do_exit(conn);
//    }
//    PQclear(res);
//
//    res = PQexec(conn, TABLE_FETECHED);
//    if (PQresultStatus(res) != PGRES_TUPLES_OK)
//    {
//        fprintf(stderr, "FETCH ALL failed: %s", PQerrorMessage(conn));
//        do_exit(conn);
//    }
//
//    // first, print out the table collumn attribute
//    fieldIndex = PQnfields(res);
//    for (i = 0; i < fieldIndex; i++)
//        printf("%-15s", PQfname(res, i));
//    printf("\n\n");
//
//    // next, print out the rows of data
//    for (i = 0; i < PQntuples(res); i++)
//    {
//        for (j = 0; j < fieldIndex; j++)
//            printf("%-15s", PQgetvalue(res, i, j));
//        printf("\n");
//    }
//    PQclear(res); // close the portal ... No error checking ...
//
//    res = PQexec(conn, "CLOSE myContactsPreset");
//    PQclear(res);
//    res = PQexec(conn, "END");
//    printf("\n=========================== SECOND-TRANSACTION_END======================================\n\n");
//    PQclear(res);   /* this must be done after every statement to avoid memory leaks */
//    PQfinish(conn); /* close the database connection and release memory */
//    return 0;
//}