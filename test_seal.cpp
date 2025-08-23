// // #include "SEAL-4.1/seal/seal.h"
#include "seal/seal.h"
#include <iostream>

int main() {
    auto version = seal::SEALVersion();
    std::cout << "Microsoft SEAL version: " 
              << version.major << "." 
              << version.minor << "." 
              << version.patch << std::endl;
    

    std::cout << "Microsoft SEAL is working!" << std::endl;
    // 간단한 SEAL 기능 테스트
    seal::EncryptionParameters parms(seal::scheme_type::bfv);
    std::cout << "SEAL BFV scheme initialized successfully!" << std::endl;

    return 0;
}


// #include "seal/seal.h"
// #include <iostream>

// int main() {
//     std::cout << "Microsoft SEAL is working!" << std::endl;
    
//     // 간단한 SEAL 기능 테스트
//     seal::EncryptionParameters parms(seal::scheme_type::bfv);
//     std::cout << "SEAL BFV scheme initialized successfully!" << std::endl;
    
//     return 0;
// }