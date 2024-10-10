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
            blurImage[i][j] = sum / count;
        }
    }

    return blurImage;
}

int main()
{
    setlocale(LC_ALL, "Russian");
   
}

