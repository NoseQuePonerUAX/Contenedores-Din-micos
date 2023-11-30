#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <algorithm>
#include <valarray>
#include <memory>
#include <boost/lexical_cast.hpp>

using namespace std;

namespace boost
{
    class bad_lexical_cast;
    template<typename Target, typename Source>
    Target lexical_cast(const Source& arg);
}

int main() {
    vector<int> numeros = {10, 20, 30, 40, 50};

    for(vector<int>::iterator it = numeros.begin(); it != numeros.end(); ++it) {
    cout << *it << " ";
    }
    cout << endl; //Término del Ejercicio 1

    list<float> lista = {1.1, 2.2, 3.3, 4.4, 5.5};
    stack<float, list<float>> pila(lista);

    while(!pila.empty()) {
        cout << pila.top() << " ";
        pila.pop();
    }
    cout << endl; //Término del Ejercicio 2

    vector<int> numeros1 = {50, 20, 60, 10, 30, 40};
    sort(numeros1.begin(), numeros1.end());

    for(int num : numeros1) {
        cout << num << " ";
    }
    cout << endl; //Para que aparezca en fila en vez de columna

    int maxNum = *max_element(numeros1.begin(), numeros1.end());
    cout << "Numero maximo: " << maxNum << endl; //Término del Ejercicio 3

    valarray<double> valores = {1.0, 2.0, 3.0, 4.0, 5.0};

    cout << "Suma: " << valores.sum() << endl;
    cout << "Media: " << valores.sum() / valores.size() << endl;

    valores += 5.0;

    cout << "Valores + 5.0: ";
    for(double valor : valores) {
        cout << valor << " ";
    }
    cout << endl; //Término del Ejercicio 4

    auto cuadrado = [](int num) { return num * num; };

    cout << "Cuadrado de 5: " << cuadrado(5) << endl;

    vector<int> numeros2 = {1, 2, 3, 4, 5};
    for_each(numeros2.begin(), numeros2.end(), [](int num) {
        cout << num << " ";
    });
    cout << endl; //Para que aparezca en fila en vez de columna

    shared_ptr<int> ptr(new int(10));
    cout << "Valor apuntado por ptr: " << *ptr << endl; //Término del Ejercicio 5

    string s = "12345";

    try {
        int i = boost::lexical_cast<int>(s);
        cout << "Numero: " << i << endl;
    } catch(boost::bad_lexical_cast &e) {
        cerr << "Error: " << e.what() << endl;
    } //No encontré como instalar boost profesor, le fallé.


    return 0;
}