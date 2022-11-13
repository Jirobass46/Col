#include "func1.h"

void DataInit()
{
    ofstream _buf("buffer.txt");

    if (!_buf)
        cout << "Error creating spool file!" << endl;

    _buf.close();
}

void DataEntry()
{
    string _surname;
    int _age;
    string _name;
    int n;

    cout << "Enter the amount of data" ;
    cin >> n;

    ofstream record("buffer.txt", ios::app);

    if(record){
        record << n << endl;

        for(int i = 0; i < n;i++){
            cout << "Enter the surname:";
            cin >> _surname;

            cout << "Enter the age:";
            cin >> _age;

            cout << "Enter the name: ";
            cin >> _name;


            record << _surname << endl;
            record << _age << endl;

            if (i < n - 1)
                record << _name << endl;
            else
                record << _name;


            cout << "_________________________" << endl;

        }
    }
    else
        cout << "Error opening file!";
    record.close();
}

void DataRead(string fileName)
{
    ifstream reading(fileName);
    ofstream record("buffer.txt",ios::out);

    if (reading){
        if (record){

            string _surname;
            int _age;
            string _name;
            int n;

            reading >> n;
            record << n << endl;

            for(int i = 0; i < n;i++){
                reading >> _surname;

                reading >> _age;

                reading >> _name;


                record << _surname << endl;
                record << _age << endl;

                if (i < n - 1)
                    record << _name << endl;
                else
                    record << _name;
                }
            cout << "Data read!" << endl;
        }
        else
            cout << "Error opening buffer!" << endl;
    }
    else cout << "File opening error!" << endl;

    reading.close();
    record.close();
}

void Print()
{
    ifstream reading ("buffer.txt");

    if (reading)
    {
        string _surname;
        int _age;
        string _name;
        int n;

        reading >> n;
        cout << "Data amount:" << n << endl << endl;

        for (int i = 0; i < n; i++){
            cout << "Number of data " << i + 1 << endl;

            reading >> _surname;
            cout << "Surname: " << _surname << endl;

            reading >> _age;
            cout << "Age: " << _age << endl;

            reading >> _name;
            cout << "Name: " << _name << endl;

            cout << "_____________________________________________________" << endl;

        }
    }
    else
        cout << "Error file openning!" << endl;

    reading.close();
}

bool Clean()
{
    bool clear = false;

    fstream _buf("buffer.txt", ios::out);

    if(!_buf)
        cout << "Error opening spooled file!" << endl;

    _buf.clear();

    if (_buf.peek() == EOF)
        clear = true;
    else
        clear = false;

    _buf.close();

    return clear;
}

void Copy()
{
    ifstream reading("buffer.txt");
    ofstream record("buffer_.txt", ios::out);

    if (reading){
        if (record){
            string _surname;
            int _age;
            string _name;
            int n;


            reading >> n;
            record << n << endl;

            for (int i = 0; i < n;i++){
                reading >> _surname;
                record << _surname << endl;

                reading >> _age;
                record << _age << endl;

                reading >> _name;
                if(i<n-1)
                    record << _name << endl;
                else
                    record << _name;

            }
        }
        else
            cout << "Error openning file!" << endl;

    }
    else cout << "Error opening spooled file!" << endl;
    record.close();
    reading.close();
}

void DataChange()
{
    Copy();

    ifstream reading("buffer_.txt");
    ofstream record("buffer.txt", ios::out);

    if (reading){
        if (record){

            string _surname;
            int _age;
            string _name;
            int n, _n;

            reading >> n;

            cout << "Select the number of the element to change (from 1 to " << n << "): ";
            cin >> _n;
            _n--;

            system("cls");

            record << n << endl;

            if(_n >= 0 && _n < n){

                for (int i = 0;i < n;i++){
                    if (i != _n){
                        reading >> _surname;
                        record << _surname << endl;

                        reading >> _age;
                        record << _age << endl;

                        reading >> _name;
                        if (i < n - 1)
                            record << _name << endl;
                        else
                            record << _name;
                    }
                    else
                    {
                        cout << "Surname: ";
                        cin >> _surname;

                        cout << "Age: ";
                        cin >> _age;

                        cout << "Name: ";
                        cin >> _name;

                        record << _surname << endl;
                        record << _age << endl;
                        if (i < n - 1)
                            record << _name << endl;
                        else
                            record << _name;

                        reading >> _surname;
                        reading >> _age;
                        reading >> _name;
                    }
                }

                cout << "Data changed!" << endl;

            }
            else
                cout << "Number entered incorrectly!" << endl;


        }
        else
            cout << "Error openning file!" << endl;
    }
    else
        cout << "Error opening spooled file!" << endl;

    record.close();
    reading.close();

    remove("buffer_.txt");
}

void Delete()
{
    Copy();

    ifstream reading("buffer_.txt");
    ofstream record("buffer.txt", ios::out);

    if (reading){
        if (record){
            string _surname;
            int _age;
            string _name;
            int n, _n;


            reading >> n;
            int b = n - 1;


            cout << "Select the number of the element to change (from 1 to " << n << "): ";
            cin >> _n;
            _n--;

            system("cls");

            record << b << endl;

            if (_n >= 0 && _n < n){
                for(int i = 0;i < n; i++){
                    if (i!= _n){
                        reading >> _surname;
                        record << _surname << endl;

                        reading >> _age;
                        record << _age << endl;

                        reading >> _name;
                        if (i < n-1)
                            record << _name << endl;
                        else
                            record << _name;

                    }
                    else
                    {
                        reading >> _surname;
                        reading >> _age;
                        reading >> _name;
                    }
                }
                cout << "Data deleted!" << endl;

            }
            cout << "Number entered incorrectly!" << endl;
        }
        cout << "Error openning file!" << endl;
    }
    cout << "Error opening spooled file!" << endl;

    record.close();
    reading.close();

    remove("buffer_.txt");
}

int AOD()
{
    ifstream _buf("buffer.txt");
    int n;

    if (_buf){
        _buf >> n;
    }
    else cout << "Error opening spooled file!"  << endl;

    _buf.close();

    return n;
}

void Add()
{
    string _surname;
    string _name;
    int _age;
    int n = AOD() + 1;

    ofstream record("buffer.txt", ios::app);
    ofstream record_("buffer.txt",ios::out | ios::in);

    if (record_){
        record_ << n << endl;
    }
    else
        cout << "Error opening spooled file!" << endl;

    if (record){
        record << endl;

        cout << "Surname: ";
        cin >> _surname;

        cout << "Age: ";
        cin >> _age;

        cout << "Name: ";
        cin >> _name;

        record << _surname << endl;
        record << _age << endl;
        record << _name << endl;

    }
    else
        cout << "Error opening file!" << endl;
    record.close();
    record_.close();
}

void Save(string fileName)
{
    ifstream reading("buffer.txt");
    ofstream record(fileName, ios::out);

    if (reading){
        if (record){

            string _surname;
            int _age;
            string _name;
            int n;

            reading >> n;
            record << n << endl;

            for (int i = 0; i < n; i++){
                reading >> _surname;
                record << _surname << endl;

                reading >> _age;
                record << _age << endl;

                reading >> _name;
                if (i < n - 1)
                    record << _name << endl;
                else
                    record << _name;

            }
            cout <<"Data saved in file " << fileName << endl;

        }
        else
            cout << "Error opening spooled file!" << endl;
    }
    else
        cout << "Error opening file!" << endl;

    record.close();
    reading.close();
}

