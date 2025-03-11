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

#include "key.h"
#include "settings.h"
#include "cypher.h"
#include <filesystem>

namespace fs = std::filesystem;

inline std::vector<unsigned char>AccLoaded;

bool decryptData_openssl_AES256CBC(vector<unsigned char> &Data){

    if(recoveryPass()){
        cout<<endl;
        Data = decryptAES(Data, keydata);
        keydata="";
        return true;
    }

    return false;

}

bool encryptData_openssl_AES256CBC(vector<unsigned char> &Data){

    if(recoveryPass()){
        Data = encryptAES(Data, keydata);
        keydata.clear();
        return true;
    }

    return false;

}

bool SaveNewWallet(uint8_t encryptionMode){

    bool result=false ;

    std::string PvData = retrievePrivFromTerminal("enter privKey Of wallet:");
    cout<<endl;
    std::string AccName= derivate(PvData);
    std::vector<unsigned char> Data(PvData.begin(), PvData.end());
    PvData="";

    switch(encryptionMode){
        case 0x01:
            result = encryptData_openssl_AES256CBC(Data);
            break;
    }

    if(result){

        saveFile("./KeyStore/"+AccName, Data);
        std::cout << "key has been saved";
        std::cout << std::endl;
        return result;
    }

    std::cout << "bad pass decrypt";
    std::cout << std::endl;

    return result;

}

bool loadWallet(string &accname){

    for (auto &s : accname){s = toupper(s);}
    vector<unsigned char>DataRead = readFile("KeyStore/"+accname);
    if(DataRead.size()>=16){ 
        if(decryptData_openssl_AES256CBC(DataRead)){
            AccLoaded=DataRead;
            DataRead.clear();
            return true;
        }
    }

   return false;

}

std::vector<std::string>savedWallets(){

    std::string path = "KeyStore/";
    std::vector<std::string>Wallets;

    try {
        for (const auto& entry : fs::directory_iterator(path)) {
            if (fs::is_regular_file(entry)) {
                Wallets.push_back(entry.path().filename().string());
            }
        }


    } catch (const fs::filesystem_error& ex) {
        std::cerr << "Error: " << ex.what() << std::endl;
    }

   return Wallets;

}