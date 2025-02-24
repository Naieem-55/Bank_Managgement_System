#include<iostream>
#include<stdlib.h> 
#include <sstream>
#include <iomanip>
#include<conio.h> 
#include<string>
using namespace std;

int N = 10;    // number of account holder

// Custom SHA-256 Implementation
string simpleHash(const string &password);
bool checkPassword();

struct bankmanagement
{
    int accountNo;                   // Account number
    string name, address;            // holder's name & address
    char accountType;                // Account type
    float amount;                    // Account balance
    string passwordHash;             // Hasehed password for secure account

    // Constructor 
    bankmanagement(){

        accountNo = 0;
        name = "";
        address = "";
        accountType = '\0';
        amount = 0.0; 
        passwordHash = "";

    }
    
    bool checkAvailabilty();         // Check if the account slot is available
    bool searchAccount(int);         // Search by account number
    void newAccount();               // Create a new bank account
    void deposit();                  // Deposit money into account
    void withdraw();                 // Withdraw money from an account
    void checkAccount();             // Display account details
    void modifyAccount();            // Modify account information
    void deleteAccount();            // Delete an account
    bool checkPassword();            // Check password
     
};

// Main function
int main()
{
    bankmanagement b[N]; 

    int x,an;        
    bool check;         
    
    while(1)
    {   
        system("CLS"); 

        cout << "\n" << endl;
        cout << "             =================              " << endl;
        cout << "             |   Bank Menu   |              " << endl;
        cout << "             =================              " << endl;
        cout << "=========================================="<<endl;
        cout << " Enter 1 to create a new account.\n Enter 2 to Deposit to account.\n Enter 3 to Withdraw from account.\n Enter 4 to Check account.\n Enter 5 to Modify account.\n Enter 6 to Delete account.\n Enter 7 to show all accounts.\n Enter 8 to exit";
        cout << "\n=========================================="<<endl;
        cout << " Enter Your Choice : ";

        cin >> x;       // Get user's input
        
        // switch statement based on user input
        switch(x)
        {
            case 1:                                     // Create a new account
            {
                check=false;
                for(int i=0; i<N; i++)
                {
                    if(b[i].checkAvailabilty())         // Check if the account slot is available
                    {
                        check=true;
                        b[i].newAccount();              // Call function to create a new account
                        cout << " working..." << endl;
                        cout << " Completed..." << endl;
                        break;
                    }   
                }
                
                if(check==false)
                    cout << " Accounts exceeded.";        // Notify if maximum accounts limit is reached
                    
                break;  
            }
            case 2:                                     // Deposit money into an account
            {
                check=false;
                cout << " Enter account no : " ;
                cin  >> an;                                // Get account number from user
                for(int i=0; i<N; i++)
                {
                    if(b[i].searchAccount(an))          // Search for the account
                    {
                        check=true;
                        if(b[i].checkPassword() == true){
                            b[i].deposit();                 // Call function to deposit money
                            break;
                        }else{
                            cout << " Incorrect password" << endl;
                        }
                    }   
                }
                
                if(check==false)
                    cout<<" No account found .";        // Notify if account not found
                    
                break;
            }
            case 3:                                     // Withdraw money from an account
            {
                check=false;
                cout << " Enter account no. : ";
                cin >> an;                                // Get account number from user
                for(int i=0; i<N; i++)
                {
                    if(b[i].searchAccount(an))          // Search for the account
                    {
                        check=true;
                        if(b[i].checkPassword() == true){
                            b[i].withdraw();                 // Call function to deposit money
                            break;
                        }else{
                            cout << " Incorrect password" << endl;
                        }
                    }   
                }
                
                if(check==false)
                    cout<<" No account found .";        // Notify if account not found
                    
                break;      
            }
            case 4:                                     // Check account details
            {
                check=false;
                cout<<" Enter account no. : ";
                cin>>an;                                // Get account number from user
                for(int i=0; i<N; i++)
                {
                    if(b[i].searchAccount(an))          // Search for the account
                    {
                        check=true;
                        if(b[i].checkPassword() == true){
                            b[i].checkAccount();                 // Call function to deposit money
                            break;
                        }else{
                            cout << " Incorrect password" << endl;
                        }
                    }   
                }
                
                if(check==false)
                    cout<<" No account found .";        // Notify if account not found
                    
                break;      
                
            }
            case 5:                                     // Modify account information
            {
                check=false;
                cout<<" Enter account no. : ";
                cin>>an;                                // Get account number from user
                for(int i=0; i<N; i++)
                {
                    if(b[i].searchAccount(an))          // Search for the account
                    {
                        check=true;
                        if(b[i].checkPassword() == true){
                            b[i].modifyAccount();                 // Call function to deposit money
                            break;
                        }else{
                            cout << " Incorrect password" << endl;
                        }
                    }   
                }
                
                if(check==false)
                    cout<<" No account found .";        // Notify if account not found
                    
                break;      
            }
            case 6:                                     // Delete an account
            {
                check=false;
                cout<<" Enter account no. : ";
                cin>>an;                                // Get account number from user
                for(int i=0; i<N; i++)
                {
                    if(b[i].searchAccount(an))          // Search for the account
                    {
                        check=true;
                        if(b[i].checkPassword() == true){
                            b[i].deleteAccount();                 // Call function to deposit money
                            break;
                        }else{
                            cout << " Incorrect password" << endl;
                        }
                    }   
                }
                
                if(check==false)
                    cout<<" No account found .";        // Notify if account not found
                    
                break;      
            }
            case 7:                                      // Show all accounts
            {
                check=false;
                for(int i=0; i<N; i++)
                {
                    if(!b[i].checkAvailabilty())           // Check if the account is not empty
                    {

                        check=true;
                        if(b[i].checkPassword() == true){
                            cout<<"\nAccount details of "<<i+1<<":\n ";
                            b[i].checkAccount();               // Call function to display account details
                            cout<<"\n==========================================\n";
                        }else{
                            cout << " Incorrect password" << endl;
                        }
                    }   
                }
                
                if(check==false)
                    cout<<" No account found .";            // Notify if no accounts are found
                    
                break;      
            }
            case 8:                                         // Exit the program
            {
                exit(0);                                    // Terminate the program
            }
            
        }
        getch();                                            // Pause the screen
    }
    
    return 0;
}

// Function to check if the account slot is available
bool bankmanagement::checkAvailabilty()
{
    if(accountNo==0 && name=="" && address=="" && accountType=='\0' && amount==0.0)
        return true;
    else
        return false;
}

// Function to search for an account by account number
bool bankmanagement::searchAccount(int a)
{
    
    if(accountNo==a )
        return true;
    else
        return false;
}

// Function to create a new account
void bankmanagement::newAccount()
{
    
    cout << " Enter your account no : ";
    cin >> accountNo; // Get account number
    
    cout << " Enter your full name : ";
    cin >> name; // Get account holder's name
    
    cout << " Enter your address : ";
    cin >> address; // Get account holder's address

    cout << " Enter strong password : ";
    cin >> passwordHash; // Get password from holder
    passwordHash = simpleHash(passwordHash);

   
    cout << " Account type saving(s) or current(c) :";
    cin >> accountType; // Get account type
   
    cout << " Enter How much money you want to deposit : ";
    cin >> amount; // Get initial deposit amount
	    
    cout << " Account Created Successfully...";	    
}

// Function to deposit money into an account
void bankmanagement::deposit()
{
    float d;
    cout << "\n Enter amount to Deposit = ";
    cin >> d; // Get amount to deposit
    amount += d; // Update account balance
    cout<<" Updated...New Amount = " << amount; // Notify user about updated balance
}

// Function to withdraw money from an account
void bankmanagement::withdraw()
{
    int wd;
    cout << "\n Enter amount to withdraw = ";
    cin >> wd; // Get amount to withdraw
    if(wd<=amount) // Check if withdrawal amount is less than or equal to account balance
    {
        amount -= wd; // Update account balance
        cout << "\n Amount withdrawed successfully."; // Notify user about successful withdrawal
    }
    else
    {
        cout<<"\n Insufficient amount in account."; // Notify user if insufficient balance
    }
    cout << "\n Remaining amount : " << amount; // Notify user about remaining balance
}

// Function to display account details
void bankmanagement::checkAccount()
{
    cout << "\n Your name : " << name; // Display account holder's name
     
    cout << "\n Your address : " << address; // Display account holder's address
    
    cout << "\n Account type : " << accountType; // Display account type
    
    cout << "\n Amount = " << amount; // Display account balance
}

// Function to modify account information
void bankmanagement::modifyAccount()
{
    
    cout << "\n Account No. : " << accountNo; // Display account number
    
    cout << "\n Modify Account Holder Name : ";
    cin >> name; // Get modified account holder's name
    
    cout << "\n Modify your address: ";
    cin >> address; // Get modified account holder's address
    
    cout << "\n Modify Type of Account: saving (s) or Current (c): ";
    cin >> accountType; // Get modified account type
    
    cout << "\n Account is modified."; // Notify user about successful modification
}

// Function to delete an account
void bankmanagement::deleteAccount()
{
    
    accountNo=0; // Reset account number
    name=""; // Reset account holder's name
    address=""; // Reset account holder's address
    accountType='\0'; // Reset account type
    amount=0.0; // Reset account balance
    cout<<"\n Account deleted successfully."; // Notify user about successful deletion
}

string simpleHash(const string &password) {
    hash<string> hasher;
    size_t hashValue = hasher(password);
    
    stringstream ss;
    ss << hex << setw(16) << setfill('0') << hashValue;
    return ss.str();
}

bool bankmanagement::checkPassword(){

    cout << " Enter password : " ;
    string userPassword; cin >> userPassword;
    
    if(simpleHash(userPassword) == passwordHash){
        return true;
    }else{
        return false;
    }
}