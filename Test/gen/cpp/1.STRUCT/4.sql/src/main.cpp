#include "Data/code.hpp"
#include "Structs/A1_sql.hpp"
#include "Structs/A_sql.hpp"
#include "Structs/With_ext_ext_ext_key_sql.hpp"
#include "Structs/With_ext_ext_key_sql.hpp"
#include "Structs/With_ext_key_sql.hpp"
#include "Structs/With_key_sql.hpp"
#include "catch.hpp"

#include <iostream>
#include <pqxx/pqxx>

TEST_CASE("SQL database", "[Struct][SQL]") {

  A a0;
  A_sql s0(a0);
  std::cout << A_sql::get_table() << "\n";
  std::cout << s0.get_insert() << "\n";

  A1 a1;
  A1_sql s1(a1);
  std::cout << A1_sql::get_table() << "\n";
  std::cout << s1.get_insert() << "\n";

  With_key a2;
  With_key_sql s2(a2);
  std::cout << With_key_sql::get_table() << "\n";
  std::cout << s2.get_insert() << "\n";

  With_ext_key a3;
  With_ext_key_sql s3(a3);
  std::cout << With_ext_key_sql::get_table() << "\n";
  std::cout << s3.get_insert() << "\n";
}

TEST_CASE("SQL database CREATE DATABASE", "[Struct][SQL][CREATE]") {
  try {
    pqxx::connection C("dbname = composql user = ruhtra password = ruhtra "
                       "hostaddr = 127.0.0.1 port = 5432");
    if (C.is_open()) {
      std::cout << "Opened database successfully: " << C.dbname() << std::endl;
    } else {
      std::cout << "Can't open database" << std::endl;
      return;
    }

    pqxx::work W(C);

    /* Execute SQL query */
    W.exec("DROP TABLE IF EXISTS a CASCADE;");
    W.exec("DROP TABLE IF EXISTS a1 CASCADE;");
    W.exec("DROP TABLE IF EXISTS with_key CASCADE;");
    W.exec("DROP TABLE IF EXISTS with_ext_key CASCADE;");
    W.exec("DROP TABLE IF EXISTS with_ext_ext_key CASCADE;");
    W.exec("DROP TABLE IF EXISTS with_ext_ext_ext_key CASCADE;");

    W.exec(A_sql::get_table());
    W.exec(A1_sql::get_table());
    W.exec(With_key_sql::get_table());
    W.exec(With_ext_key_sql::get_table());
    W.exec(With_ext_ext_key_sql::get_table());
    W.exec(With_ext_ext_ext_key_sql::get_table());
    W.commit();

    std::cout << "Table created successfully" << std::endl;
    C.disconnect();
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
}

TEST_CASE("SQL database INSERT", "[Struct][SQL][INSERT]") {
  try {
    pqxx::connection C("dbname = composql user = ruhtra password = ruhtra "
                       "hostaddr = 127.0.0.1 port = 5432");
    if (C.is_open()) {
      std::cout << "Opened database successfully: " << C.dbname() << std::endl;
    } else {
      std::cout << "Can't open database" << std::endl;
      return;
    }

    pqxx::work W(C);

    /* Execute SQL query */
    W.exec("DROP TABLE IF EXISTS a CASCADE;");
    W.exec("DROP TABLE IF EXISTS a1 CASCADE;");
    W.exec("DROP TABLE IF EXISTS with_key CASCADE;");
    W.exec("DROP TABLE IF EXISTS with_ext_key CASCADE;");
    W.exec("DROP TABLE IF EXISTS with_ext_ext_key CASCADE;");

    W.exec(A_sql::get_table());
    W.exec(A1_sql::get_table());
    W.exec(With_key_sql::get_table());
    W.exec(With_ext_key_sql::get_table());
    W.exec(With_ext_ext_key_sql::get_table());
    W.commit();

    {
      A k;
      A_sql k_l(k);

      pqxx::work W1(C);
      k.set_b(11);
      W1.exec(k_l.get_insert());

      k.set_b(22);
      W1.exec(k_l.get_insert());

      k.set_b(33);
      W1.exec(k_l.get_insert());

      k.set_b(44);
      W1.exec(k_l.get_insert());

      W1.commit();

      pqxx::nontransaction N(C);
      pqxx::result R(N.exec(k_l.get_all()));
      for (pqxx::result::const_iterator c = R.begin(); c != R.end(); ++c) {
        A l_a;
        A_sql l_a_s(l_a);
        l_a_s.build(*c);
        std::cout << l_a << std::endl;
      }
    }

    {
      // A1
      A1 k1;
      A1_sql k1_l(k1);
      pqxx::work W2(C);

      k1.set_d("test1");
      k1.set_re(0.1);
      W2.exec(k1_l.get_insert());

      k1.set_d("test2");
      k1.set_re(0.2);
      W2.exec(k1_l.get_insert());

      k1.set_d("test3");
      k1.set_re(0.3);
      W2.exec(k1_l.get_insert());

      k1.set_d("test4");
      k1.set_re(0.4);
      W2.exec(k1_l.get_insert());

      W2.commit();

      pqxx::nontransaction N(C);
      pqxx::result R(N.exec(k1_l.get_all()));
      for (pqxx::result::const_iterator c = R.begin(); c != R.end(); ++c) {
        A1 l_a;
        A1_sql l_a_s(l_a);
        l_a_s.build(*c);
        std::cout << l_a << std::endl;
      }
    }

    {
      // A1
      With_key k1;
      With_key_sql k1_l(k1);
      pqxx::work W2(C);

      k1.set_name1("name1_1");
      k1.set_name2("name1_2");
      k1.set_re(5.5);
      W2.exec(k1_l.get_insert());

      k1.set_name1("name2_1");
      k1.set_name2("name2_2");
      k1.set_re(15.5);
      W2.exec(k1_l.get_insert());

      k1.set_name1("name3_1");
      k1.set_name2("name3_2");
      k1.set_re(25.5);
      W2.exec(k1_l.get_insert());

      k1.set_name1("name4_1");
      k1.set_name2("name4_2");
      k1.set_re(35.5);
      W2.exec(k1_l.get_insert());

      W2.commit();

      pqxx::nontransaction N(C);
      pqxx::result R(N.exec(k1_l.get_all()));
      for (pqxx::result::const_iterator c = R.begin(); c != R.end(); ++c) {
        With_key l_a;
        With_key_sql l_a_s(l_a);
        l_a_s.build(*c);
        std::cout << l_a << std::endl;
      }
    }

    {
      // A1
      With_ext_key k1;
      With_ext_key_sql k1_l(k1);
      pqxx::work W2(C);

      k1.set_name3("fn1");
      k1.a_k1().set_name1("name A");
      k1.a_k1().set_name2("name B");
      k1.a_k1().set_re(0.2);

      k1.a_k2().set_name1("name C");
      k1.a_k2().set_name2("name D");
      k1.a_k2().set_re(0.5);
      std::cout << k1_l.get_insert() << "\n";
      W2.exec(k1_l.get_insert());

      k1.set_name3("fn2");
      k1.a_k1().set_name1("name E");
      k1.a_k1().set_name2("name F");
      k1.a_k1().set_re(0.2);

      k1.a_k2().set_name1("name G");
      k1.a_k2().set_name2("name H");
      k1.a_k2().set_re(0.5);
      W2.exec(k1_l.get_insert());
      W2.commit();

      pqxx::nontransaction N(C);
      std::cout << k1_l.get_all() << "\n";
      pqxx::result R(N.exec(k1_l.get_all()));

      for (pqxx::result::const_iterator c = R.begin(); c != R.end(); ++c) {
        With_ext_key l_a;
        With_ext_key_sql l_a_s(l_a);
        l_a_s.build(*c);

        std::cout << l_a << std::endl;
      }
    }

    {
      // A1
      With_ext_ext_key k1;
      With_ext_ext_key_sql k1_l(k1);
      pqxx::work W2(C);

      k1.set_name4("fn1");
      k1.a_k3().a_k1().set_name1("name A");
      k1.a_k3().a_k1().set_name2("name B");
      k1.a_k3().a_k1().set_re(0.1);

      k1.a_k3().a_k2().set_name1("name C");
      k1.a_k3().a_k2().set_name2("name D");
      k1.a_k3().a_k2().set_re(0.2);

      k1.a_k4().set_name1("name E");
      k1.a_k4().set_name2("name F");
      k1.a_k4().set_re(0.3);

      std::cout << k1_l.get_insert() << "\n";
      W2.exec(k1_l.get_insert());

      k1.set_name4("fn2");
      k1.a_k3().a_k1().set_name1("name G");
      k1.a_k3().a_k1().set_name2("name H");
      k1.a_k3().a_k1().set_re(0.4);

      k1.a_k3().a_k2().set_name1("name I");
      k1.a_k3().a_k2().set_name2("name J");
      k1.a_k3().a_k2().set_re(0.5);

      k1.a_k4().set_name1("name K");
      k1.a_k4().set_name2("name L");
      k1.a_k4().set_re(0.6);

      std::cout << k1_l.get_insert() << "\n";
      W2.exec(k1_l.get_insert());
      W2.commit();

      pqxx::nontransaction N(C);
      std::cout << k1_l.get_all() << "\n";
      pqxx::result R(N.exec(k1_l.get_all()));

      for (pqxx::result::const_iterator c = R.begin(); c != R.end(); ++c) {
        With_ext_ext_key l_a;
        With_ext_ext_key_sql l_a_s(l_a);
        l_a_s.build(*c);

        std::cout << l_a << std::endl;
      }
    }
    {
      // A1
      With_ext_ext_ext_key k1;
      With_ext_ext_ext_key_sql k1_l(k1);
      pqxx::work W2(C);

      std::cout << k1_l.get_insert() << "\n";
      W2.exec(k1_l.get_insert());
      W2.commit();
      pqxx::nontransaction N(C);
      std::cout << k1_l.get_all() << "\n";
      pqxx::result R(N.exec(k1_l.get_all()));

      for (pqxx::result::const_iterator c = R.begin(); c != R.end(); ++c) {
        With_ext_ext_ext_key l_a;
        With_ext_ext_ext_key_sql l_a_s(l_a);
        l_a_s.build(*c);
        REQUIRE(l_a == k1);

        std::cout << l_a << std::endl;
      }
    }
    C.disconnect();
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
}
