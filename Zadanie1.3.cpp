#include <iostream>
#include <string>
#include <list>
#include <math.h>
#include <format>

using namespace std;


// funkcja wyswietla wiadomosc i przyjmuje wartosc in
string read_input_str(string message) {
    string in;
    cout << message << endl;
    cin >> in;

    return in;
}


string read_input_line(string message) {
    string in;
    cout << message << endl;
    cin >> in;
    string part = in;
    getline(cin, in);
    return part + in;
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


// program wczytuje nieujemna liczbe calkowita.
int read_int_positive(string message) {
    string n;
  
    while (true) {
        string n = read_input_str(message);

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
int read_int_negative(string message) {
    string n;

    while (true) {
        string n = read_input_str(message);

        if (is_int(n)) return stoi(n);
        else cout << ("Wprowadzona wartosc nie jest prawidlowa.\n");
    }

    return -1;
}


// wyswietla zawartosc tablicy
void print_list(list<int> lis) {
    if (lis.size() > 0) {
        cout << "Lista: ";
        int i = 0;

        for (int elem : lis) {
            cout << elem;

            if (i == (lis.size() - 1)) cout << ".\n";
            else cout << ", ";
            i++;
        }
    }
    
    else cout << "Lista jest pusta.\n";
}


// funkcja wczytuje n liczb calkowitych do listy
list<int> read_n_ints(int n) {
    list<int> lis;

    if (n > 0) {
        for (int i = 0; i < n; i++) {
            lis.push_front(read_int_negative("Wprowadz element listy.\n"));
        }
        
    }
    
    else cout << "Lista jest pusta.\n";

    // cout << "check" << endl;
    // for (int i = 0; i < n; i++) {
    //    cout << result[i] << ";";
    // }

    return lis;
}


// funkcja dodaje do siebie dodatnie zawartosci args. Zwraca sume i ilosc liczb dodatnich.
int * sum_positive_int(list<int> lis) {
    int sum = 0;
    int count = 0;


    for (int elem : lis) {
        if (elem > 0) {
            sum += elem;
            count++;
        }
    }
    
    static int result[2] = { sum, count };

    return result;
}


// funkcja dodaje do siebie ujemne zawartosci args. Zwraca srednia arytmetyczna i ilosc liczb ujemnych.
float * sum_negative_int(list<int> lis) {
    int avg = 0;
    int count = 0;

    for (int elem : lis) {
        if (elem < 0) {
            avg += elem;
            count++;
        }
    }

    static float result[2];

    if (count > 0) {
        result[0] = abs((1.0f * avg) / (1.0f * count));
        result[1] = count;
    }

    else {
        result[0] = 0;
        result[1] = count;
    }

    return result;
}


// Program, ktory wczytuje z klawiatury N liczb calkowitych. 
// Oblicza sume i ilosc elementow dodatnich oraz sume i ilosc elementow ujemnych.
// Oblicza srednia arytmetyczna liczb ujemnych.
void zadanie1() {
    cout << "Program, ktory wczytuje z klawiatury N liczb calkowitych.\n";
    cout << "Oblicza sume i ilosc elementow dodatnich oraz sume i ilosc elementow ujemnych.\n";
    cout << "Oblicza srednia arytmetyczna liczb ujemnych.\n\n";

    int n = read_int_positive("Wprowadz ilosc liczb do wczytania.\n");
    list<int> lis = read_n_ints(n);

    print_list(lis);
    int *res_pos = sum_positive_int(lis);
    float *res_neg = sum_negative_int(lis);

    printf("n: %i\nSuma liczb pozytywnych: %i\nIlosc liczb pozytywnych: %i\nSrednia liczb negatywnych: %0.1f.\nIlosc liczb negatywnych. %i\n", 
        n, res_pos[0], res_pos[1], res_neg[0], (int) res_neg[1]);
 }


 // Program, ktory wczytuje kolejne liczby calkowite do momentu wczytania zera
 // Oblicza i wypisuje pierwiastek z wczytanej liczby
void zadanie2() {
    int n = -1;
    while (n != 0) {
        cout << "Program, ktory wczytuje kolejne liczby calkowite do momentu wczytania zera.\n";
        cout << "Oblicza i wypisuje pierwiastek z wczytanej liczby.\n\n";

        n = read_int_negative("Wprowadz liczbe calkowita:\n");
        if (n == 0) {
            cout << "Wyjscie.";
            return;
        }
            

        double root = sqrt(n);
        printf("Pierwiastek: %0.2f.\n", root);
    }
}


// oblicza sume okreslona wzorem i wypisuje obliczona wartosc
// sigma (od 1 do k) = (( 3 * i + 1.2 ) / ( 2 * i ))
void zadanie3() {
    cout << "Program oblicza sume okreslona wzorem i wypisuje obliczona wartosc.\n";
    cout << "Wzor: sigma (od 1 do k) = (( 3 * i + 1.2 ) / ( 2 * i )).\n\n";

    int k = read_int_positive("Wprowadz dla k liczbe calkowita wieksza od 0:\n");
    int i = 1;
    double s = 0;
    
    for (i = 1; i <= k; i++) {
        s += ((3 * i + 1.2) / (2 * i));
    }

    printf("sigma = %0.2f.\n\n", s);
}


// zwraca ilosc pieter
int get_floors() {
    int floors;

    do {
        floors = read_int_positive("Wprowadz calkowita liczbe pieter hotelu [nie mniej niz 0]:\n");
    } while (floors < 1);

    return floors;
}


// odczytuje ilosc pokoi
int get_rooms() {
    int rooms = 5;
   
    do {
        rooms = read_int_positive("Wprowadz ilosc pokoi na pietrze [nie mniej niz 5]:\n");
    } while (rooms < 5);
    
    return rooms;
}


// zwraca ilosc zajetych miejsc
int get_occupied_rooms(int rooms) {
    int n = 0;
    
    do {
        n = read_int_positive("Wprowadz ilosc zajetych pokoi na pietrze:\n");
    } while (n > rooms);
    
    return n;
}


// Program oblicza i wyswietla oblozenie hotelu na podstawie liczby pieter i pokoi.
void zadanie4() {
    cout << "Program oblicza i wyswietla oblozenie hotelu na podstawie liczby pieter i pokoi.\n\n";
    string name = read_input_line("Podaj nazwe hotelu:\n");
    int floors = get_floors();
    int rooms = 0;
    int sum_rooms = 0;
    int rooms_o = 0;
    int sum_rooms_o = 0;
    float rooms_o_p = 0;
    string message = "W hotelu " + name + " jest " + to_string(floors) + " pieter.\n";

    for (int i = 0; i < floors; i++) {
        cout << "Pietro: " << i << ".\n";

        if (i == 13) { 
            message += "Na pietrze 13 nie ma pokoi.\n";
            continue;
        }

        else {
            rooms = get_rooms();
            sum_rooms += rooms;
            rooms_o = get_occupied_rooms(rooms);
            sum_rooms_o += rooms_o;
            rooms_o_p = 0;
            rooms_o_p = ((rooms_o * 1.0f) / (rooms * 1.0f)) * 100;
            message += format("Na pietrze {} jest  {}% pokoi zajetych.\n", to_string(i), to_string(rooms_o_p));
        }
    }

    rooms_o_p = ((sum_rooms_o * 1.0f) / (sum_rooms * 1.0f)) * 100;
    cout << message;
    printf("Hotel ma %i pokoi, %0.2f pokoi jest zajetych.\n\n", sum_rooms, rooms_o_p);
}


int main() {
    while (true) {
        cout << "Opcje:\n";
        cout << "1. Zadanie 1.3.1.\n";
        cout << "2. Zadanie 1.3.2.\n";
        cout << "3. Zadanie 1.3.3.\n";
        cout << "4. Zadanie 1.3.4.\n";
        cout << "5. Wyjscie.\n\n";

        int opt = read_int_positive("Wprowadz numer zadania [od 0 - 5].\n");

        switch (opt) {
            case 0:
                
                break;
            
            case 1:
                zadanie1();
                break;

            case 2:
                zadanie2();
                break;

            case 3:
                zadanie3();
                break;

            case 4:
                zadanie4();
                break;

            case 5:
                exit(1);

            default:
                cout << "Brak wybranej opcji.\n";
                break;
        }
    }

    return 0;
}
