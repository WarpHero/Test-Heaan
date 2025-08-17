#include "seal/seal.h"
#include <iostream>

int main() {
    using namespace seal;
    
    // 1. 암호화 파라미터 설정
    EncryptionParameters parms(scheme_type::bfv);
    size_t poly_modulus_degree = 4096;
    parms.set_poly_modulus_degree(poly_modulus_degree);
    parms.set_coeff_modulus(CoeffModulus::BFVDefault(poly_modulus_degree));
    parms.set_plain_modulus(256);

    // 2. 컨텍스트 생성 및 키 생성
    SEALContext context(parms);
    KeyGenerator keygen(context);
    SecretKey secret_key = keygen.secret_key();
    PublicKey public_key;
    keygen.create_public_key(public_key);

    // 3. 암호화기, 복호화기 생성
    Encryptor encryptor(context, public_key);
    Decryptor decryptor(context, secret_key);
    Evaluator evaluator(context);

    // 4. 두 숫자 암호화
    Plaintext x_plain("6");
    Plaintext y_plain("15");
    Ciphertext x_encrypted, y_encrypted;

    encryptor.encrypt(x_plain, x_encrypted);
    encryptor.encrypt(y_plain, y_encrypted);

    // 5. 암호화된 상태에서 덧셈
    Ciphertext result;
    evaluator.add(x_encrypted, y_encrypted, result);

    // 6. 결과 복호화
    Plaintext result_plain;
    decryptor.decrypt(result, result_plain);

    std::cout << "6 + 15 = " << result_plain.to_string() << std::endl;

    return 0;
}