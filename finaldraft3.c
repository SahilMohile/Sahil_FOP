	#include <stdio.h>
	#include <math.h>
	#include <string.h>
	
	#define MIN_BALANCE 1000
	#define ARMY_BENEFIT 100000
	
	/* ================= EMI FUNCTION ================= */
	float calculateEMI(float p, float ar, float ty) {
	    float r = ar / (12 * 100);
	    float n = ty * 12;
	
	    if (p <= 0 || r <= 0) return 0;
	
	    return (p * r * pow(1 + r, n)) / (pow(1 + r, n) - 1);
	}
	
	/* ================= LOAN PROCESS ================= */
	void process_loan(char *loan_name, float rate, float min_amt, int max_y) {
	    float p, emi, total_return;
	    char is_army;
	    float final_t = max_y;
	    float final_r = rate;
	
	    printf("\nAre you Army Personnel? (y/n): ");
	    scanf(" %c", &is_army);
	
	    if ((is_army == 'y' || is_army == 'Y') &&
	        strcmp(loan_name, "Personal Loan") == 0) {
	        final_t += 1.5;
	        final_r -= 1.09;
	        if (final_r < 1.0)
	            final_r = 1.0;
	    }
	
	    printf("\n--- %s Setup ---\n", loan_name);
	    printf("Minimum Amount: Rs. %.2f\n", min_amt);
	    printf("Enter Loan Amount: ");
	    scanf("%f", &p);
	
	    if (p < min_amt) {
	        printf("ERROR: Minimum loan amount not met.\n");
	        return;
	    }
	
	    if ((is_army == 'y' || is_army == 'Y') &&
	        strcmp(loan_name, "Personal Loan") != 0) {
	        p -= ARMY_BENEFIT;
	        if (p < 1000) {
	            printf("Adjusted principal too low for EMI.\n");
	            return;
	        }
	        printf("Army Benefit Applied: Principal reduced by Rs.1,00,000\n");
	    }
	
	    emi = calculateEMI(p, final_r, final_t);
	    total_return = emi * final_t * 12;
	
	    printf("\n----- LOAN DETAILS -----\n");
	    printf("Interest Rate: %.2f%%\n", final_r);
	    printf("Tenure: %.1f years\n", final_t);
	    printf("Monthly EMI: Rs. %.2f\n", emi);
	    printf("Total Interest: Rs. %.2f\n", total_return - p);
	    printf("Total Payable: Rs. %.2f\n", total_return);
	}
	
	/* ================= PENSION SYSTEM ================= */
	
	void government_employee();
	void private_employee();
	void self_employed();
	void daily_wage_worker();
	
	void pension_system() {
	    int choice;
	
	    printf("\n===== BANKING PENSION SYSTEM =====\n");
	    printf("1. Government Employee\n");
	    printf("2. Private Employee\n");
	    printf("3. Self-Employed Professional\n");
	    printf("4. Daily Wage Worker\n");
	    printf("5. Exit\n");
	
	    printf("\nEnter your choice: ");
	    scanf("%d", &choice);
	    getchar();
	
	    switch(choice) {
	        case 1:
	            government_employee();
	            break;
	        case 2:
	            private_employee();
	            break;
	        case 3:
	            self_employed();
	            break;
	        case 4:
	            daily_wage_worker();
	            break;
	        case 5:
	            printf("\nExiting Pension System.\n");
	            break;
	        default:
	            printf("\nInvalid choice!\n");
	    }
	}
	
	void government_employee() {
	    float salary, pension;
	
	    printf("\n--- Government Employee Pension ---\n");
	    printf("Enter Basic Salary: ");
	    scanf("%f", &salary);
	    getchar();
	
	    pension = salary * 0.50;
	
	    printf("Monthly Pension Amount: Rs %.2f\n", pension);
	}
	
	void private_employee() {
	    float salary, contribution, pension;
	
	    printf("\n--- Private Employee Pension ---\n");
	    printf("Enter Monthly Salary: ");
	    scanf("%f", &salary);
	    getchar();
	
	    contribution = salary * 0.10;
	    pension = contribution * 20;
	
	    printf("Monthly Contribution: Rs %.2f\n", contribution);
	    printf("Estimated Monthly Pension: Rs %.2f\n", pension);
	}
	
	void self_employed() {
	    float monthly_contribution, pension;
	
	    printf("\n--- Self-Employed Pension ---\n");
	    printf("Enter Monthly Contribution: ");
	    scanf("%f", &monthly_contribution);
	    getchar();
	
	    pension = monthly_contribution * 25;
	
	    printf("Estimated Monthly Pension: Rs %.2f\n", pension);
	}
	
	void daily_wage_worker() {
	    float contribution, pension;
	
	    printf("\n--- Daily Wage Worker Pension ---\n");
	    printf("Enter Monthly Contribution: ");
	    scanf("%f", &contribution);
	    getchar();
	
	    pension = contribution * 30 + 1000;
	
	    printf("Estimated Monthly Pension (with subsidy): Rs %.2f\n", pension);
	}
	
	/* ================= FIXED DEPOSIT SYSTEM ================= */
	
	void fixed_deposit_system() {
	    int choice;
	    float p, TIY, rate, min_p, interest, ma;
	    int TM;
	
	    while (1) {
	        printf("\n===== Bank FD Portal (2026) =====\n");
	        printf("1. Common Scheme   (5.0%% | 18 Months | Min: 1000)\n");
	        printf("2. Special Scheme  (7.5%% | 12 Months | Min: 1500)\n");
	        printf("3. Female Scheme   (6.2%% | 16 Months | Min: 1250)\n");
	        printf("4. Army Scheme     (7.0%% | 11 Months | Min: 950)\n");
	        printf("5. Exit\n");
	        printf("Select your scheme (1-5): ");
	        scanf("%d", &choice);
	        getchar();
	
	        if (choice == 5) {
	            printf("Exiting FD Portal...\n");
	            break;
	        }
	
	        if (choice == 1) {
	            rate = 5.0; min_p = 1000.0; TM = 18;
	            printf("\nSelected: Common Scheme\n");
	        }
	        else if (choice == 2) {
	            rate = 7.5; min_p = 1500.0; TM = 12;
	            printf("\nSelected: Special Scheme\n");
	        }
	        else if (choice == 3) {
	            rate = 6.2; min_p = 1250.0; TM = 16;
	            printf("\nSelected: Female Scheme\n");
	        }
	        else if (choice == 4) {
	            rate = 7.0; min_p = 950.0; TM = 11;
	            printf("\nSelected: Army Personnel Scheme\n");
	        }
	        else {
	            printf("\nInvalid selection! Please try again.\n");
	            continue;
	        }
	
	        printf("Enter the Principal amount: ");
	        scanf("%f", &p);
	        getchar();
	
	        if (p < min_p) {
	            printf("\nError: Minimum principal for this scheme is Rs. %.2f\n", min_p);
	            continue;
	        }
	
	        TIY = (float)TM / 12.0;
	        interest = (p * rate * TIY) / 100;
	        ma = p + interest;
	
	        printf("\n--- FD Maturity Statement ---\n");
	        printf("Principal Amount:   Rs. %.2f\n", p);
	        printf("Interest Rate:      %.1f%% p.a.\n", rate);
	        printf("Tenure:             %d months\n", TM);
	        printf("Interest Earned:    Rs. %.2f\n", interest);
	        printf("Maturity Value:     Rs. %.2f\n", ma);
	        printf("-----------------------------\n");
	    }
	}
	
	
	/* ================= MAIN PROGRAM ================= */
	
	int main() {
	
	    int choice, bankChoice, i;
	    char name[30], email[30], aadhaar[13], pan[11];
	    
	    char consumerNo[20], savedConsumerNo[20];
	    char savedPassword[20], loginPass[20];
	
	    float balance = 0, amount;
	    float transactions[100];
	    int transCount = 0;
	    int kycDone = 0;
	    int accountCreated = 0;
	    int firstLogin = 1;
	
	    char receiverAccNo[25];
	
	    while (1) {
	        printf("\n==============================\n");
	        printf("   WELCOME TO World Peace Bank\n");
	        printf("==============================\n");
	        printf("1.Don't have an account?Create one!\n");
	        printf("2. Login\n");
	        printf("3. Exit\n");
	        printf("Choice: ");
	        scanf("%d", &choice);
	        getchar();
	
	        if (choice == 1) {
	            printf("\n--- SIGNUP ---\n");
	
	            printf("Enter Name: ");
	            fgets(name, sizeof(name), stdin);
	            name[strcspn(name, "\n")] = 0;
	
	            printf("Enter Email-ID: ");
	            fgets(email, sizeof(email), stdin);
	            email[strcspn(email, "\n")] = 0;
	
	            printf("Enter Password: ");
	            fgets(savedPassword, sizeof(savedPassword), stdin);
	            savedPassword[strcspn(savedPassword, "\n")] = 0;
	            while(1){
				
	            printf("Enter Aadhaar Number (12 digits): ");
	               fgets(aadhaar, sizeof(aadhaar), stdin);
	               aadhaar[strcspn(aadhaar, "\n")] = 0;
	               if (strlen(aadhaar) != 12) {
	               printf("Invalid Aadhaar Number. Please enter 12 digits\n");
	               } else {
	               printf("Aadhaar Number accepted\n");
	               break;
	               }
	           }
	
	
	            strcpy(savedConsumerNo, "1234567890");
	            accountCreated = 1;
	
	            printf("\nAccount Created Successfully!.Make sure to fill the Know Your Customer form first!\n");
	            printf("Your Consumer No: %s\n", savedConsumerNo);
	        }
	
	        else if (choice == 2) {
	            if (!accountCreated) {
	                printf("\nPlease create an account first.\n");
	                continue;
	            }
	
	            printf("\n--- LOGIN ---\n");
	            printf("Consumer No: ");
	            fgets(consumerNo, sizeof(consumerNo), stdin);
	            consumerNo[strcspn(consumerNo, "\n")] = 0;
	
	            printf("Password: ");
	            fgets(loginPass, sizeof(loginPass), stdin);
	            loginPass[strcspn(loginPass, "\n")] = 0;
	
	            if (strcmp(consumerNo, savedConsumerNo) == 0 &&
	                strcmp(loginPass, savedPassword) == 0) {
	
	                printf("\nLogin Successful!\n");
	               while (1) {
    				if (firstLogin) {
        				printf("\nEnter Initial Deposit (Greater than Rs.1000): ");
        				scanf("%f", &balance);
        				getchar();

        				if (balance >= MIN_BALANCE) {
            			firstLogin = 0;
            			break;
        			} else {
            			printf("Minimum Balance is Rs 1000.\n");
       					}
    				}
				}
     
	
	                    
	                }
	
	                while (1) {
	                    printf("\n----- BANK MENU -----\n");
	                    printf("1. Deposit Money\n");
	                    printf("2. Withdraw Money\n");
	                    printf("3. Check Balance\n");
	                    printf("4. Transactions History\n");
	                    printf("5. Know-Your-Customer(KYC)\n");
	                    printf("6. Loan Services\n");
	                    printf("7. Bank Transfer\n");
	                    printf("8. Pension Schemes\n");
	                    printf("9. Fixed Deposit(FD)\n");
	                    printf("10. Exit\n");
	                    printf("Choice: ");
	                    scanf("%d", &bankChoice);
	                    getchar();
	
	                    if (bankChoice == 1) {
	                        if (!kycDone) {
	                            printf("Complete KYC first.\n");
	                            continue;
	                        }
	                        printf("Amount: ");
	                        scanf("%f", &amount);
	                        getchar();
	                        balance += amount;
	                        transactions[transCount++] = amount;
	                        printf("%f added to account successfully!", amount);
	                    }
	
	                    else if (bankChoice == 2) {
	                        if (!kycDone) {
	                            printf("Complete KYC first.\n");
	                            continue;
	                        }
	                        printf("Amount: ");
	                        scanf("%f", &amount);
	                        getchar();
	                        if (amount <= balance) {
	                            balance -= amount;
	                            transactions[transCount++] = -amount;
	                            printf("%f amount deducted successfully!",amount);
	                        } else {
	                            printf("Insufficient balance.\n");
	                        }
	                    }
	
	                    else if (bankChoice == 3) {
	                        printf("Balance: Rs. %.2f\n", balance);
	                    }
	
	                    else if (bankChoice == 4) {
	                        if (transCount == 0) {
	                            printf("No transactions yet.\n");
	                        } else {
	                            for (i = 0; i < transCount; i++) {
	                                printf("%d. %s Rs. %.2f\n", i + 1,
	                                       transactions[i] > 0 ? "Deposit" : "Withdraw",
	                                       fabs(transactions[i]));
	                            }
	                        }
	                    }
	
	                    else if (bankChoice == 5) {
	                        if (kycDone) {
       						printf("KYC is already completed. You cannot update it again.\n");
       						continue;
    						}
							printf("Enter PAN(10 digits): ");
	                        fgets(pan, sizeof(pan), stdin);
	                        pan[strcspn(pan, "\n")] = 0;
	
	                        if (strlen(pan) == 10) {
	                            kycDone = 1;
	                            printf("KYC Completed Successfully.\n");
	                        } else {
	                            printf("Invalid PAN.\n");
	                        }
	                    }
	
	                    else if (bankChoice == 6) {
	                        int lc;
	                        printf("\n--- LOAN MENU ---\n");
	                        printf("1. Car Loan\n2. Business Loan\n3. Home Loan\n4. Personal Loan\n5. Exit\n");
	                        printf("Choice: ");
	                        scanf("%d", &lc);
	                        getchar();
	
	                        switch (lc) {
	                            case 1: process_loan("Car Loan", 7.9, 100000, 5); break;
	                            case 2: process_loan("Business Loan", 8.7, 1000000, 10); break;
	                            case 3: process_loan("Home Loan", 9.6, 1250550, 20); break;
	                            case 4: process_loan("Personal Loan", 12.7, 200000, 2); break;
	                            default: break;
	                        }
	                    }
	
	                    else if (bankChoice == 7) {
	                        if (!kycDone) {
	                            printf("Complete KYC first.\n");
	                            continue;
	                        }
	
	                        printf("Enter Receiver Account Number: ");
	                        fgets(receiverAccNo, sizeof(receiverAccNo), stdin);
	                        receiverAccNo[strcspn(receiverAccNo, "\n")] = 0;
	
	
	                        printf("Enter Amount to Transfer: ");
	                        scanf("%f", &amount);
	                        getchar();
	
	                        if (amount <= 0) {
	                            printf("Invalid transfer amount.\n");
	                        }
	                        else if (amount > balance) {
	                            printf("Insufficient balance.\n");
	                        }
	                        else {
	                            balance -= amount;
	                            transactions[transCount++] = -amount;
	                            printf("Rs. %.2f transferred successfully to Account %s.\n",
	                                   amount, receiverAccNo);
	                        }
	                    }
	
	                    else if (bankChoice == 8) {
	                        pension_system();
	                    }
	                    
						else if (bankChoice == 9) {
	   						fixed_deposit_system();
						}
	
	
	                    else if (bankChoice == 10) {
	                        printf("Logged out successfully.\n");
	                        break;
	                    }
	                }
	            } else {
	                printf("Invalid Consumer Number or Password.\n");
	            }
	        }
	
	        else if (choice == 3) {
	            printf("\nThank you for visiting World Peace Bank.\n");
	            break;
	        }
	    }
	
	    return 0;
	}

