#include <iostream>
#include <vector>

using namespace std;

// ЗАДАИНЕ: НАПИСАТЬ ФУНКЦИЮ РАЗМЫТИЯ ДЛЯ КАРТИНКИ (НАЙТИ СРЕДНЕЕ АРИФМЕТИЧЕСКОЕ)

//функция для размытия изображения
vector<vector<int>> blurImage(const vector<vector<int>>& image) {
    int N = image.size(); //размер матрицы изображения
    vector<vector<int>> blurredImage(N, vector<int>(N, 0)); //матрица для хранения размытого изображения

    //проход по каждому пикселю
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int sum = 0; //сумма значений соседних пикселей
            int count = 0; //количество соседних пикселей


            //ссумируем значения соседей 
            for (int di = -1; di <= 1; di++) {
                for (int dj = -1; dj <= 1; dj++) {
                    //условие для соседних пикселей по вертикали и горизонтали
                    //условие проверки выхода за матрицу
                    if ((di == 0 || dj == 0) && (i + di >= 0 && i + di < N && j + dj >= 0 && j + dj < N)) {
                        sum += image[i + di][j + dj];
                        count++;
                    }
                }
            }

            //новые среднее арифметическое значение пикселя
            blurredImage[i][j] = sum / count;
        }
    }

    return blurredImage;
}

int main()
{
    setlocale(LC_ALL, "Russian");
   
    int vvod = 0;

    while (true) {
        cout << "ЗАДАНИЕ: Создание функции размытия изображения" << endl;
        cout << endl;
        cout << "1. Автоматическая проверка" << endl;
        cout << "2. Ручаная проверка" << endl;
        cout << "0. Выход" << endl;
        cout << "Введите пункт, как провести проверку теста: ";
        cin >> vvod;

        if (vvod == 1) { //тест использования функции АВТОМАТИЧЕСКИЙ
            
            int N = 5; //размер матрицы
            vector<vector<int>> image = {
                {10, 20, 30, 40, 50},
                {60, 70, 80, 90, 100},
                {110, 120, 130, 140, 150},
                {160, 170, 180, 190, 200},
                {210, 220, 230, 240, 250},
            };

            vector<vector<int>> blurredImage = blurImage(image);

            //вывод размытого изображения
            for (const auto& row : blurredImage) {
                for (int pixel : row) {
                    cout << pixel << " ";
                }
                cout << endl;

            }
            cout << endl;
        }
        if (vvod == 2) { //тест использования функции РУЧНОЙ
            cout << "Ручная проверка" << endl;
            cout << endl;
        }
        if (vvod == 0) {
            return 0;
        }
        else {
            cout << endl;
            cout << "Введен несуществующий пункт меню, попробуйте снова" << endl;
            cout << endl;
        }
    }
}

