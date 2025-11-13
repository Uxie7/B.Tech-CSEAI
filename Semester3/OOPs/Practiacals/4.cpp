
// 4. Create a class called Musicians to contain three methods string(), wind() and percussion(). Each of these methods should initialize a string array to contain the following instruments:

// veena, guitar, sitar, sarod and mandolin under string()
// flute, clarinet, saxophone, nadhawaram and piccolo under wind()
// tabla, mridangam, bangos, drums and tambour under percussion()

// The base class should also display the contents of the arrays that are initialized using show() method.

// Create a derived class called InsType to contain a method called get() and show().
// The get() method must display Type of instruments to be displayed:
// a. String instruments
// b. Wind instruments
// c. Percussion instruments

// The show() method should display the relevant detail according to our choice. The base class variables must be accessible only to its derived classes.


#include <iostream>
#include <string>
using namespace std;

//base class : Musicians
class Musicians {
protected:
    //arrays to store instruments of each type
    string strInstruments[5];
    string windInstruments[5];
    string percInstruments[5];

public:
    //method to initialize string instruments
    void stringInstruments() {
        strInstruments[0] = "Veena";
        strInstruments[1] = "Guitar";
        strInstruments[2] = "Sitar";
        strInstruments[3] = "Sarod";
        strInstruments[4] = "Mandolin";
    }

    //method to initialize wind instruments
    void windInstrumentsList() {
        windInstruments[0] = "Flute";
        windInstruments[1] = "Clarinet";
        windInstruments[2] = "Saxophone";
        windInstruments[3] = "Nadaswaram";
        windInstruments[4] = "Piccolo";
    }

    //method to initialize percussion instruments
    void percussionInstruments() {
        percInstruments[0] = "Tabla";
        percInstruments[1] = "Mridangam";
        percInstruments[2] = "Bongos";
        percInstruments[3] = "Drums";
        percInstruments[4] = "Tambour";
    }

    //method to display any array
    void show(string arr[], int size) {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << endl;
        }
    }
};

//derived class : InsType
class InsType : public Musicians {
public:
    //ask the user which type of instruments to display
    void get() {
        int choice;
        cout << "Type of instruments to be displayed: \n";
        cout << "1. String instruments\n";
        cout << "2. Wind instruments\n";
        cout << "3. Percussion instruments\n";
        cout << "\nEnter your choice: ";
        cin >> choice;

        //based on choice, show relevant instruments
        switch (choice) {
        case 1:
            stringInstruments(); //initialize
            cout << "\nString Instruments:\n";
            show(strInstruments, 5); //display
            break;

        case 2:
            windInstrumentsList(); //initialize
            cout << "\nWind Instruments:\n";
            show(windInstruments, 5); //display
            break;

        case 3:
            percussionInstruments(); //initialize
            cout << "\nPercussion Instruments:\n";
            show(percInstruments, 5); //display
            break;

        default:
            cout << "Invalid choice!" << endl;
        }
    }
};

int main() {
    InsType obj;  //create derived class object
    obj.get();    //call get() method
    return 0;
}
