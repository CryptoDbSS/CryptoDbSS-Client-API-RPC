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

#include "iostream"
#include "curlpostAsync.h"
#include "codec.h"

extern std::string RPC_Address;

bool indexBalanceAcc(std::string address){

    std::string jsonval = "{\"resource\": \"" + address + "\"}";
    std::string response = curlpost(RPC_Address+"/balance", jsonval, 4500);
    if(response.length()==0|| !HexCheck(response)){
        std::cout<<"Invalid Response From RPC or temporal unavailable "<<response<< std::endl;
    } else {
        std::cout<<"Acc balance is : "<< hexToULL(response) <<std::endl;
    }

    return true;
}

std::string SearchTransactionByNumer(std::string BN, std::string TN){

    std::string typeIndex = "0";
    std::string jsonval = "{\"typeIndex\": \"" + typeIndex + "\", \"valueA\": \"" + BN + "\", \"valueB\": \"" + TN + "\"}"; 
    std::string response = curlpost(RPC_Address+"/IndexTransaction", jsonval, 4500);
    return response;

}

std::string SearchTransactionMSGByNumer(std::string BN, std::string TN){

    std::string typeIndex = "3";
    std::string jsonval = "{\"typeIndex\": \"" + typeIndex + "\", \"valueA\": \"" + BN + "\", \"valueB\": \"" + TN + "\"}"; 
    std::string response = curlpost(RPC_Address+"/IndexTransaction", jsonval, 4500);
    return response;

}

std::string HashOfTransaction(std::string BN, std::string TN){

    std::string typeIndex = "1";
    std::string jsonval = "{\"typeIndex\": \"" + typeIndex + "\", \"valueA\": \"" + BN + "\", \"valueB\": \"" + TN + "\"}"; 
    std::string response = curlpost(RPC_Address+"/IndexTransaction", jsonval, 4500);
    return response;

}

std::string SearchTransactionByHash(std::string hash){

    std::string typeIndex = "2";
    std::string jsonval = "{\"typeIndex\": \"" + typeIndex + "\", \"valueC\": \"" + hash + "\"}"; 
    std::string response = curlpost(RPC_Address+"/IndexTransaction", jsonval, 4500);
    return response;

}

std::string SearchBlByNumer(std::string id){

    std::string jsonval = "{\"resource\": \"" + id + "\"}"; 
    std::string response = curlpost(RPC_Address+"/blocksearch", jsonval, 4500);
    return response;

}