/*******************************************************************************
 *
 * Software Name: CryptoDbSS Client API RPC
 * Copyright (C) 2025 Steeven J Salazar.
 * License: CryptoDbSS: Software Review and Audit License
 * 
 * https://github.com/CryptoDbSS/CryptoDbSS-Client-API-RPC
 *
 * This notice, including the copyright notice and permission notice, 
 * must be retained in all copies or substantial portions of the Software and 
 * in all derivative works.
 *
 * IMPORTANT: Before using, compiling, or doing anything with this software,
 * you must read and accept the terms of the License provided with this software.
 *
 * If you do not have a copy of the License, you can obtain it at the following link:
 * https://github.com/CryptoDbSS/CryptoDbSS-Client-API-RPC/blob/main/LICENSE.md
 *
 * By using, compiling, or modifying this software, you implicitly accept
 * the terms of the License. If you do not agree with the terms,
 * do not use, compile, or modify this software.
 * 
 * This software is provided "as is," without warranty of any kind.
 * For more details, see the LICENSE file.
 *
 ********************************************************************************/


/*********************************************************************************
 
    The CryptoDbSS, blockchain-core, consensus, protocols and misc.

    This software is a review and audit release, it should only be used for 
    development, testing, education and auditing purposes. 

    Third-party dependencies: Crypto++, OpenSSL, libcurl.

    questions, suggestions or contact : Steevenjavier@gmail.com

                                S.S

*********************************************************************************/

#include "CryptoDbSS-ClientRPC.h"

inline std::string RPC_Address = LoadProvider();
uint maxTimeForConfirmation = 650;

void ShowHelpInfo(const string &processAppName ,const string &help){

    if(help == "ProcessTransaction"){
        cout<<processAppName+ " ProcessTransaction <fromAcc> <AddressTo or message> <value transaction> <type of transaction>"<<endl;
        return;
    }

    if(help == "setprovider"){
        cout<<processAppName+" setprovider <rpc address>"<<endl;
        return;
    }

    if(help == "IndexBalance"){
        cout<<processAppName+" IndexBalance <address Account to index>"<<endl;
        return;
    }

    if(help == "SearchTransaction"){
        cout<<processAppName+" SearchTransaction <option: bynumber, hash, MSG>  <block bumber of transaction> <number of transction>"<<endl<<
        processAppName+" SearchTransaction <option: byhash>  <hash of transaction>"<<endl;
        return;
    }

    if(help == "SearchBlock"){
        cout<<" ./cryptosbssClient  SearchBlock <number of block to index>"<<endl;
        return;
    }

    std::cout<<  std::endl;
    std::cout<< "CryptoDbSS Client commands  <funtion>            <args...>" << std::endl;
    std::cout<<  std::endl;
    std::cout<< "general:               <ProcessTransaction>      <args...>" << std::endl;
    std::cout<< "                       <IndexBalance>            <args...>" << std::endl;
    std::cout<< "                       <SearchTransaction>       <args...>" << std::endl;
    std::cout<< "                       <SearchBlock>             <args...>" << std::endl;
    std::cout<< "                       <walletsStored>             " << std::endl;
    std::cout<<  std::endl;
    std::cout<< "Accounts management:   <SaveNewWallet>           <args...>" << std::endl;
    std::cout<<  std::endl;
    std::cout<< "Settings:              <setpassencryption>       <args...>" << std::endl;
    std::cout<< "                       <setprovider>             <args...>" << std::endl;
    std::cout<<  std::endl;
    std::cout<< "      ||  Developed by:   steevenjavier@gmail.com  ||"  << std::endl;
    std::cout<<  std::endl;

}

void _savePass(){

    if(savePass()){
        cout<<"Client Password Set succesfully"<<endl;
    } else {
        cout<<"Client Password could not set"<<endl;
    }

}

bool _ProcessTransaction(char* arg[], uint NumbArgs){

    const string processAppName = arg[0];
    if (NumbArgs != 6) {
        const string help ="ProcessTransaction";
        ShowHelpInfo(processAppName, help);
        return false;
    }
    std::string fromAcc = arg[2];
    std::string AddressTo = arg[3];
    std::string value = arg[4];
    std::string typeT = arg[5];
    uint8_t TypeTransaction = hexToUint8_t(typeT);

    //cheackear valor de entrada del value

    ProcessTransaction(fromAcc, AddressTo, ullToHex(stoull(value)), TypeTransaction);

    recovered="";
    AccLoaded.clear();
    return true;
}

bool _ProcessTransaction2(char* arg[], uint NumbArgs){

    const string processAppName = arg[0];
    if (NumbArgs != 6) {

        const string help ="ProcessTransaction";

        ShowHelpInfo(processAppName, help);
        return false;
    }

    std::string fromAcc = arg[2];
    std::string AddressTo = arg[3];
    std::string value = arg[4];
    std::string typeT = arg[5];
    uint8_t TypeTransaction = hexToUint8_t(typeT);

    //cheackear valor de entrada del value

    ProcessTransaction2(fromAcc, AddressTo, ullToHex(stoull(value)), TypeTransaction);

    recovered="";
    AccLoaded.clear();
    return true;
}

bool _ProcessTransactionDebugNoSign(char* arg[], uint NumbArgs){

    const string processAppName = arg[0];
    if (NumbArgs != 6) {

        const string help ="ProcessTransaction";

        ShowHelpInfo(processAppName, help);
        return false;
    }
    std::string fromAcc = arg[2];
    std::string AddressTo = arg[3];
    std::string value = arg[4];
    std::string typeT = arg[5];
    uint8_t TypeTransaction = hexToUint8_t(typeT);

    //cheackear valor de entrada del value

    ProcessTransactionDebugNoSign(fromAcc, AddressTo, ullToHex(stoull(value)), TypeTransaction);

    recovered="";
    AccLoaded.clear();
    cout<<endl;
    return true;
}
 
bool _SaveNewWallet(){

    return SaveNewWallet(1);

}

bool _DisplayWallets(){

   std::vector<std::string>Wallets = savedWallets();

    for (size_t i = 0; i < Wallets.size(); ++i) {
        std::cout << std::setw(3) << i + 1 << ". " << Wallets[i] << std::endl;
    }

    return true;

}

bool _SetProvider(char* arg[], uint NumbArgs){

    const string processAppName = arg[0];
    if (NumbArgs != 3) {
        const string help ="setprovider";
        ShowHelpInfo(processAppName,help);
        return false;
    }

    std::string address = arg[2];

    return SetProvider(address);

}

bool _IndexBalance(char* argv[], uint NumbArgs){

    const string processAppName = argv[0];
    if (NumbArgs != 3) {
        const string help ="IndexBalance";
        ShowHelpInfo(processAppName, help);
        return false;
    }

    indexBalanceAcc(argv[2]);

    return true;

}

string _SearchTransaction(char* argv[], uint NumbArgs){


    const string processAppName = argv[0];

    if (NumbArgs != 4&&NumbArgs != 5 ) {
        const string help ="SearchTransaction";
        ShowHelpInfo(processAppName, help);
        cout<<"wrong arguments provided";
        return "wrong arguments provided";
    }

    std::string choice = argv[2];

    if(NumbArgs == 4){

        if( choice == "byhash" ){

            std::string result=  SearchTransactionByHash(argv[3]);
            std::cout<<"Raw-Data Transaction  : "<<result<<std::endl;
            return result;

        }

        const string help= "SearchTransaction";

        ShowHelpInfo(processAppName, help);
        return "call func cdbss client does not match";

    }

    string BN = ullToHex(stoull(argv[3]));
    string TN = ullToHex(stoull(argv[4]));

    if( choice == "bynumber" ){

        std::string result=  SearchTransactionByNumer(BN,TN);
        std::cout<<result<<std::endl;
        return result;
    }

    if( choice == "hash" ){

        std::string result=  HashOfTransaction(BN,TN);
        std::cout<<result<<std::endl;
        return result;
    }

    if( choice == "MSG" ){

        std::string result=  SearchTransactionMSGByNumer(BN,TN);
        std::cout<<result<<std::endl;
        return result;
    }

    const string help= "SearchTransaction";
    ShowHelpInfo(processAppName, help);

    return "call func cdbss client does not match";


}

bool _SearchBlock(char* argv[], uint NumbArgs){

    const string processAppName = argv[0];
    if (NumbArgs != 3) {
        const string help ="SearchBlock";
        ShowHelpInfo(processAppName, help);
        return false;
    }

    std::string choice = argv[2];
    std::string result = SearchBlByNumer(argv[2]);
    std::cout<<result<<std::endl;

    return true;

}




