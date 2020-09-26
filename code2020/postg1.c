//#include <stdio.h>
//#include <stdlib.h>
//#include <libpq-fe.h>
//
//void do_exit(PGconn *conn)
//{
//
//    PQfinish(conn);
//    exit(1);
//}
//
//int main()
//{
//
//    PGconn *conn = PQconnectdb("user=postgres password=Monze@2019 dbname=presly");
//
//    if (PQstatus(conn) == CONNECTION_BAD)
//    {
//        fprintf(stderr, "Connection to database failed: %s\n",
//                PQerrorMessage(conn));
//        do_exit(conn);
//    }
//
//    PGresult *res1 = PQexec(conn, "DROP TABLE IF EXISTS CONTACTSBOOK;");
//    PGresult *res2 = PQexec(conn, "CREATE TABLE CONTACTSBOOK(id SERIAL PRIMARY KEY, pname TEXT NOT NULL, pnumber1 BIGINT NOT NULL, pnumber2 BIGINT);");
//    PGresult *res3 = PQexec(conn, "INSERT INTO CONTACTSBOOK(pname, pnumber1, pnumber2) VALUES('POLICE-PG', 1992020, 223467890), ('HOSPITAL-PG', 2882020, 12356789);");
//    PGresult *res4 = PQexec(conn, "INSERT INTO CONTACTSBOOK(pname, pnumber1, pnumber2) VALUES('FIRE-PG', 37720280, 12348910), ('AMBULANCE-PG', 46662020, 112342020);");
//    PGresult *res5 = PQexec(conn, "SELECT * FROM Contactsbook LIMIT 5");
//
//    if (PQresultStatus(res1) != PGRES_TUPLES_OK)
//        if (PQresultStatus(res2) != PGRES_TUPLES_OK)
//            if (PQresultStatus(res3) != PGRES_TUPLES_OK)
//                if (PQresultStatus(res4) != PGRES_TUPLES_OK)
//                    if (PQresultStatus(res5) != PGRES_TUPLES_OK)
//                    {
//
//                        printf("No data retrieved\n");
//                        PQclear(res5);
//                        do_exit(conn);
//                    }
//
//    int rows = PQntuples(res5);
//
//    printf("\n I====================================Start======================================I\n\n");
//    for (int i = 0; i < rows; i++)
//    {
//        printf("%s %s %s %s\n", PQgetvalue(res5, i, 0), PQgetvalue(res5, i, 1),
//               PQgetvalue(res5, i, 3), PQgetvalue(res5, i, 1));
//    }
//    printf("\n I================================ ReadingComplete ==============================I\n");
//
//    PQclear(res5);
//    PQfinish(conn);
//
//    return 0;
//}