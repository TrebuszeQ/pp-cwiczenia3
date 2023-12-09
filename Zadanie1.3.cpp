#include <iostream>
#include <string>
#include <list>

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
                break;

            case 3:
                break;

            case 4:
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
