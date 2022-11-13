#include "func1.h"
#include <iostream>
using namespace std;

int _stateMenu;
void Menu(){
    cout << "Select an action:" << endl;
    cout << "0. Exit." << endl;
    cout << "1.Data input." << endl;
    cout << "2.Data output." << endl;
    cout << "3.Change data." << endl;
    cout << "4.Delete data." << endl;
    cout << "5.Add data." << endl;
    cout << "6.Save data." << endl;
    cout << "Your choice: ";
    cin >> _stateMenu;

}
int main(void)
{
 DataInit();

 Menu();

 int _actions;
 string fileName;

 while(_stateMenu != 0)
 {
     switch(_stateMenu)
     {
     case 1:
         system("cls");

         cout << "Input manually or from a file? " << endl;
         cin >> _actions;

         system("cls");

         if(_actions == 1){
             DataEntry();
         }
         else
         {
             cout << "File name? " << endl;
             cin >> fileName;

             DataRead(fileName);
         }
         system("pause");
         system("cls");
         Menu();
         break;

     case 2:
         system("cls");

         Print();

         system("pause");
         system("cls");
         Menu();
         break;
     case 3:
         system("cls");

         DataChange();

         system("pause");
         system("cls");
         Menu();
         break;

     case 4:
         system("cls");

         Delete();

         system("pause");
         system("cls");
         Menu();
         break;
     case 5:
         system("cls");

         Add();

         system("pause");
         system("cls");
         Menu();
         break;
     case 6:
         system("cls");

         cout << "Enter file name: ";
         cin >> fileName;

         system("cls");

         Save(fileName);

         system("pause");
         system("cls");
         Menu();
         break;
     default:
         cout << "Wrong menu item selected!" << endl;
         break;
     }
 }
 system ("cls");
 if (Clean())
     cout << "Data cleared" << endl;
 else
     cout << "Data not cleared" << endl;

 cout << "Work is Done!" << endl;
 system("pause");
}
