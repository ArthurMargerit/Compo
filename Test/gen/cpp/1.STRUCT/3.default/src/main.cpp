
#include <Data/Struct_AAA_builder.hpp>
#include <Data/Struct_AA_builder.hpp>
#include <Data/Struct_A_builder.hpp>
// #include <Data/Struct_B.hpp>
// #include <Data/Struct_C.hpp>

int main(int argc, char *argv[]) {

  // builder of A
  {
    A_builder a_builder;
    A a0 = a_builder.build();
    A a1 = a_builder.set_aa(1).set_ab(2).set_ac(3).build();
    A a2 = a_builder.set_aa(4).build();
    A a3 = a_builder.set_aa(5).build();

    std::cout << a0 << "\n";
    std::cout << a1 << "\n";
    std::cout << a2 << "\n";
    std::cout << a3 << "\n";
  }

  // builder of AA
  {
    AA_builder aa_builder;
    AA a0 = aa_builder.build();

    AA a1 = aa_builder.set_aa(1)
                .set_ab(2)
                .set_ac(3)
                .set_aaa(4)
                .set_aab(5)
                .set_aac(6)
                .build();

    AA a2 = aa_builder.set_aac(10).build();

    AA a3 = aa_builder.set_aa(10).build();

    std::cout << a0 << "\n";
    std::cout << a1 << "\n";
    std::cout << a2 << "\n";
    std::cout << a3 << "\n";

    // heritage
    std::shared_ptr<A> a4 = aa_builder.build_sp();
    A *a5 = aa_builder.build_p();
    std::cout << a4 << "\n";
    std::cout << a5 << "\n";
  }

  // builder of AA
  {
    AAA_builder aaa_builder;
    A_builder a_builder;

    aaa_builder.set_d(a_builder.build());

    AA a0 = aaa_builder.set_aaa(0).build();
    AAA a1 = aaa_builder.set_aaa(1).build();
    AAA a2 = aaa_builder.set_aaa(2).build();
  }

  return 0;
}
