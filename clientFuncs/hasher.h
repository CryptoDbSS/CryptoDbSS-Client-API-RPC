/*
 * Software Name: CryptoDbSS Client API RPC
 * Copyright (C) 2025 Steeven J Salazar.
 * License: CryptoDbSS: Software Review and Audit License
 * 
 * https://github.com/Steeven512/CryptoDbSS
 *
 * IMPORTANT: Before using, compiling or do anything with this software, 
 * you must read and accept the terms of this License.
 * 
 * This software is provided "as is," without warranty of any kind.
 * For more details, see the LICENSE file.
 */


/* 
 
The CryptoDbSS, blockchain-core, consensus, protocols and misc.

This software is a review and audit release, it should only be used for 
development, testing, educational and auditing purposes. 

Third-party dependencies: Crypto++, OpenSSL, libcurl.

questions, suggestions or contact : Steevenjavier@gmail.com

*/

#ifndef HASHER_H
#define HASHER_H

#include <openssl/evp.h>
#include <vector>
#include <string>
#include "codec.h"


std::vector<uint8_t> string_to_bytes(const std::string& str){
    return std::vector<uint8_t>(str.begin(), str.end());
}

std::string bytesToStringRaw(const std::vector<uint8_t>& bytes) {
    return std::string(reinterpret_cast<const char*>(bytes.data()), bytes.size());
}

void addHexStringInVec(vector<unsigned char> &vec, string datatocodify){
    uint datatocodifylength =datatocodify.length();
    for (uint i = 0; i < datatocodifylength; i += 2){
        vec.push_back(hexToInt(datatocodify.substr(i, 2)));
    }
    return;
}

std::vector<uint8_t> sha3_256(const std::string& input){

    std::vector<uint8_t> input_bytes = string_to_bytes(input);
    std::vector<uint8_t> output(EVP_MAX_MD_SIZE);
    unsigned int output_size = 0;
    EVP_MD_CTX* context = EVP_MD_CTX_new();
    EVP_DigestInit_ex(context, EVP_sha3_256(), NULL);
    EVP_DigestUpdate(context, input_bytes.data(), input_bytes.size());
    EVP_DigestFinal_ex(context, output.data(), &output_size);
    EVP_MD_CTX_free(context);
    output.resize(output_size);
    
    return output;
}

std::vector<uint8_t> sha3_256StrVector(const std::string& input){

    std::vector<uint8_t> input_bytes;
    addHexStringInVec(input_bytes, input);
    std::vector<uint8_t> output(EVP_MAX_MD_SIZE);
    unsigned int output_size = 0;
    EVP_MD_CTX* context = EVP_MD_CTX_new();
    EVP_DigestInit_ex(context, EVP_sha3_256(), NULL);
    EVP_DigestUpdate(context, input_bytes.data(), input_bytes.size());
    EVP_DigestFinal_ex(context, output.data(), &output_size);
    EVP_MD_CTX_free(context);
    output.resize(output_size);
    
    return output;
}

std::vector<uint8_t> sha3_256v(std::vector<uint8_t> input_bytes){

    std::vector<uint8_t> output(EVP_MAX_MD_SIZE);
    unsigned int output_size = 0;
    EVP_MD_CTX* context = EVP_MD_CTX_new();
    EVP_DigestInit_ex(context, EVP_sha3_256(), NULL);
    EVP_DigestUpdate(context, input_bytes.data(), input_bytes.size());
    EVP_DigestFinal_ex(context, output.data(), &output_size);
    EVP_MD_CTX_free(context);
    output.resize(output_size);
    return output;
}

std::string hasher(std::string y){
    std::vector<uint8_t> hash = sha3_256(y);
    std::string v="";

    for (uint8_t b : hash) {
        v += b;
    }
    return v;
}

std::string SHAstg(std::string  stg){ 

    std::vector<uint8_t> hash = sha3_256(stg);
    std::string msg = "";
    for (unsigned int i = 0; i < hash.size(); i++){
        msg += byteToHex2(hash[i]);
    }
    return msg;
    
}

#endif
