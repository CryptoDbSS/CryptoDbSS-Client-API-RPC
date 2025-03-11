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

#include "callFuncsMain.h"
 
int main(int argc, char* argv[]){ 

    const string appname = argv[0];
    const string help = "general";

    if (argc < 2) {
        ShowHelpInfo(appname, help);
        return 1;
    }

    std::string argCalled = argv[1];

    //set the encryption key for  secure storage of wallets
    if(argCalled=="setpassencryption"){
        _savePass();
        return 0;
    }

    //store new wallet key
    if(argCalled=="savewallet"){
        _SaveNewWallet();
        return 0;
    }

    //Shows public addresses of stored wallets
    if(argCalled=="walletsStored"){
        _DisplayWallets();
        return 0;
    }

    //Set rpc address e.g https://0.0.0.0:18090
    if(argCalled=="setprovider"){
        _SetProvider(argv, argc);
        return 0;
    }

    //check if a rpc address has been set before procced with some network function 
    if(RPC_Address.length()<1){
        cout<<"Failed to load data provider, please set it correctly with "<<appname<<" setprovider" <<endl;
        return 1;
    }

    //Reques of process a new transaction
    if(argCalled=="ProcessTransaction"){
        _ProcessTransaction(argv, argc);
        return 0;
    }

    //Reques of process a new transaction  a sings it from a key provided in the app call input
    if(argCalled=="ProcessTransaction2"){
        _ProcessTransaction2(argv, argc);
        return 0;
    }

    //sings transaction from a key provided in the app call input
    if(argCalled=="debugTransactionNoSign"){
        _ProcessTransactionDebugNoSign(argv, argc);
        return 0;
    }

    //Index balance from a public key provided
    if(argCalled=="IndexBalance"){
        _IndexBalance(argv, argc);
        return 0;
    }

    //retrieve a transaction raw data or hash in a block , can be indexed with: number of block and transaction, or hash; depending on the call argument.
    if(argCalled=="SearchTransaction"){
        string result = _SearchTransaction(argv, argc);
        return 0;
    }
    //retrieve a block raw data from its number 
    if(argCalled=="SearchBlock"){
        _SearchBlock(argv, argc);
        return 0;

    } else {

        ShowHelpInfo(appname, help);
    }

    return 0;

}