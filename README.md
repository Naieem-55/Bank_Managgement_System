# 🏦 Bank Management System

A **C++-based Bank Management System** that provides functionalities like creating accounts, deposits, withdrawals, and secure password protection with hashing.

## 📸 Screenshots  
![Console](https://raw.githubusercontent.com/Naieem-55/Bank_Managgement_System/main/bank.png)

## 🚀 Features  
✔️ **Create New Accounts** – Register new customers with essential details.  
✔️ **Deposit & Withdraw Funds** – Secure money transactions with real-time balance updates.  
✔️ **Password Protection** – Secure accounts using hashed passwords.  
✔️ **Account Management** – Modify or delete accounts when needed.  
✔️ **Check Account Details** – Display the account holder's name, balance, and account type.  

## 🛠 Technologies Used  
- **Programming Language**: C++  
- **Libraries**: `<iostream>`, `<string>`, `<iomanip>`, `<sstream>`  
- **Hashing Algorithm**: Custom SHA-256 alternative using C++ hashing  

## 📜 How to Run 
### 1️⃣ Clone the Repository

```bash
git clone https://github.com/Naieem-55/Bank_Managgement_System.git
cd Bank_Managgement_System
```

### 2️⃣ Compile the Code

```bash
g++ main.cpp -o bank_management.exe
```

### 3️⃣ Run the Program

```bash
./bank_management.exe
```

🎮 Usage Instructions
- Run the program and choose an option from the Bank Menu.
- Create a new account with a secure password.
- Use the account number and password to log in and manage funds.
- Perform transactions like depositing and withdrawing money.
- Check account details or modify and delete accounts as needed.

  🔒 Security: Password Hashing
- The system uses a simple hash function to secure passwords.
- When an account is created, the password is hashed and stored instead of plaintext.
- When logging in, the entered password is hashed and compared with the stored hash.

  📌 Future Enhancements
🔐 Advanced Encryption using OpenSSL
📊 Graphical User Interface (GUI) instead of CLI
📁 Database Integration for persistent data storage

🏆 Contributing
I welcome contributions! Feel free to fork this repository, create a feature branch, and submit a pull request.

📄 License
This project is open-source and available under the MIT License.
