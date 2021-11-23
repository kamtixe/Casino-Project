#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
#include <time.h>
#include "C:\Users\user\source\repos\Projekt2\Projekt2\include\color.hpp"

using namespace std;

int main()
{
    string usrnamecreate;
    string passwrdcreate;
    string repeatpasswrd;
    string usrname;
    string passwrd;
    string mailcreate;
    double balance = 1000;
    string currency = "USD";
    for (bool main_menu = false; main_menu == false;) {
        int wybor;
        system("CLS");
        cout << dye::red("Welcome in Kamil's Casino!") << endl;
        cout << dye::yellow("What would you want to do?") << endl;
        cout << dye::light_aqua("1 - create an account") << endl;
        cout << dye::light_aqua("2 - login to an account") << endl;
        cout << dye::light_aqua("3 - exit the program") << endl;
        cout << "Write you choice here <1-3>: ";
        cin >> wybor;
        for (bool log_in = false; log_in == false;) {
            switch (wybor)
            {
            case 1:
                system("CLS");
                cout << "Input username: ";
                cin >> usrnamecreate;
                cout << "Input mail: ";
                cin >> mailcreate;
                cout << "Input password: ";
                cin >> passwrdcreate;
                cout << "Repeat password: ";
                cin >> repeatpasswrd;
                system("CLS");
                if (repeatpasswrd == passwrdcreate)
                {
                    cout << "You've created your account! You can now login in!" << endl;

                    system("pause");

                    fstream plik;
                    plik.open("logins.txt", ios::out | ios::app);

                    plik << "login: " << usrnamecreate << endl;
                    plik << "password: " << passwrdcreate << endl;
                    plik << "mail: " << mailcreate << endl;
                    plik << "===============================" << endl;
                    plik.close();
                    log_in = true;
                }
                else
                {
                    cout << "Password's doesn't match each other! Try again!" << endl;
                    system("pause");
                }
                break;
            case 2:
                system("CLS");
                cout << "Input username: ";
                cin >> usrname;
                cout << "Input password: ";
                cin >> passwrd;
                if (passwrd == passwrdcreate)
                {
                    system("CLS");
                    cout << "You've logged in!" << endl;
                    system("pause");
                    for (bool czy_koniec = false; czy_koniec == false;)
                    {
                        int wybormenu;
                        string name = usrname;
                        int settingschoice;
                        int currencychoice;
                        string currencychange;
                        int gamechoice;
                        int guessingbet;
                        int levelchoice;
                        int ingamechoice;
                        int guessingnumber;
                        int dice;
                        int roulettebet;
                        bool flag = 0;
                        bool nmbrflag = 0;
                        srand(time(0));
                        system("CLS");
                        cout << "Welcome in Kamil's Casino" << endl;
                        cout << "1 - games" << endl;
                        cout << "2 - your profile" << endl;
                        cout << "3 - settings" << endl;
                        cout << "4 - exit" << endl;
                        cout << "Write you choice here <1-4>: ";
                        cin >> wybormenu;
                        switch (wybormenu)
                        {
                        case 1:
                            system("CLS");
                            cout << "Available games:" << endl;
                            cout << "1 - roulette" << endl;
                            cout << "2 - number guessing" << endl;
                            cout << "3 - exit" << endl;
                            cout << "Write you choice here: ";
                            cin >> gamechoice;
                            switch (gamechoice)
                            {
                            case 1:
                                system("CLS");
                                cout << setw(60) << "Roulette game";
                                cout << setw(40) << "Balance: " << balance << endl;
                                cout << "how much would you like to bet?: ";
                                cin >> roulettebet;
                                if (roulettebet <= balance)
                                {
                                    int ball = rand() % 36 + 1;
                                    int guess;
                                    system("CLS");
                                    cout << "Chose what you want to bet on" << endl;
                                    cout << "1 - number [1-36], high risk but if you win your bet is multiplied by 14" << endl;
                                    cout << "2 - red [even numbers], lower risk, if you win your bet is multiplied by 2" << endl;
                                    cout << "3 - black [odd numbers], lower risk, if you win your bet is multiplied by 2" << endl;
                                    cout << "Write your choice here: ";
                                    cin >> guess;
                                    cout << endl;
                                    if (guess == 1)
                                    {
                                        system("CLS");
                                        int number;
                                        cout << "Enter your chosen number in between 1-36: ";
                                        cin >> number;
                                        if (guess == ball)
                                        {
                                            nmbrflag = 1;
                                        }
                                        else
                                        {
                                            flag = 0;
                                        }
                                    }
                                    else if (guess == 2)
                                    {
                                        if (ball % 2 == 0)
                                        {
                                            flag = 1;
                                        }
                                        else
                                        {
                                            flag = 0;
                                        }
                                    }
                                    else if (guess == 3)
                                    {
                                        if (ball % 2 != 0)
                                        {
                                            flag = 1;
                                        }
                                        else
                                        {
                                            flag = 0;
                                        }
                                    }
                                    else
                                    {
                                        system("CLS");
                                        cout << "Invalid input " << endl;
                                    }

                                    if (flag == 1)
                                    {
                                        system("CLS");
                                        cout << "Congratulations!" << endl;
                                        cout << "You've won on red/black!" << endl;
                                        cout << "Your bet got multiplied by 2! It means you won" << roulettebet * 2 << currency << endl;
                                        balance = balance + roulettebet * 2;
                                    }
                                    else if (nmbrflag == 1)
                                    {
                                        system("CLS");
                                        cout << "Big congratulations! You've won on green!" << endl;
                                        cout << "Your bet got multiplied by 14! It means you won" << roulettebet * 14 << currency << endl;
                                        balance = balance + roulettebet * 14;
                                    }
                                    else
                                    {
                                        system("CLS");
                                        cout << "You haven't guessed, wish you best of luck next time! :D" << endl;
                                        cout << "You lost: " << roulettebet << currency << endl;
                                        balance = balance - roulettebet;
                                    }
                                }
                                else if (roulettebet > balance)
                                {
                                    system("CLS");
                                    cout << "You have insufficient funds! Please type in correct amount!" << endl;
                                }
                                else
                                {
                                    system("CLS");
                                    cout << "Please type in correct information!" << endl;
                                }
                                break;
                            case 2:
                                system("CLS");
                                cout << setw(60) << "Number guessing game";
                                cout << setw(35) << "Balance: " << balance << endl;
                                cout << "1 - easy, numbers from 1-10, if you guess your money are multiplied by 1.1" << endl;
                                cout << "2 - intermediate, numbers from 1-25, if you guess your money are multiplied by 1.5" << endl;
                                cout << "3 - hard, numbers from 1-100, if you guess your money are multiplied by 10" << endl;
                                cout << "Type in the number of mode you want to enter: ";
                                cin >> levelchoice;
                                switch (levelchoice)
                                {
                                case 1:
                                    system("CLS");
                                    cout << "You've chosed easy level!" << endl;
                                    cout << "1 - Play a game" << endl;
                                    cout << "2 - exit" << endl;
                                    cout << "Write your choice here: ";
                                    cin >> ingamechoice;
                                    switch (ingamechoice)
                                    {
                                    case 1:
                                        system("CLS");
                                        cout << "Type in how much would you like to bet: ";
                                        cin >> guessingbet;
                                        if (guessingbet <= balance)
                                        {
                                            system("CLS");
                                            cout << "Choose a number from 1 - 10: ";
                                            cin >> guessingnumber;
                                            if (guessingnumber <= 0 || guessingnumber > 10)
                                            {
                                                system("CLS");
                                                cout << "Please check the number!! It should be between 1 to 10" << endl;
                                                system("pause");
                                            }
                                            while (guessingnumber <= 0 || guessingnumber > 10);

                                            dice = rand() % 10 + 1;

                                            if (dice == guessingnumber)
                                            {
                                                cout << "Congratulations! You've guessed the number! You've won: " << guessingbet * 1.1 << endl;
                                                balance = balance + guessingbet * 1.1;
                                            }
                                            else
                                            {
                                                cout << "Bad luck, You've lost: " << guessingbet << " [" << currency << "]" << endl;
                                                balance = balance - guessingbet;
                                            }
                                            cout << "The winning number was : " << dice << endl;
                                        }
                                        else if (guessingbet > balance)
                                        {
                                            system("CLS");
                                            cout << "You have insufficient funds! Please type in correct amount!" << endl;
                                        }
                                        break;
                                    case 2:
                                        system("CLS");
                                        break;
                                    default:
                                        system("CLS");
                                        cout << "Please type in correct number!" << endl;
                                        system("pause");
                                        break;
                                    }
                                    break;
                                case 2:
                                    system("CLS");
                                    cout << "You've chosed intermediate level!" << endl;
                                    cout << "1 - Play a game" << endl;
                                    cout << "2 - exit" << endl;
                                    cout << "Write your choice here: ";
                                    cin >> ingamechoice;
                                    switch (ingamechoice)
                                    {
                                    case 1:
                                        system("CLS");
                                        cout << "Type in how much would you like to bet: ";
                                        cin >> guessingbet;
                                        if (guessingbet <= balance)
                                        {
                                            system("CLS");
                                            cout << "Choose a number from 1 - 25: ";
                                            cin >> guessingnumber;
                                            if (guessingnumber <= 0 || guessingnumber > 25)
                                            {
                                                system("CLS");
                                                cout << "Please check the number!! It should be between 1 to 25" << endl;
                                                system("pause");
                                            }
                                            while (guessingnumber <= 0 || guessingnumber > 25);

                                            dice = rand() % 25 + 1;

                                            if (dice == guessingnumber)
                                            {
                                                cout << "Congratulations! You've guessed the number! You've won: " << guessingbet * 1.5 << endl;
                                                balance = balance + guessingbet * 1.5;
                                            }
                                            else
                                            {
                                                cout << "Bad luck, You've lost: " << guessingbet << " [" << currency << "]" << endl;
                                                balance = balance - guessingbet;
                                            }
                                            cout << "The winning number was : " << dice << endl;
                                        }
                                        else if (guessingbet > balance)
                                        {
                                            system("CLS");
                                            cout << "You have insufficient funds! Please type in correct amount!" << endl;
                                        }
                                        break;
                                    case 2:
                                        system("CLS");
                                        break;
                                    default:
                                        system("CLS");
                                        cout << "Please type in correct number!" << endl;
                                        system("pause");
                                        break;
                                    }
                                    break;
                                case 3:
                                    system("CLS");
                                    cout << "You've chosed hard level!" << endl;
                                    cout << "1 - Play a game" << endl;
                                    cout << "2 - exit" << endl;
                                    cout << "Write your choice here: ";
                                    cin >> ingamechoice;
                                    switch (ingamechoice)
                                    {
                                    case 1:
                                        system("CLS");
                                        cout << "Type in how much would you like to bet: ";
                                        cin >> guessingbet;
                                        if (guessingbet <= balance)
                                        {
                                            system("CLS");
                                            cout << "Choose a number from 1 - 100: ";
                                            cin >> guessingnumber;
                                            if (guessingnumber <= 0 || guessingnumber > 100)
                                            {
                                                system("CLS");
                                                cout << "Please check the number!! It should be between 1 to 100" << endl;
                                                system("pause");
                                            }
                                            while (guessingnumber <= 0 || guessingnumber > 100);

                                            dice = rand() % 100 + 1;

                                            if (dice == guessingnumber)
                                            {
                                                cout << "Congratulations! You've guessed the number! You've won: " << guessingbet * 10 << endl;
                                                balance = balance + guessingbet * 10;
                                            }
                                            else
                                            {
                                                cout << "Bad luck, You've lost: " << guessingbet << " [" << currency << "]" << endl;
                                                balance = balance - guessingbet;
                                            }
                                            cout << "The winning number was : " << dice << endl;
                                        }
                                        else if (guessingbet > balance)
                                        {
                                            system("CLS");
                                            cout << "You have insufficient funds! Please type in correct amount!" << endl;
                                        }
                                        break;
                                    case 2:
                                        system("CLS");
                                        break;
                                    default:
                                        system("CLS");
                                        cout << "Please type in correct number!" << endl;
                                        system("pause");
                                        break;
                                    }
                                default:
                                    cout << "Please type in correct number!" << endl;
                                    break;
                                }
                                break;
                            case 3:
                                system("CLS");
                                cout << "It was good to see you there!" << endl;
                                break;
                            default:
                                system("CLS");
                                cout << "Please type in correct game number!" << endl;
                                break;
                            }
                            system("pause");
                            break;
                        case 2:
                            system("CLS");
                            cout << "|" << setw(5) << "Name: " << name << setw(5)
                                << "|" << setw(5) << "Balance: " << balance << setw(5)
                                << "|" << setw(5) << "Currency: " << currency << setw(5)
                                << "|" << endl;
                            system("pause");
                            break;
                        case 3:
                            system("CLS");
                            cout << "1 - currency settings" << endl;
                            cout << "2 - user settings" << endl;
                            cout << "Write you choice here: ";
                            cin >> settingschoice;
                            if (settingschoice == 1)
                            {
                                system("CLS");
                                cout << "Your current currency: " << currency << endl;
                                cout << "1 - change your currency" << endl;
                                cout << "2 - come back to main menu" << endl;
                                cout << "Write you choice here: ";
                                cin >> currencychoice;
                                switch (currencychoice)
                                {
                                case 1:
                                    if (currency == "USD")
                                    {
                                        system("CLS");
                                        cout << "Currently available currencies: " << endl;
                                        cout << "================================" << endl;
                                        cout << "EUR" << endl;
                                        cout << "GBP" << endl;
                                        cout << "PLN" << endl;
                                        cout << "================================" << endl;
                                        cout << "Choose your currency: ";
                                        cin >> currencychange;
                                        if (currencychange == "EUR")
                                        {
                                            system("CLS");
                                            balance = balance * 0.88;
                                            currency = "EUR";
                                            cout << "Your currency has been sucesfully updated to: " << currency << endl;
                                        }
                                        else if (currencychange == "GBP")
                                        {
                                            system("CLS");
                                            balance = balance * 0.74;
                                            currency = "GBP";
                                            cout << "Your currency has been sucesfully updated to: " << currency << endl;
                                        }
                                        else if (currencychange == "PLN")
                                        {
                                            system("CLS");
                                            balance = balance * 4.14;
                                            currency = "PLN";
                                            cout << "Your currency has been sucesfully updated to: " << currency << endl;
                                        }
                                        else
                                        {
                                            system("CLS");
                                            cout << "Please type in correct currency shortcut!" << endl;
                                            system("pause");
                                        }
                                    }
                                    else if (currency == "EUR")
                                    {
                                        system("CLS");
                                        cout << "Currently available currencies: " << endl;
                                        cout << "================================" << endl;
                                        cout << "USD" << endl;
                                        cout << "GBP" << endl;
                                        cout << "PLN" << endl;
                                        cout << "================================" << endl;
                                        cout << "Choose your currency: ";
                                        cin >> currencychange;
                                        if (currencychange == "USD")
                                        {
                                            system("CLS");
                                            balance = balance * 1.13;
                                            currency = "USD";
                                            cout << "Your currency has been sucesfully updated to: " << currency << endl;
                                        }
                                        else if (currencychange == "GBP")
                                        {
                                            system("CLS");
                                            balance = balance * 0.84;
                                            currency = "GBP";
                                            cout << "Your currency has been sucesfully updated to: " << currency << endl;
                                        }
                                        else if (currencychange == "PLN")
                                        {
                                            system("CLS");
                                            balance = balance * 4.68;
                                            currency = "PLN";
                                            cout << "Your currency has been sucesfully updated to: " << currency << endl;
                                        }
                                        else
                                        {
                                            system("CLS");
                                            cout << "Please type in correct currency shortcut!" << endl;
                                            system("pause");
                                        }
                                    }
                                    else if (currency == "GBP")
                                    {
                                        system("CLS");
                                        cout << "Currently available currencies: " << endl;
                                        cout << "================================" << endl;
                                        cout << "USD" << endl;
                                        cout << "EUR" << endl;
                                        cout << "PLN" << endl;
                                        cout << "================================" << endl;
                                        cout << "Choose your currency: ";
                                        cin >> currencychange;
                                        if (currencychange == "USD")
                                        {
                                            system("CLS");
                                            balance = balance * 1.34;
                                            currency = "USD";
                                            cout << "Your currency has been sucesfully updated to: " << currency << endl;
                                        }
                                        else if (currencychange == "EUR")
                                        {
                                            system("CLS");
                                            balance = balance * 1.19;
                                            currency = "EUR";
                                            cout << "Your currency has been sucesfully updated to: " << currency << endl;
                                        }
                                        else if (currencychange == "PLN")
                                        {
                                            system("CLS");
                                            balance = balance * 5.56;
                                            currency = "PLN";
                                            cout << "Your currency has been sucesfully updated to: " << currency << endl;
                                        }
                                        else
                                        {
                                            system("CLS");
                                            cout << "Please type in correct currency shortcut!" << endl;
                                            system("pause");
                                        }
                                    }
                                    else if (currency == "PLN")
                                    {
                                        system("CLS");
                                        cout << "Currently available currencies: " << endl;
                                        cout << "================================" << endl;
                                        cout << "USD" << endl;
                                        cout << "GBP" << endl;
                                        cout << "EUR" << endl;
                                        cout << "================================" << endl;
                                        cout << "Choose your currency: ";
                                        cin >> currencychange;
                                        if (currencychange == "USD")
                                        {
                                            system("CLS");
                                            balance = balance * 0.24;
                                            currency = "USD";
                                            cout << "Your currency has been sucesfully updated to: " << currency << endl;
                                        }
                                        else if (currencychange == "GBP")
                                        {
                                            system("CLS");
                                            balance = balance * 0.18;
                                            currency = "GBP";
                                            cout << "Your currency has been sucesfully updated to: " << currency << endl;
                                        }
                                        else if (currencychange == "EUR")
                                        {
                                            system("CLS");
                                            balance = balance * 0.21;
                                            currency = "EUR";
                                            cout << "Your currency has been sucesfully updated to: " << currency << endl;
                                        }
                                        else
                                        {
                                            system("CLS");
                                            cout << "Please type in correct currency shortcut!" << endl;
                                            system("pause");
                                        }
                                    }
                                case 2:
                                    system("CLS");
                                    break;
                                default:
                                    system("CLS");
                                    cout << "Please type in correct input!" << endl;
                                    break;
                                }
                            }
                            else if (settingschoice == 2)
                            {
                            int usernamestingchoice;
                                system("CLS");
                                cout << "Your current username: " << usrname << endl;
                                cout << "1 - change your username" << endl;
                                cout << "2 - come back to main menu" << endl;
                                cout << "Input your choice here: ";
                                cin >> usernamestingchoice;
                                switch (usernamestingchoice)
                                {
                                case 1:
                                    system("CLS");
                                    cout << "Type in your new username here: ";
                                    cin >> usrname;
                                    system("CLS");
                                    cout << "Your username has been sucesfully changed from " << usrnamecreate << " to " << usrname << endl;
                                    break;
                                case 2:
                                    system("CLS");
                                    break;
                                default:
                                    system("CLS");
                                    cout << "Please type in correct input!" << endl;
                                    break;
                                }
                            }
                            else
                            {
                                system("CLS");
                                cout << "There is no option like that, please enter valid number!" << endl;
                                system("pause");
                            }
                            system("pause");
                            break;
                        case 5:
                            system("CLS");
                            cout << "It was good to see you, hope I will see you soon again!" << endl;
                            system("pause");
                            czy_koniec = true;
                            log_in = true;
                            break;
                        default:
                            system("CLS");
                            cout << "Choose a proper action number!" << endl;
                            system("pause");
                            break;
                        }
                    }
                    log_in = true;
                }
                else if (passwrd != passwrdcreate)
                {
                    system("CLS");
                    cout << "You've typed in wrong password!" << endl;
                    system("pause");
                    log_in = true;
                }
                else if (usrname != usrnamecreate)
                {
                    system("CLS");
                    cout << "You've mispelled your username, or haven't created an account yet!" << endl;
                    system("pause");
                    log_in = true;
                }
                else
                {
                    system("CLS");
                    cout << "You've mispelled your credentials, or haven't created an account yet!" << endl;
                    system("pause");
                    log_in = true;
                }
            case 3:
                main_menu = true;
                log_in = true;
                break;
            default:
                system("CLS");
                cout << "Please type in correct input" << endl;
                system("pause");
                break;
            }
        }
    }
}