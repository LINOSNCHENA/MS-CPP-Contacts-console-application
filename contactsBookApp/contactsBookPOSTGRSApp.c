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
//    PGconn *conn = PQconnectdb("user=postgres password=Monze@2019  host=127.0.0.1 port=5433 dbname=presly");
//    char *TABLE_DROPX = "DROP TABLE IF EXISTS CONTACTSBOOK";
//    char *TABLE_CREATX = "CREATE TABLE CONTACTSBOOK (id SERIAL PRIMARY KEY,pname TEXT NOT NULL, pnumber1 BIGINT NOT NULL,pnumber2 BIGINT,pstars BIGINT, created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP);";
//    char *TABLE_INSERTX = "INSERT INTO CONTACTSBOOK(pname,pnumber1,pnumber2,pstars) VALUES('POLICE-PG', 1992020,2,22390),('HOSPITAL-PG',2882020,133,2356789);";
//    char *TABLE_UPDATEX = "UPDATE contactsbook SET pname='TRANSLATIK' WHERE Id=3";
//    char *TABLE_SELECTX = "SELECT * FROM contactsbook order by id LIMIT 10"; // FIVE
//    char *TABLE_DECLARED = "DECLARE myContactsPreset CURSOR FOR select * from contactsbook order by id LIMIT 15";
//    char *TABLE_FETECHED = "FETCH ALL in myContactsPreset";
//
//    if (PQstatus(conn) == CONNECTION_BAD)
//    {
//        fprintf(stderr, "Connection to database failed: %s\n", PQerrorMessage(conn));
//        do_exit(conn);
//    }
//
//    printf("\n===========================FIRST_TRANSACTION_START======================================\n\n");
//    PGresult *res = PQexec(conn, "BEGIN");
//    if (PQresultStatus(res) != PGRES_COMMAND_OK)
//    {
//        printf("BEGIN command failed 1\n");
//        PQclear(res);
//        do_exit(conn);
//    }
//
//    res = PQexec(conn, TABLE_DROPX);
//    if (PQresultStatus(res) != PGRES_COMMAND_OK)
//    {
//        printf("DROP command failed 2\n");
//        PQclear(res);
//        do_exit(conn);
//    }
//
//    res = PQexec(conn, TABLE_CREATX);
//    if (PQresultStatus(res) != PGRES_COMMAND_OK)
//    {
//        printf("CREATE command failed 3\n");
//        PQclear(res);
//        do_exit(conn);
//    }
//
//    res = PQexec(conn, TABLE_INSERTX);
//    if (PQresultStatus(res) != PGRES_COMMAND_OK)
//    {
//        printf("INSERT command failed 4\n");
//        PQclear(res);
//        do_exit(conn);
//    }
//
//    res = PQexec(conn, TABLE_INSERTX);
//    if (PQresultStatus(res) != PGRES_COMMAND_OK)
//    {
//        printf("INSERT command failed 4\n");
//        PQclear(res);
//        do_exit(conn);
//    }
//
//    res = PQexec(conn, TABLE_UPDATEX);
//    if (PQresultStatus(res) != PGRES_COMMAND_OK)
//    {
//        printf("UPDATE command failed 5\n");
//        PQclear(res);
//        do_exit(conn);
//    }
//
//    res = PQexec(conn, TABLE_INSERTX);
//    if (PQresultStatus(res) != PGRES_COMMAND_OK)
//    {
//        printf("INSERT command failed 4\n");
//        PQclear(res);
//        do_exit(conn);
//    }
//
//    res = PQexec(conn, TABLE_SELECTX);
//    if (PQresultStatus(res) != PGRES_TUPLES_OK)
//    {
//        printf("No data retrieved 6 \n");
//        PQclear(res);
//        do_exit(conn);
//    }
//    int i, j, fieldIndex;
//    int rows = PQntuples(res);
//    fieldIndex = PQnfields(res);
//
//    // print out the titles names
//    for (int i = 0; i < fieldIndex; i++)
//        printf("%-12s", PQfname(res, i));
//    printf("\n\n");
//    // print out the rows of data
//    for (i = 0; i < PQntuples(res); i++)
//    {
//        for (j = 0; j < fieldIndex; j++)
//            printf("%-12s", PQgetvalue(res, i, j));
//        printf("\n");
//    }
//
//    res = PQexec(conn, "COMMIT");
//    if (PQresultStatus(res) != PGRES_COMMAND_OK)
//    {
//        printf("COMMIT command failed 7\n");
//        PQclear(res);
//        do_exit(conn);
//    }
//    printf("\n\n==========================FIRST_TRANSACTION_END=======================================\n\n");
//
//    // Start a transaction block
//    res = PQexec(conn, "BEGIN");
//    if (PQresultStatus(res) != PGRES_COMMAND_OK)
//    {
//        fprintf(stderr, "BEGIN command failed 1: %s", PQerrorMessage(conn));
//        do_exit(conn);
//    }
//    PQclear(res);
//
//    res = PQexec(conn, TABLE_DECLARED);
//    if (PQresultStatus(res) != PGRES_COMMAND_OK)
//    {
//        fprintf(stderr, "DECLARE CURSOR failed 2: %s", PQerrorMessage(conn));
//        do_exit(conn);
//    }
//    PQclear(res);
//
//    res = PQexec(conn, TABLE_FETECHED);
//    if (PQresultStatus(res) != PGRES_TUPLES_OK)
//    {
//        fprintf(stderr, "FETCH ALL failed 3: %s", PQerrorMessage(conn));
//        do_exit(conn);
//    }
//
//    // print out the titles names
//    for (int i = 0; i < fieldIndex; i++)
//        printf("%-12s", PQfname(res, i));
//    printf("\n\n");
//    // print out the rows of data
//    for (i = 0; i < PQntuples(res); i++)
//    {
//        for (j = 0; j < fieldIndex; j++)
//            printf("%-12s", PQgetvalue(res, i, j));
//        printf("\n");
//    }
//    PQclear(res); // close the portal ... No error checking ...
//
//    res = PQexec(conn, "CLOSE myContactsPreset");
//    res = PQexec(conn, "END");
//    printf("\n=========================== SECOND-TRANSACTION_END======================================\n\n");
//    PQclear(res);   /* this must be done after every statement to avoid memory leaks */
//    PQfinish(conn); /* close the database connection and release memory */
//    return 0;
//}