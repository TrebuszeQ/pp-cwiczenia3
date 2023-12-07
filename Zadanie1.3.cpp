#include <iostream>
#include <string>
#include <map>

using namespace std;


// funkcja wyswietla wiadomosc i przyjmuje wartosc in
string read_input_str(string message) {
    string in = "";
    cout << message << endl;
    cin >> in;

    return in;
}


// funkcja sprawdza czy str jest liczba calkowita
bool is_int(string str) {
    try {
        stoi(str);
    }
    
    catch (exception e) {
        return false;
    }

    return true;
}


// funkcja sprawdza czy argument int jest ujemny
bool is_negative_int(int arg) {
    if (arg >= 0) return false;
    else return true;
}


// funkcja sprawdza czy argument float jest ujemny
bool is_negative_flt(float arg) {
    if (arg >= 0) return false;
    else return true;
}


// funkcja dodaje do siebie zawartosc args i zwraca sume
int sum_int(int args[], int len) {
    int sum = 0;
    
    for (int i = 0; i < len - 1; i++) {
        sum += args[i];
    }

    return sum;
}


// program wczytuje nieujemna liczbe calkowita.
int read_int_positive() {
    string n;
  
    while (true) {
        string n = read_input_str("Podaj liczbe calkowita nieujemna.\n");

        if (is_int(n)) {
            int n_int = stoi(n);

            if (!is_negative_int(n_int)) return n_int;
            else printf("Liczba %i jest ujemna.\n", n_int);
        }

        else cout << ("Wprowadzona wartosc nie jest prawidlowa.\n");
    }

    return -1;
}


// program wczytuje nieujemna i ujemna liczbe calkowita.
int read_int_negative() {
    string n;

    while (true) {
        string n = read_input_str("Podaj liczbe calkowita.\n");

        if (is_int(n)) return stoi(n);
        else cout << ("Wprowadzona wartosc nie jest prawidlowa.\n");
    }

    return -1;
}


// funkcja wczytuje n liczb calkowitych
int* read_n_ints(int n) {
    int* result = new int[n];
    if (n > 0) {
        for (int i = 0; i < n - 1; i++) {
            result[i] = read_int_negative();
        }
        
    }
    
    else {
        cout << "Tablica jest pusta.";
    }

    return result;
}


// funkcja 

void program1() {
    cout << "Program, ktory wczytuje z klawiatury N liczb calkowitych.\n";
    cout << "Oblicza sume i ilosc elementow dodatnich oraz sume i ilosc elementow ujemnych.\n";
    cout << "Oblicza srednia arytmetyczna liczb ujemnych.\n\n";

    int n = read_int_positive();
    int* arr = read_n_ints(n);


}

int main() {

   

    
    cout << "Opcje:\n";

    return 0;
}
