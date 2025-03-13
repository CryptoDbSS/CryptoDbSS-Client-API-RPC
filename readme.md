## CryptoDbSS Client API RPC
<p align="center">
  <img src="https://github.com/Steeven512/CryptoDbSS/blob/main/CryptoDbSSLogo.png" alt="Alt Text" width="250" height="250">
</p>


 Implementing client functions to interact with the CryptoDbSS protocol

 CryptoDbSS-ClientRPC.h can be used as library

 main.cpp contains CLI App

 secure encrypt AES-CBC of the private key on local stored wallets 

this tool can handle:

  - wallets managenment
  - make request and sign transactions
  - request data from CryptoDbSS based blockchain
  - index wallets balance

---

### Setup and Usage of CLI

  ### **1. License Agreement**

  - Before using, compiling, reading, auditing, or doing anything with the software or its derivatives, **you must read and accept the agreements** specified in the **LICENSE.md** file provided in the package.

  ### **2. Compiling the Application**

  CryptoDbSS Client API RPC relies on the following libraries:
  
  >  Crypto++, OpenSSL, libcurl.

   To compile the application, use the following command:
   
   ``` g++ main.cpp -o cdbss-clientapirpc-cli -lcrypto -lcryptopp -lcurl ```

  
   ### **3. Initial Setup**

  - **Set Passkey encryptation for wallets:**
  
      This ensures that your wallets stored locally </br>
      set with: ``` ./cdbss-clientapirpc-cli setpassencryption ``` </br>
      then enter your password, all wallets you will store will need this password before use </br>
  
    - **RPC Address:**
      defines the address of the node that will be interacted </br>
  
      set with: ``` ./cdbss-clientapirpc-cli setprovider <address>```  </br>
      
      e.g: https://0.0.0.0:18090</br>

  ### **4. General usage**
    
  - **Save a local wallet:**
    
      set it running: ``` ./cdbss-clientapirpc-cli savewallet ``` </br>
      enter the private key of your wallet and theb your previous settup encryptation key.</br></br>

      you can see the store wallets running:  ``` ./cdbss-clientapirpc-cli Stored wallets ```

  - **balance accounts indexing:**
    
      ``` ./cdbss-clientapirpc-cli IndexBalance <Public Address> ``` </br></br>
      ```  e.g ./cdbss-clientapirpc-cli IndexBalance 04e6177bdd06d3bdf5808c89b983969dff5f9bc3fc2608204e0305bb1c5f91c7a74c6b52d6541d706f4b7514b34fdb88ccdb718eeeb3f7e1380db6444b40205de1 ``` </br>
    
      that will show the balance of the account</br>

  - **make a transaction :**
 
      ``` ./cdbss-clientapirpc-cli ProcessTransaction <fromAcc> <AddressTo or message> <value transaction> <type of transaction> ``` </br>

      e.g ./cdbss-clientapirpc-cli IndexBalance 04e6177bd....5de1 045ca....67ac3e 123456 0x00</br>

      explanation:</br>
      
      - "fromAcc" must be one of your stored accounts.</br></br>
      - "addressTo" the Public address that you desire to transfer(if the transaction type is 0A this space is a mesagge with a 64 hex chars);</br></br>
      - "Value transaction" the amount that the account will give for the transaction;</br></br>
      - "type of transaction" can be 0x00 for normal transactions or 0x0A for post a mensagge of 32bytes;</br></br>

  - **for other options:**
  
      just run ./cdbss-clientapirpc-cli -h and see the commands.

    ---

    ---

# Get more Info And Updates

  </br>
<p align="center">Follow the blog <a href="https://cryptodbss.blogspot.com" > cryptodbss.blogspot.com </a> </p>

<p align="center">questions, suggestions or contact : Steevenjavier@gmail.com
</br></br>
 Copyright (C) 2025 Steeven J Salazar.
</p>