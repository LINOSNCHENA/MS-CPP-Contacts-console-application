////	CHH-VERSION OF FONE BOOK  v 1.1
////   ==================================
//
//#include <stdlib.h>
//#include <stdio.h>
//
//#include <mysql.h>
//
//int main(int argc, char** argv)
//{
//    MYSQL* mysql = NULL;
//
//    if (mysql_library_init(argc, argv, NULL)) {
//        fprintf(stderr, "could not initialize MySQL client library\n");
//        exit(1);
//    }
//    mysql = mysql_init(mysql);
//
//    if (!mysql) {
//        puts("Init faild, out of memory?");
//        return EXIT_FAILURE;
//    }
//
//    mysql_options(mysql, MYSQL_READ_DEFAULT_FILE, (void*)"./myCredentials.cnf");
//
//    if (!mysql_real_connect(mysql,       /* MYSQL structure to use */
//        NULL,         /* server hostname or IP address */
//        NULL,         /* mysql user */
//        NULL,          /* password */
//        NULL,               /* default database to use, NULL for none */
//        0,           /* port number, 0 for default */
//        NULL,        /* socket file or named pipe name */
//        CLIENT_FOUND_ROWS /* connection flags */)) {
//        printf("I=============================FAILURE =================================I\n");
//        puts("Connect ZAMBIA failed\n");
//    }
//    else {
//        printf("I=============================SUCCESS==================================I\n");
//        puts("Connect OK\n");
//   
//    }
//    mysql_close(mysql);
//       printf("I=============================MySQL_END==================================I\n");
//    mysql_library_end();
//    return EXIT_SUCCESS;
//}