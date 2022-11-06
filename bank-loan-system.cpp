#include <iostream>
#include <vector>
#include <math.h>
#include <iomanip>
#include <algorithm>
#include <fstream>
#include <string>
#include <stdio.h>
using namespace std;

//vector inclusing all loan names
vector<string> LOANS = {
    "Vehicle",
    "Housing",
    "Education",
    "Senior Citizen",
    "Personal",
    "Personal"};

//vector including all interest rates
vector<double> INTEREST_RATES = {0.14, 0.08, 0.06, 0.045, 0.145, 0.162};

//global variable for loan index
int LOAN_INDEX;

/**
 * Loan Detail Class
 * to store current loan status
*/
class LoanDetail
{
public:
    LoanDetail() {}
    LoanDetail(int month, double remainingLoanAmount, double interest, double repaidLoanAmount)
    {
        this->month = month;
        this->remainingLoanAmount = remainingLoanAmount;
        this->interest = interest;
        this->repaidLoanAmount = repaidLoanAmount;
    }
    int month;
    double remainingLoanAmount;
    double interest;
    double repaidLoanAmount;
};

/**
 * Customer class 
 * for details of the customer
*/
class Customer
{
    string name;
    int age;
    double monthlyIncome;

public:
    //default constructor
    Customer() {}

    //parameterized constructor
    Customer(string name, int age, double monthlyIncome)
    {
        this->name = name;
        this->age = age;
        this->monthlyIncome = monthlyIncome;
    }

    string getCustomerName()
    {
        return name;
    }

    int getCustomerAge()
    {
        return age;
    }

    double getCustomerMonthlyIncome()
    {
        return monthlyIncome;
    }
};

/**
 * returns the maximum repay period
 * for the selected loan
*/
int getMaximumRepayPeriod()
{
    switch (LOAN_INDEX)
    {
    case 1:
        return 60;
        break;
    case 2:
        return 60;
        break;
    case 3:
        return 84;
        break;
    case 4:
        return 60;
        break;
    case 5:
        return 60;
        break;
    case 6:
        return 84;
        break;
    }
}

/**
 * prints common header for
 * loan details table
*/
void loanDetailsTableHeader()
{
    cout << "+-----------|--------------------|---------------------|-------------------------------|----------------------------+" << endl;
    cout << "Loan Name-+-+-+-Monthly Income-+-+-+-Max Loan Amount-+-+-+-Max Repay Period (Months)-+-+-+-Annual interest rate fixed" << endl;
    cout << "+-----------|--------------------|---------------------|-------------------------------|----------------------------+" << endl;
}

/**
 * the following fucntions
 * are used to print 
 * the details about the 
 * loans that the customer can apply
*/
void vehicleLoan()
{
    cout << "[1]Vehicle  | Above 45000        |  1,000,000.00       |            60                 |       14%                   " << endl;
    cout << "+-----------|--------------------|---------------------|-------------------------------|----------------------------+" << endl;
}

void housingLoan()
{
    cout << "[2]Housing  | Above 100,000      |  2,500,000.00       |            60                 |       8%                   " << endl;
    cout << "+-----------|--------------------|---------------------|-------------------------------|----------------------------+" << endl;
}

void educationLoan()
{
    cout << "[3]Education| Above 45000        |  1,500,000.00       |            84                |       6%                   " << endl;
    cout << "+-----------|--------------------|---------------------|-------------------------------|----------------------------+" << endl;
}

void seniorCitizenLoan()
{
    cout << "[4]Seni.Cit.| Above 35000        |    500,000.00       |            60                 |       4.5%                   " << endl;
    cout << "+-----------|--------------------|---------------------|-------------------------------|----------------------------+" << endl;
}

void personalLoan()
{
    cout << "[5]Personal | Above 100,000      |    2,000,000.00     |            60                 |       14.5%                   " << endl;
    cout << "                                 |    3,000,000.00     |            84                 |       16.2%                   " << endl;
    cout << "+-----------|--------------------|---------------------|-------------------------------|----------------------------+" << endl;
}

/**
 * checks the wished amount of loan
 * and the possible repay period by the costomer
 * returns whether the customer is
 * suitable to grant the loan
*/
bool canGrantLoan(int loanIndex, double wishedAmount, int repayPeriod)
{
    if (loanIndex == 1 && wishedAmount <= 1000000 && repayPeriod <= 60)
    {
        LOAN_INDEX = 1;
        return true;
    }
    if (loanIndex == 2 && wishedAmount <= 2500000 && repayPeriod <= 60)
    {
        LOAN_INDEX = 2;
        return true;
    }
    if (loanIndex == 3 && wishedAmount <= 1500000 && repayPeriod <= 84)
    {
        LOAN_INDEX = 3;
        return true;
    }
    if (loanIndex == 4 && wishedAmount <= 500000 && repayPeriod <= 60)
    {
        LOAN_INDEX = 4;
        return true;
    }
    if (loanIndex == 5 && wishedAmount <= 2000000 && repayPeriod <= 60)
    {
        LOAN_INDEX = 5;
        return true;
    }
    if (loanIndex == 5 && wishedAmount <= 3000000 && repayPeriod <= 84)
    {
        LOAN_INDEX = 6;
        return true;
    }
    return false;
}

/**
 * this checks the details about
 * the customer and
 * prints the eligible loans for him
*/
int getEligibleLoans(Customer customer, vector<int> &eligibleLoans)
{
    double monthlyIncome = customer.getCustomerMonthlyIncome();
    int age = customer.getCustomerAge();

    if (age < 18 || monthlyIncome < 45000)
    {
        cout << "Not eligible for any Loan\n";
        return 0;
    }
    else
    {
        loanDetailsTableHeader();
    }

    if (age >= 18 && age <= 55 && monthlyIncome >= 45000)
    {
        eligibleLoans[0] = 1;
        vehicleLoan();
    }
    if (age >= 25 && age <= 55 && monthlyIncome >= 100000)
    {
        eligibleLoans[1] = 1;
        housingLoan();
    }
    if (age >= 25 && age <= 35 && monthlyIncome >= 45000)
    {
        eligibleLoans[2] = 1;
        educationLoan();
    }
    if (age >= 60 && monthlyIncome >= 35000)
    {
        eligibleLoans[3] = 1;
        seniorCitizenLoan();
    }
    if (age >= 30 && age <= 55 && monthlyIncome >= 100000)
    {
        eligibleLoans[4] = 1;
        personalLoan();
    }
    return 1;
}

/**
 * calculat the loan details for each month
*/
void calculateLoanDetails(int loanIndex, int repayPeriod, double loanAmount, vector<LoanDetail> &loanDetails)
{
    double annualInterestRate = INTEREST_RATES[LOAN_INDEX - 1];
    double periodicIR = annualInterestRate / 12.0; //periodic interest rate

    double discountFactor = ((pow(1 + periodicIR, repayPeriod)) - 1) / (periodicIR * (pow(1 + periodicIR, repayPeriod)));

    double totalMonthlyPayment = loanAmount / discountFactor;

    double remainingLoanAmount = loanAmount;

    double interest;
    double repaidLoanAmount;
    int month = 1;
    for (int i = 1; i <= repayPeriod; i++)
    {
        interest = remainingLoanAmount * periodicIR;

        repaidLoanAmount = totalMonthlyPayment - interest;

        LoanDetail loanDetail = LoanDetail(month, remainingLoanAmount, interest, repaidLoanAmount);
        loanDetails.push_back(loanDetail);
        month++;
        remainingLoanAmount = remainingLoanAmount - repaidLoanAmount;
    }
}

/**
 * write the loan details of
 * each customer
 * to a new file
*/
void writeToFile(Customer customer, double totalAmountPaid, double totalInterest, double requested, int repayPeriod, vector<LoanDetail> loanDetails)
{
    string name = customer.getCustomerName();
    replace(name.begin(), name.end(), ' ', '_');
    name += ".txt";

    ofstream f;
    f.open(name.c_str());
    f << "Customer Name                   : " << customer.getCustomerName() << endl;
    f << "Selected Loan                   : " << LOANS[LOAN_INDEX - 1] << endl;
    f << "Maximum repay period allowed    : " << getMaximumRepayPeriod() << endl;
    f << "Annual interest rate            : " << std::fixed << std::setprecision(2) << INTEREST_RATES[LOAN_INDEX - 1] * 100 << "%" << endl;
    f << "Requested Loan Amount           : " << std::fixed << std::setprecision(2) << requested << endl;
    f << "Repay period : " << std::fixed << std::setprecision(2) << repayPeriod << endl;
    f << "+-------|----------------------------|---------------|------------------------+\n";
    f << "Month        Remaining Loan Amount        Interest        Repaid Loan Amount\n";
    f << "+-------|----------------------------|---------------|------------------------+\n";
    for (int i = 0; i < loanDetails.size(); i++)
    {
        f << loanDetails[i].month << "        ";
        f << std::fixed << std::setprecision(2) << loanDetails[i].remainingLoanAmount << "                        ";
        f << std::fixed << std::setprecision(2) << loanDetails[i].interest << "                ";
        f << std::fixed << std::setprecision(2) << loanDetails[i].repaidLoanAmount << "                ";
        f << endl;

        //cout<<"repaid loan: "<<std::fixed << std::setprecision(2)<<loanDetails[i].repaidLoanAmount<<"        "<<endl;
        f << "+-------|----------------------------|---------------|------------------------+\n";
    }
    f << endl;
    f << "Total amount paid by customer at the end of repay period : " << std::fixed << std::setprecision(2) << totalAmountPaid << endl;
}

/**
 * get the information
 * from customer to customer
 * decides what kind of loan to grant
 * and eligibility
*/
int loanGenerator()
{

    cout << "Customer Details:" << endl;

    //variables to store customer details
    string name;
    int age;
    double monthlyIncome;
    string initials;
    string firstName;
    string lastName;

    cout << "\tName: Enter as below\n";
    cout << "\t\tInitials(without spaces) : ";
    cin >> initials;
    cout << "\t\tFirst Name               : ";
    cin >> firstName;
    cout << "\t\tLast Name                : ";
    cin >> lastName;

    name = initials + "_" + firstName + "_" + lastName;

    cout << "\tAge: ";
    cin >> age;
    cout << "\tMonthly Income: ";
    cin >> monthlyIncome;
    cout << "\n\nEligible Bank Loans" << endl;

    Customer customer = Customer(name, age, monthlyIncome);

    //getting eligible loan details
    vector<int> eligibleLoans = {0, 0, 0, 0, 0};
    int isEligible = getEligibleLoans(customer, eligibleLoans);
    if (isEligible == 0)
    {
        cout << "-----------------------\n";
        cout << "Next Customer>>" << endl;
        cout << "-----------------------\n";
        return 0;
    }

    //getting the prefered loan
    int loanIndex;
    cout << "Enter the correct loan Index :";
    bool isCorrectIndex = false;
    do
    {

        cin >> loanIndex;
        if (eligibleLoans[loanIndex - 1] == 0)
        {
            cout << "\nInvalid loan index\n";
            cout << "Enter the correct loan Index :";
        }
        else
        {
            isCorrectIndex = true;
        }

    } while (!isCorrectIndex);

    //getting the amount that the customer wishes to borrow
    //and possible repay period
    cout << "----------------------------------------\n";
    cout << "You selected " << LOANS[loanIndex - 1] << " Loan\n";
    cout << "----------------------------------------\n";
    cout << "Enter the following details\n";
    double wishedAmount;
    int repayPeriod;
    cout << "Amount of money whishing to be borrowed :";
    cin >> wishedAmount;
    cout << "Possible repay period                   : ";
    cin >> repayPeriod;

    //checking the ability to get the loan
    if (canGrantLoan(loanIndex, wishedAmount, repayPeriod))
    {
        cout << "-----------------------\n";
        cout << "Eligible to get the loan\n";
        cout << "-----------------------\n";
    }
    else
    {
        cout << "Not Eligible to get the loan\n";
        cout << "-----------------------\n";
        cout << "Next Customer>>" << endl;
        cout << "-----------------------\n";
        return 1;
    }

    //calculations regarding the loan
    vector<LoanDetail> loanDetails;
    calculateLoanDetails(loanIndex, repayPeriod, wishedAmount, loanDetails);
    double totalInterest = 0;
    double totalRepaidLoanAmount = 0;
    for (int i = 0; i < loanDetails.size(); i++)
    {
        totalInterest += loanDetails[i].interest;
        totalRepaidLoanAmount += loanDetails[i].repaidLoanAmount;
    }
    double totalAmountPaid = totalInterest + totalRepaidLoanAmount;
    cout << "Total amount to be paid by customer : " << std::fixed << std::setprecision(2) << totalAmountPaid << endl;
    cout << "Total interest earned by bank : " << std::fixed << std::setprecision(2) << totalInterest << endl;
    cout << "----------------------------------------\n";
    cout << "Next customer >>\n";
    cout << "----------------------------------------\n";
    //write to file
    writeToFile(customer, totalAmountPaid, totalInterest, wishedAmount, repayPeriod, loanDetails);
}

/**
 * welcome screen and
 * keeps a loop to include all the customers
*/
void mainMenu()
{
    //welcome screen

    cout << "////////////////////////////////////////////////////////" << endl;
    cout << "---------------------BANK LOAN SYSTEM-------------------" << endl;
    cout << "////////////////////////////////////////////////////////" << endl;

    int option;
    int customerCount = 1;
    do
    {
        cout << "\tTasks\n";
        cout << "\t\t[1] Add a customer\n";
        cout << "\t\t[2] Exit\n";
        cout << "\t\t\tTask No(1 or 2): ";
        cin >> option;
        if (option == 1)
        {
            cout << endl;
            cout << "Customer[" << customerCount << "]" << endl;
            customerCount++;
            loanGenerator();
        }
        if (option != 1 && option != 2)
        {
            cout << "Enter the correct task number!" << endl;
        }
    } while (option != 2);
    cout << "-----------------------\n";
    cout << "Have a nice day\n";
    cout << "-----------------------\n";
}

/**
 * main function
*/
int main()
{

    mainMenu();
}